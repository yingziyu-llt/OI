#include<stdio.h>
#include<string.h>
char a[32];
char str[10010];
int main()
{
	int len;
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
    gets_s(str,sizeof(str));
    for(int i = 0;i < 26;i++)
    	a[i] = getchar();
    len = strlen(str);
    for(int i = 0;i < len;i++)
    	if(str[i] >= 'A' && str[i] <= 'Z')
    		str[i] = a[str[i] - 'A'];
    for(int i = 0;i < len;i++)
    	printf("%c",str[i]);
    return 0;
}
