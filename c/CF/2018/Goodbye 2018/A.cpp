#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int a[3];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	int minm = 0x7fffffff,minn;
	for(int i = 0;i < 3;i++)
	{
		if(minm > a[i]) minm = a[i],minn = i;
	}
	for(int i = 0;i < 3;i++)
			if(a[i] < minm + i - minn)
				minm = a[i],minn = i; 
	if(minn == 0)  printf("%d",minm * 3 + 3);
	else if(minn == 1) printf("%d",minm * 3);
	else          printf("%d",minm * 3 - 3);
	return 0;
}
