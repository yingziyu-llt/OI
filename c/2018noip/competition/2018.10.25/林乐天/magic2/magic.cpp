#include<stdio.h>
int queue[10010];
int b[10010],c[10010];
int main()
{
	int n;
	int k = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n ;i++)
		queue[i - 1] = i;
	b[0] = 1;
	k = 1;
	int f = 0,r = n - 1;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < i;j++)
		{
			r = (r + 1) % 10010;
			queue[r] = queue[f];
			f = (f + 1) % 10010;
		}
	}
}