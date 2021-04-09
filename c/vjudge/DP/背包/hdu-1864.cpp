#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
double p[1001];
double f[30];
int main()
{
	int n;
	double Q;
	while(~scanf("%lf%d",&Q,&n))
	{
		if(n == 0) break;
		int cnt = 1;
		for(int i = 1;i <= n;i++)
		{
			int x;
			bool flag = true;
			scanf("%d",&x);
			double a = 0,b = 0,c = 0;
			for(int j = 0;j < x;j++)
			{
				char ch;
				getchar();
				ch = getchar();
				getchar();
				double k;
				scanf("%lf",&k);
				if(ch == 'A')
					a += k;
				else if(ch == 'B')
					b += k;
				else if(ch == 'C')
					c += k;
				else flag = false;
				if(p[cnt] > 1000 || a > 600 || b > 600 || c > 600)
					flag = false;
				p[cnt] += k;
			}
			if(flag == false)
				p[cnt] = 0;
			else
				cnt++;
		}
		for(int i = 1;i <= cnt;i++)
			for(int j = i - 1;j >= 0;j--)
				if(f[j] + p[i] <= Q) f[i] = max(f[i],f[j] + p[i]);
		printf("%.2lf\n",f[cnt]);
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(p));
	}
	return 0;
}