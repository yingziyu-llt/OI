#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std ;
#define TIME 1.0*clock()/CLOCKS_PER_SEC 
template<class T>inline void read(T &x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
    while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return ;
}
const int maxn=105;
const int inf=1<<30;

struct edge{
	int u,v,w,next,ctr;
}E[maxn*maxn];

int n,m,s,T,ecnt;
int dis[maxn*maxn],head[maxn*maxn],cur[maxn*maxn];
int f[maxn][maxn];

inline void addedge(int u,int v,int w){
	int i=++ecnt;int j=++ecnt;
	E[i].u=E[j].v=u;
	E[i].v=E[j].u=v;
	E[i].w=w;E[j].w=0;
	E[i].ctr=j;E[j].ctr=i;
	E[i].next=head[u];
	E[j].next=head[v];
	head[u]=i;head[v]=j;
}

int dfs(int u,int nar){
	if(u==T) return nar;
	for(int i=cur[u];~i;i=E[i].next){
		int v=E[i].v;cur[u]=i;
		if(dis[v]==dis[u]+1&&E[i].w>0){
			int flow=dfs(v,min(E[i].w,nar));
			if(flow){
				int j=E[i].ctr;
				E[i].w-=flow;E[j].w+=flow;
				return flow;
			}
		}
	}
	return 0;
}

inline bool bfs(){
	queue<int>q;q.push(s);
	for(int i=s;i<=T;i++) dis[i]=inf;
	dis[s]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];~i;i=E[i].next){
			int v=E[i].v;
			if(dis[v]>dis[x]+1&&E[i].w>0){
				dis[v]=dis[x]+1;
				q.push(v);
			}
		}
	}
	return dis[T]<inf;
}

inline int Dinic(){
	int ans=0,flow;
	while(bfs()){
		for(int i=s;i<=T;i++) cur[i]=head[i];
		if(flow=dfs(s,inf)) ans+=flow;
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("orz.in","r",stdin);
    freopen("orz.out","w",stdout);
#endif
	read(n),read(m);
	for(int i=1,u,v;i<=m;i++)
		read(u),read(v),f[u][v]=1;
	memset(head,-1,sizeof(head));
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=(f[i][j]||(f[i][k]&&f[k][j]));
	s=0;T=n*n+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]) addedge(i,j+n,inf);
	for(int i=1;i<=n;i++)
		addedge(s,i,1),addedge(i+n,T,1);
	printf("%d\n",n-Dinic());
    return 0;
}

