#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
bool mp[200][200];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++)
    {
        int x,y;
        char c;
        scanf("%d%d %c",&x,&y,&c);
        if(c == 'R')
        {
            if(mp[x][y + 1] == 1)
            {
                printf("%d",i);
                return 0;
            }
            else
                mp[x][y + 1] = 1;
        }
        if(c == 'D')
        {
            if(mp[x + 1][y] == 1)
            {
                printf("%d",i);
                return 0;
            }
            else
                mp[x + 1][y] = 1;
        }
    }
    printf("draw");
    return 0;
}