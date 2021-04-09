#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct node
{
	double leftx[26],rightx[26];//左边的未知数和右边的未知数（a~z）
	double normall,normalr;    //左、右常数项
}x[26];
int count1;
int leftToRight(int a,int b,int c)//移项
								 //a:式子编号 b:未知数编号
{
	double tmp=x[a].leftx[b];
	x[a].leftx[b]=0;
	x[a].rightx[b]-=tmp;
	return 0;
}
int coefficientTo1(int a,int b,int c)//系数化为一
                                    //a:式子编号 b:未知数编号
{
	double tmp=1/x[a].leftx[b];
	x[a].leftx[b]=1;
	for(int i=0;i<26;i++)
		x[a].rightx[i]/=tmp;
	for(int i=0;i<100;i++)
	{
		x[a].normall/=tmp;
		x[a].normalr/=tmp;
	}
	return 0;
}
int input()
{
	printf("输入未知数个数：");
	scanf("%d",&count1);
	printf("输入方程（写完一个式子打一个回车）（数字和字母间一个空格");
	printf("常数后带一个大写字母N）") ;
	printf("格式如下：\n+5 x +3 y -20 N= -1 N\n+2 x -2 y = 2 N\n");
	for(int i=0;i<count1;i++)
	{
		for(int o=0;o<2;o++)
		{
			bool end=false;
			for(int j=0;j<100;j++)
			{
				int lr=o+1;
				char c;
				int tmp=0;
				int note=1;
				scanf("%c",c);
				if(c=='+'||c=='-')
				{
					scanf("%lf",&tmp);
					if(c=='-') tmp*=-1;
				}
				else if(c<='z'&&c>='a') 
				{
					if(lr=1)//left
					{
						x[i].leftx[c-'a']+=tmp;
					}
					else //right
					{
						x[i].rightx[c-'a']+=tmp;
					}
				}
				else if(c=='N') //常数 
				{
					if(lr=1) x[i].normall+=tmp;
					else     x[i].normalr+=tmp;
				}
				else if(c=='=') 
				{
					break;
				}
				else if(c=='\n')
				{
					break;
				}
			}
		}
	}
}
int goase()
{
		
} 