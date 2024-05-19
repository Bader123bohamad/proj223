#include "header.h"
void list(short int cho,short int cho1,short int cho2,short int cho3,short int cho4,short int cho5, char user[20]) {



    int  data, mainData;
    char subListData[100]; // Temporary buffer for sublist data
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
                                }void appendStringSubList(MainNode* mainNode, const char* data) {
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
                        }} else {
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
               printMainList(mainList);
                MainMenu(user);



}
