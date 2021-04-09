#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#define INF 2147483633
using namespace std;
struct aa
{
	int x,y,val;
};
int a[1002];
int mapp[400][1000];
int n,m;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int map[400][1000];
queue<aa>q;
int bfsf(int t,int f)
{
	memcpy(mapp,map,sizeof(mapp));
	aa c;
	c.val=0;
	c.x=0;
	c.y=0;
	q.push(c);
	while(!q.empty())
	{
		int x=q.front().x;
		int y=q.front().y;
		int val=q.front().val;
		map[x][y]=f;
		for(int i=0;i<4;i++)
		{
			if(x+dx[i]>=0&&x+dx[i]<n&&y+dy[i]>=0&&y+dy[i]<m)
			{
				if(map[x+dx[i]][y+dy[i]]==t) 
				{
					map[x][y]=f;
					aa c;
					c.val=val+1;
					c.y=y+dy[i];
					c.x=x+dx[i];
					q.push(c);
				}
				else if(map[x+dx[i]][y+dy[i]]==2)
				{
					map[x][y]=f;
					return val+1;
				}
			}
		
		}	
	}
	return INF;
}
int main()
{
	//freopen("mc.in","r",stdin);
	//freopen("mc.out","w",stdout);
	int xxx,tot=0;
	scanf("%d",&xxx);
	for(int i=0;i<xxx;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<xxx;i++)
	{
		tot++;
		if(a[i]==1)
		{
			tot++;
			break;
		}
	}
	tot--;
	memset(mapp,0,sizeof(mapp));
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&mapp[i][j]);
		}
	}
	int x1=0,y1=0;
	if(tot%4==0||tot%4==1)
	{
		
		x1=bfsf(0,1);
		if(tot%4==1) y1=bfsf(1,0)+1;
		else         y1=bfsf(1,0)+2;
	}
	else
	{
		x1=bfsf(1,0);
		if(tot%4==3) y1=bfsf(0,1)+1;
		else         y1=bfsf(0,1)+2;
	}
	printf("%d",min(x1,y1));
	return 0;
}
