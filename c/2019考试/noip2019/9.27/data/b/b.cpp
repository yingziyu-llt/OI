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
int n,cnt1,cnt2;
int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		if(n==1)
		{
			int x=read();
			printf("%lf\n",(db)x);
			continue;
		}
		cnt1=cnt2=0;
		for(int i=1;i<=n;++i)
			if(i==1||i==n)cnt1+=read();
			else cnt2+=read();
		printf("%.3lf\n",(db)cnt1*1.0/2.0+(db)cnt2*1.0/3.0);
	}
	return 0;
}
