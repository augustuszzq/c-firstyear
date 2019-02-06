#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
int randn(int n);
void set_random_seed();
void check(int &m ,std::vector<int>v,int i,int k);
int main(int argc, const char * argv[]) {
    set_random_seed();
    int k=4;
    
    int i=0;
    std::vector<int>v;
    for (int i=0; i<4; i++) {
        if (i=0) {
            int m=randn(k);
            v.push_back(m);
        }
        else{
            int m=randn(k);
            //check(m, v, 0, k);
            v.push_back(m);
        }
    }
    for (int p=0; p<v.size(); p++) {
        std::cout<<v[p]<<std::endl;
    }

    return 0;
}
void check(int &m ,std::vector<int>v,int i,int k){
    if((v[i]==m)&&(i<v.size())){
        m=randn(k);
        return check(m, v, 0,k);
    }
    if((v[i]!=m)&&(i<v.size()))
    {
        return check(m, v, i+1,k);
    }
    else
    {
        m=m;
    }
}
void set_random_seed(){
    std::srand(std::time(0));
}

int randn(int n){
    return std::rand() % n;
}

