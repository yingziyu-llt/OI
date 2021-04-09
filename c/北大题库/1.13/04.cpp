#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char a[20],ansx[100];
int main()
{
	long long tmp=8;
	double ans=0;
	int i,L;
	scanf("%s",a);
	L=strlen(a);
	for(i=2;i<L;i++)
	{
		ans+=(double)(a[i]-'0')/(double)tmp;
		tmp*=8;
	}
 printf("%s [8] = %.45g [10]",a,ans);
	return 0;
}
