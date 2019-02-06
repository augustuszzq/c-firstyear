#include<iostream>
#include<string>
int main(int argc, char const *argv[])
{
    using namespace std;
    int n,i,j,k=0;
    cout<<"please enter a number or a integer:"<<endl;
    cin>>n;
  
	for (i=1; i<=n; i++)
 		{
  			for(j=1; j<=n; j++)
    			{
      				
      				if(i<=j)
					  {
					  	cout<<i*j<<" ";
					  }
					else
					  {
					  	cout<<"  ";
					  }
    			}
    		cout<<endl;
		}
	return 0;
}











