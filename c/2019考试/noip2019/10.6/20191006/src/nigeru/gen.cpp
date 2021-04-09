#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
const int maxn = 100005;
char s[maxn];int tot;
int main(int argv,char *argc[])
{
	int n=atoi(argc[1]);
	int tp=atoi(argc[2]);
	for (int i='a';i<='z';i++) s[tot++]=i;
	for (int i='A';i<='Z';i++) s[tot++]=i;
	for (int i=1;i<=10;i++) s[tot++]='.';
	for (int i=1;i<=10;i++) s[tot++]=' ';
	srand((int)time(0));
	if (tp==1) {
		for (int i=1;i<=n;i++)
			printf("%c",s[rand()%tot]);
	}
	if (tp==2) {
		for (int i=1;i<=n;i++)
			putchar('.');
	}
	if (tp==3) {
		for (int i=1;i<=n;i++)
			putchar(' ');
	}
	if (tp==4) {
		for (int i=1;i<=n;i++)
			putchar('a');
	}
	if (tp==5) {
		for (int i=1;i<=n;i++)
			putchar('A');
	}
	return 0;
}
