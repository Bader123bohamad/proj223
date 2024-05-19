#include "header.h"
User* users = NULL;
int userCount = 0;

int isUserExists(const char* username, const char* email) {
    FILE* file = fopen("users.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char tempUsername[50];
    char tempEmail[50], tempPassword[50];

    // Read usernames and compare
    while (fscanf(file, "%49s", tempUsername) == 1) {
        // Skip email and password
        fscanf(file, "%49s %49s", tempEmail, tempPassword);

        if (username != NULL && strcmp(tempUsername, username) == 0) {
            fclose(file);
            return 1; // Username found
        }
        // If email is provided, check email
        if (email != NULL && strcmp(tempEmail, email) == 0) {
            fclose(file);
            return 1; // Email found
        }
    }

    fclose(file);
    return 0; // Not found
}

int isValidEmail(const char* email) {
    int i = 0;
    int atFound = 0;
    int dotFound = 0;

    // Iterate through each character in the email
    while (email[i] != '\0') {
        if (email[i] == '@') {
            atFound = 1;
        } else if (email[i] == '.' && atFound) {
            dotFound = 1;
        }
        i++;
    }

    // Check if '@' and '.' are found and dot is not the last character
    return (atFound && dotFound && email[i - 1] != '.');
}

void SignUp() {
    User newUser;
    int usernameExists;
    int emailExists;

    printf("Enter '#' at any time back\n");

    do {
        // Get user input for username
        do {
            printf("Enter your username (at least 3 characters): ");
            char tempInput[50];
            scanf("%s", tempInput);

            // Check if the user wants to cancel sign-up
            if (tempInput[0] == '#') {
                main(); // Return to the calling function (most likely main)
            }

            newUser.username = strdup(tempInput);

            // Check if the username is too short
            if (strlen(newUser.username) < 3) {
                printf("Username must be at least 3 characters long. Please try again.\n");
            }
        } while (strlen(newUser.username) < 3); // Loop until a valid username is entered

        // Check if the username is already in use
        usernameExists = isUserExists(newUser.username, NULL);
        if (usernameExists) {
            printf("Username already in use. Please choose a different one.\n");
            free(newUser.username);
        }
    } while (usernameExists); // Loop until a unique username is entered

    // Get user input for email
    do {
        printf("Enter your email: ");
        char tempInput[50];
        scanf("%s", tempInput);

        // Check if the user wants to cancel sign-up
        if (tempInput[0] == '#') {
            printf("Sign-up process canceled. Returning to the main menu.\n");
            return; // Return to the calling function (most likely signUpPage)
        }

        newUser.email = strdup(tempInput);

        // Check if the email is valid
        if (!isValidEmail(newUser.email)) {
            printf("Invalid email. Please enter a valid email address with characters before '@' and at least one character before and after '.' after '@'.\n");
            free(newUser.email);
        }
    } while (!isValidEmail(newUser.email));

    // Get user input for password
    do {
        printf("Enter your password (at least 8 characters): ");
        char tempInput[50];
        scanf("%s", tempInput);

        // Check if the user wants to cancel sign-up
        if (tempInput[0] == '#') {
            printf("Sign-up process canceled. Returning to the main menu.\n");
            return; // Return to the calling function (most likely signUpPage)
        }

        newUser.password = strdup(tempInput);

        // Check if the password is at least 8 characters long
        if (strlen(newUser.password) < 8) {
            printf("Password must be at least 8 characters long. Please try again.\n");
            free(newUser.password);
        }
    } while (strlen(newUser.password) < 8); // Loop until a valid password is entered

    // Open the file for appending
    FILE* file = fopen("users.txt", "a");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write user information to the file
    fprintf(file, "%s\n%s\n%s\n\n", newUser.username, newUser.email, newUser.password);

    // Close the file
    fclose(file);

    printf("Sign-up successful!\n");

    // Open "score.txt" file to initialize user's score
    FILE* scoreFile = fopen("score.txt", "a");

    if (scoreFile == NULL) {
        perror("Error opening score file");
        exit(EXIT_FAILURE);
    }

    // Write user's name and initial score (0) to the file
    fprintf(scoreFile, "%s \n0\n", newUser.username);
    fprintf(scoreFile, "0\n" );

    // Close the score file
    fclose(scoreFile);

    printf("Your score initialized to 0.\n\n\n");

    // Allocate memory for a new user
    User* newUsers = (User*)malloc((userCount + 1) * sizeof(User));

    if (newUsers == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Copy existing users to new array
    for (int i = 0; i < userCount; i++) {
        newUsers[i] = users[i];
    }

    // Free memory for the old users array
    free(users);

    // Add the new user to the new array
    newUsers[userCount] = newUser;

    // Update users and increment user count
    users = newUsers;
    userCount++;
    login();
}
