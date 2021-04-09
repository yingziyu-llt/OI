#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,l,r;
	scanf("%d",&t);
	for(int _i = 0;_i < t;_i++)
	{
		scanf("%d %d",&l,&r);
		printf("%d %d\n",l,l * 2);
	}
}
