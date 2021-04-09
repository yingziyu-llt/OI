#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std; 
int num[1000],nn,need,tn[1000];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	//freopen("librarian.in","r",stdin);
	//freopen("librarian.out","w",stdout);
	int n,q,tmp_ans;
	int j=0,tmp=0,tmp1=1,b=0,i=0;
	scanf("%d %d",&n,&q);//n是书的数量，p是读者数量
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);//num是图书编码
	sort(num,num+n,cmp);
	for(i=0;i<q;i++)
	{
		int ans=-1;
		scanf("%d %d",&nn,&need);//nn是需求码的位数 need是需求码
		tmp=(int)pow(10,nn);
		for(int i=0;i<n;i++)
			if(num[i]%tmp==need)
				ans=num[i];
		printf("%d\n",ans);
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
