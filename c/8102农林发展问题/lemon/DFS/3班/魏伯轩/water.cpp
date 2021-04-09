#include<cstdio>
#include<cmath>
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool pd[100][100];
int a[100][100],b[100][100];
void dfs(int x,int y,int t)
{
 int i;
 pd[x][y]=1;
 for(i=0;i<=3;i++)
 {
  if(a[x+dx[i]][y+dy[i]]==0)
  continue;
  if(i==0)
  if(a[x][y+1]!=1&&a[x][y]!=2)
  {
   a[x][y]=0;
   dfs(x,y+1,t);
   a[x][y]=b[x][y];
  }    
   if(i==1)
   if(a[x][y-1]!=2&&a[x][y]!=1)
   {
    a[x][y]=0;	
    dfs(x,y-1,t);
    a[x][y]=b[x][y];
   }
    if(i==2)
    if(a[x+1][y]!=3&&a[x][y]!=4)
    {
     a[x][y]=0;
     dfs(x+1,y,t);
     a[x][y]=b[x][y];
    }
     if(i==3)
     if(a[x-1][y]!=4&&a[x][y]!=3)
     {  
      a[x][y]=0;	
      dfs(x-1,y,t);
      a[x][y]=b[x][y];
     }
   }
 }
int main()
{
 int n,i,j,max=0;
 freopen("water.in","r",stdin);
 freopen("water.out","w",stdout);
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)	
 {
  scanf("%d",&a[i][j]);
  b[i][j]=a[i][j];
 } 
 for(i=0;i<=n;i++)
 for(j=0;j<=n;j++)	
 {
  if(a[i][j]==10)
  {
   a[i][j]=5;
   dfs(i,j,0);
  }
 }
 for(i=0;i<=n;i++)
 for(j=0;j<=n;j++)
 if(pd[i][j]==0&&a[i][j]!=0)
 max++;
 printf("%d",max);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
