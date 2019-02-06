#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<ctime>

bool merge_num(std::vector<int>& v, int bi, int ei);
void rotate_anti_clock(std::vector<int>& v);
void rotate_clock(std::vector<int>& v);
bool game_over(const std::vector<int>& v);
void print_grid(const std::vector<int>& v);
int xytoi(int x, int y, int rowlen);
void random(std::vector<int>& v);

int main(){
    std::vector<int> in;
    std::ifstream infile;
    std::string filename;
    std::cout<<"enter initial configuration file name: "<<std::endl;
    std::cin>>filename;
    infile.open(filename.c_str());
    if(!infile.is_open()){
        std::cout<<"file not found, using default start configuration"<<std::endl;
        for(int i=0;i<15;i++){
            in.push_back(0);
        }
        in.push_back(2);
    }
    else{
        int n;
        while(infile>>n){
            in.push_back(n);
        }
    }
    print_grid(in);
    
    int win=1;
    std::string direction;
    int r=std::sqrt(in.size());
    while(win==1){
        
        std::cin>>direction;
        if(direction=="w"){
            int j=0;
            rotate_anti_clock(in);
            for(int i=0;i<r;i++){
                if(merge_num(in, i*r, (r*(i+1)))){
                    j=1;
                }
            }
            rotate_anti_clock(in);
            rotate_anti_clock(in);
            rotate_anti_clock(in);
            if(j==1){
                random(in);
                print_grid(in);
                std::cout<<std::endl;
            }
        }
        if(direction=="a"){
            int j=0;
            for(int i=0;i<r;i++){
                if(merge_num(in, r*i, (r*(i+1)))){
                    j=1;
                }
            }
            if(j==1){
                random(in);
                print_grid(in);
                std::cout<<std::endl;
            }
        }
        if(direction=="s"){
            rotate_anti_clock(in);
            rotate_anti_clock(in);
            rotate_anti_clock(in);
            int j=0;
            for(int i=0;i<r;i++){
                if(merge_num(in, r*i, (r*(i+1)))){
                    j=1;
                }
            }
            rotate_anti_clock(in);
            if(j==1){
                random(in);
                print_grid(in);
                std::cout<<std::endl;
            }
        }
        if(direction=="d"){
            rotate_anti_clock(in);
            rotate_anti_clock(in);
            int j=0;
            for(int i=0;i<r;i++){
                if(merge_num(in, r*i, (r*(i+1)))){
                    j=1;
                }
            }
            rotate_anti_clock(in);
            rotate_anti_clock(in);
            if(j==1){
                random(in);
                print_grid(in);
                std::cout<<std::endl;
            }
        }
        
        if(game_over(in)){
            print_grid(in);
            std::cout<<"game over"<<std::endl;
            win=0;
        }
        else{
            win=1;
        }
    }
}

int xytoi(int x, int y, int rowlen){
    return x*rowlen+y;
}

bool merge_num(std::vector<int>& v, int bi, int ei){
    std::vector<int> select;
    std::vector<int> out;
    int z=0;
    for(int i=0;i<(ei-bi);i++){
        if(v[bi+i]!=0){
            select.push_back(v[bi+i]);
        }
    }
    select.push_back(3);
    for(int j=0;j<bi;j++){
        out.push_back(v[j]);
    }
    for(int k=0;k<select.size()-1;k++){
        if(select[k]==select[k+1]){
            out.push_back(select[k]+select[k+1]);
            k++;
            z++;
        }
        else{
            out.push_back(select[k]);
        }
    }
    for(int l=0;l<(ei-bi-select.size()+z+1);l++){
        out.push_back(0);
    }
    for(int m=0;m<(v.size()-ei);m++){
        out.push_back(v[ei+m]);
    }
    int p=0;
    for(int n=0;n<out.size();n++){
        if(v[n]!=out[n]){
            p=1;
        }
    }
    if(p==1){
        v.clear();
        for(int i=0;i<out.size();i++){
            v.push_back(out[i]);
        }
        return true;
    }
    else{
        return false;
    }
}

void rotate_anti_clock(std::vector<int>& v){
    std::vector<int> out;
    int r=std::sqrt(v.size());
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            out.push_back(v[xytoi(j,(r-i-1),r)]);
        }
    }
    v.clear();
    for(int k=0;k<out.size();k++){
        v.push_back(out[k]);
    }
}

bool game_over(const std::vector<int>& v){
    std::vector<int> out;
    for(int l=0;l<v.size();l++){
        out.push_back(v[l]);
    }
    int r=std::sqrt(out.size());
    int a=0;
    for(int i=0;i<r;i++){
        if(merge_num(out,(i*r),((i+1)*r))){
            a++;
        }
    }
    rotate_anti_clock(out);
    for(int j=0;j<r;j++){
        if(merge_num(out,(j*r),((j+1)*r))){
            a++;
        }
    }
    rotate_anti_clock(out);
    for(int k=0;k<r;k++){
        if(merge_num(out,(k*r),((k+1)*r))){
            a++;
        }
    }
    rotate_anti_clock(out);
    for(int l=0;l<r;l++){
        if(merge_num(out,(l*r),((l+1)*r))){
            a++;
        }
    }
    if(a==0){
        return true;
    }
    else{
        return false;
    }
}

void print_grid(const std::vector<int>& v){
    int r=std::sqrt(v.size());
    for(int i=0;i<r;i++){
        for(int j=0;j<r;j++){
            std::cout<<v[xytoi(i,j,r)]<<"\t";
        }
        std::cout<<std::endl;
    }
}

void random(std::vector<int>& v)
{
    std::vector<int>v1;
    std::vector<int>v2;
    int y=0;
    int z=0;
    for (int a=0; a<v.size(); a++)
    {
        if (v[a]==0)
        {
            v1.push_back(a);
        }
    }
    if (v1.size()!=0)
    {
        y=rand()%(v1.size());
        z=v1[y];
        for (int p=0; p<z; p++)
        {
            v2.push_back(v[p]);
        }
        v2.push_back(2);
        for (int q=z+1; q<v.size(); q++)
        {
            v2.push_back(v[q]);
        }
        v.clear();
        for (int r=0; r<v2.size(); r++)
        {
            v.push_back(v2[r]);
        }
    }
    
}
