int work(a[][],b[][],c[][],&ans,t,m,n)//a 是否楼梯，b 指示牌，c 楼层的楼梯数量
									 //ans 答案，t 进入的房间，m个房间，n层楼
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
