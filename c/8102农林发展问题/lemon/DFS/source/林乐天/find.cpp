#include<stdio.h>
#include<string.h>
char a[10][15][15];
struct aa
{
	int x,y,z;
}no[3000];
int main()
{
	//freopen("find.in","r",stdin);
	//freopen("find.out","w",stdout);
	int n,m;
	while(1)
	{
		scanf("%d %d",&m,&n);
		memset(a,'#',sizeof(a));
		if(m==0&&n==0) break;
		if(m==1)
		{
			scanf("%s",&a[1][1]+1);
		}
		else if(m==2)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%s",&a[1][j]+1);
			}
		}
		else
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=n;j++)
				{
					scanf("%s",&a[i][j]+1);
				}
			}
		int st=1,ed=1;
		bool flag=true;
		no[1].x=1;
		no[1].y=1;
		no[1].z=1;
		while(st<=ed)
		{
			int x=no[st].x,y=no[st].y,z=no[st].z;
			if(a[z][x][y]=='@') 
			{
				printf("YES\n");
				flag=false;
				break;
			}
			a[z][x][y]='#';
			for(int i=1;i+z<m;i++) 
			{
				if(a[z+i][x][y]=='.')
				{
					a[z][x][y]='#';
					no[++ed].x=x;
					no[ed].y=y;
					no[ed].z=z+i;
				}
				else if(a[z+i][x][y]=='@')
				{
					a[z][x][y]='#';
					printf("YES\n");
					flag=false;
					break;
				}
				
			}
		for(int i=1;z-i>=0;i++)
		{
			if(a[z-i][x][y]=='.')
			{
				a[z][x][y]='#';
				no[++ed].x=x;
				no[ed].y=y;
				no[ed].z=z-i;
			}
			else if(a[z-i][x][y]=='@')
			{
				a[z][x][y]='#';
				printf("YES\n");
				flag=false;
				break;
			}
		}	
			if(a[z][x+1][y]=='.')
			{
				a[z][x][y]='#';
				no[++ed].x=x+1;
				no[ed].y=y;
				no[ed].z=z;
			}
			else if(a[z][x+1][y]=='@')
			{
				a[z][x][y]='#';
				printf("YES\n");
				flag=false;
				break;
			}
			
			if(a[z][x-1][y]=='.'&&x-1>0)
			{
				a[z][x][y]='#';
				no[++ed].x=x-1;
				no[ed].y=y;
				no[ed].z=z;
			}
			else if(a[z][x-1][y]=='@'&&x-1>0)
			{
				a[z][x][y]='#';
				printf("YES\n");
				flag=false;
				break;
			}
			if(a[z][x][y+1]=='.')
			{
				a[z][x][y]='#';
				no[++ed].x=x;
				no[ed].y=y+1;
				no[ed].z=z;
			}
			else if(a[z][x][y+1]=='@')
			{
				a[z][x][y]='#';
				printf("YES\n");
				flag=false;
				break;
			}
			if(a[z][x][y-1]=='.'&&y-1>0)
			{
				a[z][x][y]='#';
				no[++ed].x=x;
				no[ed].y=y-1;
				no[ed].z=z;
			}
			else if(a[z][x][y-1]=='@'&&y-1>0)
			{
				a[z][x][y]='#';
				printf("YES\n");
				flag=false;
				break;
			}
			a[z][x][y]='#';
			st++;
		}
		if(flag) printf("No\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
