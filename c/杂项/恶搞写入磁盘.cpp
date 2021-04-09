#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	char a[100000];
	long long cnt=0;
	srand((unsigned)time(NULL));
	while(1)
	{
		memset(a,0,sizeof(a));
		long long tmp=cnt;
		for(int i=0;i<100000;i++)
		{
			a[i]=tmp%10+'0';
			tmp/=10;
		}
		cnt++;
		FILE *f=NULL;
		freopen(a,"w",f);
		for(int i=0;i<0x7ffff;i++)
		fprintf(f,"%c",rand()%126);
	}
}
