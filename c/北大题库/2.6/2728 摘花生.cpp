#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[110][110];
int main()
{
	int t;
	scanf("%d",&t);
	for(int ii=0;ii<t;ii++)
	{
		memset(a,0,sizeof(a));
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=x;i++)
			for(int j=1;j<=y;j++)
				scanf("%d",&a[i][j]);
		
		for(int i=1;i<=x;i++)
			for(int j=1;j<=y;j++)
				a[i][j]=max(a[i-1][j]+a[i][j],a[i][j-1]+a[i][j]);
		printf("%d\n",a[x][y]);
	}
}
