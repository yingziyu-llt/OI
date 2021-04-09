#include<stdio.h>
#include<string.h>
char z[7][3]={"Cu","Fe","O","H","S","P","\0"};
int x[7]={64,56,16,1,32,31,0};
int main()
{
	char a[1000]={0};
	int ans=0;
	scanf("%s",a);
	int len=strlen(a),c=0;
	char tmp[3]={0};
	int tmpans=1;
	for(int i=0;i<len+1;i++)
	{
		
		if(a[i]=='_');
		else if(a[i]=='(')
		{
			i++;
			tmpans=0;
			for(;;i++)
			{
				if(a[i]==')')
				{
					break;
				}
				tmpans=tmpans*10+a[i]-'0';
			}
		}
		else if(a[i]>='a'&&a[i]<='z')
		{
			tmp[c]=a[i];
			c++;
		}
		else if(a[i]>='A'&&a[i]<='Z'||a[i]=='\0')
		{
			for(int j=0;j<7;j++)
			{
				if(strcmp(tmp,z[j])==0)
				{
					ans+=x[j]*tmpans;
					c=0;
					tmpans=1;
					break;
				}
			}
			memset(tmp,0,sizeof(tmp));
			tmp[c]=a[i];
			c++;
		}
	}
	printf("%d",ans);
	return 0;
}

