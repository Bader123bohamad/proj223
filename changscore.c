#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_LINE_LEN 256

void changscore( char name[], int score, int secondScore) {
    FILE *file = fopen("score.txt", "r+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LEN];
    long pos;
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, name)) {
            found = 1;
            // Remember the position of the line
            pos = ftell(file) - strlen(line);
            // Move the file pointer to the beginning of the line
            fseek(file, pos, SEEK_SET);
            // Write the updated data
            fprintf(file, "%s\n%d\n%d\n", name, score, secondScore);
            break; // No need to continue searching
        }
    }

    if (!found) {
        // Append new entry at the end of the file
        fseek(file, 0, SEEK_END);
        fprintf(file, "%s\n%d\n%d\n", name, score, secondScore);
    }

    fclose(file);
}



