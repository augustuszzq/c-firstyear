//use c++11 to compile
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
struct bdnode{
    std::string val;
    bdnode* left;
    bdnode* right;
};
typedef bdnode* bdt;
bdt buildcompactbdt(const std::vector<std::string>& fvalues);
std::string evalcompactbdt(bdt t, const std::string& input);
bdt addone(bdt t, std::vector<int> input,int i,int c);
bdt createroot(bdt tmp,int counter);
bdt constree(bdt l, bdt r,int counter2,int depth);
bdt instree(bdt t,int counter1,int depth);
bdt passnew(bdt t,const std::string input,std::string& value);
bdt compareall(bdt t,std::vector<std::string>v1,std::vector<std::string>v2);
bdt compareroot(bdt t,std::vector<std::string>v1,std::vector<std::string>v2);
void printTree(bdt t, int depth);
void printTreeRec(bdt t, int depth,std::vector<std::string>& out);
void compare(bdt& t,bdt& pt,std::vector<std::string>v1,std::vector<std::string>v2);
void pass(bdt t,std::vector<std::string>& v,int& total);
void reconnect(bdt& t,bdt& pt);
void reconnection(bdt& t);
void reconnectroot(bdt& t);
int main(){
    int node;
    double totalnode;
    double now ;
    double percentage;
    std::vector<std::string> input;
    std::string in = "010";
    input.push_back(in);
    in = "011";
    input.push_back(in);
    in = "110";
    input.push_back(in);
    in = "111";
    input.push_back(in);
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
    clock_t start_time=time(NULL);
    bdt fbdt = buildcompactbdt(input);
    clock_t end_time=time(NULL);
    double time=(double)(end_time-start_time);
    printTree(fbdt, 7);
    node = std::pow(2,in.size());
    totalnode = (2*node)-1;
    std::cout<<"Totalnode Number :  "<<totalnode<<std::endl;
    std::cout<<"Enter node number after reducing "<<std::endl;
    std::cin>>now;
    percentage = now / totalnode ;
    std::cout<<"Node reduced by "<<100*(1-percentage)<<"  percent"<<std::endl;
    std::cout<<"The answer to the number is "<<evalcompactbdt(fbdt, "111")<<std::endl;
    std::cout<<"The program took "<<time<<"  seconds"<<std::endl;
    return 0;
}
bdt buildcompactbdt(const std::vector<std::string>& fvalues){
    std::vector<std::string>v1;
    std::vector<std::string>v2;
    std::string in;
    std::vector<int> in2;
    std::vector<std::string> leftsubtree;
    std::vector<std::string> rightsubtree;
    in = fvalues[0];
    int total=pow(2, fvalues.size());
    total=total-1;
    bdt p= new bdnode;
    p->val= "x1";
    p->left = NULL;
    p->right = NULL;
    int size = in.size();
    if (fvalues.size()==0){
        return p;
    }
    p= instree(p,size,2+size);
    p= createroot(p , size);
    for (int j=0 ; j<fvalues.size();j++){
        in=fvalues[j];
        for (int i=0 ; i<size ; i++){
            in2.push_back(in[i]);
        }
        p= addone(p,in2,0,size);
        in2.clear();
    }
    //compareall(p,v1,v2);
    p=compareall(p, v1, v2);
    //compareroot(p,v1,v2);
    //compareroot(p, v1, v2);
    p=compareroot(p, v1, v2);
    return p;
}
/*void compareall(bdt& t,std::vector<std::string>v1,std::vector<std::string>v2){
    if (t->left!=NULL&&t->right!=NULL) {
        compareall(t->right,v1,v2);
        compareall(t->left,v1,v2);
        compare(t->right,t,v1,v2);
        compare(t->left,t,v1,v2);
    }
}*/
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
        reconnectroot(t);
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
void reconnection(bdt& t){
    if (t!=NULL) {
        reconnection(t->right);
        reconnection(t->left);
        delete t;
    }
}
void reconnectroot(bdt& t){
    reconnection(t->right);
    bdt x=new bdnode;
    x=t;
    t=t->left;
    delete x;
}
bdt addone(bdt t, std::vector<int> input,int i,int c){
    if (input[i]==48 && c!=0){
        t->left=addone(t->left, input, i+1,c-1);
        return t;
    }
    else if (input[i]==49 && c!=0){
        t->right=addone(t->right, input, i+1,c-1);
        return t;
    }
    else {
        bdt insert = new bdnode;
        insert->left= NULL;
        insert->right= NULL;
        insert->val="1";
        return insert;
    }
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
bdt createroot(bdt tmp,int counter){
    if (counter==0){
        bdt insert = new bdnode;
        insert->val="0";
        insert->left= NULL;
        insert->right= NULL;
        return insert;
    }
    else {
        tmp->left=createroot(tmp->left,counter-1);
        tmp->right=createroot(tmp->right,counter-1);
    }
    return tmp;
}
bdt constree(bdt l, bdt r, int counter2,int depth){
    bdt tmp= new bdnode;
    tmp->val="x"+std::to_string (depth-counter2);
    tmp->left= l;
    tmp->right=r;
    return tmp;
}
bdt instree(bdt t,int counter1,int depth){
    if (counter1>0){
        t->left = constree(NULL, NULL,counter1,depth);
        t->right = constree(NULL,NULL,counter1,depth);
        t->left= instree(t->left,counter1-1,depth);
        t->right= instree(t->right, counter1-1,depth);
        return t;
    }
    else {
        return NULL;
    }
}
std::string evalcompactbdt(bdt t,const std::string& input){
    std::string value ;
    t=passnew(t, input, value);
    return value;
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




