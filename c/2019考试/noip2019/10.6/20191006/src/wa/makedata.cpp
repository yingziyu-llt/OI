#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
const int maxn = 100005;
int a[]={0,10,1000,100000};
int c[]={0,2,4,4};
int tot;
int main()
{
	freopen("makedata.bat","w",stdout);
	//printf("@echo off\n");
	for (int i=1;i<=3;i++)
	for (int j=1;j<=c[i];j++) {
		int o=++tot;
		printf("gen %d >wa%d.in\nwa <wa%d.in >wa%d.out\n",a[i],o,o,o);
	}
	printf("pause");
	return 0;
}
