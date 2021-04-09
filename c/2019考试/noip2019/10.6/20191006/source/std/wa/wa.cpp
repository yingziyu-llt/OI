#include<cstdio>
#include<cstring>
#include<algorithm>
#define lc (o<<1)
#define rc (o<<1|1)
using namespace std;
typedef long long LL;
typedef double db;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
const int MAXN=1e5+10;
int n,a[MAXN],lst[MAXN],nxt[MAXN],num,loc[MAXN];
bool vis[MAXN];
int main()
{
    n=num=read();
    for(int i=1;i<=n;++i)a[i]=read(),loc[a[i]]=i,lst[i]=i-1,nxt[i]=i+1;
    nxt[n]=0;
    while(n)
    {
        while(vis[num]||nxt[loc[num]]==0)--num;
        vis[num]=vis[a[nxt[loc[num]]]]=true;
        nxt[lst[loc[num]]]=nxt[nxt[loc[num]]];
        lst[nxt[nxt[loc[num]]]]=lst[loc[num]];
        printf("%d %d ",num,a[nxt[loc[num]]]);
        n-=2;
    }
    puts("");
    return 0;
}
