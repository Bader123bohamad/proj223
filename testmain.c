#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
	short int QE = 0, QM = 0, QH = 0;
   	short int QE2,QM2;
	short int cataga;
	
// Define a node structure for integers
typedef struct IntNode {
    int data;
    struct IntNode* next;
} IntNode;

// Define a node structure for strings
typedef struct StringNode {
    char data[100];
    struct StringNode* next;
} StringNode;

// Define a node structure for main list
typedef struct MainNode {
    int data;
    struct MainNode* next;
    struct StringNode* subList;
} MainNode;

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
int isDuplicate(MainNode* head, int data) {
    MainNode* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1; // Duplicate found
        }
        temp = temp->next;
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
void printAllNodes(MainNode* head) {
      MainNode* temp = head;
    while (temp != NULL) {
        printf("Main node data: %d\n", temp->data);
        temp = temp->next;
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

void printMainList2(MainNode* head) {
    MainNode* temp = head;
    while (temp != NULL) {
        printf("Main node data: %d\n", temp->data);
        temp = temp->next;
    }
}
// Function to print the main list
void printMainList(MainNode* head) {
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
}

// Function to print a sublist
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
void list(short int cho,short int cho1,short int cho2,short int cho3,short int cho4,short int cho5) {



    int  data, mainData;
    char subListData[100]; // Temporary buffer for sublist data
    	MainNode* mainList = NULL;
    // Seed the random number generator
    srand(time(NULL));


                // Generate a random four-digit number and ensure it is not a duplicate in the main list
                do {
                    data = generateRandomNumber();
                } while (isDuplicate(mainList, data));
                appendMain(&mainList, data);
                mainData=data;
                MainNode* mainNode = searchMainList(mainList, mainData);
                if (mainNode != NULL) {
                    int inputIntegers[6];
                    inputIntegers[0]=cho;
                    inputIntegers[1]=cho1;
                    inputIntegers[2]=cho2;
                    inputIntegers[3]=cho3;
                    inputIntegers[4]=cho4;
                    inputIntegers[5]=cho5;

                    if (inputIntegers[5] == 1) {
                        FILE* file = fopen("easyQcs.txt", "r");
                        if (file != NULL) {
                            int lineNo = (inputIntegers[0] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file);
                                       /////////////////////
                            FILE* file = fopen("easyQcs.txt", "r");
                             lineNo = (inputIntegers[1] * 7) + 1;
                             lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file);
                            //////////////////////
                        } else {
                            printf("File not found.\n");
                        }
                        //////////////////////////
                        ////////////////////////////
                        ///////////////////////////
                        FILE* file2 = fopen("mediumQcs.txt", "r");
                        if (file2 != NULL) {
                            int lineNo = (inputIntegers[2] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file2);
                                       /////////////////////
                            FILE* file2 = fopen("mediumQcs.txt", "r");
                             lineNo = (inputIntegers[3] * 7) + 1;
                             lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file2);
                            //////////////////////
                        } else {
                            printf("File not found.\n");
                        }
                        ////////////////////////////////////////////
                        ///////////////////////////////////////////
                        FILE* file3 = fopen("hardQcs.txt", "r");
                        if (file3 != NULL) {
                            int lineNo = (inputIntegers[4] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file3) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file3) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file3);
                        }
                        /////////////////////////////////////////////
                        ///////////////////////////////////////////////
                    } 
                    
                    
                    
                    if (inputIntegers[5] == 2) {
                        FILE* file = fopen("easyQsci.txt", "r");
                        if (file != NULL) {
                            int lineNo = (inputIntegers[0] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file);
                                       /////////////////////
                            FILE* file = fopen("easyQsci.txt", "r");
                             lineNo = (inputIntegers[1] * 7) + 1;
                             lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file);
                            //////////////////////
                        } else {
                            printf("File not found.\n");
                        }
                        //////////////////////////
                        ////////////////////////////
                        ///////////////////////////
                        FILE* file2 = fopen("mediumQsci.txt", "r");
                        if (file2 != NULL) {
                            int lineNo = (inputIntegers[2] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file2);
                                       /////////////////////
                            FILE* file2 = fopen("mediumQsci.txt", "r");
                             lineNo = (inputIntegers[3] * 7) + 1;
                             lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file2);
                            //////////////////////
                        } else {
                            printf("File not found.\n");
                        }
                        ////////////////////////////////////////////
                        ///////////////////////////////////////////
                        FILE* file3 = fopen("hardQsci.txt", "r");
                        if (file3 != NULL) {
                            int lineNo = (inputIntegers[4] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file3) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file3) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file3);
                        }
                        /////////////////////////////////////////////
                        ///////////////////////////////////////////////
                    }
                    
                    
                    
                        if (inputIntegers[5] == 3) {
                        FILE* file = fopen("easyQgeo.txt", "r");
                        if (file != NULL) {
                            int lineNo = (inputIntegers[0] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file);
                                       /////////////////////
                            FILE* file = fopen("easyQgeo.txt", "r");
                             lineNo = (inputIntegers[1] * 7) + 1;
                             lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file);
                            //////////////////////
                        } else {
                            printf("File not found.\n");
                        }
                        //////////////////////////
                        ////////////////////////////
                        ///////////////////////////
                        FILE* file2 = fopen("mediumQgeo.txt", "r");
                        if (file2 != NULL) {
                            int lineNo = (inputIntegers[2] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file2);
                                       /////////////////////
                            FILE* file2 = fopen("mediumQgeo.txt", "r");
                             lineNo = (inputIntegers[3] * 7) + 1;
                             lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file2);
                            //////////////////////
                        } else {
                            printf("File not found.\n");
                        }
                        ////////////////////////////////////////////
                        ///////////////////////////////////////////
                        FILE* file3 = fopen("hardQgeo.txt", "r");
                        if (file3 != NULL) {
                            int lineNo = (inputIntegers[4] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file3) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file3) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file3);
                        }
                        /////////////////////////////////////////////
                        ///////////////////////////////////////////////
                    } 
                    
                    
                    
                                        
                    
                        if (inputIntegers[5] == 4) {
                        FILE* file = fopen("easyQsport.txt", "r");
                        if (file != NULL) {
                            int lineNo = (inputIntegers[0] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file);
                                       /////////////////////
                            FILE* file = fopen("easyQsport.txt", "r");
                             lineNo = (inputIntegers[1] * 7) + 1;
                             lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file);
                            //////////////////////
                        } else {
                            printf("File not found.\n");
                        }
                        //////////////////////////
                        ////////////////////////////
                        ///////////////////////////
                        FILE* file2 = fopen("mediumQsport.txt", "r");
                        if (file2 != NULL) {
                            int lineNo = (inputIntegers[2] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file2);
                                       /////////////////////
                            FILE* file2 = fopen("mediumQsport.txt", "r");
                             lineNo = (inputIntegers[3] * 7) + 1;
                             lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file2) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file2);
                            //////////////////////
                        } else {
                            printf("File not found.\n");
                        }
                        ////////////////////////////////////////////
                        ///////////////////////////////////////////
                        FILE* file3 = fopen("hardQsport.txt", "r");
                        if (file3 != NULL) {
                            int lineNo = (inputIntegers[4] * 7) + 1;
                            char lineData[100];
                            for (int i = 1; i <= lineNo; ++i) {
                                if (fgets(lineData, sizeof(lineData), file3) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                            }
                            // Remove newline character
                            lineData[strcspn(lineData, "\n")] = '\0';
                            appendStringSubList(mainNode, lineData);
                            // Read the next five lines
                            for (int i = 0; i < 5; ++i) {
                                if (fgets(lineData, sizeof(lineData), file3) == NULL) {
                                    printf("Error reading file.\n");
                                    exit(EXIT_FAILURE);
                                }
                                // Remove newline character
                                lineData[strcspn(lineData, "\n")] = '\0';
                                appendStringSubList(mainNode, lineData);
                            }
                            fclose(file3);
                        }
                        /////////////////////////////////////////////
                        ///////////////////////////////////////////////
                    } 
                    
                    
                    
                    if (inputIntegers[5] >=5 || inputIntegers[5] <=0)
                    		printf("Invalid input\n");
                    
      
                    
                } else {
                    printf("Main list node with data %d not found.\n", mainData);
                }
                printAllNodes(mainList);
		CreateGame();
		//printsub list/
		/*
                printf("Enter the data of the main list node to print its sublist: ");
                scanf("%d", &mainData);
                MainNode* node = searchMainList(mainList, mainData);
                if (node != NULL) {
                    if (node->subList != NULL)
                        printSubList(node->subList);
                    else
                        printf("No sublist for node with data %d.\n", mainData);
                } else {
                    printf("Main list node with data %d not found.\n", mainData);
                }*/

	////////serch mainlist 
	/*
                printf("Enter data to search in main list: ");
                scanf("%d", &data);
                MainNode* result = searchMainList(mainList, data);
                if (result != NULL) {
                    printf("Node with data %d found in main list.\n", data);
                } else {
                    printf("Node with data %d not found in main list.\n", data);
                }
*/


}
void WorkingCreateGame(int cataga) {

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
            		{
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
void CreateGame()
{

	printf("Choose a Category:\n");
	printf("1-Computer Science\n");
	printf("2-Sciences\n");
	printf("3-GEO\n");
	printf("4-SPORT\n");
	printf("5-GO BACK\n");
	printf("Enter your choice: ");
	do
	{
		scanf("%hd", &cataga);
		if (cataga>5 || cataga <1)
		{
			printf("\n**Enter a number from 1 to 4**\n\n");
			printf("Choose a Category:\n");
			printf("1-Computer Science:\n");
			printf("2-Sciences:\n");
			printf("3-GEO:\n");
			printf("4-Sports :\n");
			printf("5-Go Back :\n");
			printf("Enter your choice: ");
		}
	}
	while (cataga>5 || cataga <1);

	WorkingCreateGame(cataga);
	list(QE,QE2,QM,QM2,QH,cataga);
}



int main()
{
    	MainNode* mainList = NULL;
	CreateGame();

	return 0;
}

