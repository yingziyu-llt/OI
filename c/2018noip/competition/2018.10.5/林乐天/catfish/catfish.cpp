#include<stdio.h>
#include<string.h>
#include<math.h>
int x[40];

int main()
{
    freopen("catfish.in","r",stdin);
    freopen("catfish.out","w",stdout);
    int n;
	long long ans;
    scanf("%d",&n);
    for(int _i = 0;_i < n;_i++)
    {
        ans = 0;
        memset(x,0,sizeof(x));
        int k;
        scanf("%d",&k);
        int ws = 0;
        while(k != 0)
        {
            x[ws] = k % 2;
            k /= 2;
            ws++;
        }
        for(int i = ws;i >= 0;i--)
        {
            ans = ans * 3 + x[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
