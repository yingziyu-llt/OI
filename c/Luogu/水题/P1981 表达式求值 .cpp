#include<stdio.h>
#include<stack>
using namespace std;
stack <int> s;
int flag,end;
long long input()
{
	int a=0;
	char c=getchar();
	while(c>='0'&&c<='9')
	{
		a=a*10+c-'0';
		c=getchar();
	}
	if(c=='+')                 flag=1;
	else if(c=='*')            flag=2;
	else if(c=='\r')           c=getchar();
	else if(c=='\n'||c==EOF)   end=1;
	return a;
}
int main()
{
	long long tmp;
	while(end!=1)
	{
		tmp=input()%10000;
		while(flag==2&&end!=1)
			tmp=tmp*input()%10000;
		s.push(tmp);
	}
	long long ans=0;
	while(!s.empty())
	{
		ans=(ans+s.top())%10000;
		s.pop();	
	}
	printf("%lld",ans);
	return 0;
}
