//
//  main.cpp
//  a2
//
//  Created by AUGUSTUSZZQ on 2018/2/11.
//  Copyright © 2018年 AUGUSTUSZZQ. All rights reserved.
//

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
bdt creattree(bdt tmp,std::string s);


int main(){
    std::vector<std::string> input;
    std::string in = "000010";
    input.push_back(in);
    in = "010010";
    input.push_back(in);
    in = "110011";
    input.push_back(in);
    bdt fbdt = buildbdt(input);
    std::cout<<fbdt<<std::endl;
    evalbdt(fbdt, "000010");
    
    
    //std::cout << evalbdt(fbdt, "000010") << std::endl;
    // prints "1"
    //std::cout << evalbdt(fbdt, "000001") << std::endl;
    // prints "0"
    return 0;
}

bdt buildbdt(const std::vector<std::string>& fvalues){
    int a=fvalues.size();
    bdt tmp=new bdnode;
    bdt tmpp=new bdnode;
    tmp->left=tmpp;
    tmp->right=NULL;
    for (int i=0; i<a; i++) {
        creattree(tmpp, fvalues[i]);
    }
    tmpp->left=NULL;
    tmpp->right=NULL;
    return tmp;
}
bdt creattree(bdt tmp,std::string s){
    for (int i=0; i<s.size(); i++) {
            if (s[i]==0) {
                bdt tmppp=new bdnode;
                tmppp->val=s[i];
                tmp->left=tmppp;
                tmp->right=NULL;
            }
            else{
                bdt tmppp=new bdnode;
                tmppp->val=s[i];
                tmp->right=tmppp;
                tmp->left=NULL;
            }
    }
    bdt n=new bdnode;
    n->val="2";
    tmp->left=n;
    tmp->right=NULL;
    return tmp;
}

std::string evalbdt(bdt t, const std::string& input){
    std::string s2;
    s2=input[0];
    bdt test=new bdnode;
    bdt test1=new bdnode;
    test->left=test1;
    test->right=NULL;
    int l=0;
    for (int i=0; i<s2.size(); i++) {
        if (test1!=NULL) {
            if (s2[i]==0) {
                bdt tmppp=new bdnode;
                tmppp->val=s2[i];
                test1->left=tmppp;
                test1->right=NULL;
            }
            else{
                bdt tmppp=new bdnode;
                tmppp->val=s2[i];
                test1->right=tmppp;
                test1->left=NULL;
            }
        }
    }
    std::cout<<t->left<<std::endl;
    std::cout<<t->right<<std::endl;
    while ((t->left!=NULL)&&(t->right!=NULL)) {
        std::cout<<"a"<<std::endl;
        while (t->val!="2") {
            if ((t->left!=test->left)&&(t->right!=test->right)){
                l=l;
            }
            else{
                    if (t->left==NULL) {
                        t=t->right;
                        test=test->right;
                        l++;
                    }
                    else{
                        t=t->left;
                        test=test->left;
                        l++;
                    }
                }
            }
        if (t->left!=NULL) {
            t=t->left;
        
        }
        else{
            t=t->right;
            
        }
        
        }//判断函数问题！！！！
    
    if (l<input.size()) {
        std::cout<< "0"<<std::endl;
    }
    else{
        std::cout<<"1"<<std::endl;
    }
    return input;
    }

