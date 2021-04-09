#include<queue>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
typedef pair<int,int> pair1;
queue <pair1> q;
bool prime[10010];
bool vis[10010];
int changex(int x,int ws,int n)
{
	int xx = pow(10,ws);
	int detla = n * xx - (x / xx % 10) * xx;
	return x + detla;
}
int main()
{
	memset(prime,1,sizeof(prime));
	prime[2] = true;
	for(int i = 2;i < 10010;i++)
	{
		if(prime[i])
			for(int j = 2;i * j < 10010;j++)
				prime[i * j] = 0;
	}
	int n;
	scanf("%d",&n);
	while(n--)
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
			for(int i = 0;i < 4;i++)
			{
				for(int j = 0;j < 10;j++)
				{
					int nx = changex(sec,i,j);
					if(nx < 1000) continue;
					if(prime[nx] && !vis[nx])
					{
						vis[nx] = true;
						p.first = fir + 1;
						p.second = nx;
						q.push(p);
					}
				}
			}
		}
		while(!q.empty()) q.pop();
		if(!flag) printf("Impossible\n");
	}
}
