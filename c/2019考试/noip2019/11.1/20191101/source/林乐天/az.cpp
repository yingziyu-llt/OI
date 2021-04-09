/*#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
string s;
map <string,bool> m;
int main()
{
	int n,ans = 0;
	freopen("az.in","r",stdin);
	freopen("az.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%s",&s);
		sort(&s,&s + s.length);
		m[s] = true;
	}
	printf("%d",ans);
	return 0;
}*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int Mod = 19999999,MOD = 20000003;
char s[200];
bool available1[Mod + 10],available2[MOD + 10];
int main()
{
	int n,ans = 0;
	freopen("az.in","r",stdin);
	freopen("az.out","w",stdout);
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%s",s);
		int hnum = 0,hnum2 = 0;
		for(int j = 0;j < strlen(s);j++)
		{
			hnum += s[j];
			hnum2 += s[j];
			hnum %= Mod;
			hnum2 %= MOD;
		}
		if(!available1[hnum] && !available2[hnum2])
		{
			available1[hnum] = true;
			available2[hnum2] = true;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}