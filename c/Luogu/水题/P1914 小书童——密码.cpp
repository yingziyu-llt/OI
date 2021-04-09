#include<stdio.h>
#include<string.h>
int a,L;
char b[100];
int main()
{
	int i;
	scanf("%d",&a);
	a%=26;
	scanf("%s",b);
	L=strlen(b);
	for(i=0;i<L;i++)
	{
		b[i]=(b[i]-'a'+a)%26+'a';
	}
	printf("%s",b);
	return 0;
}
