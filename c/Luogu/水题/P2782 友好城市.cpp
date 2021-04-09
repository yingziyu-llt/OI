#include<algorithm>
#include<stdio.h>
#include<string.h>
#define INF 0x3f
using namespace std;
const int N = 210000;

int g[N],f[N];
struct line
{
	int from,to;
}a[N];

int cmp(int a,int b,int k)
{
	if(k == 1) return a >= b;
	return a < b;
}
int search(int l,int r,int val,int k)
{
	while (l < r)
	{
		int mid = (l + r) >> 1; 
		if(cmp(g[mid],val,k)) l = mid + 1;
		else r = mid;
	}
	return l;
}

bool cmp(line a,line b)
{
	if(a.from != b.from) return a.from < b.from;
	return a.to < b.to;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d %d",a[i].from,a[i].to);
	sort(a + 1,a + n + 1,cmp);
	memset(g,-0x7f,sizeof(g));
	int ans = -1;
	for(int i = 1;i <= n;i++)
	{
		f[i] = search(1,i,a[i].to,1);
		g[f[i]] = max(g[f[i]],a[i].to);
		if(f[i] > ans) ans = f[i];
	}
	printf("%d\n",ans);
	return 0;
}