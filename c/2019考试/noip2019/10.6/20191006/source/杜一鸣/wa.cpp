#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[100005],n,p[100005],num;
bool v[100005];
int main()
{
    freopen("wa.in","r",stdin);
    freopen("wa.out","w",stdout);
    scanf("%d",&n);
    num=n/2;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }
    int t=n,i;
    for(;num;)
    {
        while(v[t] || t==a[n]) t--;
        for(i=p[t]+1;i<=n;i++)
        {
            if(!v[a[i]]) break;
        }
        if(i==n+1)
        {
            t--;
            continue;
        }
        v[t]=1;
        v[a[i]]=1;
        printf("%d %d ",t,a[i]);
        num--;
    }
    return 0;
}