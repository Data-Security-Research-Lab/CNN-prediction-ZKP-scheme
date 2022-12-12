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
int arr_fc_input[64][432];
int arr_fc_weight[10][432];
int arr_fc_bias[10];
int arr_fc_output[64][10];
int arr_fc_sym[640][432];
int arr_fc_sym_add[640][431];

class read_parms
{
   public:
      void  read_fc_input();
      void  read_fc_weight();
      void  read_fc_bias();
      void  read_fc_output();
};
void read_parms:: read_fc_input ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/fc1_input_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
    cout<<"fc1_input_nume"<<endl<<endl;
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
            arr_fc_input[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<64;i++)
      {
          for(int j=0;j<432;j++)
              cout<<arr_fc_input[i][j]<<" ";
          cout<<endl;
      }   
}
void read_parms:: read_fc_weight ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/fc1_weight_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
    cout<<"fc1_weight_nume"<<endl<<endl;
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
            arr_fc_weight[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<10;i++)
      {
          for(int j=0;j<432;j++)
              cout<<arr_fc_weight[i][j]<<" ";
          cout<<endl;
      }  
}
void read_parms:: read_fc_bias ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/fc1_bias_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i;
    i=0;
    char* end;
     cout<<"fc1_bias_nume"<<endl;
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
            arr_fc_bias[i]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<10;i++)
      {
            cout<<arr_fc_bias[i]<<" ";
            cout<<endl;
      } 
}
void read_parms:: read_fc_output ()
{
    ifstream inFile("/home/libsnarkdemo/libsnark_demo/src/data/fc1_output_nume__test_3.csv", ios::in);  
    string lineStr;  
    vector<vector<string>> strArray;  
    int i,j;
    i=0;
    char* end;
     cout<<"fc1_output_nume"<<endl<<endl;
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
            arr_fc_output[i][j]=static_cast<int>(strtol(str.c_str(),&end,10));              //string -> int
            j++;
        }
        i++;     
   //     strArray.push_back(lineArray);  
    }  
      for(int i=0;i<64;i++)
      {
          for(int j=0;j<10;j++)
              cout<<arr_fc_output[i][j]<<" ";
          cout<<endl;
      } 
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
    read.read_fc_input();
    read.read_fc_bias();
    read.read_fc_weight();
    read.read_fc_output();
    // Define variables
    pb_variable<FieldT> fc_output[64][10];
    pb_variable<FieldT> fc_input[64][432];
    pb_variable<FieldT> fc_bias[10];
    pb_variable<FieldT> fc_weight[10][432];
    pb_variable<FieldT> sym[640][432];  //12*(3*6)
    pb_variable<FieldT> sym_add[640][431];
    //乘法拍平，input和weight每两个元素相乘,生成新数组
    for (unsigned int i = 0; i < 64; i++)
    {
        for (unsigned int j = 0; j <10 ; j++)
        {
            for (unsigned int m = 0; m <432; m++)
            {   
                 arr_fc_sym[i*10+j][m] = arr_fc_input[i][m]*arr_fc_weight[j][m];
            }    
        }   
    }
    for (unsigned int i = 0; i < 640; i++)
    {
        for (unsigned int j = 0; j <431 ; j++)
        {   
            if(j == 0)
            {
                arr_fc_sym_add[i][j] = arr_fc_sym[i][j]+arr_fc_sym[i][j+1];
            }
            else
            {
                arr_fc_sym_add[i][j] = arr_fc_sym_add[i][j-1] + arr_fc_sym[i][j+1];  
            }
        }  
    }
    
    // Allocate variables to protoboard
    // The strings (like "x") are only for debugging purposes  
    for ( unsigned int i = 0; i < 64; i++ )
    {   
        for(unsigned int j = 0; j < 10; j++)
        {
        std::string pi = "out" + std::to_string(i)+"_"+std::to_string(j); 
        fc_output[i][j].allocate(pb,pi);
        pb.val(fc_output[i][j]) = arr_fc_output[i][j];
        }
    }
    for ( unsigned int i = 0; i < 64; i++ )
    {   
        for(unsigned int j = 0; j <432; j++)
        {
        std::string pi = "Sym_input" + std::to_string(i)+"_"+std::to_string(j); 
        fc_input[i][j].allocate(pb,pi);
        pb.val(fc_input[i][j]) = arr_fc_input[i][j]; 
        }
    }
    
    for (unsigned  int i = 0; i < 10; i++ )
    {   
        std::string pi = "Sym_bias" + std::to_string(i);
        fc_bias[i].allocate(pb,pi);
        pb.val(fc_bias[i]) = arr_fc_bias[i];
    }
    for ( unsigned int i = 0; i < 10; i++ )
    {   
        for(unsigned int j = 0; j < 432; j++)
        {
        std::string pi = "Sym_weight" + std::to_string(i)+"_"+std::to_string(j); 
        fc_weight[i][j].allocate(pb,pi);
        pb.val(fc_weight[i][j]) = arr_fc_weight[i][j];
        }
    }
     for (unsigned  int i = 0; i < 640; i++ )
    {   
        for(unsigned int j = 0; j < 432; j++)
        {
        std::string pi = "Sym_" + std::to_string(i)+"_"+std::to_string(j); 
        sym[i][j].allocate(pb,pi);
        pb.val(sym[i][j]) = arr_fc_sym[i][j]; 
        }
    }
    
    for ( unsigned int i = 0; i < 640; i++ )
    {   
        for(unsigned int j = 0; j < 431; j++)
        {
        std::string pi = "Sym_add" + std::to_string(i)+"_"+std::to_string(j); 
        sym_add[i][j].allocate(pb,pi);
        pb.val(sym_add[i][j]) = arr_fc_sym_add[i][j]; 
        }
    }
    
    // This sets up the protoboard variables
    // so that the first one (out) represents the public
    // input and the rest is private input
    pb.set_input_sizes(28288);

    // Add R1CS constraints to protoboard
    for (unsigned int i = 0; i < 64; i++)
    {
        for (unsigned int j = 0; j <10 ; j++)
        {
            for (unsigned int m = 0; m <432; m++)
            {  
                 pb.add_r1cs_constraint(r1cs_constraint<FieldT>(fc_input[i][m], fc_weight[j][m], sym[i*10+j][m]));
            }    
        }   
    }
    for (unsigned int i = 0; i < 640; i++)
    {
        for (unsigned int j = 0; j <431 ; j++)
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
    for (unsigned int i = 0; i < 64; i++)
    {
        for (unsigned int j = 0; j < 10; j++)
        {
            pb.add_r1cs_constraint(r1cs_constraint<FieldT>(sym_add[i*10+j][430]+fc_bias[j], 1, fc_output[i][j]));   
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
