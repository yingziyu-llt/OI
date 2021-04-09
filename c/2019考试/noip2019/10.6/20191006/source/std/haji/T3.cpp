#include<cstdio>
#include<cstring>
#include<algorithm>
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
const int MAXN=20;
int n,m,a[MAXN][MAXN],ans,b[MAXN];
bool check(int x)
{
	return x<=13&&(!(x%3));
}
void cal()
{
	int tot=0,t[3];
	for(int j=1;j<=m;++j)
	{
		t[0]=t[1]=t[2]=0;
		for(int i=1;i<=n;++i)
			for(int k=0;k<=2;++k)
				t[k]+=check(b[i]+a[i][j]+k);
		tot+=max(t[0],max(t[1],t[2]));
	}
	ans=max(ans,tot);
	return;
}
void dfs(int dep)
{
	if(dep==n+1)
	{
		cal();
		return;
	}
	for(int i=0;i<=2;++i)
		b[dep]=i,dfs(dep+1);
	return;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=read();
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
