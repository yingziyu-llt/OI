#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
const int maxn = 100005;

int n,a[maxn];
int main(int argv,char *argc[])
{
	int n=atoi(argc[1]);
	srand((int)time(0)^size_t(new char));
	for (int i=1;i<=n;i++) a[i]=i;
	random_shuffle(a+1,a+n+1);
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
