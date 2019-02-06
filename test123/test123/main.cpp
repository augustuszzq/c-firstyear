//
//  main.cpp
//  test123
//
//  Created by AUGUSTUSZZQ on 2018/3/6.
//  Copyright © 2018年 AUGUSTUSZZQ. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
void change( long n,long num, int m,std::vector<long> &k);
int main(int argc, const char * argv[]) {
    std::vector<long> k;
    change(1294,6,4,k);
    std::cout<<std::endl;
    for (int i=0; i<k.size(); i++) {
        std::cout<< k[i]<<std::endl;
    }
    return 0;
}
void change(long n,long num,int m,std::vector<long> &k){
    for (int i=m-1; i>=0; i--) {
        int p=n/(pow(num, i));
        k.push_back(p);
        n=n-p*pow(num, i);
    }
}
    
    
    
    

