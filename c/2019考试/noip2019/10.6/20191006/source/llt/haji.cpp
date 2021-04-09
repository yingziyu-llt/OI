#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int map[11][11];
int main()
{
	freopen("haji.in","r",stdin);
	freopen("haji.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			scanf("%d",map[i][j]);
		}
	}
	if(n == 1)
	{
		printf("%d",n);
		return 0;
	}
	if(n == 2)
	{
		if((map[1][1] % 3 == map[1][2] % 3 && map[2][1] % 3 == map[2][2] % 3) ||(map[1][1] % 3 == map[2][1] % 3 && map[1][2] % 3 == map[2][2] % 3))
		{
			printf("%d",n * n);
			return 0;
		}
		printf("3");
	}
	return 0;
}