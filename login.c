#include "header.h"

void login() {
    char string1[20], string2[20];
    FILE *file;

    // Ask the user to input string1 and string2
    printf("Enter username or email: ");
    scanf("%s", string1);
    printf("Enter password: ");
    scanf("%s", string2);

    // Open the file in read mode
    file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return;
    }

    char line[20];
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
    			login();
    		else if (logornot==2)
    			main();
    		else
    			printf("Incorrect choice");
    	}
    while (logornot!=1 && logornot!=2);
    }
}


