

#include <iostream>
#include <string>
#include <vector>
struct bdnode{
    std::string val;
    bdnode* left;
    bdnode* right;
};
typedef bdnode* bdt;
bdt buildbdt(const std::vector<std::string>& fvalues);
std::string evalbdt(bdt t, const std::string& input);
bdt changeone(std::string s,int x,int n,int m ,bdt tmp);
bdt checkfunction(std::string s,int x,int n,int m ,bdt tmp);


bdt instree ( bdt t ,int c,int n,int counter ) ;
bdt constree ( std::string n, bdt l , bdt r ,int counter) ;
std::string evalbdt(bdt t, const std::string& input);

int main(){
std::vector<std::string> input;
std::string in = "000010";
input.push_back(in);
in = "010010";
input.push_back(in);
in = "110011";
input.push_back(in);
bdt fbdt = buildbdt(input);
std::cout << evalbdt(fbdt, "000010") << std::endl;
// prints "1"
std::cout << evalbdt(fbdt, "000001") << std::endl;
// prints "0"
    return 0;
}


bdt buildbdt(const std::vector<std::string>& fvalues){
    int n=0;
    int c=0;
    std::string s;
    s=fvalues[0];
    n=s.size();
    int size=fvalues.size();
    bdt t=new bdnode;
    int counter=2;
    t->val="x1";
    t->left=NULL;
    t->right=NULL;
    instree (t,c,n,counter);
    for (int i=0; i<size; i++) {
        t=changeone(fvalues[i],0,n,0,t);
    }
    
    return t;
}
std::string evalbdt(bdt t, const std::string& input){
    t=checkfunction(input,0,input.size(),0,t);
    if (t->val=="1") {
        return "1";
    }
    else{
        return "0";
    }
}
bdt changeone(std::string s,int x,int n,int m,bdt tmp){
    bdt tmpp=new bdnode;
    tmpp=tmp;
    for (int i=0; i<n; i++) {
        if (s[i]==49) {
            tmp=tmp->right;
        }
        else{
            tmp=tmp->left;
        }
    }
    tmp->val="1";
    return tmpp;
}
bdt checkfunction(std::string s,int x,int n,int m ,bdt tmp){
    for (int i=0; i<n; i++) {
        if (s[i]=='1') {
            tmp=tmp->right;
        }
        else{
            tmp=tmp->left;
        }
    }
    return tmp;
}


bdt constree ( std::string n , bdt l,bdt r,int counter) {
    bdt tmp = new bdnode ;
    tmp->val = n+std::to_string(counter);
    tmp->left =l;
    tmp->right =r;
    return tmp ;
}
bdt instree (bdt t ,int c,int n ,int counter) {
    if ( c==n) {
        bdt t = new bdnode ;
        t->val = "0";
        t->left =NULL;
        t->right =NULL;
        return t ;
    }
    else {
        t->left=constree("x", NULL, NULL,counter);
        t->right=constree("x", NULL, NULL,counter);
        t->left = instree (t->left,c+1,n,counter+1) ;
        t->right = instree (t->right,c+1 ,n,counter+1) ;
    }
    return t;
}
