#include<cstdio>
#include<algorithm>
int T,m,n,a[100005]={0},b[100005]={0};
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d %d",&n,&m);
        for(int j=1;j<=n;j++) scanf("%d",&a[j]);
        for(int j=1;j<=n;j++) scanf("%d",&b[j]);
        printf("Yes\n");
    }
    return 0;
}