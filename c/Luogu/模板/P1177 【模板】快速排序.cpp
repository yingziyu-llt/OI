/*Œ¥”≈ªØ*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void swap(int &a,int &b) {int tmp;tmp=a;a=b;b=tmp;}
int a[100000];
void qsort(int l,int r)
{
	if(l >= r) return;
	int i = l,j = r,tmp = a[l];
	while(i != j)
	{
		while (a[j] <= tmp && i < j) j--;
		while (a[i] >= tmp && i < j) i++;
		if(i < j)
			swap(a[i],a[j]);
	}
	a[l] = a[i];
	a[i] = tmp;
	qsort(l,i - 1);
	qsort(i + 1,r);
	return ;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	qsort(0,n-1);
	int k;
	scanf("%d",&k);
	for(int i = 0;i < k;i++)
		printf("%d\n",a[i]);
	return 0;
}
