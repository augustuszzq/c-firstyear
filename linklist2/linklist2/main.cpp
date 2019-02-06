//
//  main.cpp
//  linklist2
//
//  Created by AUGUSTUSZZQ on 2018/2/1.
//  Copyright © 2018年 AUGUSTUSZZQ. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
typedef int list_t;
struct listnode{
    list_t val;
    listnode* next;
};

typedef listnode* mlist;
void consref(list_t el,mlist& l);
mlist consret ( list_t el , mlist l ) ;
void printlist(mlist l);
void deallocate_c(mlist l);
void deallocate_r(mlist& l);
void counter(mlist l);
bool search(list_t el,mlist l);
void deletenumbers(list_t el,mlist& l);
int main(int argc, const char * argv[]) {
    std::string name;
    std::ifstream infile;
    std::cout << "enter the name of the file" << std::endl;
    std::cin >> name;
    infile.open(name.c_str());
    mlist la=NULL;
    mlist lb=NULL;
    list_t el;
    while (infile >>el){
        listnode * tmp = new listnode ;
        (*tmp).val = el;
        consref(el, la);
        lb=consret(el, lb);
    }
    std::cout<<std::endl;
    counter(la);
    std::cout<<std::endl;
    printlist(la);
    std::cout<<std::endl;
    printlist(lb);
    int n;
    std::cout<<"please enter the element you want to search"<<std::endl;
    std::cin>>n;
    search(n,la);
     std::cout<<"please enter the element you want to delete"<<std::endl;
    int y=0;
    std::cin>>y;
    
    deletenumbers(y,la);
    printlist(la);
    deallocate_c(la);
    deallocate_r(lb);

    return 0;
}
void consref(list_t el, mlist& l){
    mlist tmpp=new listnode;
    tmpp->val =el;
    tmpp->next=l ;
    l=tmpp;
}

mlist consret ( list_t el , mlist l )
{
     mlist tmpp = new listnode;
     tmpp->val = el ;
     tmpp->next = l ;
      return tmpp ;
}
              
void  printlist(mlist l){
    while(l!=NULL){
        std::cout<< l->val << std::endl ;
        l = l->next ;
    }
}
void deallocate_c ( mlist l ) {
    while ( l != NULL ) {
    mlist nextl = l->next ;
    delete l ;
    l = nextl ;
    }
}
void deallocate_r ( mlist& l ) {
    while ( l != NULL ) {
    mlist nextl = l->next ;
    delete l ;
    l = nextl;
 }
}
void counter(mlist l)
{
    int n=0;
    while (l !=NULL ) {
        n++;
        l = l->next;
    }
    std::cout<<n<<std::endl;
}
bool search(list_t el,mlist l){
    int c=1;
    while (l!=NULL) {
        if (el==l->val) {
            std::cout<<c<<std::endl;
            return false;
        }
        else
        {
            c++;
            l = l->next;
        }
    }
    return true;
}
void deletenumbers(list_t el,mlist& l){
    bool found= false;
    mlist searchptr;
    mlist oldptr;
    mlist lastptr;
    
    if (l==NULL) {
        return;
    }
    else if (l->val==el)
    {
        oldptr=l;
        l=l->next;
        delete oldptr;
    }
    else{
        found=false;
        searchptr=l;
        lastptr=l;
        while ((searchptr!=NULL)&&(!found)) {
            if (searchptr->val==el) {
                found=true;
                lastptr->next=searchptr->next;
                delete searchptr;
            }
            else
            {
                lastptr=searchptr;
                searchptr=searchptr->next;
            }
        }
    }
}
