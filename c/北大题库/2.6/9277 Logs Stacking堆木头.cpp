#include<stdio.h>
int f[200010];
int input()
{
	char c=getchar();
	int a=0;
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	return a;
}
void output(int a)
{
	if(a>=10) output(a/10);
	putchar(a%10+'0');
	return ;
}
int main()
{
	int s=1;
	f[0]=1;
	for(int i=1;i<200000;i++)
	{
		f[i]=(f[i-1]+s)%100000;
		s+=f[i];
		s%=100000;
	}
	int a;
	a=input();
	for(int i=0;i<a;i++)
	{
		int tmp=input();
		output(f[tmp-1]);
		putchar('\n');
	}
	return 0;
}
