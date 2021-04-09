#include<bits/stdc++.h>
using namespace std;
struct aa
{
	char num[10];
	int age;
	int x;
}p[100];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&p[i].num);
		scanf("%d",&p[i].age);
		p[i].x=i;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[j].age>=60)/*ÀÏÄêÈË*/
			{
				if(p[i].age<60)     swap(p[i],p[j]);
				else if(p[i].age>=60)
					    {
							if(p[i].age<p[j].age)   swap(p[i],p[j]);
							if(p[i].age==p[j].age&&p[i].x>p[j].x)   swap(p[i],p[j]);
						}
				
			}
			if(p[j].age<60)
				if(p[i].age<60&&p[i].x>p[j].x)  swap(p[i],p[j]);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s\n",p[i].num);
	}
}
