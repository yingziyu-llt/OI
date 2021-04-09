#include<stdio.h>
int a[20];
int myfunc(int aa)
{
	if(aa==1||aa==2) return a[aa]=1;
	else
	{
		if(a[aa]==0) a[aa]=myfunc(aa-1)+myfunc(aa-2);
		return a[aa];
	}
}
int main()
{
	int a,n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		printf("%d\n",myfunc(a));
	}
	return 0;
}
