#include<stdio.h>
int a[300][100];
int ni[100];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	a[0][1]=1;a[0][2]=-1;
	for(i=1;i<n+1;i++)
	{
		for(j=1;a[i-1][j]!=-1;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
		a[i][j+1]=-1;
		ni[i]=j-1;
	}
	for(i=1;i<n+1;i++){
		for(j=1;j<=ni[i];j++)
			printf("%d ",a[i][j]);
		printf("\n");
		}
	return 0;
}
