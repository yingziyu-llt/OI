#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int N = 110000,SEED = 19260817;
int n;
struct node
{
	int ls,rs,siz,key,pir,val;
	//ls:left son | rs: right son | pri:priority | val:the number of this key
};
struct Treap
{
	node a[N];
	int MainRoot,ans,cnt,ret;
	Treap()
	{
		srand(SEED);
		return ;
	}
	void push_up(int root)
	{
		a[root].siz = a[a[root].ls].siz + a[a[root].rs].siz + a[root].val;
		return ;
	}
	void lturn(int root)
	{
		int son = a[root].ls;
		a[root].ls = a[son].rs;
		a[son].rs = root;
		a[son].siz = a[root].siz;
		push_up(root);
		return ;
	}
	void rturn(int root)
	{
		int son = a[root].rs;
		a[root].rs = a[son].ls;
		a[son].ls = root;
		a[son].siz = a[root].siz;
		push_up(root);
		return ; 
	}
	void insert(int &root,int k)
	{
		if(!root)
		{
			root = ++cnt;
			a[root].key = k;
			a[root].ls = 0;
			a[root].rs = 0;
			a[root].pir = rand();
			a[root].siz = 1;
			a[root].val = 1;
		}
		++a[root].siz;
		if(k == a[root].key) ++a[root].val;
		else if(k < a[root].key)
		{
			insert(a[root].ls,k);
			if(a[root].pir < a[a[root].ls].pir) rturn(root);
		}
		else
		{
			insert(a[root].rs,k);
			if(a[root].pir < a[a[root].rs].pir) lturn(root);
		}
		return ;
	}
	void del(int &root,int k)
	{
		if(!root) return ;
		if(k == a[root].key)
		{
			if(a[root].val)
			{
				a[root].val--;
				a[root].siz--;
			}
			else if(!(a[root].ls * a[root].rs)) root = a[root].ls + a[root].rs;
			else if(a[a[root].ls].pir < a[a[root].rs].pir) 
			{
				lturn(root);
				del(root,k);
			}
			else
			{
				rturn(root);
				del(root,k);
			}
		}
		else if(k < a[root].key)
		{
			--a[root].siz;
			del(a[root].ls,k);
		}
		else
		{
			--a[root].siz;
			del(a[root].rs,k);
		}
		return ;
	}
	int query_rank(int root,int k)
	{
		if(!root) return 0;
		if(k < a[root].key) return query_rank(a[root].ls,k);
		if(k == a[root].key) return a[a[root].ls].siz + 1;
		if(k > a[root].key) return a[a[root].ls].siz + a[root].val + query_rank(a[root].rs,k);
	}
	int query_num(int root,int k)
	{
		if(!root) return 0;
		if(k <= a[a[root].ls].siz) return query_num(a[root].ls,k);
		if(k <= a[a[root].ls].siz + a[root].val) return a[root].key;
		return query_num(a[root].rs,k);
	}
	void query_pre(int root,int k)
	{
		if(!root) return ;
		if(k <= a[root].key) query_pre(a[root].ls,k);
		else
		{
			ret = a[root].key;
			query_pre(a[root].rs,k);
		}
		return ;
	}
	void query_sub(int root,int k)
	{
		if(!root) return ;
		if(k >= a[root].key) query_sub(a[root].rs,k);
		else
		{
			ret = a[root].key;
			query_sub(a[root].ls,k);
		}
		return ;
	}
};
