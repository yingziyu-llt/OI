#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char a[1000], b[1000];
int lena, lenb;
int dfs(int x,int y)
{
	for (int i = y; i < lenb; i++)
	{
		int flag = 0;
		for (int j = x; j < lena; j++)
		{
			if (a[j] == '*')
			{
				if (j == lena - 1) return 1;
				if (dfs(j + 1, i + j))   return 1;
			}
			if (a[j] == '?') continue;
			
			if (i + j - x >= lenb)
			{
				flag = 1;
				break;
			}
			if (a[j] != b[i + j - x])
			{
				flag = 1;
				break;
			}
		}
		if (!flag) return 1;
	}
	return 0;
}
int main()
{
	scanf("%s%s", a, b);
	lena = strlen(a);
	lenb = strlen(b);
	if (dfs(0, 0))
	{
		printf("matched");
	}
	else
	{
		printf("not matched");
	}
	return 0;
}
