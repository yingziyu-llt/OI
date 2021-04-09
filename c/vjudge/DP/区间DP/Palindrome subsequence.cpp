#include<stdio.h>
#include<string.h>
#include<algorithm>
const int mod = 10007;
using namespace std;
int f[1100][1100];
int main()
{
	int T;
	scanf("%d",&T);
	for(int _i = 1;_i <= T;_i++)
	{
		char s[1100];
		scanf("%s",s + 1);
		memset(f,0,sizeof(f));
		for(int i = 1;i <= strlen(s + 1);i++)
			f[i][i] = 1;
		for(int l = 2;l <= strlen(s + 1);l++)
		{
			for(int i = 1;i + l - 1 <= strlen(s + 1);i++)
			{
				int j = i + l - 1;
				f[i][j] = (f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1] + mod) % mod;
				if(s[i] == s[j]) f[i][j] += f[i + 1][j - 1] + 1,f[i][j] %= mod;;
			}
		}
		printf("Case %d: %d\n",_i,f[1][strlen(s + 1)]);
	}
	return 0;
}