#include<bits/stdc++.h>
using namespace std;
int findGCD(int a,int b)
{
	int c,tmp;
	if(a<b) swap(a,b);
	do
	{
		c=a%b;
		a=b;
		b=c;
	}while(c!=0);
	return a;
}
int main()
{
	int a,b,i,GCD;
	scanf("%d %d",&a,&b);
	GCD=findGCD(a,b);
	printf("%d",GCD);
	return 0;
}
