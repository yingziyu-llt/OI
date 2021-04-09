#include <stdio.h>
int main()
{
	int a,b=13,w=1,temp,i;
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d",&a);
	for(i=0;i<12;i++)
	{
		if((b+a)%7-1==5)  printf("%d\n",w);
		b=b+month[i];
		w++;
	}
	return 0;
}
