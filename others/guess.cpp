#include<iostream>
int  main(int argc, char const *argv[])
 {
   using namespace std;
   int n,a,b;
   string f;
   cout<<"please enter two boundries: "<<endl;
   cin>>a>>b;

   n=(a+b)/2;
   cout<<n<<endl;
   cout<<"l or s or y "<<endl;
   cin>>f;
   do
      {
          n=(a+b)/2;
		  cout<<n<<endl;
          cout<<"l or s or y "<<endl;
          cin>>f;
            if (f== "l")
              {
                 b=n;
              }
            else
              {
                 a=n; 
			  }
      } while(f!="y");

     if (f=="y")
    {
      cout<<"well done!"<<endl;  /* code */
    }
      return 0;

    }
