#include<stdlib.h>
#include<stdio.h>
int main()
{
	while(1)
	{
		system("gen > date.in");
		system("bf  > bf.out < date.in");
		system("sol > sol.out < date.in");
		if(system("fc bf.out sol.out"))
		{
			printf("WA\n");
			system("pause");
		}
		else
		{
			printf("AC\n");
		}
	}
}