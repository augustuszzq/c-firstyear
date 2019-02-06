//
//  main.cpp
//  assignme1
//
//  Created by AUGUSTUSZZQ on 2018/2/8.
//  Copyright © 2018年 AUGUSTUSZZQ. All rights reserved.
//

/// include here all the headers you need (but see guidelines)
#include <iostream>
#include <string>
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
bdt buildbdt(const std::vector<std::string>& fvalues);
std::string evalbdt(bdt t, const std::string& input);
bdt creat(bdt m,int n );
/// you can define and use additional functions
/// for the implementation of buildbdt and evalbdt

/// add here the declarations (not the implementation)
/// for any other functions you wish to define and use

/// before the submission you need to remove the main
/// (either delete it or comment it out)
/// otherwise it will intefere with the automated testing

int main(){

    std::vector<std::string> input;
    std::string in = "000010";
    for (int i=0; i<in.size(); i++) {
        std::cout<<in[i]<<std::endl;
    }
    std::cout<<in.size()<<std::endl;
    input.push_back(in);
    bdt fbdt = buildbdt(input);
    std::cout<<"b"<<std::endl;
    evalbdt(fbdt, "000010");
            
    //std::cout << evalbdt(fbdt, "000010") << std::endl;
    /// write the code for the main here in order to test your functions
    
    return 0;
}

bdt buildbdt(const std::vector<std::string>& fvalues){
    std::string s2;
    int i=0;
    s2=fvalues[i];
    std::vector<int>v;
    bdt tmp;
    for (int i=0; i<s2.size(); i++) {
        v.push_back(s2[i]);
        std::cout<<"a1"<<std::endl;
    }
    
    for (int i=0; i<v.size(); i++) {
         creat(tmp, v[i]);
        std::cout<<"a"<<std::endl;
    }
    return tmp;
}

    /*bdt t=new bdnode;
    t->left=NULL;
    t->right=NULL;
    for (int i=0; i<s2.size(); i++) {
        if (s2[i]==0) {
            bdt tmpp=new bdnode;
            tmpp->left=NULL;
            tmpp->right=NULL;
            tmpp->val="0";
            t->left=tmpp;
            i++;
        }
        else{
            if (s2[i]==1) {
                bdt tmpp=new bdnode;
                tmpp->val="0";
                t->right=tmpp;
                i++;
            }
        }*/
    /// write the implementation for the function here

bdt  creat(bdt m,int n){
    if (m!=NULL) {
        if (n==0) {
            bdt tmppp=new bdnode;
            tmppp->val=n;
            m->left=tmppp;
            m->right=NULL;
        }
        else{
            bdt tmppp=new bdnode;
            tmppp->val=n;
            m->right=tmppp;
            m->left=NULL;
        }
    }
    return m;
    
  
    
}
std::string evalbdt(bdt t, const std::string& input){
    /// write the implementation for the function here
    bdt tmp1;
    bdt tmp2;
    bdt tmp3;
    std::vector<std::string>v1;
    std::vector<std::string>v2;
    std::vector<std::string>v3;
    std::string s1="000010";
    std::string s2="010010";
    std::string s3="110011";
    v1.push_back(s1);
    v2.push_back(s2);
    v3.push_back(s3);
    tmp1=buildbdt(v1);
    tmp2=buildbdt(v2);
    tmp3=buildbdt(v3);
    int a=0;
    int b=0;
    int c=0;
    while ((tmp1->left!=NULL)&&(tmp1->right!=NULL)) {
        if((tmp1->left!=t->left)&&(tmp1->right!=t->right)) {
            a++;
            if (tmp1->left!=NULL) {
                tmp1=tmp1->left;
                t=t->right;
            }
            else{
                tmp1=tmp1->right;
                t=t->left;
            }
        }
        else{
        
            if (tmp1->left!=NULL) {
                tmp1=tmp1->left;
                t=t->left;
            }
            else{
                tmp1=tmp1->right;
                t=t->right;
        }
    }
    }//判断tmp1；
    while ((tmp2->left!=NULL)&&(tmp2->right!=NULL)) {
        if((tmp2->left!=t->left)&&(tmp2->right!=t->right)) {
            b++;
            if (tmp2->left!=NULL) {
                tmp2=tmp2->left;
                t=t->right;
            }
            else{
                tmp2=tmp2->right;
                t=t->left;
            }
        }
        else{
            if (tmp2->left!=NULL) {
                tmp2=tmp2->left;
                t=t->left;
            }
            else{
                tmp2=tmp2->right;
                t=t->right;
            }
        }
    }//判断tmp2；
    while ((tmp3->left!=NULL)&&(tmp3->right!=NULL)) {
        if((tmp3->left!=t->left)&&(tmp3->right!=t->right)) {
            c++;
            if (tmp3->left!=NULL) {
                tmp3=tmp3->left;
                t=t->right;
            }
            else{
                tmp3=tmp3->right;
                t=t->left;
            }
        }
        else{
            if (tmp3->left!=NULL) {
                tmp3=tmp3->left;
                t=t->left;
            }
            else{
                tmp3=tmp3->right;
                t=t->right;
            }
        }
    }
    //判断tmp3；
    if ((a>=1)&&(b>=1)&&(c>=1)) {
        std::cout<<"0"<<std::endl;
    }
    if ((a=0)||(b=0)||(c=0)) {
        std::cout<<"1"<<std::endl;
    }
    return 0;
}


/// add here the implementation for any other functions you wish to define and use
