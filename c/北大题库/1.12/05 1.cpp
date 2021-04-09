#include<stdio.h>
#include<string.h>
void outkey(char a,char &b)
{
	b-='a';
	b+=a;
}
void input(char a[],char b[])
{
	scanf("%s",a);
	scanf("%s",b);
}
void work(char a[],char b[])//aÃÜÔ¿,bÃ÷ÎÄ
{
	int i,j;
	int boolean=0;
	for(i=0;i<strlen(b)||boolean=1;)
	{
		for(j=0;j<strlen(a);i++)
		{
			bool x=false;
			if(a[j]>'z') a[j]=a[j]-'A'+'a';
			if(b[i]>'z')
			{
				a[j]=a[j]-'A'+'a';
				x=true;
			}
			outkey(a[j],b[i]);
			if(x)  b[i]+='A';
			
		}
	}
}
