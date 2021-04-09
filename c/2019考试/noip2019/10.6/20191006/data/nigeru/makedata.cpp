#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
const int maxn = 100005;
int c[]={0,5,5},tot;
int main()
{
	freopen("makedata.bat","w",stdout);
	//printf("@echo off\n");
	for (int i=1;i<=2;i++)
	for (int j=1;j<=c[i];j++) {
		int o=++tot;
		printf("gen 100000 %d >nigeru%d.in\nnigeru <nigeru%d.in >nigeru%d.out\n",j,o,o,o);
	}
	printf("pause");
	return 0;
}
