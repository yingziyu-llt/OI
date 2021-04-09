#include<stdio.h> 
//评分系统
int main()
{
	int a[12][6],i,j,max[12],min[12];//ans[a][x]  a=0：ave[x]   a=1:排名   a=2：奖次 
	float ave[12]={0},b[12],temp,ans[3][12];
	freopen("评分数据.in","r",stdin);
	freopen("评分结果.ans","w",stdout);
	for(i=0;i<12;i++)
	{
		for(j=0;j<6;j++)
		{
			
			scanf("%d",&a[i][j]);
		}
	}	
	for(i=0;i<12;i++)
	{
		max[i]=0;
		min[i]=120;
		for(j=0;j<6;j++)
		{
			if(max[i]<a[i][j])   max[i]=a[i][j];
			if(min[i]>a[i][j])   min[i]=a[i][j]; 
		}
		ave[i]=(double)(a[i][0]+a[i][1]+a[i][2]+a[i][3]+a[i][4]+a[i][5]-max[i]-min[i])/4.0;
	}
	
	for(i=0;i<12;i++)    b[i]=ave[i];
	
	for(i=0;i<12;i++)
	{
		for(j=i+1;j<12;j++)
		{
			if(b[i]<b[j])
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	
	for(i=0;i<12;i++)
	{
		ans[0][i]=ave[i];
		for(j=0;j<12;j++)
		{
			if(ave[i]==b[j])   {ans[1][i]=j+1;break;} 
		}
		if(ans[1][i]==1)      ans[2][i]=1;
		else if(ans[1][i]<=3) ans[2][i]=2;
		else if(ans[1][i]<=5) ans[2][i]=3;
		else                ans[2][i]=4;
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d年级%d班   %d %d %.3lf %.0lf %.0lf\n",i+7,j+1,max[i*4+j],min[i*4+j],ans[0][i*4+j],ans[1][i*4+j],ans[2][i*4+j]);
			temp=i*4+j;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
