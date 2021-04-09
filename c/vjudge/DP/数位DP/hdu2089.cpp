#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long long f[9][10];
int init()
{
	f[0][0] = 1;
	for(int i = 1;i <= 7;i++)
		for(int j = 0;j < 10;j++)
			for(int k = 0;k < 10;k++)
				if(j != 4 && !(j == 6 && k == 2))
					f[i][j] += f[i - 1][k];
}
int dight[9];
int make_dight(int n)
{
	int len = 1;
	memset(dight,0,sizeof(dight));
	while(n)
	{
		dight[len] = n % 10;
		n /= 10;
		len++;
	}
	return len - 1;
}
int solve(int n)
{
	long long ans = 0;
	int len = make_dight(n);
	for(int i = len;i >= 1;i--)
	{
		for(int j = 0;j < dight[i];j++)
			if(j != 4 && !(j == 2 && dight[i + 1] == 6))
				ans += f[i][j];
		if(dight[i] == 4 || (dight[i] == 2 && dight[i + 1] == 6)) break;
	}
	return ans;
}
int main()
{
	int m,n;
	init();
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(m == 0 && n == 0) break;
		printf("%d\n",solve(n + 1) - solve(m));
	}
	return 0;
}