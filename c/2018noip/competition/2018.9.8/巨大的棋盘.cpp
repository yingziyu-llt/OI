#include<stdio.h>
#include<string.h>
int main()
{
	int m,n,t,odown = 0,oright = 0;//odown:once down ,orignt:once right
	scanf("%d%d%d",&n,&m,&t);
	char a[100000];
	scanf("%s",&a);
	int len = strlen(a);
	for(int i = 0;i < len;i++)
	{
		if(a[i] == 'U') odown--;
		else if(a[i] == 'D') odown++;
		else if(a[i] == 'L') oright--;
		else                 oright++;
		oright %= n;
		odown %= m;
	}
	int x;
	scanf("%d",&x);
	for(int i = 0;i < x;i++)
	{
		int x,y,ansx,ansy;
		scanf("%d %d",&x,&y);
		ansx = (x + oright) %n;
		ansy = (y + odown) % n;
		if(ansx <= 0) ansx = n + ansx;
		if(ansy <= 0) ansy = n + ansy;
		printf("%d %d\n",ansx,ansy);
	}
}
