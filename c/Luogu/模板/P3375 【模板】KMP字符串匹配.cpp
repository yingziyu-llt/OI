#include<stdio.h>
#include<string.h>
char a[1000010],b[1000010];
int kmp[1000010];
int main()
{
	scanf("%s",a + 1);
	scanf("%s",b + 1);
	int lenb = strlen(b + 1);int lena = strlen(a + 1);
	int k = 0;
	for(int i = 2;i <= lenb;i++)
	{
		while(k > 0 && b[i] != b[k + 1]) k = kmp[k];//k = kmp[k];???
		if(b[i] == b[k + 1]) k++;
		kmp[i] = k; 
	}
	k = 0;
	for(int i = 1;i <= lena;i++ )
	{
		while(k > 0 && a[i] != b[k + 1]) k = kmp[k];
		if(a[i] == b[k + 1]) k++;
		if(k == lenb) printf("%d\n",i - k + 1);
	}
	for(int i = 1;i <= lenb;i++)
		printf("%d ",kmp[i]);
	return 0;
}