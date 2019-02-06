#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
void print_grid(const std::vector<int>& v);
int main(int argc, const char * argv[]) {
    std::vector<int> v;
    std::ifstream infile;
    std::string name;
    std::cout << "enter the name of the file" << std::endl;
    std::cin >> name;
    infile.open(name.c_str());

    if(!infile.is_open()){
        std::cout << "the file couldn't be open" << std::endl;
        exit(EXIT_FAILURE);
    }
    int tmp;
    while(infile >> tmp){
        v.push_back(tmp);}
    print_grid(v);
    return 0;
}

void print_grid(const std::vector<int>& v){
    int s= std::sqrt(v.size());
    int t=0 ;
    for (int e=0; e<s; e++) {
        for (int r=0; r<s; r++) {
            std::cout<<v[t]<<"\t";
            t++;
        }
        std::cout<<std::endl;
    }
}
