/*
	P1579
	by:������
	����Ϯ
	ʱ�临�Ӷȣ�O(n^2) 
*/ 
#include<stdio.h>
#include<math.h>
int prime[100000];
bool notp[200000];//notprime ����� 
void findprime(int maxn)//����ɸ ����������� ʱ�临�Ӷȣ�O(nloglogn) 
{
	for(int i = 2;i <= maxn;i++)
	{
		if(notp[i]) continue;
		for(int j = 2;j <= maxn;j++)
		{	
			if(i*j > maxn) break;//���У����������Χ������ 
			notp[i*j] = true;//��0��1�������ı����ض��Ǻ��� 
			
		}
			
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	notp[0] = notp[1] =true;
	findprime(n);//������� 
	int x = 0;
	for(int i = 0;i <= n;i++)//������ͳ�ƣ��㼯��prime���������������� 
		if(!notp[i] && i != 0 && i != 1) //���У�0��1������ 
			prime[x++] = i;
	for(int i = 0;i < x;i++)//ö�����п����� 
	{
		for(int j = 0;j < x;j++)
		{
			if(n - prime[i] - prime[j] < 0) break;//������һ����С��0���� 
			if(!notp[n - prime[i] - prime[j]] )
			{
				printf("%d %d %d",prime[i],prime[j],n - prime[i] - prime[j]);
				return 0;
			}
		}
	}
	return 0;
}
