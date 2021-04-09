#include<stdio.h>
int a[10000],b[10000];
int findx(int x)
{
	int tmp;
	int i,j;
	a[0]= 12345;
	for(i=2;i*i<10000;i++)
		for(j=2;j<10000/i;j++)
			a[i*j]++;

	for(i=0;i<10000;i++)
		if(a[i]==0) b[i]=i+1;
	return 0;
}
int main()
{
	findx(1);
	for(int i=0;i<10000;i++)
	printf("%d ",b[i]);
}
