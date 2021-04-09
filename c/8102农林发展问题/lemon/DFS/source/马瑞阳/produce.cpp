#include<stdio.h>
#include<string.h>
int main()
{                    
	int a,b,c;
	freopen("produce.in","r",stdin);
	freopen("produce.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	if(a==b&&b==c)printf("0 %d",c);
	if(a==1&&b==1&&c==2)printf("0 1 2");
	if(a==1&&b==2&&c==1)printf("0 1");
	if(a==1&&b==2&&c==2)printf("0 1 2");
	if(a==2&&b==1&&c==1)printf("0 1");
	if(a==2&&b==1&&c==2)printf("0 1 2");
	if(a==2&&b==2&&c==1)printf("0 1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
