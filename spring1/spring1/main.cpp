#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>

bool merge_num(std::vector<int>& v, int bi, int ei);
void rotate_anti_clock(std::vector<int>& v);
bool game_over(const std::vector<int>& v);
void print_grid(const std::vector<int>& v);
void randomnumber(std::vector<int>& v);

int main(){
    std::vector<int>v;
    std::string c;
    bool check;
    std::ifstream infile;
    std::vector<int>v3;
    std::string name;
    std::cout << "enter the name of the file" << std::endl;
    std::cin >> name;
    
    infile.open(name.c_str());
    int n;
    if (!infile.is_open()){
        std::cout<<"file was not found,so the system would use d start configuration"<<std::endl;
        for (int i=0;i<15;i++){
            v.push_back(0);
        }
        v.push_back(2);
    }
    else {
        while (infile >>n ){
            v.push_back(n);
        }
    }
    int q=std::sqrt(v.size());
    std::vector<int>vc;
    bool t=true;
    print_grid(v);
    do {
        int co=0;
        std::cout<<"please enter a commond "<<std::endl;
        std::cin>>c;
        
        if(c=="w")
        {
            for (int l=0; l<v.size(); l++)
            {
                vc.push_back(v[l]);
            }
            rotate_anti_clock(v);
            for (int n=0; n<q; n++)
            {
                int bi=n*q;
                int ei=bi+q-1;
                merge_num( v, bi, ei);
                
            }
            rotate_anti_clock(v);
            rotate_anti_clock(v);
            rotate_anti_clock(v);
            t=game_over(v);
            for (int f=0; f<v.size(); f++)
            {
                if (vc[f]==v[f])
                {
                    co++;
                }
            }
            if (co!=vc.size())
                {
                    randomnumber(v);
                    print_grid(v);
                }
            vc.clear();
        }
       
        if(c=="a")
        {
            for (int l=0; l<v.size(); l++)
            {
                vc.push_back(v[l]);
            }
            for (int n=0; n<q; n++)
            {
                int bi=n*q;
                int ei=bi+q-1;
                merge_num( v, bi, ei);
            }
            t=game_over(v);
            for (int f=0; f<v.size(); f++)
            {
                if (vc[f]==v[f])
                {
                    co++;
                }
            }
            if (co!=vc.size())
            {
                randomnumber(v);
                print_grid(v);
            }
            vc.clear();
        }
        
        if(c=="s")
        {
            for (int l=0; l<v.size(); l++)
            {
                vc.push_back(v[l]);
            }
            rotate_anti_clock(v);
            rotate_anti_clock(v);
            rotate_anti_clock(v);
            for (int n=0; n<q; n++)
            {
                int bi=n*q;
                int ei=bi+q-1;
                merge_num( v, bi, ei);
            }
            rotate_anti_clock(v);
            t=game_over(v);
            for (int f=0; f<v.size(); f++)
            {
                if (vc[f]==v[f])
                {
                    co++;
                }
            }
            if (co!=vc.size())
            {
                randomnumber(v);
                print_grid(v);
            }
            vc.clear();
        }
        
        if(c=="d")
        {
            for (int l=0; l<v.size(); l++)
            {
                vc.push_back(v[l]);
            }
            rotate_anti_clock(v);
            rotate_anti_clock(v);
            for (int n=0; n<q; n++)
            {
                int bi=n*q;
                int ei=bi+q-1;
                merge_num( v, bi, ei);
            }
            rotate_anti_clock(v);
            rotate_anti_clock(v);
            t=game_over(v);
            for (int f=0; f<v.size(); f++)
            {
                if (vc[f]==v[f])
                {
                    co++;
                }
            }
            if (co!=vc.size())
            {
                randomnumber(v);
                print_grid(v);
                
            }
           vc.clear();
        }
    }
    while(t);
    std::cout<<"game over"<<std::endl;
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
    for (int a=bi; a<=ei; a++)
    {
        v2.push_back(v[a]);
    }//中间抽出来的项
    for (int b=0; b<v2.size(); b++)
    {
        if (v2[b]!=0)
        {
            vtemp.push_back(v2[b]);
        }
        else
        {
            z++;
        }
    }
   vtemp.push_back(0);
    for (int c=0; c<vtemp.size(); c++)
    {
        if (vtemp[c]==vtemp[c+1])
        {
            vtemp2.push_back(vtemp[c]+vtemp[c+1]);
            c++;
            z++;
        }
        else
        {
            vtemp2.push_back(vtemp[c]);
        }
    }
    for (int a=0; a<vtemp2.size(); a++)
    {
        if (vtemp2[a]!=0)
        {
            vtemp3.push_back(vtemp2[a]);
        }
    }
    int m=v2.size()-vtemp3.size();
    for (int d=0; d<m; d++)
    {
        vtemp3.push_back(0);
    }//末尾加0；
    //如果没有一个零;把值给tp2；
    v2.clear();
    for(int e=0;e<vtemp3.size();e++)
        {
            v2.push_back(vtemp3[e]);
        }
    for (int f=0; f<bi; f++)
        {
            v1.push_back(v[f]);
        }
    for (int f=ei+1; f<v.size(); f++)
        {
            v3.push_back(v[f]);
        }
    v.clear();
    for (int g=0; g<v1.size(); g++)
        {
            v.push_back(v1[g]);
        }
    for (int g=0; g<v2.size(); g++)
        {
            v.push_back(v2[g]);
        }
    for (int g=0; g<v3.size(); g++)
        {
            v.push_back(v3[g]);
        }
    for (int g=0; g<v2.size(); g++)
    {
        if (v2[g]!=vtemp3[g])
        {
            return true;
        }
    }
    return false;
}
//一行一列测试及合并
   
void rotate_anti_clock(std::vector<int>& v)
    {
        std::vector <int>v2;
        int n= std::sqrt(v.size());
        for (int i=n-1; i>=0; i--)
        {
            for (int j=i; j<v.size(); j=j+n)
                {
                    v2.push_back(v[j]);
                }
        }
        v.clear();
        for (int a=0 ; a<v2.size(); a++)
            {
                v.push_back(v2[a]);
            }
    }
bool game_over(const std::vector<int>& v)
{
    int size= std::sqrt(v.size());
        bool check=false;
    for (int y=0; y<v.size(); y++) {
        if (v[y]==0) {
            return true;
        }
    }
        for (int p=0; p<v.size(); p=p+size)
        {
            for (int q=0; q<size-1; q++)
            {
                if (v[q]==v[q+1])
                {
                    return true;
                }
            }
        }
        for (int a=0; a<size; a++)
        {
            for (int b=0; b<v.size(); b=b+size)
            {
                if (v[b]==v[b+size])
                {
                    return true;
                }
            }
        }
        return check ;
}

void print_grid(const std::vector<int>& v)
{
    int s= std::sqrt(v.size());
    int t=0 ;
    for (int e=0; e<s; e++)
        {
            for (int r=0; r<s; r++)
            {
                std::cout<<v[t]<<"\t";
                t++;
            }
            std::cout<<std::endl;
        }
}

void randomnumber(std::vector<int>& v)
{
    std::vector<int>v1;
    std::vector<int>v2;
    int b=0;
    int m=0;
    int x=0;
    for (int a=0; a<v.size(); a++)
        {
            if (v[a]==0)
            {
                v1.push_back(a);
            }
        }
    if (v1.size()!=0)
    {
        m=rand()%(v1.size()-1-0+1)+0;
        x=v1[m];
        for (int p=0; p<x; p++)
        {
            v2.push_back(v[p]);
        }
        v2.push_back(2);
        for (int q=x+1; q<v.size(); q++)
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
