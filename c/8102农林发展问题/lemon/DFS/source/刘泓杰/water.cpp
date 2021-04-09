#include<iostream>
#include<stdio.h>
using namespace std;
int fl[110][110],Ans=0,fl2[110][110];
int main()
{
	int n;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			fl[i][j]=-3;
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>fl[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			fl2[i][j]=fl[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(fl[i][j]==10)
   			{
   				fl2[i][j]=-1;
				if(fl[i+1][j]!=3&&fl[i+1][j]!=0&&fl[i+1][j]!=-3)fl2[i+1][j]=-1;
				if(fl[i-1][j]!=4&&fl[i-1][j]!=0&&fl[i-1][j]!=-3)fl2[i-1][j]=-1;
				if(fl[i][j+1]!=1&&fl[i][j+1]!=0&&fl[i][j+1]!=-3)fl2[i][j+1]=-1;
				if(fl[i][j-1]!=2&&fl[i][j-1]!=0&&fl[i][j-1]!=-3)fl2[i][j-1]=-1;
   			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(fl2[i][j]==-1)
			{
				if(fl[i][j]==10)continue;
				if(fl[i][j]==1)
				{
					if(fl[i+1][j]!=0&&fl[i+1][j]!=-3)fl2[i+1][j]=-1;
					if(fl[i-1][j]!=0&&fl[i-1][j]!=-3)fl2[i-1][j]=-1;
					if(fl[i][j+1]!=0&&fl[i][j+1]!=-3)fl2[i][j+1]=-1;
				}
				if(fl[i][j]==2)
				{
					if(fl[i+1][j]!=0&&fl[i+1][j]!=-3)fl2[i+1][j]=-1;
					if(fl[i-1][j]!=0&&fl[i-1][j]!=-3)fl2[i-1][j]=-1;
					if(fl[i][j-1]!=0&&fl[i][j-1]!=-3)fl2[i][j-1]=-1;
				}
				if(fl[i][j]==3)
				{
					if(fl[i+1][j]!=0&&fl[i+1][j]!=-3)fl2[i+1][j]=-1;
					if(fl[i][j-1]!=0&&fl[i][j-1]!=-3)fl2[i][j-1]=-1;
					if(fl[i][j+1]!=0&&fl[i][j+1]!=-3)fl2[i][j+1]=-1;
				}
				if(fl[i][j]==4)
				{
					if(fl[i-1][j]!=0&&fl[i-1][j]!=-3)fl2[i-1][j]=-1;
					if(fl[i][j-1]!=0&&fl[i][j-1]!=-3)fl2[i][j-1]=-1;
					if(fl[i][j+1]!=0&&fl[i][j+1]!=-3)fl2[i][j+1]=-1;
				}
				if(fl[i][j]==5)
				{
					if(fl[i+1][j]!=0&&fl[i+1][j]!=-3)fl2[i+1][j]=-1;
					if(fl[i-1][j]!=0&&fl[i-1][j]!=-3)fl2[i-1][j]=-1;
					if(fl[i][j+1]!=0&&fl[i][j+1]!=-3)fl2[i][j+1]=-1;
					if(fl[i][j-1]!=0&&fl[i][j-1]!=-3)fl2[i][j-1]=-1;
				}
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(fl2[i][j]==1||fl2[i][j]==2||fl2[i][j]==3||fl2[i][j]==4||fl2[i][j]==5)Ans++;
	cout<<Ans;
	fclose(stdin);
	fclose(stdout);
	return 0;

}
