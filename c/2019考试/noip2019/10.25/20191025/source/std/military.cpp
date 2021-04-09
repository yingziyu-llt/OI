#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
inline void readi(int &x);
const int maxn=100005;
int n,m[maxn],c[maxn],ans,mx;
vector<int> h[maxn];
vector<pair<int,int> > p;
int main()
{
	freopen("military.in","r",stdin);
	freopen("military.out","w",stdout);
	readi(n);
	for(int i=1;i<=n;i++)
	{
		readi(m[i]),readi(c[i]);
		h[i].resize(m[i]);
		for(int j=0;j<m[i];j++)
			readi(h[i][j]),p.push_back(make_pair(h[i][j],i));
		sort(h[i].begin(),h[i].end());
		mx=max(mx,h[i][c[i]-1]);
	}
	sort(p.begin(),p.end());
	ans=(1<<30)-1;
	for(int k,i=0;i<p.size();i++)
	{
		ans=min(ans,mx-p[i].first);
		k=p[i].second;
		if(c[k]==m[k])break;
		mx=max(mx,h[k][c[k]++]);
	}
	printf("%d\n",ans);
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c^'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+(c^'0');}

