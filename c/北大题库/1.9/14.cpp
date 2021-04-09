//1.9 14Ã‚
#include<stdio.h>
int dt[10001][5];
int main()
{
	int a,b,g,k,i,n,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&a,&b,&g,&k);
		dt[i][1]=a;dt[i][2]=a+g;dt[i][3]=b;dt[i][4]=b+k;
	}
	scanf("%d %d",&x,&y);
	for(i=n;i>=1;i--)
		if(x>=dt[i][1]&&x<=dt[i][2]&&y>=dt[i][3]&&y<=dt[i][4]){printf("%d",i);return 0;}
	printf("-1");
	return 0;
}
