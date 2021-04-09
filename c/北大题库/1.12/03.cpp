#include<stdio.h>

struct aa
{
	char name[20];
	int ks;
	float temper;
}pl[210];
int a[210],count,x;
void pd(float temper,bool boolean,int i)
{
	if(temper>=37.5&&boolean)
	{
		a[x]=i;x++;
	}
}
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<210;i++)a[i]=-1;
 for(i=0;i<n;i++)
		scanf("%s%f %d",pl[i].name,&pl[i].temper,&pl[i].ks);
	for(i=0;i<n;i++)
		pd(pl[i].temper,(bool)pl[i].ks,i);
	for(i=0;i<n;i++)
	if(a[i]!=-1)    printf("%s\n",pl[a[i]].name);
	printf("%d",x);
	return 0;
}

