#include "header.h"
void JoinGame(char user[20])
{
	printf("\n");
	printMainList(mainList);
	short int c, score=0;
	printf("Enter ID Game: ");
	scanf("%hd",&c);
	short int x=isDuplicate(mainList, c);
	do
	{
		if (x==0)
		{
			printf("ID not found!!\nEnter another ID/ '0' to go back:  ");
			scanf("%hd",&c);
			if (c==0)
				MainMenu(user);
			x =isDuplicate(mainList, c);
		}
		else
			break;
	}while (x==0);
	timepp(15,mainList, c, user) ;
	//printQ(mainList, c, user);
	printf("\n\n");
	scorefun(user);
		printf("\n\n");
	MainMenu(user);
	
	
}
