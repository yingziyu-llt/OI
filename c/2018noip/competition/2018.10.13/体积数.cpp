#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int i,n;
	double a;
	int ans = 0;
	scanf("%d",&n);
	for(int i = 1;i < n;i++)
	{
		for(int j = 2;i / j > 0;j++)
		{
			a = pow(i,1.0/j);
			if(a == (int) a) 
			{
				ans ++;
				break;
			}
		}
	}
	printf("%d",ans + 1);
}