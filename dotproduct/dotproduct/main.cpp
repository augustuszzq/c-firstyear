
#include <iostream>
#define N 10
void dotproduct(data_t x[N],data_t y[N],data_t *output);
int main(){
    int x[N];
    int y[N];
    for (int i=0; i<N; i++) {
        x[i]=1;
        y[i]=1;
    }
    int z=0;
    dotproduct(x,y,z);
    std::cout<<z<<std::endl;
    return 0;
}

