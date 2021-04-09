#include<stdio.h>
#include<string.h>
int a[100],heapsize;
void minheaply(int n)
{
	int l,r,least = 0;
	l = n << 1;
	r = (n << 1) + 1;
	if(l <= heapsize && a[l] < a[n])
		least = l;
	else
		least = n;
	if(r <= heapsize && a[least] > a[r])
		least = r;
	if(least != n)
	{
		int tmp = a[least];
		a[least] = a[n];
		a[n] = tmp;
		minheaply(least);
	}
}
void putf(int n)
{
	heapsize++;
	a[heapsize] = n;
	for(int i = heapsize / 2;i >=1 ;i--)
	    minheaply(i);
}
void find()
{
	printf("%d\n",a[1]);
}
void del()
{
	a[1] = a[heapsize];
	heapsize--;
	minheaply(1);
}
int main()
{
	int commond,num,n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&commond);
		if(commond == 1)
		{
			scanf("%d",&num);
			putf(num);
		}
		if(commond == 2)
		{
			find();
		}
		if(commond == 3)
		{
			del();
		}
	}
}