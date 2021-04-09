#include<stdio.h>
int main()
{
	//freopen("score.in","r",stdin);
	//freopen("score.out","w",stdout);
	float a,b,c,ans;
	scanf("%f %f %f",&a,&b,&c);
	ans=a*0.2+b*0.3+c*0.5;
	printf("%.0f",ans);
	//fclose(stdin);
	//fclose(stdout);
}
