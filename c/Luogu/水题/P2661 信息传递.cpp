#include<stdio.h>
#include<algorithm>
using namespace std;
int fa[210000];
int ans[210000];
int findfather(int x)
{
	if(fa[x] != x)
	{
        int o = fa[x];
        fa[x] = findfather(fa[x]);
        ans[x] += ans[o];
    }
	return fa[x];
}
int main()
{
	int n;
	int minm = 210000;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		fa[i] = i;
	for(int i = 1; i <= n;i++)
	{
		int t;
		scanf("%d",&t);
		int a = findfather(i),b = findfather(t);
		if(a != b)
		{
			fa[a] = b;
			ans[i] = ans[t] + 1;
		}
		else
			minm = min(minm,ans[t] + 1 + ans[i]);
	}
	printf("%d",minm);
	return 0;
}