#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int V,S = 0x7fffffff;
	scanf("%d",&V);
	for(int i = sqrt(V);i > 0;i--)
	{
		if(V % i != 0) continue;
		for(int j = sqrt(V / i);j >= i;j--)
		{
			if((V % j == 0) &&( V % (V / i / j) == 0))
			{
				int c = V / i / j;
				int s = 2 * (i * j + i * c + j * c);
				S = min(S,s);
			}
		}
	}
	printf("%d",S);
	return 0;
}