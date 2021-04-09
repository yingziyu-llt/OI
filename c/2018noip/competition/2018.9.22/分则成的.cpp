#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100000];
int tmp[200000];
int f[100000];
int main()
{
	int n,k,ans = 0;
	scanf("%d%d",&n,&k);
	a[0] = n;
	tmp[0] = a[0] / 2;
	tmp[1] = a[0] - tmp[0];
	bool findmax = false;
	if(tmp[0] * tmp[1] > a[0])
	{
		findmax = true;
		a[0] = tmp[0];
		a[1] = tmp[1];
		ans = a[0] * a[1];
	} 
	n = 1;
	for(int _i = 0;_i < k - 1;_i++)
	{
		findmax = false;
		for(int i = 0;i <= n * 2;i += 2)
		{
			tmp[i] = a[i / 2] /2;
			tmp[i + 1] = a[i / 2] - tmp[i];
			f[i / 2] = tmp[i] * tmp[i+1];
		}
		int maxn = 1,maxi = -1,maxj = -1;
		for(int i = 0;i < n;i++)
		{
			if(maxn < f[i])
			{
				maxn = f[i];
				maxi = i * 2;
				maxj = i * 2 + 1;
			}
		}
		if(maxi != -1 && maxj != -1);
		{
			a[maxi / 2] = tmp[maxi];
			a[++n] = tmp[maxj];
			ans += tmp[maxj] * tmp[maxi];
		}
	}
	printf("%d",ans);
	return 0;
}
