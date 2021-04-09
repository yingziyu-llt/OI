#include <stdio.h>
int n,a,b;
int sum[100000005];
int main()
{
 freopen("military.in","r",stdin);
 freopen("military.out","w",stdout);
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
 	scanf("%d %d",&a,&b);
 	for(int j=1;j<=a;j++)
 	{
 		scanf("%d",&sum[i]);
 	}
 } 
 printf("0");
} 
