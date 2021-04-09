#include<stdio.h>
#include<algorithm>
using namespace std;
int dis[110][110];
int mustCross[10000];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++)
		scanf("%d",&mustCross[i]);
	
	for(int i = 0;i < m;i++)
		mustCross[i] --;
		
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			dis[i][j] = 0x3f3f3f3f;
	
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			scanf("%d",&dis[i][j]);
	
	for(int i = 0;i < n;i++)
		dis[i][i] = 0;
	
	for(int k = 0;k < n;k++)
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				dis[i][j] = min(dis[i][k] + dis[k][j],dis[i][j]);//Floyd
	
	int tot = 0,now = 0;
	for(int i = 0;i < m;i++)
	{
		tot += dis[now][mustCross[i]];
		now = mustCross[i];
	}
	printf("%d",tot);
	return 0;
} 
