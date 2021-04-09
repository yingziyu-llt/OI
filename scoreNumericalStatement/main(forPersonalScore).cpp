#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define BigPrime 12121 //for Hash
#define GroupNumber 14
int hash(char input[])//String Hash (mod BigPrime)
{
	int len = strlen(input);
	long long res = 0;//result of Hash
	for(int i = 0;i < len;i++)
	{
		res = (res * 256 + (long long)input[i]) % BigPrime;//Hash
	}
	return res;
}
int groupScore[20],personalScore[BigPrime + 10];  //groupScore:each group's score
												  //personalScore:each person's score
int nameToGroup[BigPrime + 10],groupToName[20][5];//map from name to group number 
												  //and map from group to name([0] is counter)
char name[100],namelist[BigPrime + 10][100];	  //name(for temp) and map from Hash number to person name
void prepare()//some works to prepare
{
	freopen("namelist.sns","r",stdin);//open the name list to input the name list
	int groupNumber;
	while(~ scanf("%s %d",name,&groupNumber))//input the namelist and Hash it
	{
		int hashNumber = hash(name);
		nameToGroup[hashNumber] = groupNumber;
		groupToName[groupNumber][++groupToName[groupNumber][0]] = hashNumber;
		strcpy(namelist[hashNumber],name);
	}
	fclose(stdin);
	printf("Input your list into 'list2.txt'.\n\n\nInput it like llt (and then put a Enter)\n\n\n");
	//remind users to input the list into right place and in right way
	system("pause");
	Sleep(1000);
	return;
}
void work()//the main of the program
// to work out the list
{
	freopen("list2.txt","r",stdin);//open the list and try to read it
	int cnt = 0,scoreToDo;//which order work on and how mang score will be added
	while(~ scanf("%s %d",name,&scoreToDo))
	{
		printf("work on %d line\n",++cnt);
		int hashNumber = hash(name);
		personalScore[hashNumber] += scoreToDo;//personal score change
	}
	fclose(stdin);
	printf("Now,we will write the result in 'result2.txt',wait for a minute.");
	freopen("result.txt","w",stdout);//prepare to write the result
	for(int i = 1;i <= GroupNumber;i++)
	{
		for(int j = 1;j <= groupToName[i][0];j++)
		{
			printf("%s : %d Point(s)\n",namelist[groupToName[i][j]],personalScore[groupToName[i][j]]);
		}
		printf("\n");
	}
	fclose(stdout);
}
int main()
{
	prepare();
	work();
	return 0;
}