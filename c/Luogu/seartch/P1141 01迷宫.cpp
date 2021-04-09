#include <queue>
#include <cstdio>
#include <string.h>
#define S 1011
using namespace std;
int tot = 0;
struct s
{
	int x, y;
} aa;
int mapx[S][S];
int map[S][S];
char tmp[1000];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
queue<s> a;
void cpy(int a[S][S], int b[S][S])
{
	for (int i = 0; i < S; i++)
		for (int j = 0; j < S; j++)
			b[i][j] = a[i][j];
}
int main()
{
	int n;
	scanf("%d", &n);
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", tmp);
		for (int j = 1; j <= n; j++)
		{
			if (tmp[j - 1] == '0')
				mapx[i][j] = 1;
			if (tmp[j - 1] == '1')
				mapx[i][j] = -1;
		}
	}
	for (int _i = 0; _i < m; _i++)
	{
		int x, y;
		tot = 0;
		scanf("%d %d", &x, &y);
		aa.x = x;
		aa.y = y;
		a.push(aa);
		cpy(mapx, map);
		while (!a.empty())
		{
			for (int i = 0; i < 4; i++)
			{
				if (map[a.front().x + dx[i]][a.front().y + dy[i]] == -map[a.front().x][a.front().y] && map[a.front().x][a.front().y] != 0)
				{
					aa.x = a.front().x + dx[i];
					aa.y = a.front().y + dy[i];
					tot++;
					a.push(aa);
				}
			}
			map[a.front().x][a.front().y] = 0;
			a.pop();
		}
		printf("%d\n", tot + 1);
	}
	return 0;
}