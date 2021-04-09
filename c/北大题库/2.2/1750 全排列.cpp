#include<stdio.h>
#include<string.h>
int b[7],a[998],n;
char s[7];
int output()
{
	for(int i=1;i<=n;i++)
		printf("%c",s[a[i]]);
	printf("\n");
}
int tryy(int t)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			a[t]=i;
			if(t==n) output();
			else     tryy(t+1);
			b[i]=0;
		}
	}
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	tryy(1);
	return 0;
}
