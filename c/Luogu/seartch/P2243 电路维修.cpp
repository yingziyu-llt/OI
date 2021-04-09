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
deque <ss> q;
int dis[510][510];
int map[510][510]; //1:'\' 2:'/'
int main()
{
	int r, c, t;
	scanf("%d", &t);
	for (int _i = 0; _i < t; _i++)
	{
		bool flag = false;
		while(!q.empty())
			q.pop_front();
		scanf("%d%d", &r, &c);
		if ((r + c) % 2 == 1)
		{
			printf("NO SOLUTION\n");
			flag = true;
		}
		memset(dis, 0x3f, sizeof(dis));
		memset(map,0,sizeof(map));
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
		if(flag) continue;
		ss now;
		now.val = 0;
		dis[1][1] = 0;
		now.x = 1;
		now.y = 1;
		q.push_back(now);
		while (!q.empty())
		{
			int nx = q.front().x,ny = q.front().y,nval = q.front().val;
			q.pop_front();
			for(int i = 0;i < 4;i++)
			{
				int xx  = nx + dx[i],yy = ny + dy[i],vval = nval;
				if(xx > 0 && xx <= r + 1 && yy > 0 && yy <= c + 1)
				{
					if(i == 0) 
						if(map[nx][ny - 1] == 1)
							vval ++;
					if(i == 1)
						if(map[nx][ny] == 2)
							vval ++;
					if(i == 2)
						if(map[xx][yy] == 2)
							vval++;
					if(i == 3)
						if(map[nx - 1][ny] == 1)
							vval++;
					if(vval < dis[xx][yy])
					{
						if  (vval != nval)
						{
							now.x = xx;
							now.y = yy;
							now.val = vval;
							dis[xx][yy] = vval;
							q.push_back(now);
						}
						else
						{
							now.x = xx;
							now.y = yy;
							now.val = vval;
							dis[xx][yy] = vval;
							q.push_front(now);
						}
					}
				}
			}
		}
		printf("%d\n",dis[r + 1][c + 1]);
	}
	return 0;
}