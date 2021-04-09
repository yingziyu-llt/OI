#include<stdio.h>
int pell(int a)
{
	if(a==1)
		return 1;
	if(a==2)
		return 2;
	return (pell(a-1)*2+pell(a-2))%32767;
}
int main()
{

	int n,in;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in);
		printf("%d\n",pell(in));
	}
	return 0;
}
