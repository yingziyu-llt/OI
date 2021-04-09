#include<stdio.h>
#pragma GCC optimize(2)

using namespace std;

int a[16][16];
int slv[16];
int count = 0;
int n;

void sets(int x,int y)
{
	a[x][y]++;
	for(int i = 1;i < n;i++)
	{
		if(y + i < n)
			a[x][y + i]++;
		if(x + i < n)
			a[x + i][y]++;
		if(y - i >= 0)
			a[x][y - i]++;
		if(x - i >= 0)
			a[x - i][y]++;
		if(y - i >= 0 && x + i < n)
			a[x + i][y - i]++;
		if(x + i < n && y + i < n)
			a[x + i][y + i]++;
		if(y - i >= 0 && x - i >= 0)
			a[x - i][y - i]++;
		if(x - i >= 0&&y + i < n)
			a[x - i][y + i]++;
	}
}

void clean(int x,int y)
{
	a[x][y]--;
	for(int i = 1;i < n;i++)
	{
		if(y + i < n)
			a[x][y + i]--;
		if(x + i < n)
			a[x + i][y]--;
		if(y - i >= 0)
			a[x][y - i]--;
		if(x - i >= 0)
			a[x - i][y]--;
		if(y - i >= 0 && x + i < n)
			a[x + i][y - i]--;
		if(x + i < n && y + i < n)
			a[x + i][y + i]--;
		if(y - i >= 0 && x - i >= 0)
			a[x - i][y - i]--;
		if(x - i >= 0&&y + i < n)
			a[x - i][y + i]--;
	}
}

void dfs(int x)
{
	for(int i = 0;i < n;i++)
	{
		if(a[x][i] == 0)
		{
			if(x == n)
			{
				if(count < 3) 
				{
					for(int i = 0;i < n;i++)
						printf("%d ",slv[i]);
					printf("\n");
				}
				count++;
				return;
			}	
			else
			{
				sets(x,i);
				slv[x] = i + 1;
				dfs(x + 1);
				slv[x] = 0;
				clean(x,i);
			}
			
		}
	}
}

int main()
{
	scanf("%d",&n);
	dfs(0);
	printf("%d",count);
}
