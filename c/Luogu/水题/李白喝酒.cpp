#include<stdio.h>
int arr[10000];
int a,b;
int f(int n)
{
	if(n==1) return a%2333333;
	if(n==2) return b%2333333;
	if(arr[n-1]==0) arr[n-1]=f(n-1)%2333333;
	if(arr[n-2]==0) arr[n-2]=f(n-2)%2333333;
	arr[n]=(arr[n-1]+arr[n-2])%2333333;
	return arr[n];
}
int main()
{
	int n;
	scanf("%d%d%d",&n,&a,&b);
	printf("%d",f(n));
	return 0;
}
