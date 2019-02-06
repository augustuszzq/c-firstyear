#include<iostream>
#include<string>
int main() 
{
	using namespace std;
	string word;
	char temp;
	int i,j;
	cout<<"Enter a word: ";
	for(j=0,i=word.size()-1;j<i,++j;)//在for循环中 ++j 与 j++ 是否有区别？ 校对！ 
		{
			temp=word[i];
			word[i]=word[j];
			word[j]=temp;
		}
	cout<<word<<endl;
	return 0;
}
