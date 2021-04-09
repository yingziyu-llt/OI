#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 1e4
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
const int MAXN=1e4+10;
int n,m,head[MAXN],cnt,f[MAXN][3];
struct edge
{
	int v,next;
}e[MAXN*2];
void addedge(int x,int y)
{
	e[++cnt]=(edge){y,head[x]};
	head[x]=cnt;
	return;
}
void dfs(int u,int fa)
{
	f[u][0]=1;
	f[u][1]=0;
	f[u][2]=INF;
	if(!head[u])
	{
		f[u][2]=-INF;
		return;
	}
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		f[u][0]+=min(f[v][0],f[v][1]);
		f[u][1]+=f[v][2];
	}
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa)continue;
		f[u][2]=min(f[u][2],f[u][1]-f[v][2]+f[v][0]);
	}
	return;
}
int main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		int x=read(),y=read();
		addedge(x,y);addedge(y,x);
	}
	dfs(1,0);
	printf("%d\n",min(f[1][0],f[1][2]));
	return 0;
}
