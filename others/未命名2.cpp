#include<iostream>
int main(){
		int a,b;
		std::cout<<"please enter two number:"<<std::endl;
		std::cin>>a>>b;
	
	
	
		int quotient=a/b;
		int remainder=a%b;
		int c,d;
			
			c=a/b;
			d=a%b;
		std::cout<<"division:"<<c<<std::endl;
		std::cout<<"remainder:"<<d<<std::endl;
	
			if (d==0)
				std::cout<<"their are perfect number";
			else
				std::cout<<"their are not perfect number";
		
	return 0;
		
		
	
	
	
	
	
	
	
	
	
} 
