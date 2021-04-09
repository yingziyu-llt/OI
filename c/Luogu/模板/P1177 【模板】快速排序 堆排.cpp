#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100010],n;
#define lson(x) (x * 2 + 1)
#define rson(x) (x * 2 + 2)
void update(int fir,int lat)
{
	int l = lson(fir);
	if(l > lat) return ;
	if(l < lat && a[l] < a[l + 1])
		l++;
	if(a[l] > a[fir])
		swap(a[l],a[fir]);
	update(l,lat);
}
int heap_sort()
{
	for (int i = n - 1; i >= 0; i--)
		update(i, n - 1);
	for(int i = n - 1;i >= 0;i--)
	{
		swap(a[0],a[i]);
		update(0,i - 1);
	}
	
}
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	heap_sort();
	for(int i = 0;i < n;i++)
		printf("%d ",a[i]);
	getchar();
	return 0;
}