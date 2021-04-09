#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define ll long long
#define INF 0x3fffff
#define clr(x) memset(x,0,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

#define M 500005

struct tree2
{
	tree2 *lson,*rson;
	int x;
}dizhi[M<<1],*root=&dizhi[0];

int n,m,t=1,a[M];

void bulid(tree2 *tree,int l,int r)
{
	if(l==r)
	{
		tree->x=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	tree->lson=&dizhi[t++];
	tree->rson=&dizhi[t++];
	bulid(tree->lson,l,mid);
	bulid(tree->rson,mid+1,r);
	tree->x=tree->lson->x+tree->rson->x;
}

void change(tree2 *tree,int l,int r,int x,int y)
{
	if(l==r)
	{
		tree->x+=y;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid)change(tree->lson,l,mid,x,y);
	else change(tree->rson,mid+1,r,x,y);
	tree->x=tree->lson->x+tree->rson->x;
}

ll query(tree2 *tree,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
		return tree->x;
	int mid=(l+r)>>1;
	ll t1=0,t2=0;
	if(x<=mid)t1=query(tree->lson,l,mid,x,y);
	if(y>mid)t2=query(tree->rson,mid+1,r,x,y);
	return t1+t2;
}

int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	bulid(root,1,n);
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		if(a==1)change(root,1,n,b,c);
		else printf("%lld\n",query(root,1,n,b,c));
	}
	return 0;
}
