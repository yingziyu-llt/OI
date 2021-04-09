#include<stdio.h>
int main()
{
	//freopen("score.in","r",stdin);
	//freopen("score.out","w",stdout);
	int a,b,c,ans;
	scanf("%d %d %d",&a,&b,&c);
	ans=a*0.2+b*0.3+c*0.5;
	printf("%d",ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
