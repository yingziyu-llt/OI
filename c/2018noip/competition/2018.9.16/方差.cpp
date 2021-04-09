#include<stdio.h>
int a[10000];
int n,sum = 0;
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	for(int i = 0;i < n;i++)
	{
		int tmp = sum;
		double ans = 0;
		tmp -= a[i];
		float average_value = (double)tmp / (double)(n - 1);
		for(int j = 0; j < n;j++)
			if(j != i)
				ans += (a[j] - average_value) * (a[j] - average_value);
		ans /= (double)(n - 1);
		ans *=  (n-1) * (n-1); 
		printf(i != n - 1 ? "%.0lf " : "%.0lf",ans);
	}
}
