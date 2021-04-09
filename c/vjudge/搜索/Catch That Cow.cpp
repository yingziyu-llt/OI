#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
struct mypair
{
	int first,second;
};
typedef mypair pair1;
queue <pair1> q;
bool vis[110000];
int main()
{
	memset(vis,0,sizeof(vis));
	int a,b;
	scanf("%d%d",&a,&b);
	pair1 p;
	p.first = 0;
	p.second = a;
	q.push(p);
	bool flag = false;
	while(!q.empty())
	{
		int fir = q.front().first,sec = q.front().second;
		q.pop();
		if(sec == b)
		{
			printf("%d\n",fir);
			flag = true;
			break;
		}
		int nx = sec + 1;
		if(nx <= b)
		{
			p.first = fir + 1;
			p.second = nx;
			if(!vis[nx])
			{
				vis[nx] = true;
				q.push(p);
			}
		}
		nx = sec - 1;
		if(nx >= 0)
		{
			p.first = fir + 1;
			p.second = nx;
			if(!vis[nx])
			{
				vis[nx] = true;
				q.push(p);
			}
		}
		if (sec < 55000)
		{
			nx = sec * 2;
			p.first = fir + 1;
			p.second = nx;
			if (!vis[nx])
			{
				vis[nx] = true;
				q.push(p);
			}
		}
	}
	return 0;
}