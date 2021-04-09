#include<stdio.h>
#include<string.h>
char a[101];
int x[26];
int main()//'a'=97
{
	int i,j,l,maxn=0,minn=101,y;
	scanf("%s",&a);
	l=strlen(a);
	for(i=0;i<l;i++)
		x[(int)a[i]-'a']++;
	for(i=0;i<26;i++)
	{
		if(x[i]>maxn)maxn=x[i];
		if(x[i]<minn&&x[i]!=0)minn=x[i];
	}
	y=maxn-minn;
	i=2;
	do
	{
		if((y%i==0&&y!=i)||(y==0)||(y==1))
		{
			printf("No Answer\n0");
			return 0;
		}
		i++;
	}
	while(i<y-1);
	printf("Lucky Word\n%d",y);
	return 0;
}
