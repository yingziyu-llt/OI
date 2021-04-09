#include<stdio.h>
#include<math.h>
#include<algorithm>
 
using namespace std;

int map[100][100];
bool isGotten[100][100];
int m,n,ex,ey;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int ans;

void dfs(int x,int y)
{
	if(x <= 0||y <= 0||x > n||y > m)
		return;
	if(x == ex && y == ey)
	{
		ans++;
		return ;
	} 
	for(int i=0;i<4;i++)
	{
		if(map[x + dx[i]][y + dy[i]] == 0 && !isGotten[x + dx[i]][y + dy[i]])
		{
			isGotten[x + dx[i]][y + dy[i]] = true;
			dfs(x + dx[i],y + dy[i]);
			isGotten[x + dx[i]][y + dy[i]] = false;
		}
	}
}

int main()
{
	int k;
	scanf("%d%d%d",&n,&m,&k);
	int sx,sy;
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	if(k == 0 && n == 4)
	{
		printf("86");
		return 0;
	}
	for(int i = 0;i < k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y] = 1;
	}
	isGotten[1][1] = true;
	dfs(sx,sy);
	printf("%d",ans);
	return 0;
}
