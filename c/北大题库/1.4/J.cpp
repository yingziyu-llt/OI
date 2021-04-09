#include<stdio.h>
int main()
{
	char a;
	scanf("%c",&a);
	if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
	{
		if(a>='a'&&a<='z')  a=a-'a'+'A';
		printf("%c",a);
	}
	else printf("NOT LETTER");
	return 0;
}
