#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>

using namespace std;

const int maxn = 15;
const int inf = 1<<20;

int a[maxn][maxn],ans,n,m,d[maxn],c[maxn][3];
int check(int o) {
	return o<=12&&(o%3==0?1:0);
}
void dfs(int stp) {
	if (stp>n) {
		int res=0;
		for (int j=1;j<=m;j++)
		{
			c[j][1]=c[j][2]=c[j][0]=0;
			for (int i=1;i<=n;i++)
			for (int k=0;k<=2;k++)
				c[j][k]+=check(d[i]+a[i][j]+k);
			res+=max(max(c[j][0],c[j][1]),c[j][2]);
		}
		ans=max(ans,res);
		return ;
	}
	for (int i=0;i<=2;i++)
		d[stp]=i,dfs(stp+1);
}
int main()
{
	#ifndef ONLINE_JUDGE
		//freopen("haji.in","r",stdin);
		//freopen("haji.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	dfs(1);printf("%d",ans);
	return 0;
}
