#include<stdio.h>
int map[1000000];
int n,sum;
int dfs(int k)
{
	if(map[k]!=0) return map[k];
	if(k==0)      return 1;
	if(k==1)      return 1;
	int ans=0;
	for(int i=1;i<=sum;i++)
	{
		if(k-i>=0)  ans=(dfs(k-i)+ans)%100003;
	}
	map[k]=ans;
	return ans;
} 
int main()
{
	scanf("%d %d",&n,&sum);
	map[0]=map[1]=1;
	printf("%d",dfs(n));
	return 0;
}
