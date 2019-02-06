//
//  main.cpp
//  data
//
//  Created by AUGUSTUSZZQ on 2018/2/8.
//  Copyright © 2018年 AUGUSTUSZZQ. All rights reserved.
//

#include <iostream>

typedef int tree_t;

struct treenode{
    tree_t  val;
    treenode* left;
    treenode* right;
};

typedef treenode* mtree;

mtree constree(tree_t el,mtree l,mtree r);

mtree instree(tree_t el, mtree t);
void instree_ref(tree_t el, mtree &t);

void printtree(mtree t);
void printroot(mtree t);

mtree deletefromtree_nmr(tree_t el, mtree t);
tree_t minvalnode(mtree t);

void deletetree(mtree t);

int main(int argc, const char * argv[]) {
    int n;
    mtree t=nullptr,t2=nullptr;
    tree_t tmp;
    std::cout<<"how many elements"<<std::endl;
    std::cin>>n;
    for (int i=0; i<n; i++) {
        std::cin>>tmp;
        t=instree(tmp, t);
        instree_ref(tmp, t2);
    }
    
    std::cout<<std::endl;
    printtree(t);
    std::cout<<std::endl;
    printtree(t2);
    
    std::cout<<"enter elements to delete"<<std::endl;
    std::cin>>n;
    
    t=deletefromtree_nmr(n, t);
    t2=deletefromtree_nmr(n, t2);
    
    std::cout<<std::endl;
    printtree(t);
    std::cout<<std::endl;
    printtree(t2);
    
    deletetree(t);
    t=nullptr;
    deletetree(t2);
    t2=nullptr;
    
    return 0;
}

mtree constree (tree_t el, mtree l, mtree r){
    mtree tmp=new treenode;
    tmp->val=el;
    tmp->left=l;
    tmp->right=r;
    return tmp;
}

mtree instree(tree_t el, mtree t){
    if (t==nullptr) {
        return constree(el, NULL, NULL);
    }
    else if (el<t->val){
        t->left=instree(el, t->left);
        return t;
    }
    else{
        t->right=instree(el, t->right);
        return t;
    }
}

void instree_ref(tree_t el, mtree&  t){
    if (t==nullptr) {
        mtree tmp=new treenode;
        tmp->val=el;
        tmp->left=NULL;
        tmp->right=NULL;
        t=tmp;
    }
    else if (el<t->val){
        instree_ref(el, t->left);
    }
    else{
        instree_ref(el, t->right);
    }
}

void printroot(mtree t){
    std::cout<<t->val<<std::endl;
}

void printtree(mtree t){
    if (t!=nullptr) {
        printtree(t->left);
        printroot(t);
        printtree(t->right);
    }
}

tree_t minvalnode(mtree t){
    if (t->left==NULL) {
        return  t->val;
    }
    else{
        return minvalnode(t->left);
    }
}

mtree deletefromtree_nmr(tree_t el, mtree t){
    if (t==nullptr) {
        return t;
    }
    else if (el==t->val){
        if ((t->left==nullptr)&&(t->right==nullptr)){
            delete t;
            return NULL;
        }
        else if (t->left==nullptr){
            mtree tmp=t->right;
            delete t;
            return tmp;
        }
        else if (t->right==nullptr){
            mtree tmp=t->left;
            delete t;
            return tmp;
        }
        else{
            t->val=minvalnode(t->right);
            t->right=deletefromtree_nmr(t->val, t->right);
            return t;
        }
    }
        else if(el<t->val){
            t->left=deletefromtree_nmr(el, t->left);
            return t;
        }
        else{
            t->right=deletefromtree_nmr(el, t->right);
            return t;
        }
}
void deletetree(mtree t){
    if (t!=nullptr) {
        deletetree(t->left);
        deletetree(t->right);
        delete t;
    }
    
}

