#include<stdio.h>
#include<algorithm>
using namespace std;
int a[9][31000],order[10];int n,m,k;
int cc[10000];
bool chosen[10];
bool isABiggerThanB(int ai,int bi)
{
	for(int i = k;i >= 0;i++)
	{
		if(a[ai][i] > a[bi][i]) return true;
		if(a[ai][i] < a[bi][i]) return false;
	}
	return true;
}
/*int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0;i < m;i++)
		for(int j = 0;j < k;j++)
			scanf("%d",&a[i][j]);
	for(int i = 0;i < m;i++)
	{
		int min = -1;
		for(int j = 0;j < m;j++)
		{
			if(!chosen[j] && (min == -1 || isABiggerThanB(min,j)))
				min = j;
		}
		order[i] = min;
	}
	int c = n / m,d = n % m;
	int ans = 0;
	for(int i = 0;i < k;i++)
	{
		ans *= c;
		ans += a[d][i];
	}
	printf("%d",ans);
	return 0;
}*/
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int cnt = 0;
	for(int i = 0;i < m;i++)
		for(int j = 0;j < k;j++)
			scanf("%d",&a[i][j]);
	for(int i1 = 0;i1 < m;i1++)
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < k;j++)
			{
				cc[cnt] *= i;
				cc[cnt] += a[i1][j];
			}
			cnt++;
		}
	sort(cc,cc + cnt);
	printf("%d",cc[n]);
	return 0;
}