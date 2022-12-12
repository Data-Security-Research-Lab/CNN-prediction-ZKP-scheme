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
int arr_relu_input[64][1728];
int arr_relu_operation[64][1728];
int arr_relu_output[64][1728];
int arr_relu_sym[64][1728];

class read_parms
{
   public:
       void  read_relu_input();
       void  read_relu_operation();
       void  read_relu_output();
};
void read_parms:: read_relu_input ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/relu1_input_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
    cout<<"relu1_input_nume"<<endl<<endl;
    if(inFile.fail())
        cout<<"读取文件失败"<<endl;
    while (getline(inFile, lineStr))  
    {  
        j=0;
        stringstream ss(lineStr);  
        string str;  
        vector<string> lineArray;  
        // 按照逗号分隔  
        while (getline(ss, str, ','))  
        {
            arr_relu_input[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<64;i++)
      {
          for(int j=0;j<1728;j++)
              cout<<arr_relu_input[i][j]<<" ";
          cout<<endl;
      }   
}
void read_parms:: read_relu_operation ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/relu1_operation__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
    cout<<"relu1_operation_nume"<<endl<<endl;
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
            arr_relu_operation[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<64;i++)
      {
          for(int j=0;j<1728;j++)
              cout<<arr_relu_operation[i][j]<<" ";
          cout<<endl;
      }
    //getchar();     
}

void read_parms:: read_relu_output ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/relu1_output_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
     cout<<"relu1_output_nume"<<endl<<endl;
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
            arr_relu_output[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<64;i++)
      {
          for(int j=0;j<1728;j++)
              cout<<arr_relu_output[i][j]<<" ";
          cout<<endl;
      }
    // getchar();     
}

int main () {
    typedef libff::Fr<default_r1cs_gg_ppzksnark_pp> FieldT;

    // Initialize the curve parameters
    default_r1cs_gg_ppzksnark_pp::init_public_params();
    struct  timeval StartSetup , EndSetup , StartGenerateProof , EndGenerateProof ,StartVerify , EndVerify ;
    unsigned  long Setup  , Proof , Verify;
    // Create protoboard
    protoboard<FieldT> pb;
    //read fc1_params
    read_parms read;
    read.read_relu_input();
    read.read_relu_operation();
    read.read_relu_output();
    // Define variables
    pb_variable<FieldT> relu_output[64][1728];
    pb_variable<FieldT> relu_input[64][1728];
    pb_variable<FieldT> relu_operation[64][1728];
    pb_variable<FieldT> sym[64][1728];  
    //乘法拍平，input和weight每两个元素相乘,生成新数组
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j <1728 ; j++)
        {
           arr_relu_sym[i][j] = arr_relu_input[i][j]*arr_relu_operation[i][j];
        }   
    }
    // Allocate variables to protoboard
    // The strings (like "out") are only for debugging purposes  
    for ( int i = 0; i < 64; i++ )
    {   
        for(int j = 0; j < 1728; j++)
        {
        std::string pi = "out" + std::to_string(i)+"_"+std::to_string(j); 
        relu_output[i][j].allocate(pb,pi);
        pb.val(relu_output[i][j]) = arr_relu_output[i][j];
        }
    }
        for ( int i = 0; i < 64; i++ )
    {   
        for(int j = 0; j <1728; j++)
        {
        std::string pi = "Sym_input" + std::to_string(i)+"_"+std::to_string(j); 
        relu_input[i][j].allocate(pb,pi);
        pb.val(relu_input[i][j]) = arr_relu_input[i][j];
        }
    }
   
    for ( int i = 0; i < 64; i++ )
    {   
        for(int j = 0; j < 1728; j++)
        {
        std::string pi = "Sym_operation" + std::to_string(i)+"_"+std::to_string(j);
        relu_operation[i][j].allocate(pb,pi); 
        pb.val(relu_operation[i][j]) = arr_relu_operation[i][j];
        }
    }
     for ( int i = 0; i < 64; i++ )
    {   
        for(int j = 0; j < 1728; j++)
        {
        std::string pi = "Sym_" + std::to_string(i)+"_"+std::to_string(j);
        sym[i][j].allocate(pb,pi); 
        pb.val(sym[i][j]) = arr_relu_sym[i][j];  
        }
    }
    
    // This sets up the protoboard variables
    // so that the first one (out) represents the public
    // input and the rest is private input
    pb.set_input_sizes(221184);//64*1728*2
    
    // Add R1CS constraints to protoboard
     for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j <1728 ; j++)
        { 
            pb.add_r1cs_constraint(r1cs_constraint<FieldT>(relu_input[i][j],relu_operation[i][j],sym[i][j])); 
        }   
    }
    //和：对应output上每一个点
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 1728; j++)
        {
            pb.add_r1cs_constraint(r1cs_constraint<FieldT>(sym[i][j],1,relu_output[i][j])); 
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
