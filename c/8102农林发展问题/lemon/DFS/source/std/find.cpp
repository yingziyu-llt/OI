#include<stdio.h>
#include<string.h>

struct cmp
{
	char map[110][110];
}a[110];
int n,m;
bool flag;
int ax[5] = {0,1,0,-1,0};
int ay[5] = {0,0,1,0,-1};

void dfs(int k,int x,int y)
{
	if(flag == true) return;
	if(a[k].map[x][y] == '@') {flag = true;return;}
	a[k].map[x][y] = '#';
	for(int i = 1 ; i <= m;i++)
	{
		if(a[i].map[x][y] != '#' && m >= 3) dfs(i,x,y);
	}
	for(int i = 1 ; i <= 4 ; i++)
	{
		int tx = x + ax[i];
		int ty = y + ay[i];
		if(tx >= 1 && tx <= n && ty >= 1 && ty <= n && a[k].map[tx][ty]!='#') 
			dfs(k,tx,ty);
	}
}

int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
 	while(scanf("%d%d",&m,&n)&&m&&n)
 	{
 		flag = false;
 		memset(a,0,sizeof(a));
 		if(m == 1)
 		{
 			char ch[10010];
		 	scanf("%s",ch);
			for(int i = 0 ; i < strlen(ch) ; i++)
			{
				if(ch[i] == '@') {printf("YES\n");break;}
				else if(ch[i] == '#') {printf("No\n");break;}
			}
		}
		else if(m == 2)
		{
			for(int i = 1 ; i <= n ; i++)
				scanf("%s",a[1].map[i] + 1);
			dfs(1,1,1);
			if(flag == false) printf("No\n");
			else printf("YES\n");
		}
		else if(m >= 3)
		{
			for(int i = 1 ; i <= m ; i++)
				for(int j = 1 ; j <= n ; j++)
					scanf("%s",a[i].map[j] + 1);
			dfs(1,1,1);
			if(flag == false) printf("No\n");
			else printf("YES\n");
		}
 	}
 }
