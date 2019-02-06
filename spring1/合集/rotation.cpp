#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
int main(){//rotation
    std::string filename;
    std::vector<int> v;
    std::cout << "plese enter name of file containing the sudoku" << std::endl;
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
    std::vector <int>v2;
    int n= std::sqrt(v.size());
    for (int i=n-1; i>=0; i--) {
        for (int j=i; j<v.size(); j=j+n) {
            v2.push_back(v[j]);
            std::cout<<v[j]<<"\t";
        }
        std::cout<<std::endl;
    }
   
    v.clear();
    for (int a=0 ; a<v2.size; a++) {
        v.push_back(v2[a]);
    }
    for (int a =0; a<v.size(); a++) {
        std::cout<<v[a]<<std::endl;
    }
    
    
    
    
    
    return 0;
}
