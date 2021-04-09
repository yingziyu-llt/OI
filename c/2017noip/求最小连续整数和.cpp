#include<stdio.h>
int main()
{
	int w,i;
	int n[100],mMix,nMix,mix,m[100],num,lnum;
	float temp;
	scanf("%d",&w);
	mix=nMix=mMix=2147000000;
	num=lnum=0;
	for(i=1;i<=(w/2+1);i++)
	{
		temp=((float)w)/i-0.5*i-0.5;
		if(temp==(int)temp)
		{
			num++;
			n[num]=i;
			m[num]=temp;
			if(temp<mMix)
			mMix=temp;
			if(n[num]<nMix)
			nMix=n[num];
			if(m[num]+n[num]<mix)
			{
				mix=m[num]+n[num];
				lnum=num;
			}
		}
	}
	printf("%d %d %d\n  %d %d",m[lnum],n[lnum],mix,mMix,nMix);
} 
