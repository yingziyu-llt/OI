#include<stdio.h>
#include<string.h>
int K,m,n;
struct MAT
{
	int mat[23][23];
	MAT()
	{
		memset(mat,0,sizeof(mat));
	}
	MAT operator *(const MAT a) const
	{
		MAT res;
		for(int i = 0;i < 23;i++)
		{
			for(int j = 0;j < 23;j++)
			{
				for(int k = 0;k < 23;k++)
				{
					res.mat[i][j] = (this->mat[i][k] * a.mat[k][j] % K + res.mat[i][j]) % K;
				}
			}
		}
		return res;
	}
}B,F;
int a[23];
int nxt[23];
void KMP()
{
	nxt[1] = nxt[0] = 0;
	int j = 0;
	for(int i = 1;i < m;i++)
	{
		while(j && a[j] != a[i]) j = nxt[j];
		if(a[i] == a[j]) j++;
		nxt[i + 1] = j;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int k = i;
			while (k && a[k] != j)
				k = nxt[k];
			k += (a[k] == j);
			if (k < n)
				B.mat[i][k] += 1;
		}
	}
}

void ksm(MAT &A,MAT &B,int t)
{
	while(t)
	{
		if(t & 1) A = A * B;
		B = B * B;
		t >>= 1; 
	}
}

int main()
{
	char s[10010];
	scanf("%d%d%d",&n,&m,&K);
	scanf("%s",s);
	for(int i = 0;i < m;i++)
		a[i] = s[i] - '0';
	KMP();
	F.mat[0][0] = 1;
	ksm(F,B,n);
	int ans = 0;
	for(int i = 0;i < m;i++) ans = (ans + F.mat[0][i]) % K;
	printf("%d",ans);
	return 0;
}