/*
	lexer.h
	
	Group no : 34
	Punit Singh Koura
	Manas Chauhan
*/

#ifndef LEXER_H
#define LEXER_H

#include "lexerDef.h"

/**
	Refreshes the input buffer B with k bytes from the input stream fp
	Params - 	File pointer fp - The file to be read from
				Buffer B - The buffer which is to be populated
				BufferSize k - The amount of bytes to be read from the file
	Return - 	The amount of bytes actually read 
*/
extern size_t getStream(FILE* fp, Buffer B,BufferSize k);

/**
	Used to populate the tokenInfo data structure with all the necessary information
	Params - 	lineno - The line no. at which the token was found
				colmno - The column no. of the start of the token
				token_type - The internal enumerated type of the token
				read_string - The actual lexeme read from the file
	Return -	The populated tokenInfo data structure corresponding to the above information
*/
extern tokenInfo makeToken(int lineno, int colmno, token_type_enum token_type, 
     char* read_string);
    
/**
	Used to check if a character c is inside the array arr.
	Params -	c - The character to be checked
				arr - The array in which to find c
				lo - The lower limit of the search index
				hi - The upper limit if the search index
	Return - 	boolean value true or false
*/
extern boolean isInside(char c,const char* arr, int lo, int hi);

/**
	Used to check if temp is a keyword according to the lexical rules of the compler
	Params -	temp - the array to be searched
	Return -	if temp is a keyword, returns what type of keyword it is.
				else returns ID
*/
extern token_type_enum checkKeyword(char* temp);

/**
	Prints the token information collected.
	Params -	head - The token to be printed
	Returns - 	void
	
	To enable the printing procedure, add #define ENABLE_DEBUG 1 .
	By default it is disabled
*/
extern void printToken(tokenInfo head);

/**
	Updated the file state data structure
	Params - 	fstate - FileState variable containing the state variables
				fp - The File pointer to the file being read.
	Returns - 	0 if successful
*/
extern int updateFileState(FILE* fp,fileState *fstate);

/**
	Used to fetch the next token from the file
	Params -	fp - The file from which to fetch the next token
				fState - A data structure to store the file state for subsequent accesses.
	Returns -	The tokenInfo Data Structure with the details of the next token
*/ 
extern tokenInfo getNextToken(FILE* fp, fileState* fstate);

#endif
