#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
struct monomial
{
	int a[27][100];
	void operator = (const monomial n)
	{
		for(int i = 0;i < 27;i++)
			for(int j = 0;j < 100;j++)
				a[i][j] = n.a[i][j];
	}
	void operator = (const int n) 
	{
		for(int i = 0;i < 27;i++)
			for(int j = 0;j < 100;j++)
				a[i][j] = 0;
		a[0][0] = n;
	}
	void operator += (const int n)
	{
		a[0][0] += n;
	}
	monomial operator + (const int n)
	{
		monomial aa = 0;
		
	}
}