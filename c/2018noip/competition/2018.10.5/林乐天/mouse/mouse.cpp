#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct aa
{
	int x, y;
	int val;
} a;
queue<aa> q;
int dy[4] = {-1, 0, 1, 0}, dx[] = {0, -1, 0, 1};
struct s
{
	int x,y,val;
}ans[1000];
bool cmp(s a,s b)
{
	if(a.val != b.val)
		return a.val < b.val;
	else if(a.x != b.x)
		return a.x < b.x;
	else 
		return a.y > b.y;
}
char map[100][100];
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	int n, m;
	bool flag = false;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", map[i]);
		if (!flag)
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 'R')
				{
					a.x = i;
					a.y = j;
					a.val = 0;
					q.push(a);
					flag = true;
					break;
				}
			}
	}
	int x, y, val = 0;
	int count = 0;
	flag = false;
	while (!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		val = q.front().val + 1;
		for (int i = 0; i < 4; i++)
		{
			if (map[x + dx[i]][y + dy[i]] == 'F' && x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < m && y + dy[i] >= 0)
			{
				ans[count].val = val;
				ans[count].x = y + dy[i] + 1;
				ans[count].y = x + dx[i] + 1;
				count++;
				flag = true;
			}
			if (x + dx[i] < m && x + dx[i] >= 0 && y + dy[i] < n && y + dy[i] >= 0 && map[x + dx[i]][y + dy[i]] != 'B')
			{
				a.val = val;
				a.x = x + dx[i];
				a.y = y + dy[i];
				q.push(a);
				map[x + dx[i]][y + dy[i]] = 'B';
			}
		}
		map[x][y] = 'B';
		q.pop();
	}
	if(!flag)
		printf("-1");
	else
	{
		int i = 0;
		sort(ans,ans + count,cmp);
		while(i < count)
		{
			printf("(%d,%d) %d\n",ans[i].x,ans[i].y,ans[i].val);
			i++;
		}
	}
	return 0;
}
