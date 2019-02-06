//using c++11
#include<iostream>
#include<string>
#include<vector>

struct bdnode{
    std::string val;
    bdnode* left;
    bdnode* right;
    
};


typedef bdnode* bdt;

bdt buildcompactbdt(const std::vector<std::string>& fvalues);
std::string evalcompactbdt(bdt t, const std::string& input);
void buildtree(int n,int j,bdt& l );// recursive function to build the whole tree;
void BoolFunc(const std::vector<std::string>& fvalues,bdt & l);// use to construct boolean function we want to imply;
void printTree(bdt t, int depth);
bdt One(int length, std::string n, bdt l);// function used in BoolFunc;
void savetree(bdt l, std::vector<std::string> & A);
void delwaste(bdt & l,bdt & prel);
void deleten(bdt& l);
void compactionX(bdt& l);
void compactionR(bdt& l);
void compaction(bdt& prel, bdt& l);

int main(){
    
    std::vector<std::string> input;
    std::string in = "000";
    input.push_back(in);
    in = "010";
    input.push_back(in);
    in = "001";
    input.push_back(in);
    in = "111";
    input.push_back(in);
    bdt fbdt = buildcompactbdt(input);
    printTree(fbdt, 10);
    std::cout << evalcompactbdt(fbdt, "001") << std::endl;
    std::cout << evalcompactbdt(fbdt, "000") << std::endl;
    return 0;
}

void delwaste(bdt & l, bdt& prel){
    deleten(l->right);
    if(prel->left==l){
        bdt x=l;
        prel->left=l->left;
        delete x;
    }
    else{
        bdt x=l;
        prel->right=l->left;
        delete x;
    }
}

void compaction(bdt& prel, bdt& l){
    if(l->right!=NULL&&l->left!=NULL){
        int cpable=1;
        std::vector<std::string> leftvec;
        std::vector<std::string> rightvec;
        savetree(l->left,leftvec);
        savetree(l->right,rightvec);
        if(leftvec.size()==rightvec.size()){
            for(int i=0;i<leftvec.size();i++){
                //      std::cout<<leftvec[i]<<"\t"<<rightvec[i]<<"\n";
                if(leftvec[i]!=rightvec[i]){
                    cpable=0;
                }
                //    std::cout<<cpable<<"\n";
            }
        }
        else{
            cpable=0;
        }
        if(cpable==1){
            delwaste(l, prel);
        }
    }
}

void compactionX(bdt& l){
    if(l->right!=NULL&&l->left!=NULL){
        //std::cout<<l->val<<"\n";
        compactionX(l->left);
        compactionX(l->right);
        compaction(l,l->left);
        compaction(l,l->right);
    }
}

void savetree(bdt l, std::vector<std::string> & A){
    if(l!=NULL){
        savetree(l->left,A);
        A.push_back(l->val);
        savetree(l->right,A);
    }
}

void deleten(bdt& l){
    if(l!=NULL){
        deleten(l->left);
        deleten(l->right);
        delete l;
    }
}

void delwasteR(bdt & l){
    deleten(l->right);
    bdt x=l;
    l=l->left;
    delete x;
}

void compactionR(bdt& l){
    if(l->right!=NULL&&l->left!=NULL){
        int cpable=1;
        std::vector<std::string> leftvec;
        std::vector<std::string> rightvec;
        savetree(l->left,leftvec);
        savetree(l->right,rightvec);
        if(leftvec.size()==rightvec.size()){
            for(int i=0;i<leftvec.size();i++){
                //std::cout<<leftvec[i]<<"\t"<<rightvec[i]<<"\n";
                if(leftvec[i]!=rightvec[i]){
                    cpable=0;
                }
                //  std::cout<<cpable<<"\n";
            }
        }
        else{
            cpable=0;
        }
        if(cpable==1){
            delwasteR(l);
        }
    }
    
}

bdt buildcompactbdt(const std::vector<std::string>& fvalues){
    bdt tmp= new bdnode;
    tmp->val="x1";
    tmp->left=NULL;
    tmp->right=NULL;
    int n=fvalues[0].size()-1;
    int counter=2;// ASCII starts with "2"
    buildtree(n,counter,tmp);
    BoolFunc(fvalues,tmp);
    compactionX(tmp);
    compactionR(tmp);
    
    return tmp;
    
}

std::string evalcompactbdt(bdt t, const std::string& input){
    while(t!=NULL){
        if(t->val =="1"||t->val =="0"){
            return t->val;
        }
        else{
            if(t->right!=NULL){
                int x=(t->val[1])-49;
                if(input[x]=='1'){
                    t=t->right;
                }
                else{
                    t=t->left;
                }
            }
            else{
                 t=t->left;
            }
        }
    }
}




void buildtree(int n,int j,bdt& l ){
    //the base case is use to preserve results of boolean function, I initially set all of them to "0";
    if(n==0){
        l->left = new bdnode;
        l->left->val="0";
        l->left->left=NULL;
        l->left->right=NULL;
        l->right = new bdnode;
        l->right->val="0";
        l->right->left=NULL;
        l->right->right=NULL;
    }
    
    else{
        //set the val of each node to "xj";
        l->left = new bdnode;
        l->left->val="x"+std::to_string(j);
        l->left->left=NULL;
        l->left->right=NULL;
        buildtree(n-1,j+1,l->left);
        l->right = new bdnode;
        l->right->val="x"+std::to_string(j);
        l->right->left=NULL;
        l->right->right=NULL;
        buildtree(n-1,j+1,l->right);
    }
}

void BoolFunc(const std::vector<std::string>& fvalues,bdt & l){
    //extract each element from the vector
    int n=fvalues.size()-1;
    while(n>=0){
        l=One(fvalues[n].size(),fvalues[n],l);
        n--;
    }
}

bdt One(int length, std::string n, bdt l){
    //put "1" to imply the function
    bdt m=l;
    for(int i =0; i<length; i++){
        if(n[i]== '1'){
            l=l->right;
        }
        else{
            l=l->left;
        }
    }
    l->val="1";
    l=m;
    return l;
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
