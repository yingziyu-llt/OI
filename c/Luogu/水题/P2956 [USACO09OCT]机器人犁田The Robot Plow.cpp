#include<stdio.h>
int main()
{
	int a[250][250]={0},x,y,l,sum=0;
	int Xll, Yll, Xur, Yur ;
	scanf("%d %d %d",&x,&y,&l);
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
			a[i][j]=1;
	for(int i=0;i<l;i++)
	{
		scanf("%d %d %d %d",&Xll,&Yll,&Xur,&Yur);
		for(int j=Xll;j<=Xur;j++)
			for(int k=Yll;k<=Yur;k++)
				a[j][k]=0;
	}
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
			if(a[i][j]==1)
				sum++;
	int ans=x*y-sum;
	printf("%d",ans);
}
