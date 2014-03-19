/*
	parser.h
	
	Group No: 34
	Punit Singh Koura
	Manas Chauhan
*/

#ifndef PARSER_H
#define PARSER_H

#include "parserDef.h"

/**
	A function to translate a token from its string format to enum format.
	Params - 	char* tk - The string representation of the token
	Return -	The enum representation of the same
*/
extern token_type_enum translate(char* tk);


/**
	Function to translate from enum format to string format
	Params -	The enum representation of the token
	Return - 	The string representation of the same
*/
extern const char* reverseTranslate(token_type_enum tk);

/**
	Creates a new list for storing the rhs of a rule.
	Stores this information in rule r
	Params - 	The rule to be initialized
	Return -	The initialized rule
*/
extern rule createNewList(rule r);

/**
	Used to print information stored in a particular rule
	Params -	The rule r to be printed
	Return -	void
*/
extern void printRule(rule r);

/**
	Used to add a new token to the rule's list
	Params - 	rule r - The rule to which to add the token
				tk - The token to be added
	Return -	The rule with token tk added
*/
extern rule addTokenList(rule r,token_type_enum tk);

/**
	Used to print a grammar
	Params -	grammar g - The grammar to be printed
				determinant - To print rhs of rule from left to right 
					or right to left
				l - The no. of rules in g
	Return -	void
*/
extern void printGrammar(grammar g, int determinant, int l)	;

/**
	Used to populate grammar from a file
	Params -	filename - The name of the file containing the grammar rules
	Return -	The populated grammar Data Structure
*/
extern grammar populateGrammar(char* filename);


/**
	Used to populate the follow set given the grammar g and the first set
	Params - 	g - The grammar for which the follow set is to be calculated
				fst - The first set for the given grammar
				fol - The follow set to be populated
	Return -	void
*/				
extern void findFollow(grammar g, int** fst,int** fol);

/**
	Used to populate convert between data representation of the follow set
	Params - 	fol - The 2D array representation of follow set
	Return - 	The grammar data structure representation of the follow set.
*/
extern grammar convertFollowToGrammar(int** fol);


/**
	Helper recursive procedure to find the first set of a grammar
	Params -	tk - The token fow whom first is to be calculated
				fst - The first data structure (a 2d array)
				lookup - Stores for whom we have already calculated the first set
				g - The grammar for which first set is to be calculated
	Return -	0 for success
				1 for failure
*/
extern int firstRec(token_type_enum tk, int** fst,int* lookup,grammar g);

/**
	The procedure to find first set of a grammar g
	Params -	g - The grammar for which first is to be calculated
	Return - 	The 2D array representing the first set
*/
extern int** findFirst(grammar g);

/**
	Used to convert between data representations of the first set
	Params - 	fst - The 2D array representation of first set
	Return - 	The grammar data structure representation of the first set.
*/
extern grammar convertFirstToGrammar(int** fst);

/**
	Populate the parse table based on the grammar, first and follow sets
	Params -	g - The grammar
				first - The first set
				follow - The follow set
	Return -	The populated predictive parsing table
*/
extern table createParseTable(grammar g, grammar first, grammar follow);

/**
	Debugging function - Can be used to print the populated parsing table
	Params - 	tab - The table to be printed
	Return -	void
*/
extern void printTable(table tab);

/**
	Initialize a new node of the parse tree with tk
	Params -	tk - The token enum which this node represents
	Returns - 	The initialized tree node
*/

/////////////////////////Parse tree related functions///////////////////////////////

extern parseTree* createNewNode(token_type_enum tk);

/**
	Used to expand a grammar rule on the parse tree
	Params - 	node - The node on which to expand the rule
				r - The rule to be expanded
	Return -	The node with the rule expanded on it
*/
extern parseTree* expandNode(parseTree* node, rule r);

/**
	Push a token enum on the stack
	Params - 	stack - The stack data structure
				tk - The token enum to be pushed
	Returns - 	The stack with the token pushed on it
*/


///////////////////////////Stack related functions//////////////////////////////////

extern tokenStack* push(tokenStack* stack, token_type_enum tk);

/**
	Pop the top element off the stack
	Params -	The stack data structure
	Return -	The stack with the top token popped off
*/
extern tokenStack* pop(tokenStack* stack);

/**
	Access the top element of the stack
	Params - 	stack - The stack
	Return - 	The top token
*/
extern token_type_enum top(tokenStack *stack);

/**
	Print the contents of the stack. USeful for debugging
	Params -	stack - The stack
	Return -	void
*/
extern void stacktrace(tokenStack* stack);

/**
	Expand a rule on the stack
	Params -	stack - The stack data structure
				r - The rule to be expanded
	Retusn - 	The stack with the rule expanded
*/
extern tokenStack *expand(tokenStack* stack,rule r);

/**
	Used to flush the contents of the stack (in case of error in parsing)
	Params - 	stack - The stack to be cleaned
	Return - 	The empty stack
*/
extern tokenStack* flush(tokenStack* stack);



/////////////////////////////Other Helper functions///////////////////////////////
/**
	Used to tokenize the remaining file (in case of parsing error, or if we are not parsing)
	Params -	fp - The file from which tokens are read
				fs - The state of the file
	Return - 	void
*/
extern void tokenizeWholeFile(FILE*fp, fileState* fs);

/**
	Parse the Input Source Code
	Params -	filename - The file containing the source code
				tab - The parsing table used
				g - Grammar containing the grammar rules
				first - The data structure containing the first rules for g
	Return -	The populated parse tree (if prasing is successful) or NULL (if error)
*/
extern parseTree* parseInputSourceCode(char* filename, table tab, grammar g,grammar first);


/**
	Print a node of the tree in the prescribed format
	Params -	The file pointer fp, to which to write the output
				tree - The node to be printed
	Return - 	void
*/			
extern void printTreeNode(parseTree* tree, FILE* fp);

/**
	A recursive helper function
	Params -	The file pointer fp in which to write the tree
				tree - The node which has to be recursively traversed
	Return -	void
*/
extern void recursePrint(parseTree* tree, FILE* fp);

/**
	The actual printParseTree function
	Params -	tree - The tree to be printed
				outfile - The name of the file to which to print the tree
	Return -	void
*/ 
extern void printParseTree(parseTree* tree, char* outfile); 

#endif
