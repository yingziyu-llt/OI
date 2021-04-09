#include<bits/stdc++.h>
 
using namespace std;
struct node
{
    int v[3];///记录三个杯子的状态
    int dist;///记录到这个状态的最小倒水数
    bool operator < (const node& s)const
    {
        return dist>s.dist;
    }
}x,y;
int vis[210][210];
int cmp[3];
int ans[210];
void updata(const node&u)
{
    for(int i=0;i<3;i++)
    {
        int d=u.v[i];
        if(ans[d]<0||ans[d]>u.dist)ans[d]=u.dist;
    }
}
void solve(int a,int b,int c,int d)
{
    cmp[0]=a;
    cmp[1]=b;
    cmp[2]=c;
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    priority_queue<node>q;
    while(!q.empty())q.pop();
    x.dist=0;
    x.v[0]=0;
    x.v[1]=0;
    x.v[2]=c;
    q.push(x);
    while(!q.empty())
    {
        y=q.top();
        q.pop();
        updata(y);///当到达状态d时更新
        if(ans[d]>=0)break;///当到达d状态时就跳出，因为用的优先队列，
        ///所以先到达的肯定是最优的
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(i==j)continue;
                if(!y.v[i]||y.v[j]==cmp[j])continue;
                int k=min(cmp[j],y.v[i]+y.v[j])-y.v[j];
                memcpy(&x,&y,sizeof(y));
                x.dist=y.dist+k;
                x.v[i]-=k;
                x.v[j]+=k;
                if(!vis[x.v[0]][x.v[1]])
                {
                    vis[x.v[0]][x.v[1]]=1;
                    q.push(x);
                }
            }
        }
    }
    while(d>=0)
    {
        if(ans[d]>=0)
        {
            printf("%d %d\n",ans[d],d);
            return;
        }
        d--;
    }
}
int main()
{
    int a,b,c,d;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        solve(a,b,c,d);
    }
    return 0;
}
