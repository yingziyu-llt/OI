#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int s1=0,s2=((1+n)*(1+m)*n*m)/4;
	for(;m>=1&&n>=1;m--,n--)
  		s1+=m*n;
	printf("%d %d",s1,s2-s1);
	return 0;
}
