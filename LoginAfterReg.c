#include "header.h"
#define MAX_LENGTH 50

void loginAfterReg(char *string1, char *string2) {
    FILE *file;

    // Open the file in read mode
    file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }

    char line[MAX_LENGTH];
   short int su=0;
    // Iterate through each line in the file
    while (fgets(line, sizeof(line), file)) {
        // Check if string1 exists in the current line
        if (strstr(line, string1) != NULL) {
            // Read the next line
            if (fgets(line, sizeof(line), file)) {
                // Check if string2 exists in the next line
                if (strstr(line, string2) != NULL) {
                    printf("Successful\n");
                    su++;
                    MainMenu(string1);
                    break;
                }
                // Check the line after the next line
                if (fgets(line, sizeof(line), file)) {
                    if (strstr(line, string2) != NULL) {
                        printf("Successful\n");
                        su++;
                        MainMenu(string1);
                        break;
                    }
                }
            }
        }
    }
    
    
    fclose(file);
    short int logornot;
    if (su==0)
    {
    	do{
    		printf("\nEnter 1 to try again, 2 to go back\n");
    		scanf("%hd",&logornot);
    		if(logornot==1)
    			loginAfterReg(string1, string2);
    		else if (logornot==2)
    			main();
    		else
    			printf("Incorrect choice");
    	}
    while (logornot!=1 && logornot!=2);
    }
}


