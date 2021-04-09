#include <stdio.h>
#include <algorithm>
using namespace std;
struct aa_0
{
	float chengji;
	int minci;
	int subject;
	int classnum, grade, n;
} pl[10000]; //People

int clnum, plnum;

struct a_0
{
	int sum;
	int clname;
	int mc;
} classn[100]; //class

int sortSmall_0(int a, int b) //С->��
{
	int i, j;
	for (i = a; i < b - a; i++)
	{
		for (j = i + 1; j < b - a; j++)
		{
			if (pl[i].chengji > pl[j].chengji)
			{
				swap(pl[i], pl[j]);
			}
		}
	}
}

int sortBig_0(int a, int b) //big->small
{
	int i, j;
	for (i = a; i < b - a; i++)
	{
		for (j = i + 1; j < b - a; j++)
		{
			if (pl[i].chengji < pl[j].chengji)
			{
				swap(pl[i], pl[j]);
			}
		}
	}
}
int input_0()
{
	freopen("inputfile.txt", "r", stdin);
	while (~scanf("%d%d%d%f", &pl[plnum].n, &pl[plnum].grade, &pl[plnum].classnum, &pl[plnum].chengji))
		plnum++;
	fclose(stdin);
	freopen("class.mem", "r", stdin);
	while (~scanf("%d%d", &classn[clnum].sum, &classn[clnum].clname))
		clnum++;
	fclose(stdin);
}

int bigToSmall_0()
{
}

int main()
{

	input_0();
	printf("%d %d", pl[0].classnum, classn[0].clname);
}