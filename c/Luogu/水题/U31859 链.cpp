#include<stdio.h>
#include<string.h>
int main()
{
	char a[10];
	long long ans=0;
	scanf("%s",a);
	for(int i=0;i<strlen(a)-1;i++)
	{
		ans=ans*2+(a[i]-'0');
	}
	printf("%lld",ans);
	return 0;
} 
