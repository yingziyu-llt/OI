#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN = 110000;
struct Splay
{
	int c[2],fa,siz;
	bool rev;
}a[MAXN];
int n,m,root;
void push_up(int o)
{
	a[o].siz = a[a[o].c[0]].siz + a[a[o].c[1]].siz + 1;
}
void reverse(int o)
{
	if(o)
	{
		swap(a[o].c[0],a[o].c[1]);
		a[o].rev ^= 1;
	}
}
void push_down(int o)
{
	if(a[o].rev)
	{
		reverse(a[o].c[0]);
		reverse(a[o].c[1]);
		a[o].rev = false;
	}
}
void rotate(int &o,int x)
{
	int y = a[x].fa,z = a[y].fa,dy = a[y].c[1] == x,dz = a[z].c[1] == y;
	push_down(y);
	if(o == y) o = x;
	else a[z].c[dz] = x;
	a[x].fa = z;
	a[y].c[dy] = a[x].c[dy ^ 1];
	a[a[y].c[dy]].fa = y;
	a[x].c[dy ^ 1] = y;
	a[y].fa = x;
	push_up(y);
	return ;
}
void splay(int &o,int x)
{
	push_down(x);
	while(o != x)
	{
		int y = a[x].fa,z = a[y].fa;
		if(y != o)
		{
			if(a[y].c[1] == x ^ a[z].c[1] == y)
				rotate(o,x);
			else
				rotate(o,y);
		}
		rotate(o,x);
	}
	push_up(x);
}
int find(int o,int v)
{
	push_down(o);
	if(v <= a[a[o].c[0]].siz) return find(a[o].c[0],v);
	if(v <= a[a[o].c[0]].siz + 1) return o;
	return find(a[o].c[1],v - a[a[o].c[0]].siz - 1);
}
void print(int o)
{
	if(!o) return ;
	push_down(o);
	print(a[o].c[0]);
	if(o > 1 && o < n + 2) printf("%d ",o - 1);
	print(a[o].c[1]);
}
int main()
{
	scanf("%d%d",&n,&m);
	a[1].siz = n + 2,a[1].c[1] = 2;
	a[n + 2].siz = 1,a[n + 2].fa = n + 1;
	for(int i = 1;i <= n;i++)
		a[i + 1] = (Splay){{0,i + 2},i,n + 2 - i,false};
	root = 1;
	for(int i = 1;i <= m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		r += 2;
		l = find(root,l),r = find(root,r);
		splay(root,r);splay(a[root].c[0],l);
		reverse(a[l].c[1]);
	}
	print(root);
	printf("\n");
	return 0;
}