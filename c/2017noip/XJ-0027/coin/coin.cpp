#include<stdio.h>
int main()
{
	int i,ans=0,in;
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	scanf("%d",&in);
	for(i=0; ;i++)
	{
		ans=ans+i*i;
		in=in-i;
		if((in==0)||(in<i))break;
	}
	if(in==0)
	printf("%d",ans);
	else
	printf("%d",ans+(i+1)*in);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
