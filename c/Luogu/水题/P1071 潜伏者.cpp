#include <stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char key[26],check[26];
char a[10000],b[10000],c[10000];
int trykey()
{
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(key[a[i]-'A']!='\0'&&key[a[i]-'A']!=b[i]) return 0;
		key[a[i]-'A']=b[i];
		check[b[i]-'A']=a[i];
	}
	int isfull[26];
	memset(isfull,0,sizeof(isfull));
	for(int i=0;i<26;i++)
		isfull[check[i]-'A']=1;	
	int i=0; 
	for(i=0;i<26;i++)
		if(!isfull[i]) return 0;	
	return 1;
} 
void outkey()
{
	 int len=strlen(c);
	 for(int i=0;i<len;i++)
	 {
	 	c[i]=key[c[i]-'A'];
	}
}
int main()
{
	scanf("%s%s%s",a,b,c);
	if(trykey()==1) 
	{
		outkey();
		printf("%s",c);
		return 0;
	}
	else printf("Failed");
	return 0;
}

