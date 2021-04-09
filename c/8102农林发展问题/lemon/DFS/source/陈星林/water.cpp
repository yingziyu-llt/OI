#include <stdio.h>
#include <string.h>
int a[105][105];
int n,i,j,s;
void Bfs(int x,int y)
{
 if(a[x][y-1]==0){
 s--;
 a[x][y-1]=-1;
 Bfs(x,y-1);	
 }
 if(a[x][y+1]==0){
 	s--;
 	a[x][y+1]=-1;
 	Bfs(x,y+1);
 }
 if(a[x-1][y]==0){
 	s--;
 	a[x-1][y]=-1;
 	Bfs(x-1,y);
 }
 if(a[x+1][y]==0){
 	s--;
 	a[x+1][y]=-1;
 	Bfs(x+1,y);
 } 
 if(a[x-1][y-1]==0){
 	s--;
 	a[x-1][y-1]=-1;
 	Bfs(x-1,y-1);
 } 
 if(a[x-1][y+1]==0){
 	s--;
 	a[x-1][y+1]=-1;
 	Bfs(x-1,y+1);
 } 
 if(a[x+1][y-1]==0){
 	s--;
 	a[x+1][y-1]=-1;
 	Bfs(x+1,y-1);
 } 
 if(a[x+1][y+1]==0){
 	s--;
 	a[x+1][y+1]=-1;
 	Bfs(x+1,y+1);
 } 
 }
int main()
{ 
 scanf("%d",&n);
 memset(a,-1,sizeof(a));
 freopen("water.in","r",stdin);
 freopen("water.out","w",stdout);
 for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   	scanf("%d",&a[i][j]);
 s=n*n;  	
 for(i=1;i<=n;i++)	
 {
  for(j=1;j<=n;j++)
  	 if(a[i][j]==10)break;
  if(a[i][j]==10)break;
 }
  Bfs(i,j);	
  if(a[i-1][j]==-1&&a[i+1][j]==-1&&a[i][j-1]==-1&&a[i][j+1]==-1)
  {
  	printf("%d",s-1);
  	return 0;
  }
  printf("%d",s);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
