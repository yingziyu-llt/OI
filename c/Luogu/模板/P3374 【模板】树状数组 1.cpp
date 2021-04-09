#include<stdio.h>
using namespace std;
long long bit_tree[500010],n;
int lowbit(int x) {return x & (-x);}
void change(long long f,long long add)
{
	for(int i = f;i <= n;i += lowbit(i))
		bit_tree[i] += add;
}
long long query(int x)
{
	if(x == 0) return 0;
	long long res = 0;
	for(int i = x;i >= 1;i -= lowbit(i))
		res += bit_tree[i];
	return res;
}
int main()
{
	int m;
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		change(i,tmp);
	}
	for(int i = 0;i < m;i++)
	{
		int commond = 0;
		int x,y;
		scanf("%d %d %d",&commond,&x,&y);
		if(commond == 1)
			change(x,y);
		else
		{
			int a = query(x - 1);
			int b = query(y);
			printf("%d\n",b - a);
		}
	}
	return 0;
}