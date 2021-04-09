#include<stdio.h>
int a[100][100];
int tob(int x,int a[64])
{
	int i=0;
	while(x!=0)
	{
		a[i]=x%2;
		x/=2;
		i++;
	}
	a[i]=-1;
}

int main()
{
	int i,j,n;
	scanf("%d",n);
	while()
}
