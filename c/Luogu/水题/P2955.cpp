#include<stdio.h>
#include<string.h>
int main()
{
	long long a,c;
	char b[10000];
	scanf("%lld",&a);
	for(;a>0;a--)
	{
		memset(b,0,sizeof(b));
		scanf("%s",&b);
		int len=strlen(b)-1;
		c=b[len]-'0';
		if(c%2==0) printf("even\n");
		else       printf("odd\n");
	}
	return 0;
} 
