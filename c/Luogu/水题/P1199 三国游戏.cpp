#include<stdio.h>
#include<algorithm>
using namespace std;
int a[500][500];
bool cmp(int i,int j)
{
	return i > j;
}
int main()
{
	int n;
	printf("1\n");
	scanf("%d",&n);
	for(int i = 0;i < n - 1;i++)
	{
		for(int j = i + 1;j < n;j++)
		{
			scanf("%d",&a[i][j]);
			a[j][i] = a[i][j];
		}
	}
	for(int i = 0 ;i < n; i++)
		sort(a[i],a[i]+n,cmp);
	int max = 0;
	for(int i = 0;i < n;i++)
	{
		if(a[i][1] > max) max = a[i][1];
	}
	printf("%d",max);
	return 0;
}
