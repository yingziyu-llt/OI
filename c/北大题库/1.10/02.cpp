#include<stdio.h>
long long a[500],an[500],tmp;
int n;
int main()
{
	int i=0,j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		if(a[i]%2==1)  {an[j]=a[i];j++;}  //»ò   if(!a[i]&1) ......
	n=j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(an[i]>an[j])
			{
				tmp=an[i];
				an[i]=an[j];
				an[j]=tmp;
		    }
		}
	}
	printf("%d",an[0]);
	for(i=1;i<n;i++)
	printf(",%d",an[i]);
	return 0;
}
