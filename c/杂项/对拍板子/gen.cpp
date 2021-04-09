#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	srand((unsigned long long)time(NULL));
	int T,a,b,c,d;
	T = rand() % 10 + 1;
	printf("%d\n",T);
	for(int i = 0;i < T;i++)
	{
		a = rand() % 200 + 1;
		b = rand() % 200 + 1;
		c = rand() % 200 + 1;
		d = rand() % 200 + 1;
		printf("%d %d %d %d\n",a,b,c,d);
	}
	return 0;
}