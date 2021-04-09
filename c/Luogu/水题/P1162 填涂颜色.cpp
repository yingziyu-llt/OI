#include<stdio.h>
#include<queue>
#include<string.h> 
#include<algorithm>
using namespace std;
int map[500][500];
int n;
struct point
{
	int x,y;
}p;
queue <point> q;
int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0}; 
void dfs(int x,int y)
{
	p.x = x;
	map[x][y] = 2;
	p.y = y;
	q.push(p);
	while(!q.empty())
	{
		int nx = q.front().x,ny = q.front().y;
		for(int i = 0;i < 4;i++)
		{
			int sx = nx + dx[i],sy = ny + dy[i];
			if(sx > 0 && sx <= n && sy > 0 && sy <= n && map[sx][sy] != 1 && map[sx][sy] != 2)
			{
				p.x = sx;
				p.y = sy;
				map[sx][sy] = 2;
				q.push(p);
			}
		}
		q.pop();
	}
}
int main()
{
	
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			scanf("%d",&map[i][j]);
	for(int i = 1;i <= n;i++)
		if(map[1][i] != 1) 
			dfs(1,i);
	for(int i = 2;i < n;i++)
	{
		if(map[i][1] != 1)
			dfs(i,1);
		if(map[i][n] != 1)
			dfs(i,n);
	}
	for(int i = 1;i <= n;i++)
		if(map[n][i] != 1) 
			dfs(n,i);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(map[i][j] == 2)
				printf("0 ");
			else if(map[i][j] == 1)
				printf("1 ");
			else
				printf("2 ");
		}
		printf("\n");
	}
	return 0;
}
