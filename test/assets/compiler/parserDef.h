/*
    parserDef.h
    
    Group no : 34
	Punit Singh Koura
	Manas Chauhan
*/

#include "lexer.h"
#ifndef PARSERDEF_H
#define PARSERDEF_H

#define MAX_SIZE 150
#define NO_OF_TERM_NONTERM 85
#define NO_OF_TERM 40
#define NO_OF_NONTERM NO_OF_TERM_NONTERM-NO_OF_TERM
#define startstate mainFunction



/**
	Data structure to store a list of tokens. Used for storing a grammar rule
*/
typedef struct _enumlist
{
    token_type_enum tk;
    struct _enumlist* next;
    struct _enumlist* prev;
} 
tokenList;

/**
	Data structure to store a grammar rule
*/
typedef struct _rule
{
    token_type_enum  lhs;	//lhs of the rule
    int count;				//no of tokens on rhs
    tokenList* head;		//A doubly linked list to store		
    tokenList* tail;		//	the rhs of a rule
}
rule;

/**
	Data structure for a stack of tokens.
	Useful in parsing.
*/
typedef struct _enumstack
{
	token_type_enum tk;
	struct _enumstack*next;
}
tokenStack;

/**
	Data structure to represent the parse tree
*/
typedef struct _parsetree
{
	token_type_enum tk;			//Token type of this node
	tokenInfo token;			//Actual token (if leaf)
	
	struct _parsetree** child;	//Pointer to child array
	struct _parsetree* parent;	//Pointer to its parent
	int leftOff;				//Store which child it was expanding
	int childnum;				//Store the no. of children
}
parseTree;


/**
	An array of rules is a grammar
*/
typedef rule* grammar;

/**
	Used to store the parsing table
*/
typedef int** table;

#endif
