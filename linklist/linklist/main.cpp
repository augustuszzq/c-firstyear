//
//  main.cpp
//  linklist
//
//  Created by AUGUSTUSZZQ on 2018/1/31.
//  Copyright © 2018年 AUGUSTUSZZQ. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
struct intlist{
    int val;
    intlist* next;
};
int main(int argc, const char * argv[]) {
    intlist* l=NULL;
    intlist* h=NULL;
    int length=0;
    int q=0;
    int d;
    std::string name;
    std::ifstream infile;
    std::cout << "enter the name of the file" << std::endl;
    std::cin >> name;
    infile.open(name.c_str());
    int m;
    while (infile >>m ){
        intlist* tmp = new intlist ;
        (*tmp).val = m;
        (*tmp).next = l;
        l=tmp;
        q++;
    }
    std::cout<<std::endl;
   
    int x;
    int counter=0;
    std::cout<<"please enter the element you want to delete "<<std::endl;
    std::cin>>d;
    
    while (l!=NULL) {
        intlist* tmp1 = new intlist ;
        if (l->val!=d) {
            (*tmp1).val = l->val;
            l=l->next;
            (*tmp1).next = h;
            h=tmp1;
        }
        else{
            l=l->next;
        }
    }
    intlist* lit=h;
    std::cout<<"please enter the element you want to search"<<std::endl;
    std::cin>>x;
    while (lit!=NULL) {
        std::cout<<lit->val<<std::endl;
        length++;
        if (lit->val==x) {
            counter=length;
        }
            lit = lit->next;
    }
    std::cout<<"the length of the elements is"<<"   "<<length<<std::endl;
    
    if (counter!=0) {
        std::cout<<"there is an element in the list, and the position of the element is "<<counter<<std::endl;
    }
    if (counter==0) {
        std::cout <<"Sorry ,there is no element in the  array"<<std::endl;
    }
    while(l!= NULL)
    {
        intlist*tmpl=l->next;
        delete l ;
         l = tmpl;
        }
    return 0;
}
