#include <stdio.h>
#include <string.h>
int map[300][300],a[101][101],xx,yy;
void dfs(int x,int y,int z)
{
 int p,q;	
 if(z==-1) return ;
 else
 {
  if(z!=0&&z!=10) map[x][y]=1;
  if(z==10) 
  {
   xx=x;
   yy=y;
   map[x][y]=4;
  }
  if(z==1) 
  {
   map[x][y-1]=3;
   if(map[x+1][y]==0)  map[x+1][y]=2;
   if(map[x-1][y]==0) map[x-1][y]=2;
   if(map[x][y+1]==0) map[x][y+1]=2;
  }
  if(z==2) 
  {
   map[x][y+1]=3;
   if(map[x][y-1]==0)  map[x][y-1]=2;
   if(map[x+1][y]==0)  map[x+1][y]=2;
   if(map[x-1][y]==0)  map[x-1][y]=2;
  }
  if(z==3) 
  {
   map[x-1][y]=3;
   if(map[x][y-1]==0) map[x][y-1]=2;
   if(map[x][y+1]==0) map[x][y+1]=2;
   if(map[x-1][y]==0) map[x-1][y]=2;
  }
  if(z==4) 
  {
   map[x+1][y]=3;
   if(map[x+1][y]==0) map[x+1][y]=2;
   if(map[x][y-1]==0) map[x][y-1]=2;
   if(map[x][y+1]==0) map[x][y+1]=2;
  }
  if(z==5) 
  {
   if(map[x-1][y]==0) map[x-1][y]=2;
   if(map[x+1][y]==0) map[x+1][y]=2;
   if(map[x][y-1]==0) map[x][y-1]=2;
   if(map[x][y+1]==0) map[x][y+1]=2;
  }
 }	
}
void dfs(int i,int j)
{
 if(map[i][j]!=0)
 {
  map[i][j]=0;
  if(map[i+1][j]==1||map[i+1][j]==2)
  {	
   dfs(i+1,j);	
  }	
  if(map[i][j+1]==1||map[i][j+1]==2)
  {
   dfs(i,j+1);	
  }	
  if(map[i-1][j]==1||map[i-1][j]==2)
  {
   dfs(i-1,j);	
  }	
  if(map[i][j-1]==1||map[i][j-1]==2)
  {
   dfs(i,j-1);	
  }	
 }	
}
int main()
{
 freopen("water.in","r",stdin);
 freopen("water.out","w",stdout);
 memset(a,-1,sizeof(a));	
 int n,i,j,l=0;
 scanf("%d",&n);
 for(i=1;i<=n*2-1;++i)
 {
  for(j=1;j<=n*2-1;++j)
  {
   scanf("%d",&a[i][j]);
   j++;	
  }
  i++;		
 }
 for(i=1;i<=n*2-1;++i)
 {
  for(j=1;j<=n*2-1;++j)
  {
   dfs(i,j,a[i][j]);	
  }	 
 }
 dfs(xx,yy);
 for(i=0;i<=n*2-1;++i)
 {
  for(j=0;j<=n*2-1;++j)
  {
   if(map[i][j]==1) l++;
  }
 }
 printf("%d",l);	
} 
