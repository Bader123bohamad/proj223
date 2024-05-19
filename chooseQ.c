#include "header.h"
void CreateGame()
{
	short int cataga;
	printf("Choose a Category:\n";
	printf("1-Computer Science\n";
	printf("2-Sciences\n";
	printf("3-GEO\n";
	printf("4-SPORT\n";
	printf("5-GO BACK\n";
	printf("Enter your choice: ");
	do
	{
		scanf("%hd", &cataga);
		if (cataga>5 || cataga <1)
		{
k			printf("\n**Enter a number from 1 to 4**\n\n");
			printf("Choose a Category:\n";
			printf("1-Computer Science:\n";
			printf("2-Sciences:\n";
			printf("3-GEO:\n";
			printf("4-Sports :\n";
			printf("5-Go Back :\n";
			printf("Enter your choice: ");
		}
	}
	while (cataga>5 || cataga <1);
	if (cataga==5)
		MainMenu();
	WorkingCreateGame(cataga);

}

void RandomQuestion(short int *a, short int *b, short int *c, short int *d, short int *e) 
{
	srand(time(NULL));
    
    	//  random numbers between 1 and the value of each input integer
    	*a = (rand() % *a) + 1;
	do
        	*b = (rand() % *b) + 1;
    	while (*b == *a);
    	// to make sure the second question will be not the same question in the first question (in the easy random question)
    	
    	*c = (rand() % *c) + 1;// for Hard question
    	
        *d = (rand() % *d) + 1;
        do
    		*e = (rand() % *e) + 1;
    	while (*e == *d);
    	// to make sure the second question will be not the same question in the first question (in the medium random question)
    	
    	
    	//changed them by refrance
}
void WorkingCreateGame(int cataga) {
	short int QE = 0, QM = 0, QH = 0;
   	short int QE2,QM2;
    	FILE *file;
    
    	if (cataga == 1) {
        	file = fopen("easyQcs.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                			QE++;
            		}
            		fclose(file);
        	} 
        	else 
            		printf("File 'easyQcs.txt' not found.\n");
            		
        	file = fopen("mediumQcs.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                			QM++;
            		}
            		fclose(file);
        	} 
        	else
            		printf("File 'mediumQcs.txt' not found.\n");
        
        	file = fopen("hardQcs.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                		QH++;
            		}
            		fclose(file);
        	} 
        	else 
            		printf("File 'hardQcs.txt' not found.\n");
        
	}
	//For opining and count the questions in CS files 
	
    	else if (cataga == 2) 
    	{
        	file = fopen("easyQsci.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                		QE++;
            		}
            		fclose(file);
        	} 
        	else 
            		printf("File 'easyQsci.txt' not found.\n");
        
        	file = fopen("mediumQsci.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                		QM++;
            		}
            		fclose(file);
        	} 
        	else
            		printf("File 'mediumQsci.txt' not found.\n");
        
        	file = fopen("hardQsci.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                		QH++;
            		}
            		fclose(file);
		} 
		else 
            		printf("File 'hardQsci.txt' not found.\n");
            		
    	} 
    	//For opining and count the questions in CSI files 
    	
    	else if (cataga == 3) 
    	{
        	file = fopen("easyQgeo.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                		QE++;
            		}
            		fclose(file);
		} 
       		else 
            		printf("File 'easyQgeo.txt' not found.\n");
            		
        	file = fopen("mediumQgeo.txt", "r");
		if (file != NULL) 
		{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                		QM++;
            		}
            		fclose(file);
		} 
		else 
            		printf("File 'mediumQgeo.txt' not found.\n");
        
        	file = fopen("hardQgeo.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                		QH++;
            		}
            		fclose(file);
        	} 
        	else 
            		printf("File 'hardQgeo.txt' not found.\n");
            		
    	}
    	//For opining and count the questions in GEO files 
    	 
    	else if (cataga == 4) 
	{
        	file = fopen("easyQsport.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                		QE++;
			}
            		fclose(file);
        	} 
        	else 
            		printf("File 'easyQsport.txt' not found.\n");
        
        	file = fopen("mediumQsport.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF)
            	o	{
                		if (c == '\n') 
                		QM++;
            		}
            		fclose(file);
        	} 
        	else 
            		printf("File 'mediumQsport.txt' not found.\n");
        
        	file = fopen("hardQsport.txt", "r");
        	if (file != NULL) 
        	{
            		char c;
            		while ((c = fgetc(file)) != EOF) 
            		{
                		if (c == '\n') 
                		QH++;
            		}
            		fclose(file);
       		 }
       		 else
            		printf("File 'hardQsport.txt' not found.\n");
	} 
	//For opining and count the questions in SPORT files 
	    	
	QE=QE/7;
	QM=QM/7;
	QH=QH/7;
	//QE,QM,QH count the lines number, Divide by 7 to know the number of questions instead of lines number
	
	QE2=QE;
	QM2=QM;
	//to take another random aquestion for easy and medium questions
	
	RandomQuestion(&QE,&QE2,&QH,&QM,&QM2);

}
