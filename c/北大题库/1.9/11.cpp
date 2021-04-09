#include<stdio.h>
#include<string.h>
char st[1001];
int main()
{
	int n,i,a=1,b=0,L;
	scanf("%d",&n);
	scanf("%s",st);
	L=strlen(st);
	for(i=1;i<L;i++)
	{
		if(st[i]==st[i-1]) a++;
		else   a=1;
		if(a==n)  { printf("%c",st[i]); b=1; break;}
	}
	if(b==0)   printf("No");
	return 0;
}
