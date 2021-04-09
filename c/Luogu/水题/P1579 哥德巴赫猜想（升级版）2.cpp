/*
	P1579
	by:林乐天
	请勿抄袭
	时间复杂度：O(n^2) 
*/ 
#include<stdio.h>
#include<math.h>
int prime[100000];
bool notp[200000];//notprime 开大点 
void findprime(int maxn)//埃氏筛 求出所有素数 时间复杂度：O(nloglogn) 
{
	for(int i = 2;i <= maxn;i++)
	{
		if(notp[i]) continue;
		for(int j = 2;j <= maxn;j++)
		{	
			if(i*j > maxn) break;//特判，如果超过范围就跳出 
			notp[i*j] = true;//非0、1正整数的倍数必定是合数 
			
		}
			
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	notp[0] = notp[1] =true;
	findprime(n);//算出素数 
	int x = 0;
	for(int i = 0;i <= n;i++)//将素数统计，汇集到prime数组里，方便后期运算 
		if(!notp[i] && i != 0 && i != 1) //特判，0和1非质数 
			prime[x++] = i;
	for(int i = 0;i < x;i++)//枚举所有可能性 
	{
		for(int j = 0;j < x;j++)
		{
			if(n - prime[i] - prime[j] < 0) break;//如果最后一个数小于0跳出 
			if(!notp[n - prime[i] - prime[j]] )
			{
				printf("%d %d %d",prime[i],prime[j],n - prime[i] - prime[j]);
				return 0;
			}
		}
	}
	return 0;
}
