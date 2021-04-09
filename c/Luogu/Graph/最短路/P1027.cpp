#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double f[410][410];
int pos[110][4][2];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i = 1;i <= 400;i++)
			for(int j = 1;j <= 400;j++)
				f[i][j] = 1e10;
		int s,t,A,B;
		scanf("%d%d%d%d",&s,&t,&A,&B);
		for(int i = 0;i < s;i++)
		{
			int ti;
			for(int j = 0;j < 3;j++)
				scanf("%d%d",&pos[i][j][0],&pos[i][j][1]);
			scanf("%d",&ti);
			double ab = dist(pos[i][0][0],pos[i][0][1],pos[i][1][0],pos[i][1][1]);
			double ac = dist(pos[i][0][0],pos[i][0][1],pos[i][2][0],pos[i][2][1]);
			double bc = dist(pos[i][2][0],pos[i][2][1],pos[i][1][0],pos[i][1][1]);
			if(ab > ac && ab > bc)
				pos[i][3][0] = pos[i][0][0] + pos[i][1][0] - pos[i][2][0],
				pos[i][3][1] = pos[i][0][1] + pos[i][1][1] - pos[i][2][1];
			else if(ac > ab && ac > bc)
				pos[i][3][0] = pos[i][0][0] + pos[i][2][0] - pos[i][1][0],
				pos[i][3][1] = pos[i][0][1] + pos[i][2][1] - pos[i][1][1];
			else if(bc > ac && bc > ab)
				pos[i][3][0] = pos[i][1][0] + pos[i][2][0] - pos[i][0][0],
				pos[i][3][1] = pos[i][1][1] + pos[i][2][1] - pos[i][0][1];
			for(int j = 0;j < 4;j++)
				for(int k = 0;k < 4;k++)
				{
					double dis_jk = dist(pos[i][j][0], pos[i][j][1], pos[i][k][0], pos[i][k][1]);
					f[i * 4 + j][i * 4 + k] = dis_jk * ti;
				}
		}
		for(int i = 0;i < s;i++)
			for(int j = 0;j < 4;j++)
				for(int i1 = i + 1;i1 <= s;i1++)
					for(int j1 = 0;j1 < 4;j1++)
						f[i * 4 + j][i1 * 4 + j1] = f[i1 * 4 + j1][i * 4 + j] = dist(pos[i][j][0], pos[i][j][1], pos[i1][j1][0], pos[i1][j1][1]) * t;
		for(int i = 0;i < s * 4;i++) f[i][i] = 0;
		for(int k = 0;k < s * 4;k++)
			for(int i = 0;i < s * 4;i++)
				for(int j = 0;j < s * 4;j++)
					f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
		double ans = 1e11;
		for(int i = 4 * (A - 1);i < 4 * A;i++)
			for(int j = 4 * (B - 1);j < 4 * B;j++)
				ans = min(f[i][j],ans);
		printf("%.1lf\n",ans);
	}
	return 0;
}