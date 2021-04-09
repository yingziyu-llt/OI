#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[110][110];
int map[110][110];
int w[101][101];
int r, c;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int dfs(int i,int j)
{
	if(w[i][j]) return map[i][j];
	int tmp[4]={0},x=0;
	w[i][j]=1;
	for (int k = 0; k < 4; k++)
	{
		if (a[i][j] > a[i + dx[k]][j + dy[k]]&&i + dx[k]>0&&i + dx[k]<=r&&j + dy[k]>0&&j + dy[k]<=c) tmp[x++]=dfs(i+dx[k],j+dy[k]);
	}
	return map[i][j]=max(max(tmp[0]+1,tmp[1]+1),max(tmp[2]+1,tmp[3]+1));
}
int main()
{

	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			map[i][j]=1;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			scanf("%d", &a[i][j]);
	int max = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			int sum=dfs(i,j);
			if(max<sum) max=sum;
		}
	}
	printf("%d", max);
	return 0;
}
