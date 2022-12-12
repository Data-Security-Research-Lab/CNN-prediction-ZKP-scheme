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
int arr_softmax_input_exp[64][10];
int arr_softmax_exp_sum[64];
int arr_softmax_output[64][10];
int arr_softmax_sym[64][10];

class read_parms
{
   public:
        void  read_softmax_input_exp();
        void  read_softmax_exp_sum();
        void  read_softmax_output();
};
void read_parms:: read_softmax_input_exp ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/softmax1_input_exp_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
    cout<<"softmax1_input_exp_nume"<<endl<<endl;
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
            arr_softmax_input_exp[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<64;i++)
      {
          for(int j=0;j<10;j++)
              cout<<arr_softmax_input_exp[i][j]<<" ";
          cout<<endl;
      }   
}
void read_parms:: read_softmax_output ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/softmax1_output_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
    cout<<"softmax1_output_nume"<<endl<<endl;
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
            arr_softmax_output[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<64;i++)
      {
          for(int j=0;j<10;j++)
              cout<<arr_softmax_output[i][j]<<" ";
          cout<<endl;
      } 
}

void read_parms:: read_softmax_exp_sum ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/exp_sum_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i;
    i=0;
    char* end;
     cout<<"softmax_exp_sum_nume"<<endl<<endl;
    if(inFile.fail())
        cout<<"读取文件失败"<<endl;
    while (getline(inFile, lineStr))  
    {  
        // 打印整行字符串  
        // cout << lineStr << endl;  
        // 存成二维表结构  
        stringstream ss(lineStr);  
        string str;  
        vector<string> lineArray;  
        // 按照逗号分隔  
        while (getline(ss, str, ','))  
        {
            arr_softmax_exp_sum[i]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
        } 
        i++;   
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<64;i++)
      {
          cout<<arr_softmax_exp_sum[i]<<" ";
          cout<<endl;
      }
      cout<<endl;   
}

int main () {
    typedef libff::Fr<default_r1cs_gg_ppzksnark_pp> FieldT;

    // Initialize the curve parameters
    default_r1cs_gg_ppzksnark_pp::init_public_params();
    //Running Time
    struct  timeval StartSetup , EndSetup , StartGenerateProof , EndGenerateProof ,StartVerify , EndVerify ;
    unsigned  long Setup  , Proof , Verify;
    // Create protoboard
    protoboard<FieldT> pb;
    //read fc1_params
    read_parms read;
    read.read_softmax_input_exp();
    read.read_softmax_exp_sum();
    read.read_softmax_output();
    // Define variables
    pb_variable<FieldT> softmax_output[64][10];
    pb_variable<FieldT> softmax_input_exp[64][10];
    pb_variable<FieldT> softmax_exp_sum[64];
    pb_variable<FieldT> sym[64][10]; 
    //乘法拍平，output和exp_sum每两个元素相乘,生成新数组
  
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j <10 ; j++)
        {
             arr_softmax_sym[i][j] = arr_softmax_output[i][j]*arr_softmax_exp_sum[i];
        }   
    }
    // Allocate variables to protoboard
    // The strings (like "out") are only for debugging purposes 
    for ( int i = 0; i < 64; i++ )
    {   
        std::string pi = "exp_sum" +  std::to_string(i); 
        softmax_exp_sum[i].allocate(pb,pi);
        pb.val(softmax_exp_sum[i]) = arr_softmax_exp_sum[i];
    }
    for ( int i = 0; i < 64; i++ )
    {   
        for(int j = 0; j <10; j++)
        {
        std::string pi = "Sym_input" + std::to_string(i)+"_"+std::to_string(j); 
        softmax_input_exp[i][j].allocate(pb,pi);
        pb.val(softmax_input_exp[i][j]) = arr_softmax_input_exp[i][j];
        }
    }
   
    for ( int i = 0; i < 64; i++ )
    {   
        for(int j = 0; j <10 ; j++)
        {
        std::string pi = "out" + std::to_string(i)+"_"+std::to_string(j); 
        softmax_output[i][j].allocate(pb,pi);
        pb.val(softmax_output[i][j]) = arr_softmax_output[i][j]; 
        }
    }
     for ( int i = 0; i < 64; i++ )
    {   
        for(int j = 0; j < 10; j++)
        {
        std::string pi = "Sym_" + std::to_string(i)+"_"+std::to_string(j); 
        sym[i][j].allocate(pb,pi);
        pb.val(sym[i][j]) = arr_softmax_sym[i][j];  
        }
    }
   
    
    // This sets up the protoboard variables
    // so that the first one (out) represents the public
    // input and the rest is private input
    pb.set_input_sizes(704);//64*10+64
    
    // Add R1CS constraints to protoboard
     for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j <10 ; j++)
        { 
            pb.add_r1cs_constraint(r1cs_constraint<FieldT>(softmax_output[i][j],softmax_exp_sum[i],sym[i][j])); 
        }   
    }
    
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            pb.add_r1cs_constraint(r1cs_constraint<FieldT>(sym[i][j],1,softmax_input_exp[i][j])); 
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
