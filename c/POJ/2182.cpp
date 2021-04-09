#include<stdio.h>
#include<algorithm>
using namespace std;
int k,n,a[9000];
int lowbit(int a){return (a ^ (-a));}
void change(int f,int b)
{
    for(int i = b;i <= n;i += lowbit(i))
        a[i] += f;
    return ;
}
int query(int b)
{
    int ans = 0;
    for(int i = b;i >= 1;i -= lowbit(i))
        ans += a[i];
    return ans;
}
int find(int k)
{
    int l = 0,r = n + 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(query(mid) > k) r = mid;
        else l = mid + 1;
    }
    return l;
}
int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        change(1,i);
    }
    for(int i = 0;i < n;i++)
    {
        int k;
        scanf("%d",&k);
        int ans = find(k);
        printf("%d\n",ans);
        change(-1,ans);
    }
    return 0;
}