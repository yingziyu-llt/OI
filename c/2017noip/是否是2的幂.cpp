#include<stdio.h>
#include<math.h>
int main()
{
	int a,i;
	double temp;
	int yn;
	scanf("%d",&a);
	yn=0;
	for(i=1;i<=32;i++)
	{
		temp=a/(pow(2,i));
		if(temp==1)
		{
			yn=1;
			break;
		}
	}
	if(yn==1)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
} 
