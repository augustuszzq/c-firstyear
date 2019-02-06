#include<iostream>
#include<cmath>
#include<string>
using namespace std;
class simulator{};
void simulator::simulator(string inputcode)
{
    string type=recog(inputcode);
    switch (type)
    {
        case type=="R"：
            std::string input;
            std::string source1;
            std::string source2;
            std::string dest;
            std::string shiftmat;
            std::string function;
            separate_R(input,source2,dest,shiftmat,function);
            switch(function){
                case function=="100000"：
                    //add overflow
                    add(source1,source2,dest,reg[32]);
                    break
                case function=="100001":
                    //addu
                    addu(source1,source2,dest,reg[32]);
                    break
                case function=="100010":
                    //sub
                    sub(source1,source2,dest,reg[32]);
                    break
                case:function=="100011":
                    subu(source1,source2,dest,reg[32]);
                    break
                case function=="100100":
                    andop(source1,source2,dest,reg[32]);
                    break
                case function=="100101":
                    orop(source1,source2,dest,reg[32]);
                    break
                case function=="100110":
                    
                    break
                case function=="010000":
                    
                    break
                case function=="010010":
                    
                    break
                case function=="011000":
                    
                    break
                case:function=="011001":
                    
                    break
                case:function=="000000":
                    
                    break
                case function=="000100":
                    
                    break
                case function=="101010":
                    
                    break
                case function=="101011":
                    
                    break
                case function=="000011":
                    
                    break
                case function=="000010":
                    
                    break
                case function=="000110":
                    
                    break
                case function=="011011":
                    
                    break
                case function=="001000":
                    
                    break
            }
            break
            
            casetype=="I"：
            string input;
            string source1;
            string source2;
            string address;
            separate_I(input,source1,source2,address);
            switch(inputcode)//重新校对
        {
            case inputcode=="001000"：
                
                break
            case inputcode=="001001"：
                
                break
            case inputcode=="001100"：
                
                break
            case inputcode=="001110"：
                
                break
            case inputcode=="001101"：
                
                break
            case inputcode=="000100"：
                
                break
            case inputcode=="000001"：
                
                break
            case inputcode=="000111"：
                
                break
            case inputcode=="000101"：
                
                break
            case inputcode=="100000"：
                
                break
            case inputcode=="001111"：
                
                break
            case inputcode=="lw"：
                
                break
            case inputcode=="101000"：
                
                break
            case inputcode=="101001":
                
                break
                caseinputcode=="001010":
                
                break
            case inputcode=="001011":
                break
                
                
        }
            break
            
        case type=="J"：
            
            break
    }
}
void simulator::separate_R(const string input,string &source1,string &source2,string &dest,string &shiftmat,string &function){
    source1=input.substr(0,4);
    source2=input.substr(5,9);
    dest=input.substr(10,14);
    shiftmat=input.substr(15,19);
    function=input.substr(20,25);
};
void simulator::separate_I(const string input,string &source1 ,string &source2,string &address){
    source1=input.substr(0,4);
    source2=input.substr(5,9);
    address=input.substr(10,25);
};
string simulator::recog(string inputcode){
    std::string subinputcode = inputcode.substr(0,5);
    std::string subinputcode_end = inputcode.substr(9,31);
    if (subinputcode=="000000")
    {
        return "R";
    }
    else if (subinputcode=="000011"||subinputcode=="000010"||(subinputcode=="000000"&&subinputcode_end=="00000000000000001000"))
    {
        return "J";
    }
    else
    {
        return "I";
    }
};
void simulator::addu(const string source1,const string source2,const string dest,int &reg[32]){
    int source1_index=getindex(source1);
    int source2_index=getindex(source2);
    int dest_index=getindex(dest);
    reg[dest_index]=reg[source1_index]+reg[source2_index];};
void simulator::add(const string source1,const string source2,const string dest,int &reg[32]){
    int source1_index=getindex(source1);
    int source2_index=getindex(source2);
    int dest_index=getindex(dest);
    if((source1_index>7)||(source2_index>7)||(dest_index>7))
    {
        cout<<"Memory exception"<<endl;
    }
    else
    {
        reg[dest_index]=reg[source1_index]+reg[source2_index];
        if (reg[dest_index]>pow(2,31)-1)
        {
            cout<<"warning!overflow occurs!"<<endl;
        }
    }
};
void simulator::subu(const string source1,const string source2,const string dest,int &reg[32]){
    int source1_index=getindex(source1);
    int source2_index=getindex(source2);
    int dest_index=getindex(dest);
    if((source1_index>7)||(source2_index>7)||(dest_index>7))
    {
        cout<<"Memory exception"<<endl;
    }
    else
    {
        reg[dest_index]=reg[source1_index]-reg[source2_index];
    }
};
void simulator::sub(const string source1,const string source2,const string dest,int &reg[32]){
    int source1_index=getindex(source1);
    int source2_index=getindex(source2);
    int dest_index=getindex(dest);
    if((source1_index>7)||(source2_index>7)||(dest_index>7))
    {
        cout<<"Memory exception"<<endl;
    }
    else
    {
        reg[dest_index]=reg[source1_index]-reg[source2_index];
        if (//我也不知道overflow条件是啥)
            {
                cout<<"warning!overflow occurs!"<<endl;
            }
            }
            };
            void simulator::andop(const string source1,const string source2,const string dest,int &reg[32]){
                int source1_index=getindex(source1);
                int source2_index=getindex(source2);
                int dest_index=getindex(dest);
                reg[dest_index]=reg[source1_index]&reg[source2_index];
            }
            void simulator::orop(const string source1,const string source2,const string dest,int &reg[32]){
                int source1_index=getindex(source1);
                int source2_index=getindex(source2);
                int dest_index=getindex(dest);
                reg[dest_index]=reg[source1_index]|reg[source2_index];
            }
            void simulator::xorop(const string source1,const string source2,const string dest,int &reg[32]){
                int source1_index=getindex(source1);
                int source2_index=getindex(source2);
                int dest_index=getindex(dest);
                reg[dest_index]=reg[source1_index]^reg[source2_index];
            }
            void simulator::mfhi()
            registers::void registers(){
                int reg[32];
                string regis[32];
            }
            simulator::void transfer(const int reg[32],string &reg_s[32]){
                for(int i=0;i<reg.size;i++)
                {
                    //reg_s[i]==
                }
            }
            simulator::int getindex(string inputvalue){
                int index=0;
                for(int i=0;i<inputvalue.size;i++) {
                    index+=inputvalue[i]*pow(2,i);
                }
                return index;
            }
            
            int main(){
                //创造一个pointer
                //读取二进制file 存到memory 临时变量register
                int memory.pc;
                int registers.reg[];
                return 0;
            }
