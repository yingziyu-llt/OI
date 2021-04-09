#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
const int MAXN = 150010,MOD = 1e9+7;
struct node
{
	int c[2],fa,val,siz,hash;
}a[MAXN];
int n,m,root,tot,power26[MAXN];
char s[MAXN];
int push_up(int x)
{
	a[x].siz = a[a[x].c[0]].siz + 1 + a[a[x].c[1]].siz;
	a[x].hash=(((long long)a[a[x].c[0]].hash*power26[a[a[x].c[1]].siz+1]%MOD+(long long)a[x].val*power26[a[a[x].c[1]].siz]%MOD)%MOD+a[a[x].c[1]].hash)%MOD;
}
void rotate(int &o,int x)
{
	int y = a[x].fa,z = a[y].fa,dy = a[y].c[1] == x,dz = a[z].c[1] == y;
	if(o == y) o = x;
	else a[z].c[dz] = x;
	a[x].fa = z;
	a[y].c[dy] = a[x].c[dy ^ 1];
	a[a[y].c[dy]].fa = y;
	a[x].c[dy ^ 1] = y;
	a[y].fa = x;
	push_up(y);
}
void splay(int &o,int x)
{
	while(o != x)
	{
		int y = a[x].fa,z = a[y].fa;
		if(y != o)
		{
			if((a[y].c[1] == x) ^ (a[z].c[1] == y))
				rotate(o,x);
			else rotate(o,y);
		}
		rotate(o,x);
	}
	push_up(x);
	return ;
}
int find(int o,int v)
{
	if(v <= a[a[o].c[0]].siz) return find(a[o].c[0],v);
	if(v <= a[a[o].c[0]].siz + 1) return o;
	return find(a[o].c[1],v - a[a[o].c[0]].siz - 1);
}
int main()
{
	scanf("%s",s + 1);
	scanf("%d",&m);
	n = strlen(s + 1);
	power26[0] = 1;
	for(int i = 1;i <= MAXN;i++) power26[i] = power26[i - 1] * 26 % MOD;
	a[1].siz = n + 2,a[1].c[1] = 2;
	a[n + 2].siz = 1;a[n + 2].fa = n + 1;
	for(int i = 1;i <= n;i++)
		a[i + 1] = (node){{0,i + 2},i,s[i] - 'a',n - i + 2,0},push_up(i + 1);
	tot = n + 2,root = 1;
	while(m--)
	{
		char ques[100];
		scanf("%s",ques);
		if(ques[0] == 'Q') 
		{
			int x,y;
			scanf("%d %d",&x,&y);
			if(x > y) swap(x,y);
			int l = 0,r = n - y + 2;
			while(l < r - 1)
			{
				int mid = (l + r) >> 1;
				splay(root,find(root,x));
				splay(a[root].c[1],find(root,x + mid + 1));
				int tmp = a[a[a[root].c[1]].c[0]].hash;
				splay(root,find(root,y));
				splay(a[root].c[1],find(root,y + mid + 1));
				tmp -= a[a[a[root].c[1]].c[0]].hash;
				if(tmp != 0) r = mid;
				else l = mid; 
			}
			printf("%d\n",l);
		}
		else if(ques[0] == 'R')
		{
			int x;
			char c[10];
			scanf("%d%s",&x,c);
			splay(root,find(root,x + 1));
			a[root].val = c[0] - 'a';
			push_up(x);
		}
		else
		{
			int x;char c[10];
			scanf("%d%s",&x,c);
			splay(root,find(root,x + 1));
			splay(a[root].c[1],find(root,x + 2));
			a[a[root].c[1]].c[0] = ++tot;
			a[tot] = (node){{0,0},a[root].c[1],c[0] - 'a',1,c[0] - 'a'};
			push_up(a[root].c[1]);
			push_up(root);
		}
	}
	return 0;
}