#include<stdio.h>
int f1(int a,int b)
{
	return a+b;
}
int f2(int a,int b)
{
	return a-b;
}
int f3(int a,int b)
{
	return a*b;
}
int f4(int a,int b)
{
	return a/b;
}
int f5(int a,int b)
{
	return a%b;
}
int main()
{
	long long int a,b,ans;
	char x;
	scanf("%d ",&a);
	scanf("%c ",&x);
	scanf("%d",&b);
	switch (x)
	{
		case '+':

			ans=f1(a,b);
			break;

		case '-':

			ans=f2(a,b);
			break;

		case '*':

			ans=f3(a,b);
			break;

		case '/':

			ans=f4(a,b);
			break;

		case '%':

			ans=f5(a,b);
			break;

	}
	printf("%d",ans);
	return 0;
}
