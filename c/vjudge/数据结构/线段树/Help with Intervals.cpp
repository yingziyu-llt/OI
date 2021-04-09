#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 140000;
#define lson root << 1
#define rson root << 1 | 1
struct Segment_tree
{
	int xtag[N << 2],cov[N << 2];
	bool hsh[N];
	void funcxor(int root)
	{
		if(cov[root] != -1) cov[root] ^= 1;
		else xtag[root] ^= 1;
	}
	void push_down(int root,int l,int r)
	{
		if(cov[root] != -1)
		{
			cov[lson] = cov[rson] = cov[root];
			xtag[root] = xtag[lson] = xtag[rson] = 0;
			cov[root] = -1;
		}
		if(xtag[root])
		{
			funcxor(lson);
			funcxor(rson);
			xtag[root] = 0;
		}
	}
	void change(int root,int l,int r,char op,int x,int y)
	{
		if(l >= x && r <= y)
		{
			if(op == 'U')
			{
				cov[root] = 1;
				xtag[root] = 0;
			}
			else if(op == 'D')
			{
				cov[root] = 0;
				xtag[root] = 0;
			}
			else if(op == 'C' || op == 'S')
			{
				funcxor(root);
			}
			return ;
		}
		push_down(root,l,r);
		int mid = (l + r) / 2;
		if(x <= mid) change(lson,l,mid,op,x,y);
		else if(op == 'C' || op == 'I')
			cov[lson] = xtag[lson] = 0;
		if(mid < y) change(rson,mid + 1,r,op,x,y);
		else if(op == 'C' || op == 'I')
			cov[rson] = xtag[rson] = 0;
	}
	void quary(int root,int l,int r)
	{
		if(cov[root] == 1)
		{
			for(int i = l;i <= r;i++)
				hsh[i] = true;
			return ;
		}
		else if(cov[root] == 0) return;
		if(l == r) return ;
		push_down(root,l,r);
		int mid = (l + r) / 2;
		quary(lson,l,mid);
		quary(rson,mid + 1,r);
		return ;
	}
}Tree;
int main()
{
	Tree.cov[1] = Tree.xtag[1] = 0;
	char op,l,r;
	int a,b;
	while(~scanf("%c %c%d,%d%c\n",&op,&l,&a,&b,&r))
	{
		a = a << 1,b = b << 1;
		if(l == '(') a++;
		if(r == ')') b--;
		if(a > b)
		{
			if(op == 'C' || op == 'I')
				Tree.cov[1] = Tree.xtag[1] = 0;
		}
		else 
			Tree.change(1,0,N,op,a,b);
	}
	Tree.quary(1,0,N);
	int s = -1,e;
	bool flag = false;
	for(int i = 0;i < N;i++)
	{
		if(Tree.hsh[i])
		{
			if(s == -1) s = i;
			e = i;
		}
		else
		{
			if(s != -1)
			{
				if(flag) printf(" ");
				flag = true;
				printf("%c%d,%d%c",s & 1 ? '(' : '[',s >> 1,(e + 1) >> 1,e & 1 ? ')' : ']');
				s = -1;
			}
		}
	}
	if(!flag) printf("empty set");
	return 0;
}