#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
bool game_over(const std::vector<int>& v);
void rotate_anti_clock(std::vector<int>& v);
int main(){//bool game_over(const std::vector<int>& v)；
    std::string filename;
    std::vector<int> v;
    std::cout << "plese enter name of file containing the int i=0;
    while(!b&&i<3){
        rotate_anti_clock(tmp);
        b=merge_num(tmp, bi, ei);
        bi=bi+side;
        ei=ei+side;
        if(b){
            return false;
        }
        i++;
    }
    return true;
}" << std::endl;
    std::cin >> filename;
    
    std::ifstream infile;
    infile.open(filename.c_str());
    
    if(!infile.is_open()){
        std::cout << "error, can't open input file" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    int tmp;
    while(infile >> tmp){
        v.push_back(tmp);
    }
    bool check;
    check= game_over(v);
    if (!check) {
        std::cout<<"continue"<<std::endl;
    }
    else{
        std::cout<<"game over"<<std::endl;
    }
        
    
    
    
    
    return 0;
}
bool game_over(const std::vector<int>& v){
    int size= std::sqrt(v.size());
    bool check=false;
    for (int p=0; p<v.size(); p=p+size) {
        for (int q=0; q<size-1; q++)
        {
            if (v[q]==v[q+1])
            {
                return check;
            }
            else
            {
                return true;
            }
        }
    }

    for (int a=0; a<size-1; a++) {
        for (int b=0; b<v.size(); b=b+size)
        {
            if (v[b]==v[b+size])
            {
                return check;
            }
            else
            {
                return true;
            }
        }
    }
}


