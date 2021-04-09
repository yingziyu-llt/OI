#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#define ll long long
#define INF 1000000000
#define clr(x) memset(x,0,sizeof(x))
#define maxclr(x) memset(x,0x3f,sizeof(x))

using namespace std;

inline int read()
{
	register int ret=0,c=getchar(),b=1;
	while(!isdigit(c))b=c=='-'?-1:1,c=getchar();
	while(isdigit(c))ret=ret*10+c-'0',c=getchar();
	return ret*b;
}

#define M 500005

int n,k,a[M],l[M],r[M],p[M];
ll ans;

int main()
{
#ifdef anantheparty
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--)
	{
		n=read(),k=read()-1;
		r[0]=1;l[n+1]=n;ans=0;
		for(int i=1;i<=n;i++)
			a[i]=read(),p[a[i]]=i,l[i]=i-1,r[i]=i+1;
		for(int i=1;i<=n;i++)
		{
			int x=p[i],L=l[x],R=x,lt=0,rt=0;
			while(L!=0&&lt<k)L=l[L],lt++;
			while(lt+rt<k&&R!=n+1)R=r[R],rt++;
			while(R!=n+1&&rt<=k&&R!=n+1)
			{
				ans+=1LL*(r[L]-L)*(r[R]-R)*i;
				L=r[L],R=r[R],rt++;
			}
			r[l[x]]=r[x],l[r[x]]=l[x];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
