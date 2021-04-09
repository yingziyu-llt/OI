#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("contra.in","r",stdin);
	freopen("contra.out","w",stdout);
	int n,l;//n最小时间m HP k 比率 l boss数量 
	double m,k,a,x,y,t;
	scanf("%d%lf%lf%d",&n,&m,&k,&l);
	t = 0;
	for(int i = 1 ; i <= l ; i++)
	{
		bool flag = false;
		scanf("%lf%lf",&x,&y);//X boss HP Y boss攻击力
		do
		{
			if(flag == true) x = x + 10;
			a = m * k / 100.0;
			t = t + ceil(x/a);
			m = m - (ceil(x/a)-1) * y;
			if(m <= 0) {printf("%d",i);return 0;}
			flag = true;
		}while(ceil(x/a) < n);	
	}
	int aa,bb;
	aa = t;
	bb = m;
	printf("%d %d",aa,bb);
}
		
	
