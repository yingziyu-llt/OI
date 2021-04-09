#include<stdio.h>
#include<string.h>
struct aa
{
	int x,y,v;
}a[1000];
int map[100][100];
int xx[6]={0,0,0,1,-1},yy[6]={0,1,-1,0,0};
int main()
{
	while(1)
	{
		memset(map,0,sizeof(map));
		int m,n;
		scanf("%d%d",&m,&n);
		if(m==0&&n==0) break;
		for(int i=1;i<=m;i++)
		{
			char l[100]={0};
			scanf("%s",l+1); 
			for(int j=1;j<=n;j++)
			{
				if(l[j]=='.') map[i][j]=1;
				else if(l[j]=='#') map[i][j]=0;
				else if(l[j]=='@')
				{
					a[1].v=1;
					a[1].x=i;
					a[1].y=j;
					map[i][j]=1;
				}
				else if(l[j]='*') map[i][j]=2;
			}
		}
		int ft=1,ed=1;bool flag=false;
		while(ft<=ed)
		{
			for(int i=1;i<=4;i++)
			{
				if(map[a[ft].x+xx[i]][a[ft].y+yy[i]]==1)
				{
					ed++;
					map[a[ft].x+xx[i]][a[ft].y+yy[i]]=0;
					a[ed].v=a[ft].v+1;
					a[ed].x=a[ft].x+xx[i];
					a[ed].y=a[ft].y+yy[i];
				}
				if(map[a[ft].x+xx[i]][a[ft].y+yy[i]]==2)
				{
					ed++;
					map[a[ft].x+xx[i]][a[ft].y+yy[i]]=0;
					a[ed].v=a[ft].v+1;
					a[ed].x=a[ft].x+xx[i];
					a[ed].y=a[ft].y+yy[i];
					flag=true;
					break;
				}
				
			}ft++;
			if(flag) 
			{
				printf("%d\n",a[ed].v-1);
				break;
			}
		}
		if(!flag) printf("-1\n");
	}
	return 0;
}
