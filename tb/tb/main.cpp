//used C++11 features
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
struct bdnode{
    std::string val;
    bdnode* left;
    bdnode* right;
    
};
//https://intranet.ee.ic.ac.uk/m.cattafi/scripts/dw/doku.php?id=algds:a2-s-2018
typedef bdnode* bdt;

//std::string evalbdt(bdt t, const std::string& input);
void buildEmptyTree(bdt& node,int counter);
//void printtree(bdt t);
void scantree(bdt t, int leaf);
void printTreeRec(bdt t, int depth,std::vector<std::string>& out);
void printTree(bdt t, int depth);
bool ifequal(bdt t);
void storedata (bdt t, std::vector<std::string>& output);
bdt buildcompactbdt(const std::vector<std::string>& fvalues);
std::string evalcompactbdt(bdt t, const std::string& input);
void deleteleftnodes(bdt node);
void simplify (bdt& node);
std::string filterX (std::string input);
//std::string evalcompactbdt(bdt t, const std::string& input);

int main(){
 std::vector<std::string> input;
 std::cout<<"how many input?"<<std::endl;
 int temp;
 std::cin>>temp;
 std::string temp2;
 std::cout<<"enter"<<std::endl;
 for(int a=0;a<temp;a++){
 std::cin>>temp2;
 input.push_back(temp2);
 
 }
 
 bdt output=buildcompactbdt(input);
 //std::cout<<"build"<<std::endl;
 //printtree(output);
 //std::cout<<evalbdt(output,"11")<<std::endl;
 std::cout<<std::endl;
 std::cout<<"selina";
 //std::cout<<evalbdt(output,"00")<<std::endl;
 //std::cout<<evalbdt(output,"01")<<std::endl;
 //std::cout<<evalbdt(output,"10")<<std::endl;
 
 //std::cout<<evalbdt(output,NULL)<<std::endl;
 std::cout<<"end"<<std::endl;
 //printtree(output);
 printTree(output, 4);
 std::cout<<"eval:"<<evalcompactbdt(output,"010")<<std::endl;
 std::cout<<"eval:"<<evalcompactbdt(output,"011")<<std::endl;
 std::cout<<"eval:"<<evalcompactbdt(output,"110")<<std::endl;
 std::cout<<"eval:"<<evalcompactbdt(output,"000")<<std::endl;
 //std::string a="x100";
 //std::cout<<a<<std::endl;
 //a=filterX(a);
 //std::cout<<"after"<<a<<std::endl;
 
 
 
 
 
 /// write the code for the main here in order to test your functions
 
 return 0;
 }

std::string filterX (std::string input){
    //std::cout<<"filterX:"<<input<<std::endl;
    std::string temp;
    for(int a=0;a<input.size();a++){
        if(input[a]!=120){//ASCII
            temp.push_back(input[a]);
        }
    }
    //std::cout<<"after:"<<temp;
    return temp;
    
}






std::string evalcompactbdt(bdt t, const std::string& input){
    if(t!=NULL){
        if(t->left !=NULL && t->right!=NULL){
            int temp=std::stoi(filterX(t->val));
            if(input[temp-1]==48){
                return evalcompactbdt(t->left,input);
            }
            else if(input[temp-1]==49){
                return evalcompactbdt(t->right,input);
            }
        }
        else if(t->val=="0"){
            return "0";
        }
        else if(t->val=="1"){
            return "1";
        }
    }
    return "2";
}







bdt buildcompactbdt(const std::vector<std::string>& fvalues){
    
    
    int length;
    bdt root;
    root=new bdnode;
    root=NULL;
    
    if(fvalues.size()!=0){
        length=fvalues[0].size();
        int counter=1;//counter used to indicate which level the function buildEmptyTree is building
        
        for(int a=0;a<length+1;a++){//build the tree level by level
            buildEmptyTree(root,counter);
            counter++;
            
        }
        
        
        
        
        for(int a=0;a<fvalues.size();a++){
            bdt temproot=root;
            for(int b=0;b<fvalues[0].size();b++){
                
                std::string temp;
                temp=fvalues[a];
                if(temp[b]==49){//49 is the ASCII code of digit "1"
                    temproot=temproot->right;
                    
                }
                else{
                    temproot=temproot->left;
                    
                }
            }
            
            temproot->val="1";
            
        }
        scantree(root,length+1);
    }
    else{
        length=0;
        
        buildEmptyTree(root,1);
        
    }
    
    
    simplify(root);
    
    return root;
    
    
    
    
}

void simplify (bdt& node){
    
    
    
    if(node->left!=NULL && node->right != NULL && node!=NULL){
        
        if (ifequal(node)==true){
            
            bdt tempnode;
            tempnode=node;
            node=node->right;
            deleteleftnodes(tempnode->left);
            delete tempnode;
            
            
            
            
            simplify(node);
        }
        else if (ifequal(node->left)==true){
            
            bdt tempnode=node->left;
            node->left=node->left->right;
            deleteleftnodes(tempnode->left);
            delete tempnode;
            simplify(node);
        }
        
        else if (ifequal(node->right)==true){
            
            bdt tempnode=node->right;
            node->right=node->right->right;
            deleteleftnodes(tempnode->left);
            delete tempnode;
            simplify(node);
            
        }
        else{
            simplify(node->left);
            simplify(node->right);
        }
    }
    
    
    
    
    
    
    
}








void deleteleftnodes(bdt node){
    if(node!=NULL){
        deleteleftnodes(node->left);
        deleteleftnodes(node->right);
        delete node;
    }
}

void buildEmptyTree(bdt& node,int counter){
    //std::cout<<"build"<<std::endl;
    std::string value="x";
    
    
    
    if(node!=NULL){
        buildEmptyTree(node->left,counter);
        buildEmptyTree(node->right,counter);
    }
    else{
        
        
        
        
        bdt newnode;
        newnode=new bdnode;
        newnode->val=value+ std::to_string(counter);
        newnode->left=NULL;
        newnode->right=NULL;
        
        
        node=newnode ;
    }
    
    
    
    
    
    
    
}

/*std::string evalbdt(bdt t, const std::string& input){
 
 int length=input.size();
 for(int a=0;a<length;a++){
 if(input[a]==49){
 t=t->right;
 }
 else{
 t=t->left;
 }
 }
 if(t->val=="1"){
 return "1";
 }
 else{
 return "0";
 }
 
 
 
 
 }
 
 void printtree(bdt t){
 if(t!=NULL){
 printtree(t->left);
 std::cout<<t->val<<std::endl;
 printtree(t->right);
 }
 
 }*/

void scantree(bdt t, int leaf){
    if(t!=NULL){
        scantree(t->left,leaf);
        if(t->val=="x"+std::to_string(leaf)){
            t->val="0";
        }
        scantree(t->right,leaf);
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

void storedata (bdt t, std::vector<std::string>& output){
    if (t!=NULL){
        storedata(t->left,output);
        output.push_back(t->val);
        //std::cout<<t->val;
        //std::cout<<" ";
        storedata(t->right,output);
    }
}

bool ifequal(bdt t){
    std::vector<std::string> temp1;
    std::vector<std::string> temp2;
    //printtree(t);
    
    storedata(t->left,temp1);
    
    storedata(t->right,temp2);
    
    
    if (temp1.size()==temp2.size() && temp1.size()!=0 && temp2.size()!=0){
        for(int a=0;a<temp1.size();a++){
            if(temp1[a]!=temp2[a]){
                return false;
                
            }
        }
        
        return true;
    }
    else {
        
        return false;
    }
    
}
/// write the implementation for the function here

