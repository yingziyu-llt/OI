#include <stdio.h>
int a[101][101];
void dfs(int i,int j)
{
 if(a[i][j]==1)
 {
  a[i][j]=-1;
  if(a[i+1][j]&&a[i+1][j]!=3) dfs(i+1,j);
  if(a[i-1][j]&&a[i-1][j]!=4) dfs(i-1,j);
  if(a[i][j+1]&&a[i][j+1]!=2) dfs(i,j+1);
 }
 if(a[i][j]==2)
 {
  a[i][j]=-1;
  if(a[i+1][j]&&a[i+1][j]!=3) dfs(i+1,j);
  if(a[i-1][j]&&a[i-1][j]!=4) dfs(i-1,j);
  if(a[i][j-1]&&a[i][j-1]!=1) dfs(i,j-1);
 }
 if(a[i][j]==3)
 {
  a[i][j]=-1;
  if(a[i+1][j]&&a[i-1][j]!=4) dfs(i+1,j);
  if(a[i][j-1]&&a[i][j-1]!=1) dfs(i,j-1);
  if(a[i][j+1]&&a[i][j+1]!=2) dfs(i,j+1);
 }
 if(a[i][j]==4)
 {
  a[i][j]=-1;
  if(a[i-1][j]&&a[i-1][j]!=3) dfs(i-1,j);
  if(a[i][j-1]&&a[i][j-1]!=1) dfs(i,j-1);
  if(a[i][j+1]&&a[i][j-1]!=2) dfs(i,j+1);
 }
 if(a[i][j]==10||a[i][j]==5)
 {
  a[i][j]=-1;
  if(a[i+1][j]&&a[i+1][j]!=4) dfs(i+1,j);
  if(a[i-1][j]&&a[i-1][j]!=3) dfs(i-1,j);
  if(a[i][j-1]&&a[i][j-1]!=2) dfs(i,j-1);
  if(a[i][j+1]&&a[i][j+1]!=1) dfs(i,j+1);
 }
}
int main()
{
 int n;
 freopen("water.in","r",stdin);
 freopen("water.out","w",stdout);
 scanf("%d",&n);
 int i,j,s=0;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i][j]==10) dfs(i,j);
  }
 }
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i][j]==0) s--;
   if(a[i][j]!=-1) s++;
  }
 }
 printf("%d",s);
 fclose(stdin);
 fclose(stdout);
} 
