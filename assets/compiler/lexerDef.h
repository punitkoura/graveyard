/*
	lexerDef.h
	
	Group no : 34
	Punit Singh Koura
	Manas Chauhan
*/

#include<stdio.h>
#ifndef LEXERDEF_H
#define LEXERDEF_H



#define inf 1000000000


#define MAX_LENGTH_TOKEN 30
#define MAX_LENGTH 80

typedef enum {false,true} boolean;

/**	
	enum data type to represent tokens, and non terminals 
*/

typedef enum {ASSIGNOP,FUNID,ID,NUM,RNUM,STR,SQO,SQC,OP,CL,SEMICOLON,
	COMMA,PLUS,MINUS,MUL,DIV,SIZE,LT,LE,EQ,GT,GE,NE,
	END,INT,REAL,STRING,MATRIX,IF,ELSE,
	ENDIF,READ,PRINT,FUNCTION,AND,OR,NOT,MAIN, EPSILON, DOLLAR, 
	mainFunction, stmtsAndFunctionDefsExtension, functionDef, type, 
	remainingList, var_list, more_ids, leftHandSide_singleVar, 
	leftHandSide_listVar, sizeExpression, ifStmt, ifExtension,
	otherStmts, ioStmt, funCallStmt, inputParameterList, listVar,
	arithmeticExtension, factorExtension, factor, operator_lowPrecedence, 
	operator_highPrecedence, booleanExpression, constrainedVars, 
	var, matrix, rowExtension, row, numExtension, remainingColElements,
	matrixElement, logicalOp, relationalOp, parameter_list, declarationStmt,
	assignmentStmt_type1, assignmentStmt_type2, rightHandSide_type2, rows,
	stmt, arithmeticTerm, stmtOrFunctionDef, arithmeticExpression, rightHandSide_type1,
	stmtsAndFunctionDefs,NONE,ERROR}
	token_type_enum;

/**
	A data structure to store the details of the token read
*/
	
typedef struct token_type
{
	int cur_line;		//The current line number
	int cur_pos;		//The column number in the current line
	
	token_type_enum token_type;			//Type of the token
	char read_string[MAX_LENGTH_TOKEN];	//The token as it is
	int int_val;		//For integer values
	float real_val;		//For real values
} tokenInfo;


/**
	Internal data structure to store the state of the DFA 
	we are using for determining the token type
*/

typedef enum {start,oneequal,equalnot,greater,less,dumb,funid,funidalpha,
    id,stringbegin,stringbeginalpha,logicalbegin,logicalalpha,
    num,numdot,numdot1,error,errorid,gotowhite,idnum,end} state;



/**
	Type definition for buffer, and its size
*/

typedef char* Buffer;

typedef int BufferSize;



/**
	Data structure to store the state of the file
	between successive getNextToken accesses
*/

typedef struct file_state
{
    Buffer filename;
    size_t size;
    Buffer buffer;
    int lookahead;
    int lineno;
    int colmno;
} fileState;


#endif
