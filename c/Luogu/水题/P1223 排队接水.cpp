#include<algorithm>
#include<stdio.h>
using namespace std;
struct aa
{
	int num;
	int t;
} a[100000];
bool cmp(aa a,aa b)
{
	if(a.t != b.t) return a.t < b.t;
	return a.num < b.num;
}
int main()
{
	int n;
	double t  = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++) 
	{
		scanf("%d",&a[i].t);
		a[i].num = i + 1;
	}
	sort(a,a+n,cmp);
	int j = n - 1;
	for(int i = 0;i < n;i++)
	{
		t = t + a[i].t * j;
		j--;
	}
	t = t / (double)n;
	for(int i = 0;i < n;i++)
		printf("%d ",a[i].num);
	printf("\n%.2lf",t);
	return 0;
} 
