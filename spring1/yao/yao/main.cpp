//
//  main.cpp
//  yao
//
//  Created by AUGUSTUSZZQ on 2018/2/2.
//  Copyright © 2018年 AUGUSTUSZZQ. All rights reserved.
//

#include<iostream>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<cmath>
    
    bool merge_num(std::vector<int>& v, int bi, int ei);
    void print_grid(const std::vector<int>& v);
    bool game_over(const std::vector<int>& v);
    void rotate_anti_clock(std::vector<int>& v);
    void random( std::vector<int>& v);
    
    int main(){
        std::ifstream infile;
        std::cout<<"what file?"<<std::endl;
        std::string as;
        std::cin>>as;
        infile.open(as.c_str());
        int a;
        
        
        std::vector<int> input;
        if(infile.is_open()){
            while(infile>>a){
                input.push_back(a);
            }
        }
        else{
            for(int er=0;er<16;er++){
                if(er<15){
                    input.push_back(0);
                }
                else{
                    input.push_back(2);
                }
            }
        }
        
        print_grid(input);
        
        std::cout<<"a";
        
        if(game_over(input)==true){
            std::cout<<" game over"<<std::endl;
        }
        else{
            std::string answer;
            while(game_over(input)!=true){
                std::cout<<"please enter a move"<<std::endl;
                std::cin>>answer;
                
                int gridsize=input.size();
                int rowsize=std::sqrt(gridsize);
                
                if(answer=="s"){
                    rotate_anti_clock(input);
                    rotate_anti_clock(input);
                    rotate_anti_clock(input);
                    merge_num(input, 2+(rowsize-1),2+(rowsize-1)*2);
                    merge_num(input,3+(rowsize-1)*2,3+(rowsize-1)*3);
                    merge_num(input,4+(rowsize-1)*3,4+(rowsize-1)*4);
                    rotate_anti_clock(input);
                }
                else if(answer=="w"){
                    rotate_anti_clock(input);
                    merge_num(input,1,1+(rowsize-1));
                    merge_num(input, 2+(rowsize-1),2+(rowsize-1)*2);
                    merge_num(input,3+(rowsize-1)*2,3+(rowsize-1)*3);
                    merge_num(input,4+(rowsize-1)*3,4+(rowsize-1)*4);
                    rotate_anti_clock(input);
                    rotate_anti_clock(input);
                    rotate_anti_clock(input);
                    
                }
                else if(answer=="a"){
                    merge_num(input,1,1+(rowsize-1));
                    merge_num(input, 2+(rowsize-1),2+(rowsize-1)*2);
                    merge_num(input,3+(rowsize-1)*2,3+(rowsize-1)*3);
                    merge_num(input,4+(rowsize-1)*3,4+(rowsize-1)*4);
                }
                else if(answer=="d"){
                    rotate_anti_clock(input);
                    rotate_anti_clock(input);
                    merge_num(input,1,1+(rowsize-1));
                    merge_num(input, 2+(rowsize-1),2+(rowsize-1)*2);
                    merge_num(input,3+(rowsize-1)*2,3+(rowsize-1)*3);
                    merge_num(input,4+(rowsize-1)*3,4+(rowsize-1)*4);
                    rotate_anti_clock(input);
                    rotate_anti_clock(input);
                }
                else{std::cout<<"not valid move"<<std::endl;}
                random(input);
                print_grid(input);
                
            }
        }
        return 0;
    }
    void random( std::vector<int>& v){
        int max=v.size();
        std::vector<int> randomvec;
        for(int i=0;i<max;i++){
            if(v[i]==0){
                randomvec.push_back(i);
            }
        }
        int randomnum=rand()%(randomvec.size());
        randomnum=randomvec[randomnum];
        v[randomnum]=2;
    }
    
    
    bool merge_num(std::vector<int>& v, int bi, int ei){
        int total=ei-bi+1;
        int current=0;
        int next=0;
        int temp;
        bool result=false;
        std::vector<int> tempvec;
        for(int n=0;n<total;n++){
            if(v[bi+n]==0){
                //if its all empty, fault
            }
            else{
                temp=v[bi+n];
                next=0;
                while(v[bi+n+next]==0 && (bi+n+next)<ei){
                    next++;
                }
                if(v[bi+n]==v[bi+n+next] && next!=0){
                    tempvec.push_back(2*v[bi+n]);
                    v[bi+n+next]=0;
                }
                else if(v[bi+n]==v[bi+n+next] && next==0){
                    tempvec.push_back(v[bi+n]);
                }
                else{
                    tempvec.push_back(v[bi+n]);
                    tempvec.push_back(v[bi+n+next]);
                    v[bi+n+next]=0;
                }
                next=0;
            }
            
            
            
        }
        for(int j=0;j<total;j++){
            if (v[bi+j]!=tempvec[j]){
                v[bi+j]=tempvec[j];
                result=true;
            }
        
            
        }
        return result;
    }
    
    
    
    void rotate_anti_clock(std::vector<int>& v){
        std::vector<int> index;
        int nums=std::sqrt(v.size());
        for(int a=nums;a>0;a=a-1){
            for(int b=0;b<nums;b++){
                index.push_back(v[a+(b*nums)-1]);
            }
        }
        
        for(int c=0;c<16;c++){
            v[c]=index[c];
        }
        
    }
    
    
    
    
    
    bool game_over(const std::vector<int>& v){
        int total= v.size();
        int subsize=std::sqrt(total);
        bool full=true;
        bool nomove=true;
        for(int m=0;m<total;m++){
            if(v[m]==0){
                full=false;
            }
            
        }
        
        for(int q=0;q<subsize;q++){
            for(int w=0;w<subsize;w++){
                if(v[w+q*subsize]==v[w+q*subsize+1]){
                    nomove=false;
                }
            }
        }// check right
        
        for(int e=0;e<subsize;e++){
            for(int r=subsize-1;r>=0;r=r-1){
                if(v[r+e*subsize]==v[r+e*subsize-1]){
                    nomove=false;
                }
            }
        }// check left
        
        for(int t=0;t<subsize;t++){
            for(int y=0;y<subsize;y++){
                if(v[y+t*subsize]==v[y+(t+1)*subsize]){
                    nomove=false;
                }
            }
        }// check up
        
        for(int d=subsize-1;d>=0;d--){
            for(int f=0;f<subsize;f++){
                if(v[f+d*subsize]==v[f+(d-1)*subsize]){
                    nomove=false;
                }
            }
        }// check down
        
        if(nomove==true && full==true){
            return true;
        }
        else{
            return false;
        }
    }

    
    
    
    
    
    void print_grid(const std::vector<int>& v){
        int total=v.size();
        int subsize=std::sqrt(total);
        for(int i=0;i<subsize;i++){
            for(int y=0;y<subsize;y++){
                std::cout<<v[y+i*subsize];
                std::cout<<" ";
            }
            std::cout<<std::endl;
        }
        
        
    }

