#include<bits/stdc++.h>
int main()
{
	freopen("find5.in","w",stdout);
	srand((unsigned)time(NULL));
	int m = 10,n = 5;
	int T = 10;
	while(T--)
	{
	printf("%d %d\n",m,n);
	for(int i = 1 ; i <= m ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			for(int k = 1 ; k <= n ; k++)
			{
				int r = rand()%10;
				if(r <= 3) printf(".");
				else printf("#"); 
			}
			printf("\n");
		}
		printf("\n");
	}
	}
}
