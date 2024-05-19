#include "header.h"
void MainMenu(char user[20])
{
	short int op;
	do
	{
		printf("\nWelcome %s :)\n\n",user);
		printf("\n**Enter a number from 1 to 3**\n\n");
		printf("Choose an option\n");
		printf("1-Join Game:\n");
		printf("2-Create Game:\n");
		printf("3-Log Out:\n");
		printf("4-Your Score:\n");
		printf("Enter your choice: ");
		scanf("%hd", &op);
	}
	while (op>6 || op<1);
	
	switch (op)
	{
		case 1:
			JoinGame(user);
			break;
		case 2:
			CreateGame(user);
			break;
		case 3:
			main();
			break;
		case 4:
			scorefun(user);
			break;
	
	}


}
