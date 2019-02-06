#include<iostream>
#include<string>
#include<vector>
void v_union();
void v_intersection();
void v_subset();
std::vector<double> v1;
std::vector<double> v2;
std::vector<double> v3;
std::vector<double> v4;
int main(int argc, char const *argv[]) {
std::string another="y";
std::vector<double>v1;
double y;
std；：string p;
do {
  std::cout << "please enter a number " <<std::endl;
  std::cin >> y;
  std::cout << "1/2/s" <<endl;
  std::cin >> p;
  while(p==1)
  {v1.push_back(y);}
  while (p==2)
   {v2.puch_back(y);}
} while(p!=s ）
  vin=v2;
  v_union(v1,v2);
  v_intersection(v1,v2);
  v_subset(v1,v2);
  std::cout<< "the union of two vectors are: " << v1;
  std::cout<<"the intersection of two vectors are:"<<v1;
  std::cout << "the subset of two vectors are" <<v1;




  return 0;
}
  void v_union(std::vector<double>vin,double t,std::vector<double>&vout)
  {
    for (int i=0;i<vin.size();i++)
      {
        for (int k= 0; k<v1.size(); i++)
          {
            if (vin[i]!=v1[k])
              {
                vout.puck_back(v1[i]);
              }
          }
      }
    };
  void v_intersection(std::vector<double>vin,double t,std::vector<double>&vout)
  {
    for (int i=0;i<vin.size();i++)
    {
      for(int k=v1.size()-1;k=k-1,k>=0)
        if (vin[i]==v1[k])
          {
            vout.pop_back();
          }


    }
  };
  void v_subset(std::vector<double>vin,double t,std::vector<double>&vout)
  {
    int i=0,i<vin.size();
    int k=0,k<v1.size();
    int m=0;
      do
      {
        if (vin[i]==v1[k])
         {
            m++;
            i++;
            k++;
         } while(i<=vin.size());
      }
     if (m==i) {
       std::cout << "v1 is the subset of v2 " << '\n';
     }
