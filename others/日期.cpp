#include<iostream>
	int main()
{
		int date,month,year,date1,month1,year1; 
			std::cout<<"please enter the date:"<<std::endl;
			std::cin>>date;
			std::cout<<"please enter the month:"<<std::endl;
			std::cin>>month;
			std::cout<<"please enter the year:"<<std::endl;
			std::cin>>year;	
			if (month==12,date==31)
				{
				year1=year+1;
				month1=1;
				date1=1;
				}
				else
	        	{
					date1=date+1;
					month1=month;
					year1=year;
					 
		
				}			
					if(month==1,3,5,7,8,10,date==31){
					
					std::cout<<"the following date is:"<<"1"<<month1<<yea1r<<std::endl;}
					
					else(month==2,4,6,9,11,date==30){
					
					std::cout<<"the following date is:"<<"1 "<<month1 <<year1 <<std::endl;}
					
			        else(month==1,2,3,4,5,6,7,8,9,10,11,12){
				
					date1=date+1,yea1r=year,month1=month;
					std::cout<<"the following date is:"<<date1 <<month1 <<year1 <<std::endl;}
					
			return 0;
	
	} 
