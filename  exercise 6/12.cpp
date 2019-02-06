//
//  main.cpp
//  34
//
//  Created by AUGUSTUSZZQ on 2018/1/12.
//  Copyright © 2018年 AUGUSTUSZZQ. All rights reserved.
//

//
//  main.cpp
//  new
//
//  Created by AUGUSTUSZZQ on 2018/1/12.
//  Copyright © 2018年 AUGUSTUSZZQ. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

void compare (int x,int y);
int main(){
    int M [1000];
    int i=0;
    int p;
    std::ifstream infile;
    std::string filename;
    std::cout<<"please enter the name of the file "<<std::endl;
    std::cin>>filename ;
    infile.open (filename.c_str());
    if (!infile.is_open()){
        std::cout << "the file couldn't be opened" <<std::endl;
        exit ( EXIT_FAILURE ) ;
    }
    std::cout<<"the name of the file :"<<filename<<std::endl;
    int n;
    while(infile >> n){
        std::cout<<"the content of the sequence :"<< n <<std::endl;
        M[i]=n;
        i++;
    }
    std::cout<<"please enter a number :"<<std::endl;
    std::cin>>p;
    for (int j=0; j<i; j++) {
        compare(M[j],p);
    }
    return 0 ;
}
void compare(int x,int y){
    if (x<y)
    { std::cout<<x<<std::endl;}
}

