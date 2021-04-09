#include<stdio.h>
int map[100][100];
int nmap[100][100];
int m,n;
int cnt,max=-1;
int dfs(int x,int y,int c)
{
	if(nmap[x][y]==0)
	{
		nmap[x][y]=1;
		int a=map[x][y];
		int size=1;
		if(a>=8)
			a-=8;
		else if(x<m-1)
			size+=dfs(x+1,y,c+1);
		if(a>=4)
			a-=4;
		else if(y<n-1)
			size+=dfs(x,y+1,c+1);
		if(a>=2)
			a-=2;
		else if(x>0) 
			size+=dfs(x-1,y,c+1);	
		if(a>=1)
			a-=1;
		else if(y>=0)
			size+=dfs(x,y-1,c+1);
		return size;
	}
	else return 0;
}
int main()
{
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int aa=dfs(i,j,1);
			if(aa!=0) cnt++;
			max= max>aa ? max :aa;
		}
	}
	printf("%d\n%d",cnt,max);
}
