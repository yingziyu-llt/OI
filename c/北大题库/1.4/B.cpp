#include<stdio.h>
int main()
{
 int a;
 int d,e,f,g,h;
 int k=0,p=0;
 scanf("%d",&a);
 d=a%10;
 e=a/10%10;
 f=a/100%10;
 g=a/1000%10;
 h=a/10000;
 if(d%2==0)			k+=d;
 else 				p+=d;	
 if(e%2==0)			k+=e;
 else 				p+=e;	
 if(f%2==0)			k+=f;
 else 				p+=f;	
 if(g%2==0)			k+=g;
 else 				p+=g;	
 if(h%2==0)			k+=h;
 else 				p+=h;	
 printf("%d\n",p);
 printf("%d",k);
 return 0;
}
