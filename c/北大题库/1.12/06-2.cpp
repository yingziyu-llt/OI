#include<stdio.h>
int input(int &n,int &m,int &t,int a[10001][101],int b[10001][101],int c[10001])//ÂíÈğÑô
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
      for(int j=0;j<=m-1;j++)
     {
      scanf("%d %d",&a[i][j],&b[i][j]);
      if (a[i][j]) c[i]++;
     }
    scanf("%d",&t);
 }


int Jeffwork(int n,int m,int &ans,int t,int a[10001][101],int b[10001][101],int c[10001])//½ùğ©Ğñ
{
 int s,x;
 for(int i=1;i<=n;i++)
 {
  ans=(ans+b[i][t])%20123;
  s=(b[i][t]-1)%c[i]+1;
  if (a[i][t])x=1;else x=0;
  while (x<s)
  {
   if(t==m-1)t=0;else t++;
   if(a[i][t])x++;
  }
 }
}


int output(int ans)// »ÆÌìÓî
{
 printf("%d",ans);
}


int main()//½ùğ©Ğñ
{
 int n,m,t,ans=0,a[10001][101],b[10001][101],c[10001];
 input(n,m,t,a,b,c);
 Jeffwork(n,m,ans,t,a,b,c);
 output(ans);
 return 0;
}

