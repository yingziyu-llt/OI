#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
char a[100][100]={"H","C","N","O","F","Na","Mg","Al","Si","P","S","Cl","K","Ca","Mn","Fe","Cu","Zn","Ag","I","Ba","Hf","Pt","Au","Hg"};//�������ű� 
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
		if(aa[i]>='A'&&aa[i]<='Z'||aa[i]=='(')//�����µ�Ԫ�� 
		{
			for(int j=0;j<26;j++)
			{
				if(strcmp(tmp,a[j])==0) //��� 
				{
					if(temp==0) ans+=b[j];
					else ans+=temp*b[j];
					break;
				}
			}
			memset(tmp,0,sizeof(tmp));
			tmp[0]=aa[i]; //��¼Ԫ�� 
			temp=0;
		}
		if(aa[i]>='a'&&aa[i]<='z')//һ��Ԫ�صĺ��Σ�һ��Ԫ�����2�ֽڣ� 
		{
			tmp[1]=aa[i];
		}
		if(aa[i]>='0'&&aa[i]<='9')//�������� 
		{
			temp=temp*10+(aa[i]-'0');
		}
		if(aa[i]=='(')//������ 
		{
			ans+=calc(++i,1);
		}
		if(aa[i]==')'&&d==1)//�����Ŵ�����
		{
			for(int j=0;j<26;j++)//��������һ��Ԫ�� 
			{
				if(strcmp(tmp,a[j])==0) 
				{
					if(temp==0) ans+=b[j];
					else ans+=temp*b[j];
					break;
				}
			}
			if(aa[i+1]=='_')//�����ź���ϵ�� 
			{
				temp=0;
				for( ;aa[i]!='}';i++)
				{
					if(aa[i]>='0'&&aa[i]<='9')//�������� 
					{
						temp=temp*10+(aa[i]-'0');
					}
				}
				ans*=temp;
			}
			return ans;
		}
		if(aa[i]=='~')//ˮ���� 
		{
			int j=i+1;
			int tmpp=0;
			while(1)//����ˮ�����ϵ�� 
			{
				if(aa[j]=='H') break;
				tmpp=tmpp*10+aa[j]-'0';
				j++;
			}
			if(tmpp==0) ans+=18;//H2O������18 
			else        ans+=18*tmpp;
			lenx=j;
			i+=lenx+6;
		}	 
		i++;
	}
	for(int j=0;j<26;j++)//��������һ��Ԫ�� 
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
		if(ans-(int)ans>0.8) printf("%d",(int)ans+1);//����int�����⣨����1.999999999�� 
		else                 printf("%.1f",ans);//������0.5�Ĵ� 
	}
	else                     printf("%d",(int)ans);//���������� 
	return 0;
}
