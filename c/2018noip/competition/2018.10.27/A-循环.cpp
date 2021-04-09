#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int op,a,b,c,ans = 0;
	scanf("%d%d%d%d",&a,&op,&b,&c);
	if(op == 1)
	{
		if(a <= b && c < 0 || a <= b && c == 0)
			printf("-1");
		else
		{
			for(int i = a;i <= b;i += c)
				ans++;
			printf("%d",ans);
		}
	}
	else if(op == 2)
	{
		if(a >= b && c > 0 || a >= b && c == 0)
			printf("-1");
		else
		{
			for(int i = a;i >= b;i += c)
				ans++;
			printf("%d",ans);
		}
	}
	else
	{
		if(a > b && c > 0 || a < b && c < 0 || a != b && c == 0)
			printf("-1");
		else if(a == b) 
			printf("0");
		else if((a - b) % c != 0)
			printf("-1");
		else
		{
			for(int i = a;i != b;i += c)
				ans++;
			printf("%d",ans);
		}
	}
	return 0;
}