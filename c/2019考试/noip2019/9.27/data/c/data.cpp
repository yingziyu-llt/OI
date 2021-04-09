#include<bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[])
{
	srand(time(0));
	int nn=atoi(argv[1]);
	int n=rand()%nn+1;
	printf("%d\n",n);
	for(int i=2;i<=n;++i)printf("%d %d\n",i,rand()%(i-1)+1);
	return 0;
}
