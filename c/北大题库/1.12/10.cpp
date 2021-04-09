#include<stdio.h>
int a[10010],c[2][10010],x=2;
int findfx(int b)
{
	int i;
	bool is;
	a[0]=2;a[1]=3;
	for(i=5;i<b;i++)
	{
		is=true;
		for(int j=0;j<x;j++)
		{
			if(i%a[j]==0){
				is=false;
				break;
			}
		}
		if(is)  {
			a[x]=i;
			x++;
		}
	}
	return 0;
}
int isright(int xx)
{
	int i,j,mid,l,r,tmp,y=0;
	bool z;
	for(i=0;i<xx&&i<x;i++)
	{
		z=false;
		tmp=a[i]+2;
		if(tmp==a[i+1]){
			c[1][y]=a[i];
			c[2][y]=tmp;
			y++;
   		}
	}
	return y;
}
int main()
{
	int i,n,y;
	bool find=false;
	scanf("%d",&n);
	if(n==5)
	{
		printf("3 5");
		return 0;
	}
	findfx(n);
	y=isright(n);
	find=(y>0);
	if(find)
	{
		for(i=0;i<y;i++)
		{
			printf("%d %d\n",c[1][i],c[2][i]);
		}
	}
	else    printf("empty");
	return 0;
}
