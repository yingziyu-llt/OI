#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int isalpha(char c)//Linux ctype诡异bug，手写ctype要用到的函数
{
    if(c >='A' && c <= 'Z') return 1;
    else if(c >='a' && c <= 'z') return 2;
    else return 0;
}
int isdigit(char c)
{
    if(c >= '0' && c <= '9') return 1;
    else return 0;
}
char s[1000000];
int main()
{
	int p1,p2,p3;
	scanf("%d%d%d",&p1,&p2,&p3);
	scanf("%s",s);
	for(int i = 0;i < strlen(s);i++)
	{
		char line = 0;
		if(s[i] != '-')
		{
			putchar(s[i]);
			continue;
		}
		else if(s[i - 1] - s[i + 1] >= 0)
		{
			putchar('-');
			continue;
		}
		else if(isalpha(s[i - 1]) && isalpha(s[i + 1]))
		{
			line  = 0;
			
			if(p3 == 1)
				for(int j = 1;s[i - 1] + j < s[i + 1];j++)
				{
					if(p1 == 1) line = 'a';
					else if(p1 == 2) line = 'A';
					else line = '*';
					for(int k = 0;k < p2;k++)
					{
						if(line == '*') putchar('*');
						else if(isalpha(s[i - 1]) == 1) printf("%c",s[i - 1] - 'A' + j + line);
						else if(isalpha(s[i - 1]) == 2) printf("%c",s[i - 1] - 'a' + j + line);
					}
				}
			else if(p3 == 2)
				for(int j = s[i + 1] - s[i - 1] - 1;j >= 1;j--)
				{
					if(p1 == 1) line = 'a';
					else if(p1 == 2) line = 'A';
					else line = '*';
					for(int k = 0;k < p2;k++)
					{
						if(line == '*') putchar('*');
						else if(isalpha(s[i - 1]) == 1) printf("%c",s[i - 1] - 'A' + j + line);
						else if(isalpha(s[i - 1]) == 2) printf("%c",s[i - 1] - 'a' + j + line);
					}
				}
		}
		else if(isdigit(s[i - 1]) && isdigit(s[i + 1]))
		{
			if(p3 == 1)
			{
				for(int j = 1;s[i - 1] + j < s[i + 1];j++)
				{
					if(p1 == 3) line = '*';
					else line = 0;
					for(int k = 0;k < p2;k++)
					{
						if(line == '*') putchar('*');
						else            printf("%c",s[i - 1] + j);
					}
				}
			}
			else
			{
				for(int j = s[i + 1] - s[i - 1] - 1;j >= 1;j--)
				{
					if(p1 == 3) line = '*';
					else line = 0;
					for(int k = 0;k < p2;k++)
					{
						if(line == '*') putchar('*');
						else            printf("%c",s[i - 1] + k);
					}
				}
			}
		}
		else putchar('-');
	}
}