#include<stdio.h>
#include<algorithm>
#include<string.h>
#define lson root<<1
#define rson root<<1|1
using namespace std;
const int N = 200000;
int a[200000][2];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-')f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+ch-'0'; ch=getchar(); }
	return x*f;
}
struct Segment_tree
{
	bool f[N << 2][2][2];
	void push_up(int root,int l,int r)
	{
		int mid = (l + r) / 2;
		for(int i = 0;i < 2;i++)
			for(int j = 0;j < 2;j++)
			{
				f[root][i][j] = false;
				for(int k = 0;k < 2;k++)
					for(int l = 0;l < 2;l++)
						f[root][i][j] |= f[lson][i][k] && f[rson][l][j] && (a[mid][k] <= a[mid + 1][l]);
			}
	}
	void build(int root,int l,int r)
	{
		if(l == r)
		{
			f[root][0][0] = f[root][1][1] = true;
			return ;
		}
		int mid = (l + r) / 2;
		build(lson,l,mid);
		build(rson,mid + 1,r);
		push_up(root,l,r);
		return;
	}
	void change(int root,int l,int r,int k)
	{
		if(l == r)
		{
			f[root][0][0] = f[root][1][1] = true;
			return ;
		}
		int mid = (l + r) / 2;
		if(k <= mid) change(lson,l,mid,k);
		else change(rson,mid + 1,r,k);
		push_up(root,l,r);
	}
}Tree;
int main()
{
	int n = 0;
	n = read();
	for(int i = 1;i <= n;i++)
		a[i][0] = read(),a[i][1] = read();
	Tree.build(1,1,n);
	int m;
	scanf("%d",&m);
	for(int i = 0;i < m;i++)
	{
		int x,y;
		x = read(),y = read();
		swap(a[x],a[y]);
		Tree.change(1,1,n,x);
		Tree.change(1,1,n,y);
		if(Tree.f[1][0][0] || Tree.f[1][1][0] || Tree.f[1][1][1]||Tree.f[1][0][1])
			printf("TAK\n");
		else
			printf("NIE\n");
	}
	return 0;
}