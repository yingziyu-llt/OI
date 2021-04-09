#include<stdio.h>
#include<algorithm>
using namespace std;
int color[1000][1000];
char a[10000][10000];
int n;
const char key[] = "yizhong";
const int dx[] = {1,1,1,-1,-1,-1,0,0};
const int dy[] = {1,-1,0,1,-1,0,-1,1};
bool dfs(int x,int y,int i,int j)
{
    if(j >= 7) return true;
    if(x < n && x >= 0 && y < n && y >= 0)
        if(a[x][y] == key[j])
        {
            color[x][y]++;
            if(!dfs(x + dx[i],y + dy[i],i,j+1))
            {
                color[x][y]--;
                return false;
            }
            else return true;
        }
        else
            return false;
}
int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%s",a[i]);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(a[i][j] == 'y')
            {
                for(int k = 0;k < n;k++)
                {
                    dfs(i,j,k,0);
                }
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(color[i][j] == 0)
                printf("*");
            else
                printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
