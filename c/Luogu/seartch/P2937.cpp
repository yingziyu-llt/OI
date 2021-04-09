#include <stdio.h>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
const int W = 100, H = 100;
struct point
{
	int x, y, val;
};
queue<point> q;
int map[W][H], val[W][H];
bool vis[W][H];
int startx, starty;
int w, h;
int main()
{
	scanf("%d%d", &w, &h);
	for (int i = 1; i <= h; i++)
	{
		char s[W];
		scanf("%s", s);
		for (int j = 0; j < w; j++)
		{
			if (s[j] == 'C')
				map[i][j + 1] = 3, startx = j + 1, starty = i;
			else if (s[j] == '*')
				map[i][j + 1] = 0;
			else
				map[i][j + 1] = 1;
		}
	}
	point p;
	p.val = 0, p.x = starty, p.y = startx;
	int endx = 0, endy = 0;
	map[starty][startx] = 1;
	memset(val, 0x3f, sizeof(val));
	val[starty][startx] = 0;
	vis[starty][startx] = true;
	q.push(p);
	while (!q.empty())
	{
		bool find = false;
		p = q.front();
		q.pop();
		vis[p.x][p.y] = true;
		for (int i = p.x; i > 0; i--)
		{
			if (map[i][p.y] == 0)
				break;
			if (map[i][p.y] == 3)
			{
				find = true;
				val[i][p.y] = p.val + 1;
				endx = i, endy = p.y;
				break;
			}
			if (!vis[i][p.y])
			{
				val[i][p.y] = p.val + 1;
				point np;
				np.x = i, np.y = p.y, np.val = p.val + 1;
				vis[i][p.y] = true;
				q.push(np);
			}
		}
		if (find)
			break;
		for (int i = p.x; i <= h; i++)
		{
			if (map[i][p.y] == 0)
				break;
			if (map[i][p.y] == 3)
			{
				find = true;
				val[i][p.y] = p.val + 1;
				endx = i, endy = p.y;
				break;
			}
			if (!vis[i][p.y])
			{
				val[i][p.y] = p.val + 1;
				point np;
				np.x = i, np.y = p.y, np.val = p.val + 1;
				vis[i][p.y] = true;
				q.push(np);
			}
		}
		if (find)
			break;
		for (int i = p.y; i <= w; i++)
		{
			if (map[p.x][i] == 0)
				break;
			if (map[p.x][i] == 3)
			{
				find = true;
				val[p.x][i] = p.val + 1;
				endx = p.x, endy = p.y;
				break;
			}
			if (!vis[p.x][i])
			{
				val[p.x][i] = p.val + 1;
				point np;
				np.x = p.x, np.y = i, np.val = p.val + 1;
				vis[p.x][i] = true;
				q.push(np);
			}
		}
		if (find)
			break;
		for (int i = p.y; i > 0; i--)
		{
			if (map[p.x][i] == 0)
				break;
			if (map[p.x][i] == 3)
			{
				find = true;
				val[p.x][i] = p.val + 1;
				endx = p.x, endy = p.y;
				break;
			}
			if (!vis[p.x][i])
			{
				val[p.x][i] = p.val + 1;
				point np;
				np.x = p.x, np.y = i, np.val = p.val + 1;
				vis[p.x][i] = true;
				q.push(np);
			}
		}
		if (find)
			break;
	}
	printf("%d", val[endx][endy]);
	return 0;
}