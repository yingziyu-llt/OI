#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 1100;
int f[N][N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char s1[N],s2[N];
		scanf("%s%s",s1,s2);
		int len1 = strlen(s1),len2 = strlen(s2);
		for(int i = 0;i < len1;i++) f[i][0] = i;
		for(int i = 0;i < len2;i++) f[0][i] = i;
		for(int j = 0;j < len2;j++)
		{
			for(int i = 0;i < len1;i++)
			{
				if(s1[i] == s2[j]) f[i + 1][j + 1] = f[i][j];
				else f[i + 1][j + 1] = min(min(f[i + 1][j] + 1,f[i][j + 1] + 1),f[i][j] + 1);
			}
		}
		printf("%d\n",f[strlen(s1)][strlen(s2)]);
	}
	return 0;
}