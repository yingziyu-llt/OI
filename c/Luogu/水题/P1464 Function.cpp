#include<stdio.h>
long long map[21][21][21];
long long function(long long a,long long b,long long c)
{
	if(a<=0||b<=0||c<=0) return 1;
	else if(a>20||b>20||c>20) return function(20,20,20);
	else if(a<b&&b<c)
	{
		if(map[a][b][c-1]==0)
		 map[a][b][c-1] = function(a,b,c-1);
		if(map[a][b-1][c-1]==0)
		 map[a][b-1][c-1] = function(a,b-1,c-1);
		if(map[a][b-1][c]==0)
		 map[a][b-1][c] = function(a,b-1,c);
		if(map[a][b][c]==0)
	     map[a][b][c]= map[a][b][c-1] + map[a][b-1][c-1] - map[a][b-1][c];
		return map[a][b][c];
	}
	else //w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)
	{
		if(map[a-1][b][c]==0)
		 map[a-1][b][c] = function(a-1,b,c);
		if(map[a-1][b-1][c-1]==0)
		 map[a-1][b-1][c-1] = function(a-1,b-1,c-1);
		if(map[a-1][b-1][c]==0)
		 map[a-1][b-1][c] = function(a-1,b-1,c);
		if(map[a-1][b][c-1]==0)
		 map[a-1][b][c-1] = function(a-1,b,c-1);
		if(map[a][b][c]==0)
    	 map[a][b][c]= map[a-1][b][c]+map[a-1][b-1][c]+map[a-1][b][c-1]-map[a-1][b-1][c-1];
		return map[a][b][c];
	}
}
int main()
{
	long long a,b,c;
    while(1) 
	{   
	    scanf("%lld%lld%lld",&a,&b,&c);
	    if(a==-1&&b==-1&&c==-1) break;
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,function(a,b,c));
	}
		
}
