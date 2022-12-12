import torch
from torchvision.datasets import MNIST
import torch as t
import torch.nn as nn
import torch.nn.functional as F
import datetime
import numpy as np
import pandas as pd
import tensorflow as tf
torch.set_printoptions(precision=10)
class LeNet(nn.Module):
    def __init__(self):
        super(LeNet, self).__init__()
        self.conv1 = nn.Conv2d(in_channels=1, out_channels=3, kernel_size=(5, 5), stride=1)
        self.maxpool1 = nn.MaxPool2d((2, 2), stride=2)
        self.fc1 = nn.Linear(432, 10)
        self.softmax1 = nn.Softmax(dim=1)  # 对每一行进行softmax      dim = 0是对行

    def forward(self, x):
        print ("conv1_input",x.shape)
        x = F.relu(self.conv1(x))
        print("卷积后输出", x.shape)
        x = self.maxpool1(x)  #output N*3*2*2   N表示一次前向传播中的batch_size
        print("池化后输出", x.shape)
        x = x.view(x.size()[0], -1)     #每张图片压平为1维   N*12
        print("全连接层输入",x.shape)
        # print(x[1])
        # x = torch.dropout(x,p=0.1,train=True)
        x = self.fc1(x)            #N*6
        x = self.softmax1(x)
        print("softmax输出",x.shape)
        return x
# def extract_params(model):
#     bias_conv1 = model.conv1.bias.data
#     weight_conv1 = model.conv1.weight.data
#     bias_fc1 = model.fc1.bias.data
#     weight_fc1 = model.fc1.weight.data
#     # print("卷积层偏置",bias_conv1,bias_conv1.size())
#     # print("卷积层权重",weight_conv1,weight_conv1.size())
#     print("全连接层偏置", bias_fc1, bias_fc1.size())
#     print("全连接层权重", weight_fc1, weight_fc1.size())
#
#     '''存储卷积层和全连接层权重参数'''
#     fc1_bias = bias_fc1.detach().numpy()
#     fc1_bias = fc1_bias.reshape(-1,6)
#     fc1_weight = weight_fc1.detach().numpy()
#     np.savetxt('fc1_weight.csv', fc1_weight, delimiter=',')
#     np.savetxt('fc1_bias.csv', fc1_bias, delimiter=',')
#     # return bias_fc1,weight_fc1

'''改变输入数据要修改网络结构以及卷积层hook函数，池化层中的卷积步长等（模型参数）'''
#写不同层的hook函数，分别存储csv
def hook_conv1(net, inputdata, output):
    # print("check_conv1_output",output)   #N*C*H*W
    bias_conv1 = net.bias.data
    weight_conv1 = net.weight.data
    temp = list(inputdata).pop(0)  # inputdata为元组类型，使用列表转换，弹出第一个元素即为张量形式
    conv1_input = temp.detach().numpy()
    conv1_output = output.detach().numpy()
    conv1_bias = bias_conv1.detach().numpy()
    conv1_weight = weight_conv1.detach().numpy()
    kernel_H,kernel_W = conv1_weight.shape[2],conv1_weight.shape[3]
    print("卷积shape", kernel_H*kernel_W)
    conv1_weight = conv1_weight.reshape(-1, kernel_H*kernel_W)

    print("卷积层输入大小",conv1_input.shape)
    print("卷积层输出大小",conv1_output.shape)
    print("卷积层bias大小",conv1_bias.shape)
    print("卷积层weight大小",conv1_weight.shape)
    # 卷积输入数据转换为大矩阵X     X*W+b = conv_output
    conv1_input_im2col = im2col(conv1_input, kernel_H, kernel_W, 1, 0)   #参数：卷积输入数据，卷积核-高，卷积核-宽，步长，填充

    # 三维numpy无法输出为csv,必须用reshape重塑
    N_input,C_input,H_input,W_input = conv1_input.shape[0] , conv1_input.shape[1] , conv1_input.shape[2] , conv1_input.shape[3]
    N_output,C_output,H_output,W_output = conv1_output.shape[0] , conv1_output.shape[1] , conv1_output.shape[2] , conv1_output.shape[3]

    print("卷积层输入shape", N_input, C_input*H_input*W_input, "\n卷积层输出shape", N_output, C_output*H_output*W_output)

    c = conv1_input.reshape(-1, C_input*H_input*W_input)
    b = conv1_output.reshape(-1, C_output*H_output*W_output)
    # np.savetxt('conv1_input__'+str+'.csv', c, delimiter=',')
    # np.savetxt('conv1_output__'+str+'.csv', b, delimiter=',')
    '''处理：浮点数变整数（分数化）'''
    function_vector_1 = np.vectorize(fix_A)
    function_vector_2 = np.vectorize(fix_B)

    # 将浮点数矩阵分数化，nume:分子，deno:分母
    conv1_input_im2col_nume = function_vector_1(conv1_input_im2col)
    conv1_output_nume_handle = function_vector_2(conv1_output)
    conv1_weight_nume = function_vector_1(conv1_weight)
    conv1_bias_nume = function_vector_2(conv1_bias)
    '''ndarray数据类型转换float32转int32'''
    conv1_input_im2col_nume.astype(np.int32)


    print("conv1_input_im2col_nume_shape", conv1_input_im2col_nume.shape)
    print("conv1_output_nume_handle_shape", conv1_output_nume_handle.shape)
    print("conv1_weight_nume_shape", conv1_weight_nume.shape)
    print("conv1_bias_nume_shape", conv1_bias_nume.shape)

    '''处理得到的可参与验证的conv1层输出,以下用到的皆为分子'''
    w_T = conv1_weight_nume.T
    l = np.matmul(conv1_input_im2col_nume, w_T)
    conv1_out_nume = l + conv1_bias_nume
    # print("处理得到的可参与验证的conv1层输出分子\n", conv1_out_nume, type(conv1_out_nume), conv1_out_nume.dtype)
    # print("直接处理：conv1层输出：conv1_output_nume分子\n", conv1_output_nume_handle, conv1_output_nume_handle.dtype)
    conv1_out_nume.astype(np.int32)

    print("1.conv1_weight_nume尺寸\n", conv1_weight_nume.shape)
    print("1.conv1_bias_nume尺寸\n", conv1_bias_nume.shape)
    print("1.conv1_input_im2col_nume尺寸\n", conv1_input_im2col_nume.shape)
    print("1.conv1_output_nume尺寸\n", conv1_out_nume.shape)

    #存储
    np.savetxt('data/conv1_weight_nume__'+str+'.csv', conv1_weight_nume, delimiter=',', fmt='%d')
    np.savetxt('data/conv1_bias_nume__'+str+'.csv', conv1_bias_nume, delimiter=',', fmt='%d')
    np.savetxt('data/conv1_input_im2col_nume__'+str+'.csv', conv1_input_im2col_nume, delimiter=',', fmt='%d')
    np.savetxt('data/conv1_output_nume__'+str+'.csv', conv1_out_nume, delimiter=',', fmt='%d')

    print("relu输入------------------------------------\n",conv1_output_nume_handle)
    '''卷积层的无激活输出，即为激活层的输入，这里同样处理为整数'''
    relu1_input = conv1_output_nume_handle.reshape(-1, C_output*H_output*W_output)
    print("relu1层的输入-----------------------\n",relu1_input)
    print("1.relu1_input_nume尺寸\n", relu1_input.shape)

    np.savetxt('data/relu1_input_nume__'+str+'.csv', relu1_input, delimiter=',', fmt='%d')
    function_vector_3 = np.vectorize(relu_C)
    relu1_operation = function_vector_3(relu1_input)
    print("2.relu1_operation尺寸\n",  relu1_operation.shape)

    np.savetxt('data/relu1_operation__'+str+'.csv', relu1_operation, delimiter=',', fmt='%d')
    print("relu1_operation\n",relu1_operation)

    #查看：im2col计算得到的输出还原为网络计算的卷积层输出形式
    r = conv1_out_nume.T
    r = r.reshape(N_output, C_output, H_output, W_output)
    r = r.transpose(1, 0, 2, 3)  # (转换为（N,C，H,W）的形式，与原网络中计算的输出结果形式一致)
    # print("im2col方法自行计算卷积层conv1输出\n", r)


def hook_maxpool1(net,inputdata, output):
   # print("check_maxpool1", output) #N*3*12*12
   temp = list(inputdata).pop(0)
   maxpool1_input = temp.detach().numpy()
   maxpool1_output = output.detach().numpy()
   # 三维numpy无法输出为csv,必须用reshape重塑
   N,C,H_output,W_output = maxpool1_input.shape[0],maxpool1_input.shape[1],maxpool1_output.shape[2],maxpool1_output.shape[3],
   CHW_input = maxpool1_input.shape[1]*maxpool1_input.shape[2]*maxpool1_input.shape[3]
   CHW_output = maxpool1_output.shape[1]*maxpool1_output.shape[2]*maxpool1_output.shape[3]
   print("池化层输入shape", N, CHW_input, "\n池化层输出shape", N, CHW_output)
   c = maxpool1_input.reshape(-1, CHW_input)
   b = maxpool1_output.reshape(-1, CHW_output)
   # np.savetxt('maxpool1_input__'+str+'.csv', c, delimiter=',')
   # np.savetxt('maxpool1_output__'+str+'.csv', b, delimiter=',')

   function_vector_2 = np.vectorize(fix_B)
   relu1_output_nume = function_vector_2(maxpool1_input)
   relu1_output_nume.astype(np.int32)
   relu1_output_nume = relu1_output_nume.reshape(-1, CHW_input)

   print("3.relu1_output_nume尺寸\n", relu1_output_nume.shape)
   np.savetxt('data/relu1_output_nume__'+str+'.csv', relu1_output_nume, delimiter=',', fmt='%d')


   col = im2col(maxpool1_input, 2, 2, 2, 0)  # 参数：池化输入数据，池化-高，池化-宽，步长，填充
   print("池化输入-矩阵col\n",col,col.shape)
   maxpool1_input_col = col.reshape(-1, 2 * 2)
   print("池化输入-矩阵（im2col）\n", maxpool1_input_col, maxpool1_input_col.shape)
   L = maxpool1_input_col.shape[0]
   '''处理：浮点数变整数（分数化）'''
   maxpool1_input_im2col_nume = function_vector_2(maxpool1_input_col)
   maxpool1_input_im2col_nume.astype(np.int32)
   print("maxpool1输入(im2col)-(整数化分子)\n", maxpool1_input_im2col_nume,maxpool1_input_im2col_nume.shape)

   # maxpool的最大值索引，第1维度（每一行最大元素下标）
   idx = np.argmax(maxpool1_input_im2col_nume, axis=1)
   print("池化留下的元素索引",idx)

   # 生成最大池化操作矩阵（自定义,电路中与此计算逻辑相同）
   new_maxpool = np.zeros(maxpool1_input_im2col_nume.shape)
   maxpool1_operation = maxpool_D(new_maxpool, idx,L)
   print("maxpool1操作-矩阵\n", maxpool1_operation,maxpool1_operation.shape)
   temp_maxpool1_out_nume = np.matmul(maxpool1_input_im2col_nume, maxpool1_operation.T)  # (36*4)·（4*36）
   cal_maxpool1_output_nume = np.diagonal(temp_maxpool1_out_nume)  # 取对角元素，对角元素是有效的池化输出信息
   print("池化输出信息(一行展示)",cal_maxpool1_output_nume)

   '''此处保存电路需要的 池化im2col输入,池化输出，池化操作矩阵'''
   maxpool1_output_nume = np.max(maxpool1_input_im2col_nume, axis=1)
   print("1.maxpool1_output_nume尺寸\n",  maxpool1_output_nume.shape)
   print("2.maxpool1_input_im2col_nume尺寸\n",  maxpool1_input_im2col_nume.shape)
   print("3.maxpool1_operation尺寸\n",  maxpool1_operation.shape)

   np.savetxt('data/maxpool1_output_nume__'+str+'.csv', maxpool1_output_nume, delimiter=',', fmt='%d')
   np.savetxt('data/maxpool1_input_im2col_nume__'+str+'.csv', maxpool1_input_im2col_nume, delimiter=',', fmt='%d')
   np.savetxt('data/maxpool1_operation__'+str+'.csv', maxpool1_operation, delimiter=',', fmt='%d')

   '''im2col方法计算的池化输出，对比，还原(注意im2col方法计算的输出要变形才是神经网络中的形式)'''
   cal_maxpool1_output_nume = cal_maxpool1_output_nume.reshape(N, H_output, W_output, C)  # (N, out_h, out_w, C)     变形
   cal_maxpool1_output_nume = cal_maxpool1_output_nume.transpose(0, 3, 1, 2)  # 这里是为了保持和网络中计算的池化输出形式保持一致
   print("col方法计算maxpool1输出(分子)\n", cal_maxpool1_output_nume)
   print("网络计算的maxpool1_output\n", maxpool1_output, maxpool1_output.shape)

   '''整数化处理后，自行计算的maxpool1输出还原为浮点数输出,误差为1/2^(k+1)'''
   # function_vector_3 = np.vectorize(fix_rerurn)
   # OP = function_vector_3(maxpool1_output_nume)
   # print("maxpool1输出还原为浮点数输出", OP)

def hook_fc1(net,inputdata, output):
   # print("check_fc1_input", inputdata)  # N*3*12
   # print("check_fc1_output", output,output.size()) #N*3*6
   bias_fc1 = net.bias.data
   weight_fc1 = net.weight.data
   temp = list(inputdata).pop(0)                     #inputdata为元组类型，使用列表转换，弹出第一个元素即为张量形式
   fc1_input = temp.detach().numpy()                 #  处理后类型为numpy.adarray
   fc1_output = output.detach().numpy()
   fc1_bias = bias_fc1.detach().numpy()
   fc1_weight = weight_fc1.detach().numpy()
   N, CHW_input, CHW_output = fc1_input.shape[0], fc1_input.shape[1], fc1_output.shape[1]
   print("全连接层输入shape", N, CHW_input, "\n全连接层输出shape", N, CHW_output)
   # 三维numpy无法输出为csv,必须用reshape重塑
   c = fc1_input.reshape(-1, CHW_input)
   b = fc1_output.reshape(-1, CHW_output)
   # np.savetxt('fc1_input__'+str+'.csv', c, delimiter=',')
   # np.savetxt('fc1_output__'+str+'.csv', b, delimiter=',')

   #
   # '''---测试tensor张量计算-------------------------------------------'''
   # print("a",weight_fc1,weight_fc1.size())
   # print("b",temp,temp.size())
   # print("c",output,output.size())
   # print("bias", bias_fc1,bias_fc1.shape)
   # weight_fc1_T = weight_fc1.transpose(0,1)
   # bias_fc1 = bias_fc1.unsqueeze(0)
   # print("bias_fc1",bias_fc1,bias_fc1.size())
   #
   # c = temp.mm(weight_fc1_T)
   # z = c + bias_fc1
   # print("自己计算", z)
   # if(torch.equal(z,output)):
   #     print("true1")
   # print("输出",output)
   #
   # s1 = z.detach().numpy()
   # s2 = output.detach().numpy()
   # if (np.array_equal(s1, s2)):
   #     print("true2")
   # '''---测试矩阵计算----------------------------------------------'''

   #Tensor转numpy计算有精度不一致的问题
   # fc1_weight = fc1_weight.T
   # out = np.matmul(fc1_input, fc1_weight)
   # out = out + fc1_bias
   # print("自行计算",out)
   # print("原始", fc1_output)
   # if np.array_equal(fc1_output, out):
   #     print("验证分子矩阵计算，成功！")

   '''处理：浮点数变整数（分数化）'''
   function_vector_1 = np.vectorize(fix_A)
   function_vector_2 = np.vectorize(fix_B)

   #将浮点数矩阵分数化，nume:分子，deno:分母
   fc1_input_nume = function_vector_1(c)
   fc1_output_nume_handle = function_vector_2(b)
   fc1_weight_nume = function_vector_1(fc1_weight)
   fc1_bias_nume = function_vector_2(fc1_bias)
   '''ndarray数据类型转换float32转int32'''
   fc1_input_nume.astype(np.int32)
   fc1_output_nume_handle.astype(np.int32)
   fc1_weight_nume.astype(np.int32)
   fc1_bias_nume.astype(np.int32)

   print("fc1_output_nume_handle_shape",fc1_output_nume_handle.shape)
   '''处理得到的可参与验证的fc1层输出'''
   w_T = fc1_weight_nume.T
   l = np.matmul(fc1_input_nume,w_T)
   fc1_out_nume = l + fc1_bias_nume
   print("处理得到的可参与验证的fc1层输出分子", fc1_out_nume,type(fc1_out_nume),fc1_out_nume.dtype)
   print("直接处理：fc1层输出：fc_output_nume分子",fc1_output_nume_handle,fc1_output_nume_handle.dtype)
   fc1_out_nume.astype(np.int32)
   # if np.array_equal(fc1_out_nume, fc1_output_nume_handle):
   #     print("true3")

   '''存储fc1层参数、输入、输出的分子矩阵'''

   print("1.fc1_weight_nume尺寸\n",fc1_weight_nume.shape)
   print("1.fc1_bias_nume尺寸\n", fc1_bias_nume.shape)
   print("1.fc1_input_nume尺寸\n", fc1_input_nume.shape)
   print("1.fc1_output_nume尺寸\n", fc1_out_nume.shape)

   np.savetxt('data/fc1_weight_nume__'+str+'.csv', fc1_weight_nume, delimiter=',',fmt='%d')
   np.savetxt('data/fc1_bias_nume__'+str+'.csv',   fc1_bias_nume, delimiter=',',fmt='%d')
   np.savetxt('data/fc1_input_nume__'+str+'.csv',  fc1_input_nume, delimiter=',',fmt='%d')
   np.savetxt('data/fc1_output_nume__'+str+'.csv', fc1_out_nume, delimiter=',',fmt='%d')


def hook_softmax1(net,inputdata, output):
    temp = list(inputdata).pop(0)  # inputdata为元组类型，使用列表转换，弹出第一个元素即为张量形式
    softmax1_input = temp.detach().numpy()  # 处理后类型为numpy.adarray
    softmax1_output = output.detach().numpy()
    exp_x = np.exp(softmax1_input)        # e**x
    print("分子\n", exp_x)
    sum = np.sum(exp_x, axis=-1, keepdims=True)   # e**x的和
    print("分母\n",sum)
    out = exp_x / np.sum(exp_x, axis=-1, keepdims=True)
    print("自行计算输出\n",out)
    print("softmax层输入\n", softmax1_input)
    print("softmax层输出\n", softmax1_output)

    '''处理：浮点数变整数（分数化）'''
    #int32 表示范围    -2147483648 到 2147483647    int64 数值取值范围为 -9223372036854775808 到 9223372036854775808

    function_vector_2 = np.vectorize(fix_A)
    softmax1_output_nume = function_vector_2(softmax1_output)
    exp_sum_nume = function_vector_2(sum)

    softmax1_output_nume.astype(np.int32)
    exp_sum_nume.astype(np.int32)

    softmax1_input_exp_nume = softmax1_output_nume * exp_sum_nume
    softmax1_input_exp_nume.astype(np.int32)
    # softmax  :  1. *  2. =   3.
    print("1.softmax1_output_nume尺寸\n",softmax1_output_nume.shape)
    print("2.exp_sum_nume尺寸\n",exp_sum_nume.shape)
    print("3.softmax1_input_exp_nume尺寸\n", softmax1_input_exp_nume.shape)

    np.savetxt('data/softmax1_output_nume__'+str+'.csv', softmax1_output_nume, delimiter=',', fmt='%d')
    np.savetxt('data/exp_sum_nume__'+str+'.csv', exp_sum_nume, delimiter=',', fmt='%d')
    np.savetxt('data/softmax1_input_exp_nume__'+str+'.csv', softmax1_input_exp_nume, delimiter=',', fmt='%d')



'''定点小数表示法-处理：将浮点数转换为整数'''
def fix_A(x):
    return ((int)(x * 2 ** 10))

def fix_B(x):
    return ((int)(x * 2 ** 20))

def fix_rerurn(x):
    return ((x /(2 ** 20)))

def relu_C(x):
    if x < 0:
        x = 0
    else:
        x = 1
    return (x)

def maxpool_D(x,idx,L):
    k = 0
    for id in range(L):
        id = idx[k]
        x[k][id] = 1
        k = k + 1
    return (x)

def softmax_E(x):
    nume = np.exp(x)
    return nume

def im2col(input_data, filter_h, filter_w, stride=1, pad=0):
    """
    Parameters
    ----------
    input_data : 由(数据量, 通道, 高, 长)的4维数组构成的输入数据
    filter_h : 卷积核的高
    filter_w : 卷积核的长
    stride : 步幅
    pad : 填充

    Returns
    -------
    col : 2维数组
    """
    # 输入数据的形状
    # N：批数目，C：通道数，H：输入数据高，W：输入数据长
    N, C, H, W = input_data.shape
    out_h = (H + 2 * pad - filter_h) // stride + 1  # 输出数据的高
    out_w = (W + 2 * pad - filter_w) // stride + 1  # 输出数据的长
    # 填充 H,W
    img = np.pad(input_data, [(0, 0), (0, 0), (pad, pad), (pad, pad)], 'constant')
    # (N, C, filter_h, filter_w, out_h, out_w)的0矩阵
    col = np.zeros((N, C, filter_h, filter_w, out_h, out_w))

    for y in range(filter_h):
        y_max = y + stride * out_h
        for x in range(filter_w):
            x_max = x + stride * out_w
            col[:, :, y, x, :, :] = img[:, :, y:y_max:stride, x:x_max:stride]
    # 按(0, 4, 5, 1, 2, 3)顺序，交换col的列，然后改变形状
    col = col.transpose(0,4,5,1,2,3).reshape(N * out_h * out_w, -1)
    return col

if __name__ == '__main__':
   # oldtime=datetime.datetime.now()
   #初始化网络，输入随机产生的img
   net = LeNet()
   str = input("请输出测试名称序号（例：test_1）")
   print(str)
   N, C, H, W = map(int, input("请输入模型input数据：").split())  # 以空格为间隔符
   img = torch.randn(N, C, H, W)    #（N,C，H,W）:图片数量，通道，高，宽

   handle_conv1 = net.conv1.register_forward_hook(hook_conv1)
   handle_maxpool1 = net.maxpool1.register_forward_hook(hook_maxpool1)
   handle_fc1 = net.fc1.register_forward_hook(hook_fc1)
   handle_softmax1 = net.softmax1.register_forward_hook(hook_softmax1)
   net(img)
   #用完hook后删除
   handle_conv1.remove()
   handle_maxpool1.remove()
   handle_fc1.remove()
   handle_softmax1.remove()
   print("模型预测过程各层的计算信息已提取完毕")
   torch.save(net, "model.pt")
   # newmodel = torch.load("./model.pt" )
   # (bias_fc1, weight_fc1) = extract_params(newmodel)

   # newtime=datetime.datetime.now()
   # print (u'相差：%s秒'%(newtime-oldtime).seconds)




