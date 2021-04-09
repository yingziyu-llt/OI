#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand((unsigned long long)time(NULL));
	int r,c;
	r = rand() % 20;
	c = rand() % 20;
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++)
		{
			int t = rand() % 2;
			printf("%c",t == 0 ? '\\':'/');
		}
		printf("\n");
	}
	return 0;
}