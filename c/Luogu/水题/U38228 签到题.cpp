#include<stdio.h>
#include<stdlib.h>
#include<time.h>
long long n;
int main()
{
	int count = 0;
	int m,k;
	scanf("%d%d",&k,&m);
	n = 0;
	for(int i = 0;i < 19;i++)
	{
		n = n * 10 + 1;
		count++;
		if(n % m == k)
			break;
	}
	if(count == 0)
	{
		srand((unsigned int)time(NULL));
		count = rand() % 100 + 19;
	}
	printf("%d",count);
	return 0;
}
