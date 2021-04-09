#include<stdio.h>
#include<string.h>
char a[10000000],b[10000000],c[10000000];
int fir=100000000,tot,lena,lenb;
int cheak(int x)
{
	int i;
	for(i=0;i<lena;i++)
	{
		if(a[i]!=b[x+i]) return 0;
	}
	i=x+i;
	if(b[i]!=' ') return 0;
	return 1;
}
int main()
{
	int i,j;
	gets(a);
	gets(b);
	c[0]=' ';
	strcat(c,b);
	strcat(c," ");
	strcpy(b,c);
	lena=strlen(a);
	lenb=strlen(b);
	for(i=0;i<lena;i++)
		if(a[i]>='A'&&a[i]<='Z') a[i]=a[i]-'A'+'a';
	for(i=0;i<lenb;i++)
		if(b[i]>='A'&&b[i]<='Z') b[i]=b[i]-'A'+'a';
	for(i=0;i<lenb;i++)
	{
		if(b[i]==' '&&b[i+1]!=' ')
			if(cheak(i+1))
			{
				if(i<fir) fir=i;
				tot++;
			}
	}
	if(tot==0)  printf("-1");
	else        printf("%d %d",tot,fir);
	return 0;
}
