#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int ans[10][10];
bool column[10][10], row[10][10],block[10][10];
int getBlock(int x,int y)
{
	int a,b;
	if(x <= 3)
		a = 0;
	else if(x <= 6)
		a = 1;
	else
		a = 2;

	if(y <= 3)
		b = 1;
	else if(y <= 6)
		b = 2;
	else
		b = 3;
	int res = a * 3 + b;
	return res;
}
int dfs(int x,int y)
{
	if(x == 10) return 1;
	if(ans[x][y])
	{
		int flag = 0;
		if(y == 9)
			flag = dfs(x + 1,1);
		else
			flag = dfs(x,y + 1);
		return flag;
	}
	else
	{
		int k = getBlock(x,y);
		for(int i = 1;i <= 9;i++)
		{
			if(!column[x][i] && !row[y][i] && !block[k][i])
			{
				ans[x][y] = i;
				column[x][i] = true;
				row[y][i] = true;
				block[k][i] = true;
				int flag = 0;
				if(y == 9)
					flag = dfs(x + 1,1);
				else
					flag = dfs(x,y + 1);
				if(flag) 
					return 1;
				else
				{
					ans[x][y] = 0;
					column[x][i] = false;
					row[y][i] = false;
					block[k][i] = false;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int _i = 0;_i < T;_i++)
	{
		char s[10010];
		memset(row,0,sizeof(row));
		memset(ans,0,sizeof(ans));
		memset(column,0,sizeof(column));
		memset(block,0,sizeof(block));
		for(int i = 1;i <= 9;i++)
		{
			scanf("%s",s);
			for(int j = 1;j <= 9;j++)
			{
				ans[i][j] = s[j - 1] - '0';
				if(s[j - 1] - '0' != 0)
				{
					column[i][s[j - 1] -'0'] = true;
					row[j][s[j - 1] -'0'] = true;
					block[getBlock(i,j)][s[j - 1] -'0']  = true;
				}
			}
		}
		dfs(1,1);
		for(int i = 1;i <= 9;i++)
		{
			for(int j = 1;j <= 9;j++)
			{
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}