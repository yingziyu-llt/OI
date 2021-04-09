#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

int prime[100000];
bool isp[2000000000];
int s[10000];

void getprime(int maxn)
{
	for (int i = 2; i <= maxn; i++)
	{
		while (!isp[i])
			i++;
		for(int j = 2;i * j <= maxn; j++)
			isp[i * j] = false;
	}
}

int main()
{
	int n;
	int m1,m2;
	
	memset(isp,true,sizeof(isp));
	scanf("%d");
}
