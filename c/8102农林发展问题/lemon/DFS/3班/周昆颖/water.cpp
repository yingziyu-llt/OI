#include <bits/stdc++.h>
using namespace std;
int dx[8]={0,0,-1,1,1,1,-1,-1},dy[8]={1,-1,0,0,1,-1,1,-1},m,n,sum=0;
char a[101][101];
int search(int x,int y)//回溯 
{
for(int i=0;i<=7;i++)
{
int xx=x+dx[i],yy=y+dy[i];
if(xx>=1 && xx<=m && yy>=1 && yy<=n && a[xx][yy]=='W')//满足条件 
a[xx][yy]='.',search(xx,yy);//标记成已经包括的，回溯 
}
}
int main()
{
cin>>m>>n;
for(int i=1;i<=m;i++)
for(int j=1;j<=n;j++)
cin>>a[i][j];
for(int i=1;i<=m;i++)
for(int j=1;j<=n;j++)
if(a[i][j]=='W')//搜索 
search(i,j),sum++;//因为每一次搜索完之后都要加一 
cout<<sum;
}

