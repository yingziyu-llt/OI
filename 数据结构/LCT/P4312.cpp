#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;
stack <int> sta;
const int N = 3e4 + 10;
struct LCT
{
	int c[N][2],fa[N],val[N],sum[N];
	bool rev[N];
	void push_up(int o)
	{
		sum[o] = sum[c[o][0]] + sum[c[o][1]] + val[o];
		return ;
	}
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
	bool is_root(int o)
	{
		return c[fa[o]][0] != o && c[fa[o]][1] != o;
	}
	void rotate(int &x)
	{
		int y = fa[x],z = fa[y],dy = c[y][1] == x,dz = c[z][1] == y;
		if(!is_root(y)) c[z][dz] = x;
		c[y][dy] = c[x][dy ^ 1];
		fa[c[y][dy]] = y;
		c[x][dy ^ 1] = y;
		fa[y] = x;
		fa[x] = z;
		push_up(y);
		return ;
	}
	void splay(int &x)
	{
		sta.push(x);
		for(int i = x;!is_root(i);i = fa[i])
			sta.push(fa[i]);
		while(!sta.empty())
		{
			push_down(sta.top());
			sta.pop();
		}
		while (!is_root(x))
		{
			int y = fa[x],z = fa[y];
			if(!is_root(y))
			{
				if(c[y][1] == x ^ c[z][1] == y) rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
		push_up(x);
		return ;
	}
	void access(int o)
	{
		for(int i = 0;o;i = o,o = fa[o])
		{
			splay(o);
			c[o][1] = i;
		}
	}
	int find_root(int o)
	{
		access(o);
		splay(o);
		while(c[o][0])
			o = c[o][0];
		return o;
	}
	void make_root(int o)
	{
		access(o);
		splay(o);
		reverse(o);
	}
	void link(int x,int y)
	{
		make_root(x);
		fa[x] = y;
	}
}T1;
int main()
{
	int q,n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&T1.sum[i]);
		T1.val[i] = T1.sum[i];
	}
	scanf("%d",&q);
	while(q--)
	{
		char op[10];
		scanf("%s",op);
		if(op[0] == 'b')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(T1.find_root(x) == T1.find_root(y))
				printf("no\n");
			else
			{
				printf("yes\n");
				T1.link(x,y);
			}
		}
		else if(op[0] == 'e')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(T1.find_root(x) != T1.find_root(y))
				printf("impossible\n");
			else
			{
				T1.make_root(x);
				T1.access(y);
				T1.splay(y);
				printf("%d\n",T1.sum[y]);
			}
		}
		else
		{
			int o,x;
			scanf("%d%d",&o,&x);
			T1.make_root(o);
			T1.val[o] = x;
			T1.push_up(x);
		}
	}
	return 0;
}