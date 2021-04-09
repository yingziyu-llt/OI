#include<bits/stdc++.h>
long long scan()
{
	char ch = getchar();
	long long temp = 0;
	while(ch > '9' || ch < '0') {ch = getchar();if(ch == EOF) return -1;}
	while(ch >= '0' && ch <= '9')
	{
		temp = (temp << 3) + (temp << 1) + ch - '0';
		ch = getchar();
		if(ch == EOF) return -1;
	}
	return temp;
}

int main()
{
	freopen("koopa.in","r",stdin);
	freopen("koopa.out","w",stdout);
	long long a,b;
	while(1)
	{
		a = scan();
		b = scan();
		if(a == -1 || b == -1) break;
		if(a - b * 6 > 0) printf("WIN\n");
		else printf("LOSE.\n");
	}
}
	
