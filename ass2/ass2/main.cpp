/// include here all the headers you need (but see guidelines)
#include <iostream>
#include <vector>
/// do not use using namespace std

/// do not alter the struct declaration
struct bdnode{
    std::string val;
    bdnode* left;
    bdnode* right;
};

/// do not alter the typedef
typedef bdnode* bdt;

/// do not alter these two function declarations
bdt buildcompactbdt(const std::vector<std::string>& fvalues);
std::string evalcompactbdt(bdt t, const std::string& input);
bdt base(bdt &t);
bdt mtree(bdt &t);
/// you can define and use additional functions
/// for the implementation of buildcompactbdt and evalcompactbdt

/// add here the declarations (not the implementation)
/// for any other functions you wish to define and use

/// before the submission you need to remove the main
/// (either delete it or comment it out)
/// otherwise it will intefere with the automated testing

int main(){
    
    /// write the code for the main here in order to test your functions
    
    return 0;
}

bdt buildcompactbdt(const std::vector<std::string>& fvalues){
    bdt t= new bdnode;
    int s=fvalues.size();
    int k=0;
    t->val=k;
    t->left=NULL;
    t->right=NULL;
    //建立一棵树
    //用recursion
    //check vector 倒数第二个值是否为1
    //不确定 是什么个意思
    return t;
    /// write the implementation for the function here
}

bdt base(bdt t){
    bdt tmp=new bdnode;
    tmp->left=NULL;
    tmp->right=NULL;
    tmp->val="x";
    t=tmp;
    return t;
}
bdt mtree(bdt &t){
    if ((t->left=NULL)&&(t->right=NULL)) {
         t=base(t);
    }
    else{
        return t;
    }
}
std::string evalcompactbdt(bdt t, const std::string& input){
    /// write the implementation for the function here
}

/// add here the implementation for any other functions you wish to define and use
