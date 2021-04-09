#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[])
{
	srand(time(0));
	int T=rand()%5+1;
	printf("%d\n",T);
	int nn=atoi(argv[1]);
	while(T--)
	{
		int n=rand()%nn+1,m=rand()%nn+1;
		printf("%d %d\n",n,m);
		for(int i=1;i<=n;++i)printf("%d ",rand()%n+1);
		puts("");
		for(int i=1;i<=m;++i)printf("%d ",rand()%n+1);
		puts("");
	}
	return 0;
}
