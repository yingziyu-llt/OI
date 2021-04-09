#include <bits/stdc++.h>
using namespace std;
int dx[8]={0,0,-1,1};
int dy[8]={1,-1,0,0};
int m,n,sum=0,a[101][101];
int search(int x,int y)
{
	for(int i=0;i<=7;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=1 && xx<=m && yy>=1 && yy<=n && a[xx][yy]==10) 
		a[xx][yy]=1,search(xx,yy);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(n<=2)continue;
			if(a[i][j]==10){
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++){
						if(a[i-1][j]==0&&a[i+1][j]==0&&a[i][j-1]==0&&a[i][j+1]==0)
						{
							if(i==1)
							{
								if(j==1)printf("%d",n*n-4);
								else if(j==n)printf("%d",n*n-4);
								else printf("%d",n*n-6);
							}
							else if(j==1)
							{
								if(i==1)printf("%d",n*n-4);
								else if(i==n)printf("%d",n*n-4);
								else printf("%d",n*n-6);
							} 
							else if(i==n&&j==n)printf("%d",n*n-4);
							else if(i==n)printf("%d",n*n-6);
							else if(j==n)printf("%d",n*n-6);
							else printf("%d",n*n-9);
						}	
					}
			}	
		}
		if(n<=2){printf("0");return 0;}	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==10)
				search(i,j),sum++; 
	printf("%d",sum);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
