#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
const int MAXN = 1e5 + 10;
int cnt,a[MAXN],len,n,f[MAXN],ans[MAXN],root;
struct point
{
	int pri,lc,rc,siz;
}p[MAXN];
void push_up(int root)
{
	p[root].siz = p[p[root].lc].siz + 1 + p[p[root].rc].siz;
	return;
}
void lturn(int &root)
{
	int tmp = p[root].rc;
	p[root].rc = p[tmp].lc;
	p[tmp].lc = root;
	p[tmp].siz = p[root].siz;
	push_up(root);
	root = tmp;
	return ;
}
void rturn(int &root)
{
	int tmp = p[root].lc;
	p[root].lc = p[tmp].rc;
	p[tmp].rc = root;
	p[tmp].siz = p[root].siz;
	push_up(root);
	root = tmp;
	return ;
}
void insert(int &root,int rank)
{
	if(!root)
	{
		p[root = ++cnt] = (point){rand(),0,0,1};
		return ;
	}
	++p[root].siz;
	if(rank <= p[p[root].lc].siz)
	{
		insert(p[root].lc,rank);
		if(p[p[root].rc].pri > p[root].pri) lturn(root);
	}
	else
	{
		insert(p[root].rc,rank - p[p[root].lc].siz - 1);
		if(p[p[root].lc].pri > p[root].pri) rturn(root);
	}
	return ;
}
void dfs(int root)
{
	if(!root) return ;
	dfs(p[root].lc);
	a[++cnt] = root;
	dfs(p[root].rc);
	return ;
}
void lis()
{
	for(int i = 1;i <= n;i++)
	{
		int l = 1,r = len;
		if(a[i] > f[len])
		{
			f[++len] = a[i];
			ans[a[i]] = len;
			continue;
		}
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(a[i] > f[mid]) l = mid + 1;
			else r = mid;
		}
		f[l] = a[i];
		ans[a[i]]= l;
	}
	return ;
}
int main()
{
	scanf("%d",&n);
	srand(n);
	for(int i = 1;i <= n;i ++)
	{
		int x;
		scanf("%d",&x);
		insert(root,x);
	}
	cnt = 0;
	dfs(root);
	lis();
	for(int i = 1;i <= n;i++)
	{
		ans[i] = max(ans[i - 1],ans[i]);
		printf("%d\n",ans[i]);
	}
	return 0;
}