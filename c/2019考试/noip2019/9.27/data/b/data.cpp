#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[])
{
	srand(time(0));
	int TT=atoi(argv[1]);
	int T=rand()%TT+1;
	printf("%d\n",T);
	int nn=atoi(argv[2]);
	while(T--)
	{
		int n=rand()%nn+1;
		printf("%d\n",n);
		for(int i=1;i<=n;++i)printf("%d ",rand()%1000+1);
		puts("");
	}
	return 0;
}
