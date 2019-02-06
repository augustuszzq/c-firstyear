#include <iostream>
#include <string>
#include <vector>
struct bdnode{
    std::string val;
    bdnode* left;
    bdnode* right;
};
typedef bdnode* bdt;
bdt buildcompactbdt(const std::vector<std::string>& fvalues);
std::string evalcompactbdt(bdt t, const std::string& input);
bdt changeone(std::string s,int x,int n,int m ,bdt tmp);
bdt checkfunction(std::string s,int x,int n,int m ,bdt tmp);
bdt instree ( bdt t ,int c,int n,int counter ) ;
bdt constree ( std::string n, bdt l , bdt r ,int counter) ;
bdt passnew(bdt t,const std::string input,std::string& value);
bdt compareall(bdt t,std::vector<std::string>v1,std::vector<std::string>v2);
bdt compareroot(bdt t,std::vector<std::string>v1,std::vector<std::string>v2);
bdt reconnection(bdt t);
bdt reconnectroot(bdt t);
void pass(bdt t,std::vector<std::string>& v,int& total);
void reconnect(bdt& t,bdt& pt);
void compare(bdt& t,bdt& pt,std::vector<std::string>v1,std::vector<std::string>v2);
std::string evalbdt(bdt t, const std::string& input);
void printTree(bdt t, int depth);
void printTreeRec(bdt t, int depth,std::vector<std::string>& out);
int main(){

    std::vector<std::string> input;
    std::string in = "010";
    input.push_back(in);
    //in = "011";
    //input.push_back(in);
    in = "110";
    input.push_back(in);
    //in = "111";
    //input.push_back(in);
    /*in = "100100";
     input.push_back(in);
     in = "010100";
     input.push_back(in);
     in = "110100";
     input.push_back(in);
     in = "001100";
     input.push_back(in);
     in = "000010";
     input.push_back(in);
     in = "000010";
     input.push_back(in);
     in = "101010";
     input.push_back(in);
     in = "011010";
     input.push_back(in);
     in = "111010";
     input.push_back(in);
     in = "000110";
     input.push_back(in);
     in = "100110";
     input.push_back(in);
     in = "010110";
     input.push_back(in);
     in = "110110";
     input.push_back(in);
     in = "001110";
     input.push_back(in);
     in = "101110";
     input.push_back(in);
     in = "011110";
     input.push_back(in);
     in = "111110";
     input.push_back(in);
     in = "000001";
     input.push_back(in);
     in = "111001";
     input.push_back(in);
     in = "000101";
     input.push_back(in);
     in = "001101";
     input.push_back(in);
     in = "011101";
     input.push_back(in);
     in = "100011";
     input.push_back(in);
     in = "110011";
     input.push_back(in);
     in = "001011";
     input.push_back(in);
     in = "101111";
     input.push_back(in);
     in = "111111";
     input.push_back(in);*/
    bdt fbdt = buildcompactbdt(input);
    printTree(fbdt, 7);
    std::cout<<"The answer to the number is "<<evalcompactbdt(fbdt, "000")<<std::endl;
    return 0;
}
bdt buildcompactbdt(const std::vector<std::string>& fvalues){
    int n=0;
    int c=0;
    std::string s;
    std::vector<std::string>v1;
    std::vector<std::string>v2;
    s=fvalues[0];
    n=s.size();
    int size=fvalues.size();
    bdt p=new bdnode;
    int counter=2;
    p->val="x1";
    p->left=NULL;
    p->right=NULL;
    instree (p,c,n,counter);
    for (int i=0; i<size; i++) {
        p=changeone(fvalues[i],0,n,0,p);
    }
    p=compareall(p, v1, v2);
    p=compareroot(p, v1, v2);
    return p;
}
std::string evalcompactbdt(bdt t, const std::string& input){
    std::string value ;
    t=passnew(t, input, value);
    return value;
}
bdt compareall(bdt t,std::vector<std::string>v1,std::vector<std::string>v2){
    if (t->left!=NULL&&t->right!=NULL) {
        t->right=compareall(t->right, v1, v2);
        t->left=compareall(t->left, v1, v2);
        compare(t->right,t,v1,v2);
        compare(t->left,t,v1,v2);
        return t;
    }
    else{
        return t;
    }
}
void compare(bdt& t,bdt& pt,std::vector<std::string>v1,std::vector<std::string>v2){
    if (t->left!=NULL&&t->right!=NULL) {
        int c=0;
        int total1=0;
        int total2=0;
        pass(t->left,v1,total1);
        pass(t->right,v2,total2);
        if (v1.size()==v2.size()) {
            for (int i=0; i<v1.size(); i++) {
                if(v1[i]==v2[i]){
                    c++;
                }
            }
        }
        if (c==v1.size()&&c!=total1) {
            reconnect(t, pt);
        }
    }
}
bdt compareroot(bdt t,std::vector<std::string>v1,std::vector<std::string>v2){
    int total1=0;
    int total2=0;
    pass(t->left,v1,total1);
    pass(t->right,v2,total2);
    int c=0;
    if (v1.size()==v2.size()) {
        for (int i=0; i<v1.size(); i++) {
            if(v1[i]==v2[i]){
                c++;
            }
        }
    }
    if (c==v1.size()) {
        t=reconnectroot(t);
        return t;
    }
    else{
        return t;
    }
}
void pass(bdt t,std::vector<std::string>& v,int& total){
    if(t!=NULL){
        pass(t->right,v,total);
        total++;
        v.push_back(t->val);
        pass(t->left,v,total);
        total++;
    }
}
void reconnect(bdt& t,bdt& pt){
    reconnection(t->right);
    if(pt->left==t){
        bdt x=new bdnode;
        x=t;
        pt->left=t->left;
        delete x;
    }
    else{
        bdt x=new bdnode;
        x=t;
        pt->right=t->left;
        delete x;
    }
}
bdt reconnection(bdt t){
    if (t!=NULL) {
        reconnection(t->right);
        reconnection(t->left);
        delete t;
        return t;
    }
    return t;
}
bdt reconnectroot(bdt t){
    reconnection(t->right);
    bdt x=new bdnode;
    x=t;
    t=t->left;
    delete x;
    return t;
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
void printTreeRec(bdt t, int depth,std::vector<std::string>& out){
    if(t!=NULL){
        out[depth]=out[depth]+"  "+t->val;
        printTreeRec(t->left,depth+1,out);
        printTreeRec(t->right,depth+1,out);
    }
}
void printTree(bdt t, int depth){
    std::vector<std::string> out;
    for(int i=0;i<depth;i++){
        out.push_back("");
    }
    printTreeRec(t,0,out);
    for (int i=0;i<depth;i++){
        std::cout << i<<"\t| "<<out[i]  << '\n';
    }
    std::cout << "x" << '\n';
}
bdt passnew(bdt t,const std::string input,std::string& value){
    std::string sameinput1;
    std::string counter;
    if (t->left==NULL&&t->right==NULL) {
        value=t->val;
        return t;
    }
    else{
        sameinput1=t->val;
        sameinput1.erase(0,1);
        int i=std::stoi(sameinput1,nullptr,0);
        counter=input[i-1];
        if (counter=="0"&&t->left!=NULL&&t->right!=NULL) {
            return passnew(t->left, input, value);
        }
        if (counter=="1"&&t->left!=NULL&&t->right!=NULL) {
            return passnew(t->right, input, value);
        }
        else{
            return t;
        }
    }
}
