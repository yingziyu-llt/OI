#include<stdio.h>
int workf(int n, int i, int j) 
{
    if (i == 1)
        return j;
    if (j == n)
        return n+i-1;
    if (i == n)
        return 3*n-2-j+1;
    if (j == 1)
        return 4*n-4-i+2;
    return workf(n-2,i-1,j-1)+4*(n-1);
}
int main()
{
	int i,j,n;
	scanf("%d %d %d",&n,&i,&j);
	long long ans=workf(n,i,j);
	printf("%d",ans);
	return 0;
}
