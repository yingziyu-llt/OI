#include<stdio.h>
#include<algorithm>
using namespace std;
const int Mod = 1e9+7;
struct Mat
{
	long long a[200][200],c,l;
	void clean()
	{
		for(int i = 0;i <= c;i++)
			for(int j = 0;j <= l;j++)
				a[i][j] = 0;
		for(int i = 1;i <= c;i++)
			a[i][i] = 1;
	}
	Mat operator * (const Mat& A1) const
	{
		Mat ans;
		ans.c = c;
		ans.l = A1.l;
		for(int i = 0;i <= ans.c;i++)
			for(int j = 0;j <= ans.l;j++)
				ans.a[i][j] = 0;
		
		for(int i = 1;i <= c;i++)
		{
			for(int j = 1;j <= A1.l;j++)
			{
				for(int k = 1;k <= l;k++)
				{
					ans.a[i][j] = (a[i][k] * A1.a[k][j] % Mod + ans.a[i][j]) % Mod; 
				}
			}
		}
		return ans;
	}
};
Mat A,ans;
void ksm(int k)
{
	while(k)
	{
		if(k & 1)
			ans = ans * A;
		A = A * A;
		k >>= 1;
	}
}
int main()
{
	int n,k;
	
	scanf("%d%d",&n,&k);
	A.l = A.c = n;ans.l = ans.c = n;
	A.clean();ans.clean();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			scanf("%d",&A.a[i][j]);
	ksm(k);
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
			printf("%d ",ans.a[i][j]);
		printf("\n");
	}
	return 0;
}