int work(a[][],b[][],c[][],&ans,t,m,n)//a �Ƿ�¥�ݣ�b ָʾ�ƣ�c ¥���¥������
									 //ans �𰸣�t ����ķ��䣬m�����䣬n��¥
{
	int i,s;
	for(i=0;i<n;i++)
	{
		ans=(ans+b[i][t])%20123;
		x=(b[i][t]-1)%c[i]+1;
		if(a[i][t]==1) s=1;else s=0;
		while(s<x)
		{
			if(t==m-1)  t=0;
			else        t++;
			if(a[i][t]==1)
				s++;
		}
	}
	return ;
}
