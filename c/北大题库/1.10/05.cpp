#include<bits/stdc++.h>
using namespace std;
int n,m,x;
struct a
{
	int num;
	int s;
}people[5011];
int main()
{
	int i,j,y,z=0;
	scanf("%d %d",&n,&m);
	x=(int)((double)m*1.5);
	for(i=1;i<=n;i++)
		scanf("%d %d",&people[i].num,&people[i].s);
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(people[i].s<people[j].s)	swap(people[i],people[j]);
			if(people[i].s==people[j].s&&people[i].num>people[j].num)	swap(people[i],people[j]);
		} 
	}
	y=people[x].s;
	for(i=1;i<=n;i++)
		if(people[i].s>=y)  z++;
	printf("%d %d\n",y,z);
	for(i=1;i<=z;i++)
		printf("%d %d\n",people[i].num,people[i].s);
	return 0;
}
