#include<stdio.h>
int cnt = 0;
int a[110][110];
int b[110][110];
int n;

void dfs(int x,int y)
{
	if(a[x][y] == 0) return;
	a[x][y] = 0;
	if(b[x][y] != 2 && a[x][y+1] != 1 && a[x][y+1] != 0 && y + 1 >= 1) {cnt--;dfs(x,y+1);}
	if(b[x][y] != 1 && a[x][y-1] != 2 && a[x][y-1] != 0 && y - 1 <= n) {cnt--;dfs(x,y-1);}	
	if(b[x][y] != 4 && a[x+1][y] != 3 && a[x+1][y] != 0 && x + 1 <= n) {cnt--;dfs(x+1,y);}
	if(b[x][y] != 3 && a[x-1][y] != 4 && a[x-1][y] != 0 && x - 1 >= 1) {cnt--;dfs(x-1,y);}	
}

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int ax,ay;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j] = a[i][j];
			if(a[i][j] == 10) ax = i,ay = j;
			if(a[i][j] != 10 && a[i][j] != 0) cnt++;
		}
	dfs(ax,ay);
	printf("%d",cnt);
}
