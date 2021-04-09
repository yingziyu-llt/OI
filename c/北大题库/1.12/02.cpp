#include<stdio.h>
int count=0;
int cut(int a)
{
	a-=70;
	count++;
	if(a<=0)
		return 0;
	else cut(a);
}
int main()
{
	int n,i,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		cut(m);
	}
	printf("%.1lf",(double)count*0.1);
	return 0;
}
