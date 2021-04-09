#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
template<class T> inline void readi(T &x); 
const int maxn=1000005;
typedef long long LL;
int n,p,h[maxn],v[maxn],c[maxn],Q[maxn],cur;
LL m,sum,ans;

bool cmpv(const int &a,const int &b)
{return v[a]>v[b];}

void deal()
{
	int k;
	while(m>0&&cur<=n)
	{
		k=Q[cur++];
		if(k>p||c[k]==h[k])continue;
		if(m>=h[k]-c[k])
		{
			sum+=(LL)v[k]*(h[k]-c[k]);
			m-=h[k]-c[k];
			c[k]=h[k];
		}
		else
		{
			sum+=v[k]*m;
			c[k]+=m;
			m=0;
			cur--;
		}
	}
}

int main()
{
	freopen("training.in","r",stdin);
	freopen("training.out","w",stdout);
	readi(n),readi(m);
	for(int i=1;i<=n;i++)
		readi(h[i]),readi(v[i]),Q[i]=i;
	m++;
	sort(Q+1,Q+n+1,cmpv);cur=1;
	for(int i=1;i<=n&&m;i++)
	{
		p=i;
		c[i]=1;
		sum+=v[i];
		m--;
	}
	deal();
	ans=max(ans,sum);
	while(m==0&&p>1)
	{
		sum-=(LL)v[p]*c[p];
		m+=c[p];
		c[p]=0;
		p--;
		deal();
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}

template<class T> inline void readi(T &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c^'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+(c^'0');}

