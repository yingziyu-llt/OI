#include<stdio.h>
int a[1001];
int main()
{
	int n,i,b=0,x=0,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==a[i-1]) ans++;
		else   ans=1;
		if(x<ans)  {x=ans;}
	}
	printf("%d",x);
	return 0;
}
