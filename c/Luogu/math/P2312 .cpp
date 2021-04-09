#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long long Mod1 = 1e9+7,Mod2 = (long long)1e9 + 7,Mod3 = (long long)1e9 + 9;
long long a[110][3],ans[1000000];
void read(long long *a)
{
	long long ans1 = 0,ans2 = 0,ans3 = 0,flag = false;
	char c;
	while(c != '-' && (c > '9' || c < '0'))
		c = getchar();
	if(c == '-') 
		flag = true,c = getchar();
	while(c >= '0' && c <= '9')
	{
		ans1 = ans1 * 10 % Mod1 + c - '0';
		ans2 = ans2 * 10 % Mod2 + c - '0';
		ans3 = ans3 * 10 % Mod2 + c - '0';
		c = getchar();
	}
	a[0] = ans1 * (flag ? -1 : 1);
	a[1] = ans2 * (flag ? -1 : 1);
	a[2] = ans3 * (flag ? -1 : 1);
	return ;
}
int main()
{
	long long n,m,cnt = 0;
	scanf("%lld%lld",&n,&m);
	for(long long i = 0;i <= n;i++)
		read(a[i]);
	for(long long i = 1;i <= m;i++)
	{
		long long c1 = 0,c2 = 0,c3 = 0;
		for(long long j = n;j >= 1;j--)
		{
			c1 = (c1 % Mod1 + a[j][0]) * i % Mod1;
			c2 = (c2 % Mod2 + a[j][1]) * i % Mod2;
			c3 = (c3 % Mod3 + a[j][2]) * i % Mod3;
		}
		c1 = (c1 + a[0][0]) % Mod1;
		c2 = (c2 + a[0][1]) % Mod2;
		c3 = (c3 + a[0][2]) % Mod3;
		if(c1 == 0 && c2 == 0 && c3 == 0)
		{
			cnt++;
			ans[cnt] = i;
		}
	}
	printf("%lld\n",cnt);
	for(long long i = 1;i <= cnt;i++)
		printf("%lld\n",ans[i]);
	return 0;
}