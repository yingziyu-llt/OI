#include<stdio.h>
#include<string.h>
int hsh[26];
#include<algorithm>
using namespace std;
int main()
{
	char s[10010];
	scanf("%s",s);
	int len = strlen(s);
	for(int i = 0 ;i < len;i++)
		hsh[s[i] - 'a']++;
	int min = 110,max = 0; 
	for(int i = 0;i < 26;i++)
	{
		if(hsh[i] != 0 && hsh[i] < min) min = hsh[i];
		if(hsh[i] > max) max = hsh[i];
	}
	int x = max - min;
	bool b = false;
	if(x <= 1) b = true;
	for(int i  = 2;i < x;i++)
		if(x % i == 0) b = true;
	if(b) 
		printf("No Answer\n0");
	else
		printf("Lucky Word\n%d",x);
	return 0;
}