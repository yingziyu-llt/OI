#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[100000][2];
int d,b;
int main()
{
	int c;
	int i,j;
	srand((unsigned)time(NULL));
	/*随机种子*/
	for(j=0;j<20;j++)
	{
	c=rand()%(20-1+1)+1;
	FILE *aa=fopen("C:\\Users\\林茂\\Desktop\\input.txt","w");
	fprintf(aa,"%d\n",c);
	for(i=0;i<c;i++)
	{
		fprintf(aa,"%d %d",rand()%(10-1+1)+1,rand()%(10-1+1)+1);
	}
	system("CD C:\\Users\\林茂\\Desktop\\c\\北大题库\\2.2");
	system("sol.exe");
	FILE *bb=fopen("C:\\Users\\林茂\\Desktop\\c\\北大题库\\2.2\\output.txt","r");
	for(i=0;i<c;i++)
		fscanf(bb,"%d %d",&a[i][0],&a[i][1]);
	double fr=clock();
	system("666.exe");
	double ed=clock();
	double time=ed-fr;
	fseek(bb,0,0);
	for(i=0;i<c;i++)
	{
		fscanf(bb,"%d %d",&d,&b);
		if(d!=a[i][0]||b!=a[i][1])
		{
			printf("Wrong Answer!");
			break;
		}
	}
	printf("AC 用时%lf ms",time);
	}
}
