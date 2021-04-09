#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int T;
int f[16000000];
double p[16000000];
void feb(int n)
{
 int i;
 f[1]=1;
 f[2]=1;
 for(int i=3;i<=n;i++)
 {
  f[i]=f[i-1]+f[i-2];
  f[i]%=998244353;
 }
}
inline int jf(int n)
{
	int g=0;
	for(int i=n;i>=1;i--)
	{
		g+=i;
	}
	return g;
}
inline void deal(int n)
{
	for(int i=1;i<=n;i++)
	{
		p[i]=(double)i/(double)jf(n);
	}
}
int main()
{
	scanf("%d",&T);
	int n;
	double ans=0;
	while(T--)
	{
		scanf("%d",&n);
		feb(n);
		deal(n);
		for(int i=1;i<=n;i++)
		{
			ans+=p[i]*f[n];
		}
		printf("%.0lf\n",ans); 
	}
	return 0;
} 

