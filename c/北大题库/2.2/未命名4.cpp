#include<stdio.h>
int aa[10000];
int f(int a,int b)
{
	if(a==1) return 1;
	if(b==1) return 0;
	if(a%b==0) return f(a/b,b)+f(a,b-1);
	return f(a,b-1);
}
int main()
{
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",f(a,a));
	}
	return 0;
}
