#include<stdio.h>
int a[10000];
int main()
{
    freopen("boat.in","r",stdin);
    freopen("boat.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n - 1;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            int k;
            scanf("%d",&k);
            if(a[j] > a[i] + k || a[j] == 0)
                a[j] = a[i] + k;
        }
    }
    printf("%d",a[n]);
    return 0;
}