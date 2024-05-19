#ifndef Frontpage_H
#define FrontPage_H
#include "header.h"
IntNode* createIntNode(int) ;
StringNode* createStringNode(const char*);
int isDuplicate(MainNode* head, int );
int generateRandomNumber();
void appendMain(MainNode** head, int ) ;
void appendStringSubList(MainNode*,const char* );
void printMainList(MainNode* head);
void printSubList(StringNode* subList);
MainNode* searchMainList(MainNode* head, int );
int main();
void printQ(MainNode* head, int , char[]);
void timepp(int ,MainNode* head, int , char []) ;
#endif
