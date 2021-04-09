#include <iostream>
using namespace std;
int main()
{
	char big[30],small[30];
	int a;
	cout<<"输入要变成大写的句子，结束写入0"<<endl; 
	for(a=0;a<30;a++)
	{
	cin>>small[a];
		if(small[a]=='0')
		{
			small[a]='\0';
			break;
		}
	}
	a=0;
	while(small[a]!='\0')
	{
		big[a]=small[a]-'a'+'A';
		a++;
	}
	a=0;
	while(big[a]!='\0')
	{
		cout<<big[a];
		a++;
	}
} 
