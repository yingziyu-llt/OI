#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
int groupScore[20],personalScoreForGroup[BigPrime + 10];  //groupScore:each group's score
												  //personalScore:each person's score
int personalScore[BigPrime + 10];
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
	printf("Input your list into 'list.txt'.\n\n\nInput it like llt (score) (1 means to group,2 means to preson) (then put a enter)\n\n\n");
	//remind users to input the list into right place and in right way
	system("pause");
}
void work()//the main of the program
// to work out the list
{
	freopen("list.txt","r",stdin);//open the list and try to read it
	int cnt = 0,scoreTodo,kind;//which order work on and how mang score will be added
							   //kind 1 means add to the grope
							   //kind 2 means add to person
	while(~ scanf("%s %d %d",name,&scoreTodo,&kind))
	{
		//printf("work on %d line\n",++cnt);
		int hashNumber = hash(name);
		if(kind == 1)
		{
			personalScoreForGroup[hashNumber] += scoreTodo;//personal score change
			groupScore[nameToGroup[hashNumber]] += scoreTodo;//group score change
		}
		else
		{
			personalScore[hashNumber] += scoreTodo;
		}
		//system("cls");
	}
	fclose(stdin);
	printf("Now,we will write the result in 'result.txt',wait for a minute.");
	freopen("result.txt","w",stdout);//prepare to write the result
	printf("Group scores :\n");
	for(int i = 1;i <= GroupNumber;i++)
	{
		printf("%c : %d Point(s) \n",'A' + i - 1,groupScore[i]);//write the group name and score
		for(int j = 1;j <= groupToName[i][0];j++)
		{
			printf("%s : %d Point(s)\n",namelist[groupToName[i][j]],personalScoreForGroup[groupToName[i][j]]);
				//print each person's score
		}
		printf("\n");
	}
	for(int i = 1;i <= GroupNumber;i++)
	{
		for(int j = 1;j <= groupToName[i][0];j++)
		{
			personalScore[groupToName[i][j]] += groupScore[i];//calcuate each person's score
															  //score = selfScore + groupScore
			//printf("%s : %d Point(s)\n",namelist[groupToName[i][j]],personalScore[groupToName[i][j]]);
			printf("%d\n",personalScore[groupToName[i][j]]);
		}
	}
	fclose(stdout);
}
int main()
{
	prepare();
	work();
	return 0;
}