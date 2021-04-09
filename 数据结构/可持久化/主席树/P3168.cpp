#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN = 2e5+10;
struct node
{
	int tim,k,x;
	bool operator < (const node b) const
	{
		return tim < b.tim;
	}
} tsk[MAXN];
int mp[MAXN],n,m;
struct Segment_Tree
{
	int sizv[MAXN * 20],lc[MAXN * 20],rc[MAXN * 20],root[MAXN],cnt;
	long long sumv[MAXN * 20];
	void update(int lst,int &o,int l,int r,int k,int x)
	{
		o = ++cnt;
		sizv[o] = sizv[lst] + x;
		sumv[o] = sumv[lst] + (long long)x * mp[k];
		if(l == r) return ;
		int mid = (l + r) >> 1;
		if(k <= mid) 
			update(lc[lst],lc[o],l,mid,k,x),rc[o] = rc[lst];
		else
			update(rc[lst],rc[o],mid + 1,r,k,x),lc[o] = lc[lst];
		return ;
	}
	long long quary(int o,int l,int r,int k)
	{
		if(sizv[o] <= k)
			return sumv[o];
		if(l == r) 
			return (long long)mp[l] * k;
		int mid = (l + r) >> 1;
		if(k <= sizv[lc[o]])
			return quary(lc[o],l,mid,k);
		return sumv[lc[o]] + quary(rc[o],mid + 1,r,k - sizv[lc[o]]);
	}
}T1;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		mp[i] = z;
		tsk[i * 2 - 1] = (node){x,z,1};
		tsk[i * 2] = (node){y + 1,z, -1};
	}
	sort(tsk + 1,tsk + 1 + n * 2);
	sort(mp + 1,mp + n + 1);
	int tot = unique(mp + 1,mp + n + 1) - mp - 1;
	int lst = 0,now = 0;
	for(int i = 1,j = 1;i <= m;i++)
	{
		while(tsk[j].tim == i)
		{
			T1.update(lst,now,1,tot,lower_bound(mp + 1,mp + 1 + tot,tsk[j].k) - mp,tsk[j].x);
			lst = now;
			j++;
		}
		T1.root[i] = now; 
	}
	long long lstans = 1;
	for(int i = 1;i <= m;i++)
	{
		int x,a,b,c;
		scanf("%d%d%d%d",&x,&a,&b,&c);
		int k = 1 + (lstans * a + b) % c;
		printf("%lld\n",lstans = T1.quary(T1.root[x],1,tot,k));
	}
	return 0;
}