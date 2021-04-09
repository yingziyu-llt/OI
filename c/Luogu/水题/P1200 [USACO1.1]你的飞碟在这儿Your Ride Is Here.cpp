#include<stdio.h>
#include<string.h>
char a[30],b[30];
int main()
{
	int len1,len2,shi1=1,shi2=1,i;
	scanf("%s%s",a,b);
	len1=strlen(a);
	len2=strlen(b);
	for(i=0;i<len1;i++) shi1*=a[i]-'A'+1;
	for(i=0;i<len2;i++) shi2*=b[i]-'A'+1;
	shi1%=47;
	shi2%=47;
	if(shi1==shi2)  printf("GO");
	else            printf("STAY");
	return 0;
}
