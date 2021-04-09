#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int input(int &x)
{
	char c='0';
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
		if(c==EOF) return -1;
		if(c=='\n') return -2;
		if(c==' ')  return x;
	}
}
int main()
{
	int a[100]={0};
	freopen("1ol.in","r",stdin);
	freopen("1ol.out","w",stdout);
	bool stop=false;
	while(1)
	{
		int len;
		memset(a,0,sizeof(a));
		for(len=0;;len++)
		{
			int flag=input(a[len]);
			if(flag==-1) 
			{
				stop=true;
				break;
			}
			if(flag==-2)
			{
				break;
			}
		}
		long long x=0,y=0;
		int head=0,tail=len;
		while(head<=tail)
		{
			if(head==tail)
			{
				x+=a[head];
				printf("%d ",a[head]);
				break;
			}
			if(a[head]>a[tail])
			{
				x+=a[head];
				printf("%d ",a[head]);
				y+=a[tail];
				printf("%d ",a[tail]);
			}
			else
			{	
				x+=a[tail];
				printf("%d ",a[tail]);
				y+=a[head];
				printf("%d ",a[head]);
			}	
			head++;
			tail--;
		}
		if(x>y)
			printf("Win\n");
		else if(x==y)
			printf("Draw\n");
		else
			printf("Lose\n");
		if(stop) break;
	}
	return 0;
} 
