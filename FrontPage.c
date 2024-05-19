#include "header.h"
// Function to create a new integer node
IntNode* createIntNode(int data) {
    IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new string node
StringNode* createStringNode(const char* data) {
    StringNode* newNode = (StringNode*)malloc(sizeof(StringNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to check if a number already exists in the main list
int isDuplicate(MainNode* head, int key) {
    MainNode* tempp = head;
    while (tempp != NULL) {
        if (tempp->data == key)
        { 
            return 1; // Duplicate found
         }
        tempp = tempp->next;
    }
    return 0; // No duplicate found
}

// Function to generate a random four-digit number
int generateRandomNumber() {
    return rand() % 9000 + 1000; // Range: 1000 to 9999
}

// Function to add an integer node at the end of the main list
void appendMain(MainNode** head, int data) {
    MainNode* newNode = (MainNode*)malloc(sizeof(MainNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->subList = NULL;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        MainNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to append a string node to the sublist of a main list node
void appendStringSubList(MainNode* mainNode, const char* data) {
    StringNode* newNode = createStringNode(data);
    if (mainNode->subList == NULL) {
        mainNode->subList = newNode;
    } else {
        StringNode* temp = mainNode->subList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the main list
/*void printMainList(MainNode* head) {
    printf("Main List:\n");
    MainNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        printf("[");
        StringNode* subTemp = temp->subList;
        while (subTemp != NULL) {
            printf("%s", subTemp->data);
            if (subTemp->next != NULL) {
                printf("\n");
            }
            subTemp = subTemp->next;
        }
        printf("]");
        temp = temp->next;
        printf("\n");
    }
    printf("NULL\n");
}*/
void printMainList(MainNode* head) {
    printf("Main List:\n");
    MainNode* temp = head;
    while (temp != NULL) {
        printf("Game ID: %d  ", temp->data);
        temp = temp->next;
        printf("\n");
    }
}

//Function to print a sublist
void printSubList(StringNode* subList) {
    printf("Sublist: ");
    StringNode* temp = subList;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a node with given value in the main list
MainNode* searchMainList(MainNode* head, int key) {
    MainNode* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
	  
    return NULL;
}

void printQ(MainNode* head, int key, char user[20]) {
    short int i = 0;
    short int choice, correctanswer, point = 0;
    MainNode* temp = head;

    while (temp != NULL) {
        // Check if the main node's data matches the key
        if (temp->data == key) {
            StringNode* subTemp = temp->subList;

            // Check if sublist exists
            if (subTemp == NULL) {
                printf("No sublist nodes found for main node with data: %d\n", key);
            } else {
                printf("Sublist nodes for main node with data %d:\n", key);

                // Traverse the sublist
                while (subTemp != NULL) {
                    i++;

                    if (i == 6 || i == 12) {
                        printf("\nEnter Your Answer: ");
                        scanf("%hd", &choice);
                        correctanswer = atoi(subTemp->data);
                        if (correctanswer == choice)
                            point = point + 10;
                        subTemp = subTemp->next;
                        continue;
                    }
                    if (i == 18 || i == 24) {
                        printf("\nEnter Your Answer: ");
                        scanf("%hd", &choice);
                        correctanswer = atoi(subTemp->data);
                        if (correctanswer == choice)
                            point = point + 20;
                        subTemp = subTemp->next;
                        continue;
                    }
                    if (i == 30) {
                        printf("\nEnter Your Answer: ");
                        scanf("%hd", &choice);
                        correctanswer = atoi(subTemp->data);
                        if (correctanswer == choice)
                            point = point + 40;
                        subTemp = subTemp->next;
                        continue;
                    }
                    printf("    %s\n", subTemp->data);
                    subTemp = subTemp->next;

                }
            }
            printf("\n\t\t\t\t\tGame has been ended :)\n\t\t\t\t\tTotal Point you got %d/100\n\n", point);
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
                    int x1 = atoi(buffer);
                    fgets(buffer, sizeof(buffer), file);
                    int x2 = atoi(buffer);
                    if (point > x2)
                        x2 = point;
                    x1 = x1 + point;
                    found = 1;
                    changscore(user, x1, x2);
                    break;
                }
            }

            if (!found) {
                printf("String not found in the file.\n");
            }

            fclose(file);
            return;
        }
        temp = temp->next;
    }
    printf("Main node with data %d not found.\n", key);
}

void timepp(int second, MainNode* head, int key, char user[20]) {
    pid_t pid = fork(); // Create a child process
    if (pid == 0) { // Child process
        printQ(head, key, user); // Call the function to ask questions
        exit(0); // Exit the child process with the number of questions answered
    } else if (pid > 0) { // Parent process
        int status;
        pid_t result = waitpid(pid, &status, WNOHANG); // Non-blocking wait for the child process

        if (result == 0) { // Child process is still running
            sleep(second); // Wait for specified seconds
            kill(pid, SIGKILL); // Kill the child process after the specified time
            waitpid(pid, &status, 0); // Wait for the child process to terminate
        } else { // Child process has already finished
            printf("Child process finished before timeout.\n");
        }
    } else { // Fork failed
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
}
MainNode* mainList = NULL;
int main()
{
	short int choice;
	do
	{
		printf("1. Login \n");
		printf("2. Sign up\n");
		printf("3. Exit\n");
		printf("4. Contact Us\n");
		printf("Enter your choice: \n");

		scanf("%hd", &choice);
		if (choice == 1)
			login();
		else if (choice ==2)
			SignUp();
		else if (choice ==3)
			exit (0);
		else if (choice ==4)
		{
			printf("Email: 223Project@gmail.com");
		}
		else
			printf("\nIncorrect choice!!!");
	}
	while (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5);
}

