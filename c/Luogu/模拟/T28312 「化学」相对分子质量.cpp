#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
char a[100][100]={"H","C","N","O","F","Na","Mg","Al","Si","P","S","Cl","K","Ca","Mn","Fe","Cu","Zn","Ag","I","Ba","Hf","Pt","Au","Hg"};//打了两张表 
float b[100]={1,12,14,16,19,23,24,27,28,31,32,35.5,39,40,55,56,64,65,108,127,137,178.5,195,197,201};
char aa[110];
int lenx=0;
float calc(int &i,int d)	
{
	float ans=0;
	char tmp[100]={0};
	int temp=0;
	while(aa[i]!='\0')
	{
		if(aa[i]>='A'&&aa[i]<='Z'||aa[i]=='(')//处理新的元素 
		{
			for(int j=0;j<26;j++)
			{
				if(strcmp(tmp,a[j])==0) //查表 
				{
					if(temp==0) ans+=b[j];
					else ans+=temp*b[j];
					break;
				}
			}
			memset(tmp,0,sizeof(tmp));
			tmp[0]=aa[i]; //记录元素 
			temp=0;
		}
		if(aa[i]>='a'&&aa[i]<='z')//一个元素的后半段（一个元素最多2字节） 
		{
			tmp[1]=aa[i];
		}
		if(aa[i]>='0'&&aa[i]<='9')//处理数字 
		{
			temp=temp*10+(aa[i]-'0');
		}
		if(aa[i]=='(')//分子团 
		{
			ans+=calc(++i,1);
		}
		if(aa[i]==')'&&d==1)//分子团处理完
		{
			for(int j=0;j<26;j++)//处理最后的一个元素 
			{
				if(strcmp(tmp,a[j])==0) 
				{
					if(temp==0) ans+=b[j];
					else ans+=temp*b[j];
					break;
				}
			}
			if(aa[i+1]=='_')//分子团后还有系数 
			{
				temp=0;
				for( ;aa[i]!='}';i++)
				{
					if(aa[i]>='0'&&aa[i]<='9')//处理数字 
					{
						temp=temp*10+(aa[i]-'0');
					}
				}
				ans*=temp;
			}
			return ans;
		}
		if(aa[i]=='~')//水合物 
		{
			int j=i+1;
			int tmpp=0;
			while(1)//处理水合物的系数 
			{
				if(aa[j]=='H') break;
				tmpp=tmpp*10+aa[j]-'0';
				j++;
			}
			if(tmpp==0) ans+=18;//H2O分子量18 
			else        ans+=18*tmpp;
			lenx=j;
			i+=lenx+6;
		}	 
		i++;
	}
	for(int j=0;j<26;j++)//处理最后的一个元素 
	{
		if(strcmp(tmp,a[j])==0) 
		{
			if(temp==0) ans+=b[j];
			else ans+=temp*b[j];
			break;
		}
	}
	return ans;
}
int main()
{

	float ans=0;
	scanf("%s",aa);
	int i=0;
	ans=calc(i,0);
	if(ans-(int)ans>0)
	{
		if(ans-(int)ans>0.8) printf("%d",(int)ans+1);//处理int的问题（避免1.999999999） 
		else                 printf("%.1f",ans);//输出后带0.5的答案 
	}
	else                     printf("%d",(int)ans);//正好是整数 
	return 0;
}
