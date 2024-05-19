#include "header.h"
void scorefun(char user[20]) {
    FILE* file = fopen("score.txt", "r");
    if (file == NULL) {
        printf("Error opening file score.txt.\n");
        return;
    }
    char buffer[100];
    int found = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strncmp(buffer, user, strlen(user)) == 0) {
            fgets(buffer, sizeof(buffer), file);
            printf("\nTotal Point is: %s", buffer); 
	    fgets(buffer, sizeof(buffer), file);
            printf("Maximum Point is: %s\n", buffer); 
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("String not found in the file.\n");
    }

    fclose(file);
}
