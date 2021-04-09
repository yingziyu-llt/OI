#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
char s[1000];
char a[1000];
int add1[1000],add2[1000];
void tonum(int n,char s[1000],int res[1000])
{
	int len = strlen(s);
	if(n == 16)
	{
		for(int i = 0;i < len;i++)
		{
			if(isalpha(s[i]))
			{
				if(s[i] == 'a'||s[i] == 'A')
					res[i] = 10;
				else if(s[i] == 'b' || s[i] == 'B')
					res[i] = 11;
				else if(s[i] == 'c' || s[i] == 'C')
					res[i] = 12;
				else if(s[i] == 'd' || s[i] == 'D')
					res[i] = 13;
				else if(s[i] == 'e' || s[i] == 'E')
					res[i] = 14;
				else if(s[i] == 'f' || s[i] == 'F')
					res[i] = 15;
			}
			else res[i] = s[i] - '0';
		}
	}
	else
	{
		for(int i = 0;i < len;i++)
		{
			res[i] = s[i] - '0';
		}
	}
	
}
void tos(char s[1000],int a[1000],int n)
{
	for(int i = 0;i < n;i++)
	{
		if(a[i] >= 10) s[i] = a[i] - 10 + 'A';
		else           s[i] = a[i] + '0';
	}
}
void add(int n)
{
	tonum(n,s,add1);
	strcpy(a,s);
	reverse(a,a + strlen(a));
	tonum(n,a,add2);
	int len = strlen(s);
	int tmp = 0;
	for(int i = 0;i < len;i++)
	{
		add1[i] = add1[i] + add2[i] + tmp;
		tmp = add1[i] / n;
		add1[i] %= n;
	}
	if(tmp != 0)
	{
		len++;
		add1[len - 1] += tmp;
	}
	tos(s,add1,len);
}
int main() 
{
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	strcpy(a,s);
	reverse(a,a + strlen(a));
	if(strcmp(s,a) == 0)
	{
		printf("STEP=0");
		return 0;
	}
	int step = 0;
	while(step < 30)
	{
		add(n);
		strcpy(a,s);
		reverse(a,a + strlen(a));
		step++;
		if(strcmp(s,a) == 0)
			break;
	}
	if(step >= 30) printf("Impossible!");
	else           printf("STEP=%d",step);
}
