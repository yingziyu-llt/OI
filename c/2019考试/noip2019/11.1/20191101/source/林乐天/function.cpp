#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 30,M = 30,Mod = 1000000007;
int n,m;
int F[M][M];
int f(int i,int j)
{
	if((i == 1 && j == 1) || (i == 1 && j == 2))
	{
		F[i][j] = 1;
		return 1;
	}
	if(i == 1)
	{
		if(F[i][j] != 0) return F[i][j];
		F[i][j] = f(1,j - 1) % Mod;
		F[i][j] += 2 * (f(1,j - 2) % Mod);
		F[i][j] %= Mod;
		return F[i][j];
	}
	if(F[i][j] != 0) return F[i][j];
	for(int k = j;k <= j + n - 1;k++)
	{
		F[i][j] = (F[i][j] + f(i - 1,k) % Mod) % Mod;
	}
	return F[i][j];
}
int main()
{
	int T;
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	scanf("%d",&T);
	for(int i = 0;i < T;i++)
	{
		scanf("%d%d",&n,&m);
		memset(F,0,sizeof(F));
		printf("%d\n",f(m,1) % Mod);
	}
	return 0;
}