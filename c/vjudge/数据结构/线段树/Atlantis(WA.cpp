//扫描线
//POJ 1151 / HDU 1542
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
const int N = 110;
double b[N << 1];
map < double,int> mp;
struct node
{
	double x,y1,y2;
	int s;
	bool operator <(const node b) const
	{
		return x < b.x;
	}
}a[N << 1];

struct segment_tree
{
	int cnt[N << 3];
	double len[N << 3],lf[N << 3],rf[N << 3];
	void push_up(int root,int l,int r)
	{
		if(cnt[root])
		{
			len[root] = rf[root] - lf[root];
		}
		else if(l + 1 == r)
		{
			len[root] = 0;
		}
		else
		{
			len[root] = len[root << 1] + len[root << 1 + 1];
		}
		return ;
	}
	void build(int root,int l,int r)
	{
		if(l + 1 == r)
		{
			lf[root] = b[l];
			rf[root] = b[r];
			return ;
		} 
		int mid = (l + r) >> 1;
		build(root << 1,l,mid);
		build(root << 1 | 1,mid,r);
		lf[root] = lf[root << 1];
		rf[root] = rf[root << 1 | 1];
		return ;
	}
	void update(int root,int l,int r,int x,int y,int k)
	{
		if(x <= l && r <= y)
		{
			cnt[root] += k;
			push_up(root,l,r);
			return ;
		}
		int mid = (l + r) >> 1;
		if(x < mid) update(root << 1,l,mid,x,y,k);
		if(y > mid) update(root >> 1 | 1,mid,r,x,y,k);
		push_up(root,l,r);
		return ;
	}
}Tree;

int main()
{
	int T = 0;
	while(++T)
	{
		int n = 0,tot = 0;
		double ans = 0;
		scanf("%d",&n);
		if(!n) break;
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i++)
		{
			double x1,y1,x2,y2;
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			a[i * 2 - 1] = (node){x1,y1,y2,1};
			a[i * 2] = (node){x2,y1,y2,-1};
			b[++tot] = y1;
			b[++tot] = y2;
		}
		sort(a + 1,a + n * 2 + 1);
		sort(b + 1,b + n * 2 + 1);
		tot = unique(b + 1,b + n * 2 + 1) - b - 1;
		for(int i = 1;i <= tot;i++)
			mp[b[i]] = i;
		Tree.build(1,1,tot);
		Tree.update(1,1,tot,mp[a[1].y1],mp[a[1].y2],a[1].s);
		for(int i = 2;i <= n * 2;i++)
		{
			ans += Tree.len[1] * (a[i].x - a[i - 1].x);
			Tree.update(1,1,tot,mp[a[i].y1],mp[a[i].y2],a[i].s);
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n",T,ans);
	}
	return 0;
}