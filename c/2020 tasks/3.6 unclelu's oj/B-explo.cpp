#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int dp[]
int main()
{
	int n,k,c,san;
	freopen("explo.in","r",stdin);
	freopen("explo.out","w",stdout);
	scanf("%d%d%d%d",&n,&k,,&c,&san);
	int knowleage = 0;
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int t,xi;
		scanf("%d%d",&t,&xi);
		if(t == 1)
			ans = max(ans,knowleage + san * xi);

	}
}