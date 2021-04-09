#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=100005,N=1000000;
const int M=998244353;
int n,m,ans;
int c[maxn];
int fc[N+5],fi[N+5];

int pow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=(LL)a*a%M)
		if(b&1)s=(LL)s*a%M;
	return s;
}

int main()
{
	freopen("horrible.in","r",stdin);
	freopen("horrible.out","w",stdout);
	for(int i=fc[0]=1;i<=N;i++)fc[i]=(LL)fc[i-1]*i%M;
	fi[N]=pow(fc[N],M-2);
	for(int i=N;i;i--)fi[i-1]=(LL)fi[i]*i%M;
	scanf("%d",&m);
	ans=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",c+i);
		ans=(LL)ans*fi[c[i]]%M;
		n+=c[i];
	}
	ans=(LL)ans*fc[n]%M;
	printf("%d\n",ans);
	return 0;
}

