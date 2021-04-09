// luogu-judger-enable-o2
#include<stdio.h>
#include<algorithm>
using namespace std;
int fa[100000];
struct side
{
    int val,f,e;
}s[200000];
int findfather(int a)
{
    return fa[a] = fa[a] == a ? a : findfather(fa[a]);
}
bool cmp(side a,side b)
{
    return a.val < b.val;
}
int main()
{
    int n,m;
    int ans  = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0 ;i < n;i++)
        fa[i] = i;
    for(int i = 0;i <m;i++)
        scanf("%d%d%d",&s[i].f,&s[i].e,&s[i].val);
    int i = 0;
    int tot = 0;
    sort(s,s + m,cmp);
    while(i < m)
    {
        int f1,f2;
        f1 = findfather(s[i].f);
        f2 = findfather(s[i].e);
        if(f1 != f2)
        {
            fa[f2] = f1;
            ans += s[i].val;
            tot++;
        }
        if(tot == n - 1)
            break;
        i++;
    }
    int a = fa[0];
    if(tot >= n - 1)
        printf("%d",ans);
    else
        printf("orz");
    return 0;
}