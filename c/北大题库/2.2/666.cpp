#include<stdio.h>
int aa[10001];
int putf(int a,int b)
{
	if(a==1||b==1)
	{
		if(aa[a]==0) aa[a]=1;
		return aa[a];
	}
	if(a<b)
	{
		if(aa[a]==0) aa[a]=putf(a,a);
		return aa[a];
	}
		if(aa[a]==0) aa[a]=putf(a,b-1)+putf(a-b,b);
		return aa[a];
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int m,n,x,i;
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		scanf("%d %d",&m,&n);
		printf("%d\n",putf(m,n));
	}
	return 0;
}
