#include<stdio.h>
#include<string.h>
int main()
{
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	char s[100];
	int i = 0;
	int ans = 0;
	while(~ scanf("%c",&s[i]))
	{
		if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
			ans++;
		i++;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
