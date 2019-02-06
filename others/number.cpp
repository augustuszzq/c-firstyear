#include <iostream>


int main(){
    int n1,n2;
    std::cout<<"please enter two integer numbers:"std::endl;
    std:: cin>>n1>>n2;

    int quotient=n1/n2;
    int remainder=n1%n2;

    std::cout<<"interger division"<<n1<<"/"<<n2<<std::endl;
    std::cout<<"the quotient:"<<quotient<< std::endl;
    std::cout<<"the remainder:"<<remainder<<std::endl;

    return 0;





}
