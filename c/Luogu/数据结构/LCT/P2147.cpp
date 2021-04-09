#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;
const int N = 11000,M = 210000;
stack <int> sta;
struct LCT
{
	int c[N][2],fa[N],siz[N];
	bool rev[N];
	void reverse(int x)
	{
		if(!x) return ;
		rev[x] ^= 1;
		swap(c[x][0],c[x][1]);
		return ;
	}
	void push_down(int x)
	{
		if(rev[x])
		{
			reverse(c[x][0]);
			reverse(c[x][1]);
			rev[x] = 0;
		}
		return ;
	}
	bool isroot(int x)
	{
		if(c[fa[x]][1] == x || c[fa[x]][0] == x) return false;
		else return true;
	}
	void rotate(int &x)
	{
		int y = fa[x],z = fa[y],dy = c[y][1] == x,dz = c[z][1] == y;
		if(!isroot(y)) c[z][dz] = x;
		c[y][dy] = c[x][dy ^ 1];
		fa[c[y][dy]] = y;
		c[x][dy ^ 1] = y;
		fa[y] = x;
		fa[x] = z;
		return ;
	}
	void splay(int &x)
	{
		sta.push(x);
		int i = x;
		while(!isroot(i))
		{
			sta.push(fa[i]);
			i = fa[i];
		}
		while(!sta.empty())
		{
			push_down(sta.top());
			sta.pop();
		}

		while(!isroot(x))
		{
			int y = fa[x],z = fa[y];
			if(!isroot(y))
			{
				if((c[y][0] == x) ^ (c[z][0] == y)) rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
		return ;
	}
	void access(int o)
	{
		for(int i = 0;o;i = o,o = fa[o])
		{
			splay(o);
			c[o][1] = i;
		}
		return ;
	}
	void makeroot(int o)
	{
		access(o);
		splay(o);
		reverse(o);
	} 
	int findroot(int o)
	{
		access(o);
		splay(o);
		while(c[o][0])
			o = c[o][0];
		return o;
	}
	void link(int x,int y)
	{
		makeroot(x);
		fa[x] = y;
		return ;
	}
	void cut(int x,int y)
	{
		makeroot(x);
		access(y);
		splay(y);
		c[y][0] = fa[x] = 0;
		return ;
	}
}T1;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		char t1[100];
		int t2,t3;
		scanf("%s",t1);
		scanf("%d%d",&t2,&t3);
		if(t1[0] == 'Q')
		{
			printf("%s\n",T1.findroot(t2) == T1.findroot(t3) ? "Yes" : "No");
		}
		else if(t1[0] == 'C')
			T1.link(t2,t3);
		else
			T1.cut(t2,t3);
	}
	return 0;
}