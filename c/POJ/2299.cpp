#include<stdio.h>
#include<string.h>
long long ans;
int a[510000],b[510000];
void mergeSort(int l,int r)
{
	if(l == r) return ;
	int mid = (l + r) >> 1;
	int i = l,j = mid + 1;
	mergeSort(l,mid);
	mergeSort(mid + 1,r);
	for(int k = l;k <= r;k++)
	{
		if(j > r || (i <= mid && a[i] <= a[j])) b[k] = a[i++];
		else b[k] = a[j++],ans += mid - i + 1;
	}
	for(int k = l;k <= r;k++) a[k] = b[k];
	return ;
}
int main()
{
	int len;
	while(1)
	{
		ans = 0;
		scanf("%d",&len);
		if(len == 0) break;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i = 1;i <= len;i++)
			scanf("%d",&a[i]);
		mergeSort(1,len);
		printf("%lld\n",ans);
	}
	return 0;
}