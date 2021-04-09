#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
struct node
{
	int x,val;
}nodex;
int a[1000][50];
bool map[50][50];
queue <node> q;
int main()
{
	int n,m,count;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y] = true;
		map[y][x] = true;
	}
	int k;
	scanf("%d",&k);
	for(int i = 0;i < k;i++)
	{
		bool flag[40] = {0};
		count = 0;
		int x,y,tmp;
		scanf("%d%d",&x,&y);
		nodex.val = 0;
		nodex.x = x;
		q.push(x);
		while(!q.empty())
		{
			if(tmp != q.front().val) count = 0,tmp = q.front().val;
			for(int j = 0;j < n;j++)
			{
				if(map[q.front().x][j])
				{
					nodex.val = q.front().val + 1;
					nodex.x = j;
					q.push(node);
				}
			}
			a[q.front().val][count++] = q.front().x;
			if(q.front().x == y)
				break;
			q.pop();
		}
		memset(a[count],0,sizeof(a[count]));
		a[count][0] = y;
		bool flag2[50][50] = {0};
		for(int j = tmp;j >= 0;j--)
		{
			for(int f = 0;f < n;f++)
			{
				for(int d = 0;d < n;d++)
					for(int b = 0;b < n;b++)
						if(a[j][f] == a[d][b])
							flag[s[d][b]] = true,flag[s[d][b]] = true;
				
			}
		}
	}

	
}