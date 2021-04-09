#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char s[100100];
void toBigger(char &c)
{
	c = (c >= 'a' && c <= 'z') ? (c - 'a' + 'A') : c;
}
void toSmall(char &c)
{
	c = (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}
int main()
{
	freopen("nigeru.in","r",stdin);
	freopen("nigeru.out","w",stdout);
	gets(s);
	int len = strlen(s);
	bool frist = true;
	for(int i = 0;i < len;i++)
	{
		if(s[i] == '.')
		{
			frist = true;
		}
		else if(s[i] == ' ')
		{
			continue;
		}
		else if(frist)
		{
			toBigger(s[i]);
			frist = false;
		}
		else
		{
			toSmall(s[i]);
		}
	}
	printf("%s",s);
	return 0;
}