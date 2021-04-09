#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std; 
char dic[30][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};//��Ӧ
int di[30]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
int a[1000];
int main()
{
	long long ans = 0;
	int x = 0;
	for(int _i = 0;_i <= 6;_i++)
	{
		char tmp[100];
		scanf("%s",tmp);
		for(int i = 0;i < strlen(tmp);i++)
			if(tmp[i] >= 'A' && tmp[i] <= 'Z')
				tmp[i] = tmp[i] + 'a' - 'A';
		if(tmp[strlen(tmp)-1] == '.') tmp[strlen(tmp)-1] = '\0';
		for(int i = 0;i <= 26;i++)
			if(strcmp(dic[i],tmp) == 0)
			{
				a[x++] = di[i] % 100;
				break;
			}
	}
	sort(a,a + x);
	for(int i = 0;i < x;i++)
		ans = ans * 100 + a[i];
	printf("%lld",ans);
	return 0;
}
