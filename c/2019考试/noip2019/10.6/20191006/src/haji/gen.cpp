#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
const int maxn = 100005;

int main(int argv,char *argc[])
{
	int n=atoi(argc[1]);
		
	srand((int)time(0)^size_t(new char));
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		printf("%d%c",rand()%12+1," \n"[j==n]);
	return 0;
}
