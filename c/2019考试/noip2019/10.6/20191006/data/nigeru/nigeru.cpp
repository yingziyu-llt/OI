#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h> 

using namespace std;
const int maxn = 100005;

char s[maxn];int len;bool State;
bool check_low(char ch) {
	return ch>='a'&&ch<='z';
}
bool check_upp(char ch) {
	return ch>='A'&&ch<='Z';
}
int main()
{
	#ifndef ONLINE_JUDGE
		//freopen("nigeru.in","r",stdin);
		//freopen("nigeru.out","w",stdout);
	#endif
	gets(s+1);len=strlen(s+1);State=true;
	for (int i=1;i<=len;i++)
	{
		if (s[i]=='.') {State=true;putchar('.');}
		else if (s[i]==' ') putchar(' ');
		else if (check_low(s[i])) {
			if (State) putchar(s[i]-'a'+'A');
			else putchar(s[i]);
			State=false;
		}
		else if (check_upp(s[i])) {
			if (State) putchar(s[i]);
			else putchar(s[i]-'A'+'a');
			State=false;
		}
	}
	return 0;
}
