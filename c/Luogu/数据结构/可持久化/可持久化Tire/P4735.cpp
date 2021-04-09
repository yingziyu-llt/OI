#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN = 600010;
struct node
{
	int ch[2],cnt;
}node[MAXN * 28];
int n,m,root[MAXN],cnt,pre;
void insert(int &now,int lst,int t,int x)
{
	now = ++cnt;
	node[now].cnt = node[lst].cnt + 1;
	if(t < 0) return;
	int i = (x >> t) & 1;
	node[now].ch[!i] = node[lst].ch[!i];
	insert(node[now].ch[i],node[lst].ch[i],t - 1,x);
	return ;
}
int query(int o1,int o2,int t,int x)
{
	if(t < 0) return 0;
	int i = (x >> t) & 1;
	if(node[node[o2].ch[!i]].cnt > node[node[o1].ch[!i]].cnt)
		return (1 << t) + query(node[o1].ch[!i],node[o2].ch[!i],t - 1,x);
	return query(node[o1].ch[i],node[o2].ch[i],t - 1,x);
}
int main()
{
	scanf("%d%d",&n,&m);
	insert(root[0],0,25,0);
	for(int i = 1;i <= n;i++)
	{
		int t;
		scanf("%d",&t);
		pre ^= t;
		insert(root[i],root[i - 1],25,pre);
	}
	while(m--)
	{
		char s[10];
		scanf("%s",s);
		if(s[0] == 'A')
		{
			int x;
			scanf("%d",&x);
			n++;
			pre ^= x;
			insert(root[n],root[n - 1],25,pre);
		}
		else
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			l--,r--;
			if(l == 0) printf("%d\n",query(0,root[r],25,x ^ pre));
			else printf("%d\n",query(root[l - 1],root[r],25,x ^ pre));
		}
	}
	return 0;
}