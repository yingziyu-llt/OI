#include<stdio.h>
int main()
{
	//freopen("librarian.in","r",stdin);
	//freopen("librarian.out","w",stdout);
	int n,q,num[1000]={0},neednum[1000]={0},need[1000]={0},tempans;
	int j=0,temp=0,temp1=1,tempn[1000]={0},ans[1000]={100000001},b=0,i=0;
	scanf("%d %d",&n,&q);//n是书的数量，p是读者数量 
	for(i=0;i<1000;i++)	ans[i]=100000001;
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);//num是图书编码 
	}
	for(i=0;i<q;i++)
	{
		scanf("%d %d",&neednum[i],&need[i]);//neednum是需求码的位数 need是需求码 
	}
	
	
	for(i=0;i<q;i++)
	{
		b=0;
		temp=need[i];
		temp1=1;
		for(j=0;j<neednum[i];j++)
		{
			need[i]=need[i]/10;
			temp1=temp1*10;
		}
		for(j=0;j<1000;j++)	tempn[j]=0;
		for(j=0;j<n;j++)
		{
			tempn[j]=num[j]%temp1;
		}
		for(j=0;j<n;j++)
		{
			if(tempn[j]==temp)	tempans=num[j];
			else tempans=1000000000;
			if(tempans<ans[i])
			{
				ans[i]=tempans;
				b=1;
			}
		}
		if(b==0) ans[i]= -1;
	}
	
	
	for(i=0;i<q;i++)	printf("%d\n",ans[i]);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
