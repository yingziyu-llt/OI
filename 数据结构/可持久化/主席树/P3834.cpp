#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 210000;
//persistent_segment_tree可持久化线段树
int root[N];
int pointCnt = 0;
struct point
{
	int num, lson, rson, size;
} date[N << 5];
int build(int l, int r)
{
	int nowPointCnt = ++pointCnt;
	if (l == r)
	{
		date[nowPointCnt].lson = date[nowPointCnt].rson = -1;
		date[nowPointCnt].num = 0;
		date[nowPointCnt].size = 1;
		return nowPointCnt;
	}
	date[nowPointCnt].lson = build(l, (l + r) >> 1);
	date[nowPointCnt].rson = build(((l + r) >> 1) + 1, r);
	date[nowPointCnt].num = 0;
	date[nowPointCnt].size = date[date[nowPointCnt].rson].size + date[date[nowPointCnt].lson].size;
	return nowPointCnt;
}
int add(int l, int r, int n, int pre)
{
	int nowPointCnt = ++pointCnt;
	date[nowPointCnt] = date[pre];
	date[nowPointCnt].size++;
	if (l < r)
	{
		int mid = (l + r) >> 1;
		if (n > mid)
			date[nowPointCnt].rson = add(mid + 1, r, n, date[pre].rson);
		else
			date[nowPointCnt].lson = add(l, mid, n, date[pre].lson);
	}
	return nowPointCnt;
}
int query(int l, int r, int from, int to, int k)
{
	if (l == r)
		return l;
	int tmp = date[date[to].lson].size - date[date[from].lson].size;
	int mid = (l + r) >> 1;
	if (k > tmp)
		return query(mid + 1, r, date[from].rson, date[to].rson, k);
	else
		return query(l, mid, date[from].lson, date[to].lson, k);
}
int a[N],b[N],reb[N];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	sort(a + 1,a + n + 1);
	int cnt = 0;
	for(int i = 1;i <= n;i++)
		if(a[i] != a[i - 1])
			b[a[i]] = ++ cnt,reb[cnt] = a[i];
	root[0] = build(1,n);
	for(int i = 1;i <= n;i++)
		root[i] = add(1,n,b[a[i]],root[i - 1]);
	for(int i = 1;i <= m;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",reb[query(1,n,root[l],root[r],k)]);
	}
	return 0;
}