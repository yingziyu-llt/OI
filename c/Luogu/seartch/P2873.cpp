#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int map[1010][1010];
int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};
struct node
{
    int x,y,val;
}no;
queue <node> q;
int main()
{
    int n,x,y,ans;
    bool ok = false;
    memset(map,0,sizeof(map));
    scanf("%d%d%d",&x,&y,&n);
    map[x + 500][y + 500] = 2;
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d",&x,&y);
        map[x + 500][y + 500] = -1;
    }
    no.val = 0;
    no.x = 500;
    no.y = 500;
    q.push(no);
    while(!q.empty())
    {
        for(int i = 0;i < 4;i++)
        {
            int x,y,val;
            x = q.front().x;
            y = q.front().y;
            val = q.front().val;
            if(x + dx[i] >= 0 && x + dx[i] <= 1000 && y + dy[i] >= 0 && y + dy[i] <= 1000 && map[x + dx[i]][y + dy[i]] != -1)
            {
                if(map[x + dx[i]][y + dy[i]] == 2)
                {
                    ok = true;
                    ans = val  +1;
                    break;
                }
                map[x + dx[i]][y + dy[i]] = -1;
                no.val = val + 1;
                no.y = y + dy[i];
                no.x = x + dx[i];
                q.push(no);
            }
        }
        if(ok) break;
        q.pop();
    }
    printf("%d",ans);
    return 0;
}