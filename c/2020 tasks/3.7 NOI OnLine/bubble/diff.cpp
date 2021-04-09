#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
bool exist[1000];
int main()
{
	int n,m;
	while(1)
	{
		freopen("bubble.in","w",stdout);
		srand((unsigned)time(NULL));
		n = rand() % 50 + 1;
		m = rand() % 50 + 1;
		printf("%d %d\n",n,m);
		memset(exist,0,sizeof(exist));
		for(int i = 0;i < n;)
		{
			int c = rand() % n + 1;
			if(!exist[c]) printf("%d ",c),i++;
			exist[c] = true;
		}
		puts("");
		for(int i = 0;i < m;i++)
		{
			int t = rand() % 2 + 1,c = rand() % n + 1;
			printf("%d %d\n",t,c);
		}
		fclose(stdout);
		system("bf.exe");system("bubble.exe");
		if(system("diff bubble.ans bubble.out")) system("pause");
		else printf("AC\n");
	}
}