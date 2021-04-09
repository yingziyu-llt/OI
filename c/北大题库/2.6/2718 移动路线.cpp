#include<stdio.h>
int x,y;
int a[100][100];
int f(int i,int j)
{
	if(i==1||j==1) return 1;
	else return f(i-1,j)+f(i,j-1);
}
int main()
{
	scanf("%d %d",&x,&y);
	printf("%d",f(x,y));
	return 0;
}
