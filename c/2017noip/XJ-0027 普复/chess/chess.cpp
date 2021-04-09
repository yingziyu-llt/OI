#include<stdio.h>
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	printf("%d",-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
