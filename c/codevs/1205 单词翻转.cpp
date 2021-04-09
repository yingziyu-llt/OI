#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	char a[1000][1000];
	int i=0;
	while(~scanf("%s",&a[i]))
	{
		i++;
	}
	int j=strlen(a[i])-1;
	a[i][j]='\0';
	while(i>=0)
	{
		printf("%s ",a[i]);
		i--;
	}
}
