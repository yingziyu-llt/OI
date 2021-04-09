#include<bits/stdc++.h>
int main()
{
 int n,sum=0,a[110][110],i,j;
 freopen("water.in","r",stdin);
 freopen("water.out","w",stdout);
 scanf("%d",&n);
  sum=n*n-1; 
  if(n==1||n==2)
    { 
     printf("0");
     return 0; 
    } 
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
  }
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(a[i][j]==10)
     {
      if(a[i][j+1]==1)sum--;
      if(a[i][j-1]==2)sum--;
      if(a[i-1][j]==3)sum--;
      if(a[i+1][j]==4)sum--;
     }
     if(a[i][j]==5)
     {
      if(a[i+1][j]!=5&&10&&0)sum--;
      if(a[i-1][j]!=5&&10&&0)sum--;
      if(a[i][j-1]!=5&&10&&0)sum--;
      if(a[i][j+1]!=5&&10&&0)sum--;
     }
     if(a[i][j]==0)sum--;
   }
  }
 printf("%d",sum);
 fclose(stdin);
 fclose(stdout);
 return 0;
}
