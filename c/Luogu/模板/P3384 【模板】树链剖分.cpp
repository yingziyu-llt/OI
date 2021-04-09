#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 110000;
int P,n,w[N],wt[N];
void swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
	return ;
}

//segment tree start
struct segment_tree
{
	int date[N << 2],lazy[N << 2];
	void push_up(int now)
	{
		date[now] = (date[now << 1] + date[now << 1 | 1]) % P;
	}
	void push_down(int now,int l,int r)
	{
		if(lazy[now]){
			int mid = (l + r) >> 1;
			date[now << 1] += lazy[now] * (mid - l + 1);
			date[now << 1] %= P;
			date[now << 1 | 1] += lazy[now] * (r - mid);
			date[now << 1 | 1] %= P;
			lazy[now << 1] += lazy[now];
			lazy[now << 1 | 1] += lazy[now];
			lazy[now] = 0;
		} 
	}
	void build(int now,int l,int r)
	{
		if(l == r)
		{
			date[now] = wt[l];
			date[now] %= P;
			lazy[now] = 0;
			return ;
		}
		int mid = (l + r) >> 1;
		build(now << 1,l,mid);
		build(now << 1 | 1,mid + 1,r);
		push_up(now);
	}
	void change(int now,int l,int r,int x,int y,int c)
	{
		if(x <= l && y >= r)
		{
			date[now] += c * (r - l + 1);
			lazy[now] += c;
			date[now] %= P;
			return ;
		}
		push_down(now,l,r);
		int mid = (l + r) >> 1;
		if(x <= mid)
			change(now << 1,l,mid,x,y,c);
		if(y > mid)
			change(now << 1 | 1,mid + 1,r,x,y,c);
		push_up(now);
		return ;
	}
	int query(int now,int l,int r,int x,int y)
	{
		if(x <= l && y >= r)
			return date[now] % P;
		push_down(now,l,r);
		int mid = (l + r) >> 1;
		int res1 = 0,res2 = 0;
		if(x <= mid)
			res1 = query(now << 1,l,mid,x,y);
		if(y > mid)
			res2 = query(now << 1 | 1,mid + 1,r,x,y);
		return (res1 + res2) % P;
	}
}Tree;
//segment tree end

//edge start
struct Edge
{
	int from,to,nxt;
}e[N << 1];
int edgeHead[N],edgeCnt;
void addEdge(int from,int to)
{
	edgeCnt++;
	e[edgeCnt].from   = from;
	e[edgeCnt].to     = to;
	e[edgeCnt].nxt    = edgeHead[from];
	edgeHead[from] = edgeCnt;
}
//edge end

//树剖 start
int son[N],fa[N],depth[N],mson[N];
/*void getSonNum(int now,int father,int dep)
{
	fa[now] = father;
	son[now] = 1;
	depth[now] = dep;
	for(int i = edgeHead[now];i;i = e[i].nxt)
	{
		if(e[i].to == father) continue;
		getSonNum(e[i].to,now,dep + 1);
		son[now] += son[e[i].to];
		if(son[mson[now]] < son[e[i].to])
			mson[now] = e[i].to;
	}
}*/
void getSonNum(int now,int father,int dep)
{
	son[now] = 1;
	depth[now] = dep;
	fa[now] = father;
	for(int i = edgeHead[now];i;i = e[i].nxt)
	{
		if(e[i].to == father)
			continue;
		getSonNum(e[i].to,now,dep + 1);
		son[now] += son[e[i].to];
		if(son[mson[now]] < son[e[i].to])
			mson[now] = e[i].to;
	}
}
int top[N],id[N],idCnt;
void getLine(int now,int father)
{
	id[now] = ++idCnt;
	wt[idCnt] = w[now];//把每个点的初始值赋到新编号上来 
	if(top[now] == 0)
		top[now] = now;
	if(mson[now] == 0)
		return ;
	top[mson[now]] = top[now];
	getLine(mson[now],now);
	for(int i = edgeHead[now];i;i = e[i].nxt)
	{
		if(e[i].to == father || e[i].to == mson[now])
			continue;
		getLine(e[i].to,now);
	}
}
/************************************/
int queryRange(int a,int b)
{
	int ans = 0;
	while(top[a] != top[b])
	{
		if(depth[top[a]] < depth[top[b]]) swap(a,b);
		int res = Tree.query(1,1,n,id[top[a]],id[a]);
		ans += res;
		ans %= P;
		a = fa[top[a]];
	}
	if(depth[a] < depth[b]) swap(a,b);
	ans += Tree.query(1,1,n,id[b],id[a]);
	return ans % P;
}

void changeRange(int a,int b,int c)
{
	c %= P;
	while(top[a] != top[b])
	{
		if(depth[top[a]] < depth[top[b]]) swap(a,b);
		Tree.change(1,1,n,id[top[a]],id[a],c);
		a = fa[top[a]];
	}
	if(depth[a] < depth[b]) swap(a,b);
	Tree.change(1,1,n,id[b],id[a],c);
	return ;
}

int querySon(int a)
{
	int res = Tree.query(1,1,n,id[a],id[a] + son[a] - 1);
	return res % P;
}

void changeSon(int a,int c)
{
	Tree.change(1,1,n,id[a],id[a] + son[a] - 1,c);
}
//树剖 end
int main()
{
	int m,root;
	scanf("%d%d%d%d",&n,&m,&root,&P);
	for(int i = 1;i <= n;i++)
		scanf("%d", &w[i]);
	for(int i = 1;i < n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addEdge(x,y);
		addEdge(y,x);
	}
	getSonNum(root,0,1);
	getLine(root,root);
	Tree.build(1,1,n);
	for(int i = 0;i < m;i++)
	{
		int k;
		scanf("%d",&k);
		if(k == 1)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			changeRange(x,y,z);
		}
		if(k == 2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int ans = queryRange(x,y);
			printf("%d\n",ans);
		}
		if(k == 3)
		{
			int x,z;
			scanf("%d%d",&x,&z);
			changeSon(x,z);
		}
		if(k == 4)
		{
			int x;
			scanf("%d",&x);
			int ans = querySon(x);
			printf("%d\n",ans);
		}
	}
	return 0;
}