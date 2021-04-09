#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int a[3000],b[3000],ans[7000];

int main()
{
	char aa[2010],bb[2010];
	memset(aa,0,sizeof(aa));
	memset(bb,0,sizeof(bb));
	scanf("%s",aa);
	scanf("%s",bb);
	int lena = strlen(aa),lenb = strlen(bb);
	int flag = 1;
	if(aa[0] == '-') flag *= -1,lena--;
	if(bb[0] == '-') flag *= -1,lenb--;
	int x = 0;
	if(aa[0] == '0' || bb[0] == '0')
	{
		printf("0");
		return 0;
	}
	for(int i = 0;i < lena;i++)
		if(aa[i] >= '0' && aa[i] <= '9')
			a[lena - x++ - 1] = aa[i] - '0';
	lena = x;
	x = 0;
	for(int i = 0;i < lenb;i++)
		if(bb[i] >= '0' && bb[i] <= '9')
			b[lenb - x++ - 1] = bb[i] - '0';
	lenb = x;
	if(aa[0] == '-') lena++;
	if(bb[0] == '-') lenb++;
	x = 0;
	int tmp = 0;
	for(int i  = 0;i < lena;i++)
	{
		tmp = 0;
		for(int j = 0;j < lenb;j++)
		{
			ans[i + j] = ans[i + j] + a[i] * b[j] + tmp;
			tmp = ans[i + j] / 10;
			ans[i + j] %= 10;
		}
		ans[i + lenb] += tmp;
	}
	int i = lena + lenb;
	while(ans[i] == 0) i--;
	if(flag == -1)
		printf("-");
	for(;i >= 0;i--)
		printf("%d",ans[i]);
	return 0;
}
