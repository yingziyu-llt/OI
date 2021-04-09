#include<stdio.h>
#include<string.h>
char a[1010],b[1010];
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
bool getsmall(char a[])
{
	bool x=false;
	for(int i=0;i<strlen(a);i++)
	if(a[i]>'z')
	{
		a[i]=a[i]-'A'+'a';
		x=true;
	}
	return x;
}
void work(char a[],char b[])//aÃÜÔ¿,bÃ÷ÎÄ
{
	int i,j;
	int boolean=0;
	for(j=0;j<strlen(a); )
	{
		for(i=0;i<strlen(b);i++)
		{
			bool x=false;
			getsmall(a);
			x=getsmall(b);
			outkey(a[j],b[i]);
			if(x)  b[i]+='A';
			j++;
		}
		j=0;
	}
	return ;
}
void output(char a[])
{
	for(int i=0;i<strlen(a);i++)
		printf("%c",a[i]);
	return ;
}
int main()
{
	input(a,b);
	work(a,b);
	output(b);
	return 0;
}
