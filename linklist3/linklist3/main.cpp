//
//  main.cpp
//  linklist3
//
//  Created by AUGUSTUSZZQ on 2018/2/6.
//  Copyright © 2018年 AUGUSTUSZZQ. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

typedef int list_t;
struct listnode{
    list_t val;
    listnode* next;
};

typedef listnode* mlist;

void consref(list_t el,mlist&l);
mlist consret(list_t el, mlist l);

mlist constail_rec(list_t el, mlist l);

void printlist_rec(mlist l);
void printrevlist_rec(mlist l);

void deallocate_r_rec(mlist& l);
mlist deallocate_c_rec(mlist  l);
void deallocate_r_rec_wrong(mlist& l);

int mfact(int n);
int mpower(int x,int p );
int counter(mlist l);
int search(int a,mlist l);
void insert(int z,mlist& l);


int main(int argc, const char * argv[]) {
    std::ifstream infile;
    std::string name;
    std::cout << "enter the name of the file" << std::endl;
    std::cin >> name;
    infile.open(name.c_str());
    
    mlist la=NULL;
    mlist lb=NULL;
    
    int n;
    list_t el;
    
    if(!infile.is_open()){
        std::cout << "the file couldn't be open" << std::endl;
        exit(EXIT_FAILURE);
    }
    while(infile >> el){
        la=consret(el, la);
        lb=constail_rec(el, lb);
    }
    
    std::cout<<std::endl;
    
    std::cout<<"print normal order:"<<std::endl;
    printlist_rec(la);
   /* std::cout<<std::endl;
    printlist_rec(lb);*/
    
     std::cout<<std::endl;
    
    /*int y=0;
    y=mfact(n);
    std::cout<<y<<std::endl;*/
    
    /*int x;
    int p;
    std::cout<<"please enter x"<<std::endl;
    std::cin>>x;
    std::cout<<"please enter p"<<std::endl;
    std::cin>>p;
    int o=0;
    o=mpower(x, p );
    std::cout<<o<<std::endl;*/
    
    std::cout<<std::endl;
    
    /*int c=0;
    c=counter(la);
    std::cout<<c<<std::endl;*/

    /*int v=0;
    int a;
    std::cout<<"please enter the elements you want to search"<<std::endl;
    std::cin>>a;
    v=search(a,la);
    std::cout<< v<<std::endl;*/

    
    
    int z;
    std::cout<<"please enter the elements you want to insert"<<std::endl;
    std::cin>>z;
    
    insert(z,la);
    
    printlist_rec(la);
    
    std::cout<<std::endl;
    
    /*std::cout<<"print reverse order:"<<std::endl;
    printrevlist_rec(la);
    std::cout<<std::endl;
    printrevlist_rec(lb);*/
    
    std::cout<<std::endl;
   
    deallocate_r_rec(la);
    std::cout<<la<<std::endl;
    lb=deallocate_c_rec(lb);
    std::cout<< lb <<std::endl;
    
    
    return 0;
}
int mfact(int n){
    if (n==0) {
        return 1;
    }
    else{
        return n* mfact(n-1);
    }
}

int mpower(int x,int p ){
    if (p==0) {
        return 1;
    }
    else{
        return x*mpower(x, p-1);
    }
}


void consref(list_t el,mlist& l ){
    mlist tmpp=new listnode;
    tmpp -> val= el;
    tmpp-> next=l;
    l=tmpp;
}
mlist consret(list_t el,mlist l){
    mlist tmpp=new listnode;
    tmpp -> val= el;
    tmpp ->next =l;
    return tmpp;
}
mlist  constail_rec(list_t el,mlist l){
    if (l==NULL) {
        return consret(el, l);
    }
    else{
        l->next=constail_rec(el, l->next);
        return l;
    }
}

void printhead(mlist l){
    std::cout<<l->val<<std::endl;
    
}

void printrevlist_rec(mlist l){
        if (l!=NULL) {
            printhead(l);
            printrevlist_rec(l->next);
        }
    }
void printlist_rec(mlist l){
    if (l!=NULL) {
        printlist_rec(l->next);
        printhead(l);
    }
}


void deallocate_r_rec_wrong(mlist &l){
    if (l!=NULL) {
        mlist nextl=l->next;
        delete l;
        deallocate_r_rec_wrong(nextl);
    }
}

void deallocate_r_rec(mlist &l){
    if (l!=NULL) {
        mlist tmp=l;
        l=l->next;
        delete tmp;
        deallocate_r_rec(l);
    }
}

mlist deallocate_c_rec(mlist l){
    if (l==NULL) {
        return l;
    }
    else{
        mlist nextl=l->next;
        delete l;
        return deallocate_c_rec(nextl);
    }
}

int counter(mlist l){
    if (l!=NULL) {
        l=l->next;
        return 1+counter(l);
    }
    return 0;
}

int search(int a,mlist l){
    if (l!=NULL) {
        if (a==l->val) {
            l=l->next;
            return 1+search(a,l);
        }
        else{
            l=l->next;
            return search(a,l);
        }
    }
    return 0;
}



void insert(int z,mlist& l){
     if (l!=NULL) {
        if (z>l->val){
            mlist tmpp=new listnode;
            tmpp->val=z;
            tmpp->next=l;
            l=tmpp;
        }
        else{
            return insert(z, l->next);
        }
        }
     else{
         mlist tmpp=new listnode;
         tmpp->val=z;
         tmpp->next=l;
         l=tmpp;
     }
    
}
  


