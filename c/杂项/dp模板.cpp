#include<stdio.h>
#define maxm 201
#define maxn 301
int m,n;
int w[maxn],c[maxn];
int f[maxn][maxm];
int max(int x,int y)
{
	if(x<y) return y;
	else    return x;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		scanf("%d %d",&w[i],&c[i]);
	for(int i=1;i<=m;i++)
		for(int v=n;v>0;v--)
			if(w[i]<=v) f[i][v]=max(f[i-1][v],f[i-1][v-w[i]]+c[i]);
			 else f[i][v]=f[i-1][v];
	printf("%.2f",(double)f[m][n]);
	return 0;
}
