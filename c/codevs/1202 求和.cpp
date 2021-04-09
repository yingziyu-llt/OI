#include<stdio.h>
int n,x[110];
void input()
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	return ;
}
int sumf()
{
	int i;
	int ans=0;
	for(i=0;i<n;i++)
	{
		ans+=x[i];
	}
	return ans;
}
int main()
{
	int ans;
	input();
	ans=sumf();
	printf("%d",ans);
	return 0;
}