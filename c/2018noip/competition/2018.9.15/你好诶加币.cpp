#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
/*int a[100], b[100], res[100];
void add(int lena,int lenb)
{
    int tmp = 0;
    int max = max(lena,lenb);
    for (int i = 0; i < max; i++)
    {
        res[i] = a[i] + b[i] + tmp;
        tmp = res[i] / 10;
        res[i] %= 10;
    }
}
void subt(int lena,int lenb)
{
	
}
*/
int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	double ans;
	ans = (double)a + (double)b;
	if(ans >= -9223372036854775808.0 && ans <= 9223372036854775807.0)
		printf("%.0lf",ans);
	else
		printf("\"hello, \%lld\\n\"");
	return 0;
}
