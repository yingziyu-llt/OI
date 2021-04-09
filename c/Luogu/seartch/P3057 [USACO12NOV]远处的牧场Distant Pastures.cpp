#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 40;
struct point
{
	int val,x,y;
};
int a,b;
int dis[N][N];
int map[N][N];
bool inQueue[N][N];
int n;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1},ans = 0; 
queue <point> q;
int BFS(int x,int y)
{
	memset(dis,0x3f,sizeof(dis));
	memset(inQueue,0,sizeof(inQueue));
	while(!q.empty())
		q.pop();
	point p;
	p.x = x,p.y = y,p.val = 0;
	q.push(p);
	dis[x][y] = 0;
	inQueue[x][y] = true;
	while(!q.empty())
	{
		point np = q.front();
		q.pop();
		inQueue[np.x][np.y] = false;
		for(int i = 0;i < 4;i++)
		{
			int nx = np.x + dx[i],ny = np.y + dy[i];
			if(nx > 0 && nx <= n && ny > 0 && ny <= n)
			{
				int nval = dis[np.x][np.y];
				if(map[nx][ny] != map[np.x][np.y])
					nval += b;
				else
					nval += a;
				if(nval < dis[nx][ny])
				{
					dis[nx][ny] = nval;
					p.x = nx;
					p.y = ny;
					p.val = nval;
					if(!inQueue[nx][ny])
						q.push(p),inQueue[nx][ny] = true;
				}
			}
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			ans = max(ans,dis[i][j]);
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i = 0;i < n;i++)
	{
		char s[N];
		scanf("%s",s);
		int len = strlen(s);
		for(int j = 0;j < len;j++)
			map[i + 1][j + 1] = s[j] == '(' ? 1:2;
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			BFS(i,j);
	printf("%d",ans);
	return 0;
}