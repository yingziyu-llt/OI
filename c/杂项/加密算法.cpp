#include<bits/stdc++.h>
using namespace std;
char a[100000];
int getkey(int m,int n)
{
	long long x;
	int c;
	x=pow(m,n);
	srand((unsigned)time(NULL)); /*Ëæ»úÖÖ×Ó*/
	c=rand()%(32767-0+1)+0;
	return x%c%26;
}
int toGet(int key)
{
	for(int i=0;i<strlen(a);i++)
	{
		a[i]+=key;
	}
	return 0;
}
int main()
{
	int key;
	int x,y;
	gets(a);
	srand((unsigned)time(NULL));
	key=getkey(rand()%(10-1+1)+1,rand()%(10-1+1)+1);
	toGet(key);
	printf("%s %d",a,key);
	return 0;
}
