#include<stdio.h>
int father[1000000];
int findfather(int a)
{
	return father[a]= father[a]==a ? a:findfather(father[a]);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a=1000000;
	while(--a) father[a]=a;
	while(m--)
	{
		int x,y,z;
		scanf("%d",&z);
		scanf("%d%d",&x,&y);
		if(z==1)
			father[findfather(x)]=findfather(y);
		else if(findfather(x)==findfather(y)&&z==2) printf("Y\n");
		else if(z==2)                          printf("N\n");
		
	}
}
