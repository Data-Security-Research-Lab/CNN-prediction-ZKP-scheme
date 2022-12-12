#include <libsnark/common/default_types/r1cs_gg_ppzksnark_pp.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_gg_ppzksnark/r1cs_gg_ppzksnark.hpp>
#include <libsnark/gadgetlib1/pb_variable.hpp>
#include<iostream>
#include<stdio.h>
#include<vector>
#include <string>  
#include <vector>  
#include <fstream>  
#include <sstream>
#include <sys/time.h>  
using namespace libsnark;
using namespace std;
static int arr_conv_input[36864][25];
static int arr_conv_weight[3][25];
static int arr_conv_bias[3];
static int arr_conv_output[36864][3];
static int arr_conv_sym[110592][25];
static int arr_conv_sym_add[110592][24];

typedef libff::Fr<default_r1cs_gg_ppzksnark_pp> FieldT;
pb_variable<FieldT> conv_output[36864][3];
pb_variable<FieldT> conv_input[36864][25];
pb_variable<FieldT> conv_bias[3];
pb_variable<FieldT> conv_weight[3][25];
pb_variable<FieldT> sym[110592][25];  //25*(3*36864)
pb_variable<FieldT> sym_add[110592][24]; 

class read_parms
{
   public:
      void  read_conv_input();
      void  read_conv_weight();
      void  read_conv_bias();
      void  read_conv_output();
};
void read_parms:: read_conv_input ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/conv1_input_im2col_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
    cout<<"conv1_input_nume"<<endl<<endl;
    if(inFile.fail())
        cout<<"读取文件失败"<<endl;
    while (getline(inFile, lineStr))  
    {  
        j=0;
        // 打印整行字符串  
        // cout << lineStr << endl;  
        // 存成二维表结构  
        stringstream ss(lineStr);  
        string str;  
        vector<string> lineArray;  
        // 按照逗号分隔  
        while (getline(ss, str, ','))  
        {
            arr_conv_input[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<36864;i++)
      {
          for(int j=0;j<25;j++)
              cout<<arr_conv_input[i][j]<<" ";
          cout<<endl;
      }
   // getchar();     
}
void read_parms:: read_conv_weight ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/conv1_weight_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
    cout<<"conv1_weight_nume"<<endl<<endl;
    if(inFile.fail())
        cout<<"读取文件失败"<<endl;
    while (getline(inFile, lineStr))  
    {  
        j=0;
        // 打印整行字符串  
        // cout << lineStr << endl;  
        // 存成二维表结构  
        stringstream ss(lineStr);  
        string str;  
        vector<string> lineArray;  
        // 按照逗号分隔  
        while (getline(ss, str, ','))  
        {
            arr_conv_weight[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<3;i++)
      {
          for(int j=0;j<25;j++)
              cout<<arr_conv_weight[i][j]<<" ";
          cout<<endl;
      }
    //getchar();     
}
void read_parms:: read_conv_bias ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/conv1_bias_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i;
    i=0;
    char* end;
     cout<<"conv1_bias_nume"<<endl;
    if(inFile.fail())
        cout<<"读取文件失败"<<endl<<endl;
    while (getline(inFile, lineStr))  
    {  
        // 打印整行字符串  
        // cout << lineStr << endl;  
        // 存成二维表结构  
        stringstream ss(lineStr);  
        string str;  
        vector<string> lineArray;  
        // 按照逗号分隔  
        while (getline(ss, str))  
        {
            arr_conv_bias[i]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<3;i++)
      {
            cout<<arr_conv_bias[i]<<" ";
            cout<<endl;
      }
    // getchar();     
}
void read_parms:: read_conv_output ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/conv1_output_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
     cout<<"conv1_output_nume"<<endl<<endl;
    if(inFile.fail())
        cout<<"读取文件失败"<<endl;
    while (getline(inFile, lineStr))  
    {  
        j=0;
        // 打印整行字符串  
        // cout << lineStr << endl;  
        // 存成二维表结构  
        stringstream ss(lineStr);  
        string str;  
        vector<string> lineArray;  
        // 按照逗号分隔  
        while (getline(ss, str, ','))  
        {
            arr_conv_output[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<36864;i++)
      {
          for(int j=0;j<3;j++)
              cout<<arr_conv_output[i][j]<<" ";
          cout<<endl;
      }
    // getchar();     
}

int main () {
    //typedef libff::Fr<default_r1cs_gg_ppzksnark_pp> FieldT;

    // Initialize the curve parameters
    default_r1cs_gg_ppzksnark_pp::init_public_params();
    //Running Time
    struct  timeval StartSetup , EndSetup , StartGenerateProof , EndGenerateProof ,StartVerify , EndVerify ;
    unsigned  long Setup  , Proof , Verify;
    // Create protoboard
    protoboard<FieldT> pb;
    //read fc1_params
    read_parms read;
    read.read_conv_input();
    read.read_conv_bias();
    read.read_conv_weight();
    read.read_conv_output();
    // Define variables
    
    //乘法拍平，input和weight每两个元素相乘,生成新数组
    for (int i = 0; i < 36864; i++)
    {
        for (int j = 0; j <3 ; j++)
        {
            for (int m = 0; m <25; m++)
            {   
                 arr_conv_sym[i*3+j][m] = arr_conv_input[i][m]*arr_conv_weight[j][m];
            }    
        }   
    }
    //每两个元素相加，生成新的中间变量
    for (int i = 0; i < 110592; i++)
    {
        for (int j = 0; j <24 ; j++)
        {   
            if(j == 0)
            {
                arr_conv_sym_add[i][j] = arr_conv_sym[i][j] + arr_conv_sym[i][j+1];
            }
            else
            {
                arr_conv_sym_add[i][j] = arr_conv_sym_add[i][j-1] + arr_conv_sym[i][j+1];  
            }
        }  
    }
    // Allocate variables to protoboard
    // The strings (like "x") are only for debugging purposes  
    for ( int i = 0; i < 36864; i++ )
    {   
        for(int j = 0; j < 3; j++)
        {
        std::string pi = "out" + std::to_string(i)+"_"+std::to_string(j); 
        conv_output[i][j].allocate(pb,pi);
        pb.val(conv_output[i][j]) = arr_conv_output[i][j];
        }
    }
    for ( int i = 0; i < 36864; i++ )
    {   
        for(int j = 0; j <25; j++)
        {
        std::string pi = "Sym_input" + std::to_string(i)+"_"+std::to_string(j); 
        conv_input[i][j].allocate(pb,pi);
        pb.val(conv_input[i][j]) = arr_conv_input[i][j]; 
        }
    }
    for ( int i = 0; i < 3; i++ )
    {   
        std::string pi = "Sym_bias" + std::to_string(i);
        conv_bias[i].allocate(pb,pi);
        pb.val(conv_bias[i]) = arr_conv_bias[i];
    }
    for ( int i = 0; i < 3; i++ )
    {   
        for(int j = 0; j < 25; j++)
        {
        std::string pi = "Sym_weight" + std::to_string(i)+"_"+std::to_string(j); 
        conv_weight[i][j].allocate(pb,pi);
        pb.val(conv_weight[i][j]) = arr_conv_weight[i][j];
        }
    }
     for ( int i = 0; i < 110592; i++ )
    {   
        for(int j = 0; j < 25; j++)
        {
        std::string pi = "Sym_" + std::to_string(i)+"_"+std::to_string(j); 
        sym[i][j].allocate(pb,pi);
        pb.val(sym[i][j]) = arr_conv_sym[i][j]; 
        }
    }
    for ( int i = 0; i < 110592; i++ )
    {   
        for(int j = 0; j < 24; j++)
        {
        std::string pi = "Sym_add" + std::to_string(i)+"_"+std::to_string(j); 
        sym_add[i][j].allocate(pb,pi);
        pb.val(sym_add[i][j]) = arr_conv_sym_add[i][j]; 
        }
    }
    // This sets up the protoboard variables
    // so that the first one (out) represents the public
    // input and the rest is private input
    pb.set_input_sizes(1032192);  //36864*28

    // Add R1CS constraints to protoboard
    for (int i = 0; i < 36864; i++)
    {
        for (int j = 0; j <3 ; j++)
        {
            for (int m = 0; m <25; m++)
            {  
                 pb.add_r1cs_constraint(r1cs_constraint<FieldT>(conv_input[i][m], conv_weight[j][m], sym[i*3+j][m]));
            }    
        }   
    }
     for (int i = 0; i < 110592; i++)
    {
        for (int j = 0; j <24; j++)
        {   
            if (j == 0)
            {
                pb.add_r1cs_constraint(r1cs_constraint<FieldT>(sym[i][j]+sym[i][j+1],1,sym_add[i][j])); 
            } 
            else 
            {
                pb.add_r1cs_constraint(r1cs_constraint<FieldT>(sym_add[i][j-1]+sym[i][j+1],1,sym_add[i][j]));
            }  
        }   
    }
    //和：对应output上每一个点
    for (int i = 0; i < 36864; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            pb.add_r1cs_constraint(r1cs_constraint<FieldT>(sym_add[i*3+j][23]+conv_bias[j],1,conv_output[i][j]));   
        }
    }
    
    const r1cs_constraint_system<FieldT> constraint_system = pb.get_constraint_system();
    
    // generate keypair
    gettimeofday(&StartSetup,NULL);
    const r1cs_gg_ppzksnark_keypair<default_r1cs_gg_ppzksnark_pp> keypair = r1cs_gg_ppzksnark_generator<default_r1cs_gg_ppzksnark_pp>(constraint_system);
    gettimeofday(&EndSetup,NULL);
    // Add public input and witness values
    // generate proof
    gettimeofday(&StartGenerateProof,NULL);
    const r1cs_gg_ppzksnark_proof<default_r1cs_gg_ppzksnark_pp> proof = r1cs_gg_ppzksnark_prover<default_r1cs_gg_ppzksnark_pp>(keypair.pk, pb.primary_input(), pb.auxiliary_input());
    gettimeofday(&EndGenerateProof,NULL);
    // verify
    gettimeofday(&StartVerify,NULL);
    bool verified = r1cs_gg_ppzksnark_verifier_strong_IC<default_r1cs_gg_ppzksnark_pp>(keypair.vk, pb.primary_input(), proof);
    gettimeofday(&EndVerify,NULL);
    cout << "Number of R1CS constraints: " << constraint_system.num_constraints() << endl;
    //cout << "Primary (public) input: " << pb.primary_input() << endl;
    //cout << "Auxiliary (private) input: " << pb.auxiliary_input() << endl;
    cout << "Verification status: " << verified << endl;
    
    Setup = 1000000 * (EndSetup.tv_sec-StartSetup.tv_sec)+ EndSetup.tv_usec-StartSetup.tv_usec;
    Proof = 1000000 * (EndGenerateProof.tv_sec-StartGenerateProof.tv_sec)+ EndGenerateProof.tv_usec-StartGenerateProof.tv_usec;
    Verify = 1000000 * (EndVerify.tv_sec-StartVerify.tv_sec)+ EndVerify.tv_usec-StartVerify.tv_usec;
    printf("Setup时间： %ld ms\n ",Setup/1000);
    printf("Generate Proof时间： %ld ms\n ",Proof/1000);
    printf("Verify时间： %ld ms\n ",Verify/1000);
    return 0;
}
