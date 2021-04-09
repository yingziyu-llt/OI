#include <bits/stdc++.h>
int rt[4]={0,0,1,-1};
int ry[4]={1,-1,0,0};
bool pd[105][105];
int a[105][105],b[105][105];
void dfs(int q,int y,int t)
{
int i;
pd[q][y]=1;
for(i=0;i<=3;i++)
{
if(a[q+rt[i]][y+ry[i]]==0)continue;
if(i==0)
if(a[q][y+1]!=1&&a[q][y]!=2)
{
a[q][y]=0;
dfs(q,y+1,t);
a[q][y]=b[q][y];
}  
if(i==1)
if(a[q][y-1]!=2&&a[q][y]!=1)
{
a[q][y]=0;
dfs(q,y-1,t);
a[q][y]=b[q][y];
}
if(i==2)
if(a[q+1][y]!=3&&a[q][y]!=4)
{
a[q][y]=0;
dfs(q+1,y,t);
a[q][y]=b[q][y];
}
if(i==3)
if(a[q-1][y]!=4&&a[q][y]!=3)
{
a[q][y]=0;
dfs(q-1,y,t);
a[q][y]=b[q][y];
}
}
}
int main()
{
int n,i,j,ans=0;
//freopen("water.in","r",stdin);
//freopen("water.out","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
b[i][j]=a[i][j];
}
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
if(a[i][j]==10)
{
a[i][j]=5;
dfs(i,j,0);
}
}
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(pd[i][j]==0&&a[i][j]!=0)ans++;
printf("%d",ans);
//fclose(stdin);
//fclose(stdout);
return 0;
}
