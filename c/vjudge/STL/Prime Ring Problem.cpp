#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int n,a[10010];
bool isp[10010],vis[10010];
void dfs(int i)
{
	if(i == n)
	{
		for(int j = 1;j <= n;j++)
		{
			if(!vis[j])
			{
				if(isp[j + a[i - 1]] && isp[j + a[1]])
				{
					a[i] = j;
					for(int k = 1;k < n;k++)
						printf("%d ",a[k]);
					printf("%d\n",a[n]);
				}
				return ;
			}
		}
	}
	int ok = 1;
	for(int j = 1;j <= n;j++)
	{
		if(isp[j + a[i - 1]] && !vis[j])
		{
			a[i] = j;
			vis[j] = true;
			dfs(i + 1);
			vis[j] = false;
		}
	}
	return ;
}
int main()
{
	//freopen("tmp.txt","w",stdout);
	int T = 0;
	while(~scanf("%d",&n))
	{
		T++;
		memset(a,0,sizeof(a));
		memset(isp,1,sizeof(isp));
		memset(vis,0,sizeof(vis));
		if(T != 0) printf("\n");
		cout << "Case " << T << ":" << endl;
		for(int i = 2;i <= n;i++)
		{
			for(int j = 2;i *j <= n * 2;j++)
			{
				isp[i * j] = false;
			}
		}
		vis[1] = true;
		a[1] = 1;
		dfs(2);
	}
}