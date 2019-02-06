
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
bool merge_num(std::vector<int>& v, int bi, int ei);

int main(int argc, const char * argv[]) {
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
    }//以上将文件输入vector；
    
    merge_num(v,0,15);
    
    for(int c=0;c<v.size();c++){
        std::cout<<v[c]<<std::endl;
    }
    
    return 0;
}


bool merge_num(std::vector<int>& v, int bi, int ei)
{
    std::vector<int>v1;
    std::vector<int>v2;
    std::vector<int>v3;
    std::vector<int>vtemp;
    std::vector<int>vtemp2;
    std::vector<int>vtemp3;
    int z=0;
    for (int a=bi; a<=ei; a++) {
        v2.push_back(v[a]);
    }//中间抽出来的项
    for (int b=0; b<v2.size(); b++) {
        if (v2[b]!=0) {
            vtemp.push_back(v2[b]);
        }
        else{
            z++;
        }
    }
    vtemp.push_back(0);
    for (int c=0; c<vtemp.size(); c++) {
        if (vtemp[c]==vtemp[c+1]) {
            vtemp2.push_back(vtemp[c]+vtemp[c+1]);
            c++;
            z++;
        }
        else  {
            vtemp2.push_back(vtemp[c]);
        }
    }
    
    int m=v2.size()-vtemp2.size();
    for (int d=0; d<m; d++)
    {
        vtemp2.push_back(0);
    }//末尾加0；
    //如果没有一个零;把值给tp2；
    v2.clear();
    
    for(int e=0;e<vtemp2.size();e++)
    {
        v2.push_back(vtemp2[e]);
    }
    
    for (int f=0; f<bi; f++) {
        v1.push_back(v[f]);
    }
    for (int f=ei+1; f<v.size(); f++) {
        v3.push_back(v[f]);
    }
    v.clear();
    for (int g=0; g<v1.size(); g++) {
        v.push_back(v1[g]);}
    for (int g=0; g<v2.size(); g++) {
        v.push_back(v2[g]);
    }
    for (int g=0; g<v3.size(); g++) {
        v.push_back(v3[g]);
    }
    for (int g=0; g<v2.size(); g++) {
        if (v2[g]!=vtemp2[g]) {
            return true;
        }
    }
    return false;
}
