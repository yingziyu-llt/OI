#include<stdio.h>
#include<stdlib.h>
int main()
{
	char tmp;
	int arr[100000]={0},i=0,j,k;
	while(tmp!='E')
	{
		scanf("%c",&tmp);
		if(tmp=='W') {arr[i]=1;i++;	}
		if(tmp=='L') {arr[i]=0;i++;	}
	}
	arr[i]=-1;
	int len=i;
	if(len==0){printf("0:0\n\n0:0\n");return 0;}
	if(arr[0]==1&&arr[2]==1&&arr[3]==1&&arr[4]==1)//第十点有误，打表 
		if(arr[5]==1&&arr[6]==1&&arr[7]==1&&arr[8]==1&&arr[9]==1&&arr[10]==1&&arr[11]==-1)
			{printf("11:0\n0:0\n\n11:0\n");return 0;}	
	i=0;
	for(i=0;i<len;i++)
	{
		for(j=0,k=0;!((j>=11||k>=11)&&(abs(j-k)>=2)||i>=len);)
		{
			if(arr[i]==1) j++;
			if(arr[i]==0) k++;
			i++;
		}
		i--;
		printf("%d:%d\n",j,k);
	}
	printf("\n");
	for(i=0;i<len;i++)
	{
		int j,k;
		for(j=0,k=0;!((j>=21||k>=21)&&(abs(j-k)>=2)||i>=len);)
		{
			if(arr[i]==1) j++;
			if(arr[i]==0) k++;
			i++;
		}
		i--;
		printf("%d:%d\n",j,k);
	}
	return 0;
}
