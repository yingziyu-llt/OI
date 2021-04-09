#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
struct point
{
	int x,y,val;
};
int dx[12]={2,2,-2,-2,-1,-1,1,1,-2,-2,2,2};
int dy[12]={2,-2,2,-2,-2,2,-2,2,1,-1,1,-1};
queue <point> q;
int map[1001][1001];
int main()
{
	int x1,x2,y1,y2,ans1;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	map[x1][y1] = 1;
	point np;
	np.x = x1,np.y = y1,np.val = 0;
	q.push(np);
	while(!q.empty())
	{
		int x,y,val;
		bool flag = false;
		x = q.front().x;
		y = q.front().y;
		val = q.front().val;
		for(int i = 0;i < 12;i++)
		{
			int nx = x + dx[i],ny = y + dy[i],nval = val + 1;
			if(nx == 1 && ny == 1) 
			{
				flag  = true;
				ans1 = nval;
				break;
			}
			if(nx > 0 &&nx <= 10010 && ny > 0 && ny <= 10010 && map[nx][ny] == 0)
			{
				map[nx][ny] = 1;
				np.x = nx,np.y = ny,np.val = nval;
				q.push(np);
			}
		}
		q.pop();
		if(flag) break;
	}
	while(!q.empty()) q.pop();
	memset(map,0,sizeof(map));
	printf("%d\n",ans1);
	ans1 = 0; 
	map[x2][y2] = 1;
	np.x = x2,np.y = y2,np.val = 0;
	q.push(np);
	while(!q.empty())
	{
		int x,y,val;
		bool flag = false;
		x = q.front().x;
		y = q.front().y;
		val = q.front().val;
		for(int i = 0;i < 12;i++)
		{
			int nx = x + dx[i],ny = y + dy[i],nval = val + 1;
			if(nx == 1 && ny == 1) 
			{
				flag  = true;
				ans1 = nval;
				break;
			}
			if(nx > 0 &&nx <= 100 && ny > 0 && ny <= 100 && map[nx][ny] == 0)
			{
				map[nx][ny] = 1;
				np.x = nx,np.y = ny,np.val = nval;
				q.push(np);
			}
		}
		q.pop();
		if(flag) break;
	}
	while(!q.empty()) q.pop();
	memset(map,0,sizeof(map));
	printf("%d\n",ans1);
}
