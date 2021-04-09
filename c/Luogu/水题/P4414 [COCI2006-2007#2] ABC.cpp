#include<stdio.h>
void bsort(int a[])
{
	for(int i=0;i<3;i++)
	{
		for(int j=i;j<3;j++)
		{
			if(a[i]>a[j]) 
			{
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
} 
int main()
{
	int a[3];
	char c[4]={0};
	for(int i=0;i<3;i++) scanf("%d",&a[i]);
	scanf("%s",c);
	bsort(a);
	for(int i=0;i<3;i++)
		printf("%d ",a[c[i]-'A']);
	return 0;
}
