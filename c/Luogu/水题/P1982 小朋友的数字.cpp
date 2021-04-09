#include<stdio.h>
#include<algorithm>
#include<math.h>
#define INF 0x7fffffff
using namespace std;
long long a[1000005];
long long b[1000005];
long long dp[1000005];
long long p;
int main()
{
    long long n;
    long long ans=-INF;
    scanf("%lld%lld",&n,&p);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    dp[1]=a[1];
    b[1]=a[1];
    for(int i=2;i<=n;i++)
        dp[i]=max(dp[i-1]+a[i],a[i]);
    for(int i=2;i<=n;i++)
        dp[i]=max(dp[i],dp[i-1]);
    b[2]=dp[1]+a[1];
    ans=b[1];
    int flag=0;
    for(int i=3;i<=n;i++)
    {
        if(dp[i-1]+b[i-1]<0&&b[i-1]>0) flag=1;
        if(flag==1)
            b[i]=(b[i-1]%p+dp[i-1])%p;
        else
            b[i]=(b[i-1]+dp[i-1],b[i-1]);
        ans=max(b[i],ans);
    }
    if(flag==1)
        printf("%lld",b[n]%p);
    else
        printf("%lld",ans%p);
    return 0;
}