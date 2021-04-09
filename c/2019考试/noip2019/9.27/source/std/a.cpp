#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef double db;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-')f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+ch-'0'; ch=getchar(); }
	return x*f;
}
const int MAXN=160;
int n,m,head[MAXN*2],cnt,idx[MAXN*2],tot,S,T;
struct edge
{
	int v,next,val;
}e[MAXN*MAXN*2];
void addedge(int x,int y,int z)
{
	e[cnt]=(edge){y,head[x],z};
	head[x]=cnt++;
	swap(x,y);
	e[cnt]=(edge){y,head[x],0};
	head[x]=cnt++;
	return;
}
void bfs()
{
	memset(idx,0,sizeof(idx));
	queue<int>q;
	q.push(S);
	idx[S]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=head[u];~i;i=e[i].next)
		{
			int v=e[i].v;
			if(idx[v]||!e[i].val)continue;
			idx[v]=idx[u]+1;
			q.push(v);
		}
	}
	return;
}
int dfs(int u,int _min)
{
	if(u==T)return _min;
	int ret=0,k;
	for(int i=head[u];~i;i=e[i].next)
	{
		int v=e[i].v;
		if(idx[v]!=idx[u]+1||!e[i].val)continue;
		k=dfs(v,min(_min-ret,e[i].val));
		e[i].val-=k;
		e[i^1].val+=k;
		ret+=k;
		if(ret==_min)break;
	}
	return ret;
}
int dinic()
{
	int ret=0;
	while(true)
	{
		bfs();
		if(!idx[T])break;
		ret+=dfs(S,INF);
		if(ret==INF)break;
	}
	return ret;
}
int main()
{
	int TT=read();
	while(TT--)
	{
		n=read();m=read();
		memset(head,-1,sizeof(head));
		tot=cnt=0;
		for(int i=1;i<=n;++i)
		{
			int x=read();
			tot+=x;
			addedge(0,i,x);
		}
		T=n+m+1;
		for(int i=1;i<=m;++i)addedge(i+n,T,read());
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				addedge(i,j+n,1);
		int ans=dinic();
		if(ans==tot)puts("Yes");
		else puts("No");
	}
	return 0;
}
