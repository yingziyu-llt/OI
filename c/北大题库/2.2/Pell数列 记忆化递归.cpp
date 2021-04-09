#include<stdio.h>
int aa[1000000];
int pell(int a)
{
	if(a==1)
		return 1;
	if(a==2)
		return 2;
	if(aa[a])
		return aa[a];
	return aa[a]=(pell(a-1)*2+pell(a-2))%32767;
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in);
		printf("%d\n",pell(in));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
