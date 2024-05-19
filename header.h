#ifndef header_H
#define header_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
typedef struct {
    char *username;
    char *email;
    char *password;
} User;
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
extern MainNode* mainList;
#include "CreateGame.h"
#include "FrontPage.h"
#include "list.h"
#include "login.h"
#include "MainMenu.h"
#include "SignUp.h"
#include "JoinGame.h"
#include "scorefun.h"
#include "changscore.h"
#include "timep.h"



#endif








