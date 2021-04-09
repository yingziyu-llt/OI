#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
const int maxn = 100005;
int a[]={0,2,5,10};
int c[]={0,1,1,8};
int main()
{
	freopen("makedata.bat","w",stdout);
	//printf("@echo off\n");
	int tot=0;
	for (int i=1;i<=3;i++)
	for (int j=1;j<=c[i];j++) {
		int o=++tot;
		printf("gen %d >haji%d.in\nhaji <haji%d.in >haji%d.out\n",a[i],o,o,o);
	}
	printf("pause");
	return 0;
}
