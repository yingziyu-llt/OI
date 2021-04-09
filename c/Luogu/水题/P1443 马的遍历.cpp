#include<stdio.h>
#include<queue>
#include<string.h> 
#include<algorithm>
using namespace std;
int map[500][500];
int get[500][500];
struct point
{
	int x,y,cost;
}p;
queue <point> q;
int dx[] = {-2,-2,-1,-1,1,1,2,2},dy[] = {1,-1,2,-2,2,-2,1,-1}; 
int main()
{
	int n,m,x,y;
	memset(get,0,sizeof(get));
	scanf("%d%d%d%d",&n,&m,&x,&y);
	p.x = x;
	get[x][y] = 1;
	p.y = y;
	p.cost = 0;
	q.push(p);
	while(!q.empty())
	{
		int nx = q.front().x,ny = q.front().y,nc = q.front().cost;
		for(int i = 0;i < 8;i++)
		{
			int sx = nx + dx[i],sy = ny + dy[i];
			if(sx > 0 && sx <= n && sy > 0 && sy <= m && get[sx][sy] == 0)
			{
				p.x = sx;
				p.y = sy;
				p.cost = nc + 1;
				get[sx][sy] = 1;
				map[sx][sy] = nc + 1;
				q.push(p);
			}
		}
		q.pop();
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(get[i][j] == 0) 
				map[i][j] = -1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
			printf("%-5d",map[i][j]);
		printf("\n"); 
	}
		
}
