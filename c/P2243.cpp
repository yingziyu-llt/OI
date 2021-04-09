#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
struct ss
{
	int val, x, y;
};
int dx[] = {1, 1, -1, -1};
int dy[] = {-1, 1, -1, 1};
int need[] = {2, 1, 2, 1};
queue<ss> q, p;
int dis[510][510];
int map[510][510]; //1:'\' 2:'/'
int main()
{
	int r, c, t;
	scanf("%d", &t);
	for (int _i = 0; _i < t; _i++)
	{
		scanf("%d%d", &r, &c);
		if ((r + c) % 2 == 1)
		{
			printf("NO SOLUTION");
			continue;
		}
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= r; i++)
		{
			char s[510];
			scanf("%s", s);
			int len = strlen(s);
			for (int j = 0; j < len; j++)
			{
				if (s[j] == '\\')
					map[i][j + 1] = 1;
				else
					map[i][j + 1] = 2;
			}
		}
		ss now;
		now.val = 0;
		dis[1][1] = 0;
		now.x = 1;
		now.y = 1;
		q.push(now);
		while (!q.empty())
		{
			int nx, ny, nval;
			nx = q.front().x;
			ny = q.front().y;
			nval = q.front().val;
			for (int i = 0; i < 4; i++)
			{
				int xx, yy;
				xx = nx + dx[i];
				yy = ny + dy[i];
				if (map[xx][yy] != 0)
				{
					if (map[xx][yy] == need[i])
					{
						if (dis[xx][yy] > nval)
						{
							now.val = nval;
							now.x = xx;
							now.y = yy;
							q.push(now);
							dis[xx][yy] = nval;
						}
					}
					else
					{
						if (dis[xx][yy] > nval + 1)
						{
							now.val = nval + 1;
							now.x = xx;
							now.y = yy;
							q.push(now);
							dis[xx][yy] = nval + 1;
						}
					}
				}
			}
			q.pop();
		}
		printf("%d\n",dis[r][c]);
	}
	return 0;
}