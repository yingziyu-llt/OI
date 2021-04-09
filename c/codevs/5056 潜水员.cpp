#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int w1[1005],w2[1005],v[1005];
int f[101][101];
int main()
{
	int m,n,k;
	scanf("%d %d%d",&m,&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d",&w1[i],&w2[i],&v[i]);
	memset(f,126,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=k;i++)
	{
		for(int j=m;j>=0;--j)
		{
			for(int k=n;k>=0;--k)
			{
				int t1=min(j+w1[i],m),t2=min(k+w2[i],n);
				f[t1][t2]=min(f[i][j]+v[i],f[t1][t2]);
			}
		}
	}
	printf("%d",f[m][n]);
	return 0;
}
