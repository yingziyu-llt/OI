#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
struct point
{
	int val, x, y;
} gr;
queue<point> q;
int map[510][510], dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
int main()
{
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	memset(map, 0xff, sizeof(map));
	for (int i = 0; i < a; i++)
	{
		int tx, ty;
		scanf("%d%d", &tx, &ty);
		gr.x = tx;
		gr.y = ty;
		gr.val = 0;
		q.push(gr);
		map[tx][ty] = 0;
	}
	while (!q.empty())
	{
		int nx, ny, nval;
		nx = q.front().x;
		ny = q.front().y;
		nval = q.front().val;
		for (int i = 0; i < 4; i++)
		{
			int x = nx + dx[i];
			int y = ny + dy[i];
			if (x >= 0 && x <= n && y >= 0 && y <= m)
			{
				if (map[x][y] == -1 || nval + 1 < map[x][y])
				{
					gr.x = x;
					gr.y = y;
					gr.val = nval + 1;
					map[x][y] = nval + 1;
					q.push(gr);
				}
			}
		}
		q.pop();
	}
	for(int i = 0;i < b;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",map[x][y]);
	}
	return 0;
}