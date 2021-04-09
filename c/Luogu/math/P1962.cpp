#include<stdio.h>
#include<string.h>
#include<math.h>
#define Mod 1000000007
struct mat
{
	long long a[3][3];
	mat()
	{
		memset(a,0,sizeof(a));
	}
	mat operator *(const mat&b) const
	{
		mat res;
		for(int i = 1;i <= 2;i++)
		{
			for(int j = 1;j <= 2;j++)
			{
				for(int k = 1;k <= 2;k++)
				{
					res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % Mod;
				}
			}
		}
		return res;
	}
}ans,tmp;
void ksm(long long c)
{
	tmp.a[1][1] = tmp.a[1][2] = tmp.a[2][1] = 1;
	ans.a[1][1] = ans.a[1][2] = 1;
	while(c)
	{
		if(c & 1)
			ans = ans * tmp;
		tmp = tmp * tmp;
		c >>= 1;
	}
	return ;
}
int main()
{
	long long c;
	scanf("%lld",&c);
	if(c > 2)
		ksm(c - 2);
	printf("%d",(c <= 2)?1:ans.a[1][1] %Mod);
	return 0;
}