#include <stdio.h>
#include <string.h>
const int Base = 10;
struct BigNumber
{
	int num[10010], cnt;
	BigNumber()
	{
		memset(num, 0, sizeof(num));
		cnt = 0;
	}
	int& operator [] (int now)
	{
		return num[now];
	}
	void operator*=(int a)
	{
		for (int i = 0; i < cnt; i++)
		{
			num[i] *= a;
		}
		for (int i = 0; i < cnt; i++)
		{
			if (num[i] >= Base)
			{
				num[i + 1] = num[i] / Base;
				num[i] %= Base;
			}
		}
		while (num[cnt + 1] != 0)
		{
			cnt++;
			if (num[cnt] >= Base)
			{
				num[cnt + 1] = num[cnt] / Base;
				num[cnt] %= Base;
			}
		}
	}
	void operator/=(int a)
	{
		for (int i = cnt; i >= 0; i--)
		{
			num[i - 1] += (num[i] % a * Base);
			num[i] /= a;
		}
		while (!num[cnt])
		{
			cnt--;
		}
	}
	void to_BigNumber(int now)
	{
		cnt = -1;
		while (now)
		{
			num[++cnt] = now % Base;
			now /= Base;
		}
	}
	void print(char end = 0)
	{
		for (int i = cnt; i >= 0; i--)
			printf("%d", num[i]);
		end &&putchar(end);
	}
};

int main()
{
	int n,d[1000],cnt = 0,sum = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i] == -1) continue;
		if(d[i] == 0)
		{
			printf("0");
			return 0;
		}
		cnt++;
		sum += d[i] - 1;
	}
	if(sum > n - 2)
	{
		printf("0");
		return 0;
	}
	BigNumber a;
	a.to_BigNumber(1);
	sum = 0;
	cnt = 0;
	int k1 = n - 2;
	for(int i = 0;i < n;i++)
	{
		int t = d[i];
		if(t == -1)
		{
			cnt++;
			continue;
		}
		if(t == 0)
			continue;
		for(int j = k1; j > k1 - t;j--)
			a *= j;
		k1 -= t;
		for(int j = 1;j <= t;j++)
			a /= j;
	}
	for(int i = 1;i <= k1;i++)
		a *= cnt;
	a.print();
	return 0;
}