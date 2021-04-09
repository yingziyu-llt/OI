/*
05
统计单词数
  by
     林乐天
*/
#include<stdio.h>
#include<string.h>
char a[100000][10];
char b[100];
int x[100];
int len[100000],rig[100000];
int main()
{
	freopen("1.txt","r",stdin);
	int i,L,count=0,j,x;
	scanf("%s",&b);
	i=0;
	while(~scanf("%s",&a[i]))	i++;
	x=i;
	L=strlen(b);
	for(;i>=0;i--)
		for(j=0;j<strlen(a[i]);j++)
			if(a[i][j]>='A'&&a[i][j]<='Z')  a[i][j]=a[i][j]-'A'+'a';
	for(i=0;i<L;i++)    if(b[i]>='A'&&b[i]<='Z')    b[i]=b[i]-'A'+'a';
	for(i=0;i<x;i++)    if(strcmp(b,a[i])==0)   {
		rig[count]=i;
		count++;
	}
	for(i=0;i<x;i++)    len[i]=strlen(a[i]);
	if(count==0)    {
		printf("-1");
		return 0;
	}
	printf("%d ",count);
	count=0;
	for(i=0;i<rig[0];i++)
	count+=len[i]+1;
	printf("%d",count);
	return 0;
}
