#include<stdio.h>
#include<queue>
using namespace std;
struct aa
{
	int x,y,val;
};
queue <aa> q;
int map[1010][1010],dx[4] = {0,0,-1,1},dy[4] = {-1,1,0,0};
int main()
{
	int n,ans;
	int x1,y1,x2,y2;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		char s[1011];
		scanf("%s",&s);
		for(int j = 0;j < n;j++)
			map[i][j] = s[j] - '0';
	}
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	x1--,x2--,y1--,y2--; 
	aa s;
	s.val = 0;
	s.x = x1;
	s.y = y1;
	q.push(s);
	while(!q.empty())
	{
		s = q.front();
		int x = s.x,y = s.y,val = s.val;
		if(x == x2 && y == y2) 
		{
			ans = val;
			break;
		}
		for(int i = 0;i < 4;i++)
		{
			int nx = x + dx[i],ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == 0)
			{
				s.val = val + 1;
				s.x = nx;
				s.y = ny;
				q.push(s);
				map[nx][ny] = 1;
			}
		}
		map[x][y] = 1;
		q.pop();
	}
	printf("%d",ans);
	return 0;
} 
