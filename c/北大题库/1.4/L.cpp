#include<stdio.h>
//#include<math.h> 
int main()
{
	//"//"内是第2版 
	int a,b,c;//int d;
	scanf("%d %d",&a,&b);
	//d=(int)log10(b)+1;
	if(b<10)        c=a*10+b;//if(d==1)
	else if(b<100)  c=a*100+b;//if(d==2)
	else if(b<1000) c=a*1000+b;//if(d==3)
	//第三：c=a*(int)pow() 
	printf("%d",c);
	return 0;
}

