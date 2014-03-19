/**
	parser.c

	Group no : 34
	Punit Singh Koura
	Manas Chauhan
*/

#include "parser.h"
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>


/**
	An array containing the string form of token_type_enum
	defined in lexerDef.h
*/

const char* trans[ NO_OF_TERM_NONTERM] = {"ASSIGNOP" , "FUNID" , "ID" , "NUM" , "RNUM" , "STR" , "SQO" , "SQC" , "OP" , "CL" , "SEMICOLON" , "COMMA" , "PLUS" , "MINUS" , "MUL" , "DIV" , "SIZE" , "LT" , "LE" , "EQ" , "GT" , "GE" , "NE" , "END" , "INT" , "REAL" , "STRING" , "MATRIX" , "IF" , "ELSE" , "ENDIF" , "READ" , "PRINT" , "FUNCTION" , "AND" , "OR" , "NOT" , "MAIN" , "EPSILON" , "DOLLAR" , "mainFunction" , "stmtsAndFunctionDefsExtension" , "functionDef" , "type" , "remainingList" , "var_list" , "more_ids" , "leftHandSide_singleVar" , "leftHandSide_listVar" , "sizeExpression" , "ifStmt" , "ifExtension" , "otherStmts" , "ioStmt" , "funCallStmt" , "inputParameterList" , "listVar" , "arithmeticExtension" , "factorExtension" , "factor" , "operator_lowPrecedence" , "operator_highPrecedence" , "booleanExpression" , "constrainedVars" , "var" , "matrix" , "rowExtension" , "row" , "numExtension" , "remainingColElements" , "matrixElement" , "logicalOp" , "relationalOp" , "parameter_list" , "declarationStmt" , "assignmentStmt_type1" , "assignmentStmt_type2" , "rightHandSide_type2" , "rows" , "stmt" , "arithmeticTerm" , "stmtOrFunctionDef" , "arithmeticExpression" , "rightHandSide_type1" , "stmtsAndFunctionDefs"};

int l;

token_type_enum translate(char* tk)
{
	//convert from string representation to variable
	int x;
	for(x=0;x< NO_OF_TERM_NONTERM;x++)
	{
		if(strcmp(tk,trans[x])==0)
		return (token_type_enum)x;
	}
	return x;
}


const char* reverseTranslate(token_type_enum tk)
{
	return trans[tk];
}

rule createNewList(rule r)
{
	r.head=NULL;
	r.tail=NULL;
	r.count = 0;
	return r;
}

void printRule(rule r)
{
	tokenList* list;
	list = r.head;
	while(list!=NULL)
	{
		printf("%s ",reverseTranslate(list->tk));
		list = list->next;
	}
	printf("\n");
	return;
}

rule addTokenList(rule r,token_type_enum tk)
{
	if(r.head==NULL)
	{
		r.head=(tokenList*)malloc(sizeof(tokenList));
		r.tail = r.head;
		r.head->tk = tk;
		r.head->prev = NULL;
		r.head->next = NULL;
		r.count++;
		return r;
	}
	
	r.tail->next = (tokenList*)malloc(sizeof(tokenList));
	r.tail->next->tk = tk;
	r.tail->next->prev = r.tail;
	r.tail->next->next = NULL;
	r.count++;
	r.tail = r.tail->next;
	return r;
}



void printGrammar(grammar g, int determinant, int l)	
/*
	determinant - 
		0 for head to tail
		1 for tail to head
*/
{
	int x;
	tokenList*temp;
	for(x=0;x<l;x++)
	{
		printf("%s -> ",trans[g[x].lhs]);
		if(!determinant)
		{
			temp = g[x].head;
			while(temp!=NULL)
			{
				printf("%s ",trans[temp->tk]);
				temp = temp->next;
			}
		}
		else
		{
			temp = g[x].tail;
			while(temp!=NULL)
			{
				printf("%s ",trans[temp->tk]);
				temp = temp->prev;
			}
		}
		printf("\n");
	}
}


grammar populateGrammar(char* filename)
{
    //input - File containing grammar rules
    //output - The populated grammar
    
    FILE*fp = fopen(filename,"r");
    char buffer[MAX_SIZE];
    if(fp==NULL)
    {
        printf("Cannot populate grammar\n");
        return NULL;
    }
    fgets(buffer,MAX_SIZE,fp);
    l = atoi(buffer);
    
    grammar g = (grammar)malloc(sizeof(rule)*l);
    
    
    char *temp;
    int tempnum;
    int x;
    for(x=0;x<l;x++)
    {
    	g[x] = createNewList(g[x]);
    	fgets(buffer,MAX_SIZE,fp);
    	temp = strtok(buffer," ");
    	
    	g[x].lhs = translate(temp);
    	temp = strtok(NULL," ");
    	temp = strtok(NULL," ");
    	while(temp!=NULL)
    	{
    		tempnum = strlen(temp);
    		if(temp[tempnum-1]=='\n')
    			temp[tempnum-1] = '\0';
			//if(!(temp[0]=='-'))
			
			
			g[x] = addTokenList(g[x],translate(temp));
    		temp = strtok(NULL," ");
		}
    	
	}
	
    return g;
}



grammar convertFollowToGrammar(int** fol)
{
	int x,y;
	
	grammar g = (grammar)malloc(sizeof(rule)*NO_OF_TERM_NONTERM);
	
	for(x=0;x<NO_OF_TERM_NONTERM;x++)
    {
    	g[x] = createNewList(g[x]);
    	g[x].lhs = x;
    	
    	for(y=0;y<NO_OF_TERM_NONTERM;y++)
    	{
    		if(fol[x][y]==1)
    		{
    			g[x] = addTokenList(g[x],y);
			}
		}
    	
    	
	}
	return g;
}


void findFollow(grammar g, int** fst,int** fol)
{
	int flag;
	flag=1;
	
	int x;
	tokenList* list;
	
	token_type_enum tk;
	
	int y;
	
	int flag1;
	
	while(flag)
	{
		flag=0;
		for(x=0;x<l;x++)
		{
			list = g[x].head;
			while(list!=NULL)
			{
				tk = list->tk;
				if(tk<NO_OF_TERM)
				{
					//it is a terminal
					list=list->next;
					continue;
				}
				if(tk==mainFunction)
				{
					if(fol[tk][DOLLAR]==0)
					{
						fol[tk][DOLLAR] = 1;
					}
					list = list->next;
					continue;
				}		
				if(list->next==NULL)
				{
					for(y=0;y<NO_OF_TERM_NONTERM;y++)
					{
						if(fol[g[x].lhs][y]==1)
						{
							if(fol[tk][y]==0)
							{
								fol[tk][y] = fol[g[x].lhs][y];
								flag=1;
							}
						}
					}
				}
				else
				{
					flag1 = 0;
					for(y=0;y<NO_OF_TERM_NONTERM;y++)
					{
						if(fst[list->next->tk][y]==1)
						{
							if(y==EPSILON)
							{
								flag1 = 1;
							}
							else if(fol[tk][y] == 0)
							{
								fol[tk][y] = fst[list->next->tk][y];
								flag=1;
							}
						}
					}
					if(flag1==1)
					{
						for(y=0;y<NO_OF_TERM_NONTERM;y++)
						{
							if(fol[g[x].lhs][y]==1)
							{
								if(fol[tk][y]==0)
								{
									fol[tk][y] = fol[g[x].lhs][y];
									flag=1;
								}
							}
						}
					}
				}
				list = list->next;
			}
		}
	}
	
	fol[mainFunction][DOLLAR] = 1;
	
	return ;
}
				



int firstRec(token_type_enum tk, int** fst,int* lookup,grammar g)
{
	if(lookup[tk]==1)
	{
		return 1;
	}
	if(tk<NO_OF_TERM)
	{
		fst[tk][tk] = 1;
		lookup[tk] = 1;
		return 1;
	}
	
	int x;
	
	int y;
	
	tokenList* list;
	token_type_enum temp;
	
	int flag;
	
	for(x=0;x<l;x++)
	{
		if(g[x].lhs==tk)
		{
			//for each rule
			list = g[x].head;
			while(list!=NULL)
			{
				flag=0;
				temp = list->tk;
				firstRec(temp,fst,lookup,g);
				lookup[temp] = 1;
				for(y=0;y<NO_OF_TERM_NONTERM;y++)
				{
					if(fst[temp][y]==1)
					{
						if(y==EPSILON)
						{
							flag=1;
						}
						else
							fst[tk][y] = 1;
					}
				}
				if(flag==0)
					break;
				
				list = list->next;
			}
			if(list==NULL)
			{
				fst[tk][EPSILON] = 1;
			}
		}
	}
	lookup[tk] = 1;
	return 1;
	
}


int** findFirst(grammar g)
{
	int** fst;
	fst = (int**)malloc(sizeof(int*)*NO_OF_TERM_NONTERM);
	int x;
	int y;
	
	for(x=0;x<NO_OF_TERM_NONTERM;x++)
	{
		fst[x] = (int*)malloc(sizeof(int)*NO_OF_TERM_NONTERM);
		for(y=0;y<NO_OF_TERM_NONTERM;y++)
		{
			fst[x][y] = 0;
		}
	}
	
	int*lookup;
	lookup = (int*)malloc(sizeof(int)*NO_OF_TERM_NONTERM);
	
	for(x=0;x<NO_OF_TERM_NONTERM;x++)
		lookup[x] = 0;
		
	
	token_type_enum tk;
	
	for(tk=0;tk<NO_OF_TERM_NONTERM;tk++)
	{
		firstRec(tk,fst,lookup,g);
	}
	
	return fst;
	
}


grammar convertFirstToGrammar(int** fst)
{
	int x,y;
	
	grammar g = (grammar)malloc(sizeof(rule)*NO_OF_TERM_NONTERM);
	
	for(x=0;x<NO_OF_TERM_NONTERM;x++)
    {
    	g[x] = createNewList(g[x]);
    	g[x].lhs = x;
    	
    	for(y=0;y<NO_OF_TERM_NONTERM;y++)
    	{
    		if(fst[x][y]==1)
    		{
    			g[x] = addTokenList(g[x],y);
			}
		}
    	
    	
	}
	return g;
}
			

table createParseTable(grammar g, grammar first, grammar follow)
{
	int** tab = (int**)(malloc(sizeof(int*)*NO_OF_TERM_NONTERM));
	int x;
	for(x=0;x<NO_OF_TERM_NONTERM;x++)
	{
		tab[x] = (int*)malloc(sizeof(int)*NO_OF_TERM_NONTERM);
	}
	
	token_type_enum tk;
	tokenList* list;
	
	token_type_enum _tk;
	
	token_type_enum temptk;
	
	boolean flag;
	
	int y;
	
	for(x=0;x<NO_OF_TERM_NONTERM;x++)
	{
		for(y=0;y<NO_OF_TERM_NONTERM;y++)
		{
			tab[x][y] = -1;
		}
	}
	
	
	for(x=0;x<l;x++)
	{
		//for each grammar rule
		tk = g[x].lhs;
		list = first[tk].head;
		
		_tk = g[x].head->tk;
		list = first[_tk].head;
		
		flag = false;
		while(list!=NULL)
		{
			temptk = list->tk;
			if(temptk == EPSILON) 
			{
				flag=true;
			}
			else
			{
				tab[tk][temptk] = x;
			}
			list = list->next;
		}
		if(flag==true)
		{
			list = follow[tk].head;
			while(list!=NULL)
			{
				_tk = list->tk;
				tab[tk][_tk] = x;
				list = list->next;
			}
		}
	}
	
	return tab;
}


void printTable(table tab)
{
	int x,y;
	for(x=0;x<NO_OF_TERM_NONTERM;x++)
	{
		printf("%s \n",trans[x]);
		for(y=0;y<NO_OF_TERM_NONTERM;y++)
		{
			if(x>DOLLAR && y<=DOLLAR && tab[x][y]!=-1)
			{
			printf("%s %d ",trans[y],tab[x][y]);
			}
		}
		printf("\n========================\n");
	}
	return;
}


parseTree* createNewNode(token_type_enum tk)
{
	parseTree* temp = (parseTree*)malloc(sizeof(parseTree));
	temp->leftOff = 0;
	temp->tk = tk;
	temp->child = NULL;
	return temp;
}

parseTree* expandNode(parseTree* node, rule r)
{
	int count = r.count;
	node->child = (parseTree**)malloc(sizeof(parseTree*)*count);
	node->childnum = count;
	
	int x;
	tokenList* list;
	list = r.head;
	
	int flag = 0;
	
	for(x=0;x<count;x++)
	{
		node->child[x] = createNewNode(list->tk);
		node->child[x]->parent = node;
		if(list->tk==EPSILON)
			flag=1;
		
		
		list = list->next;
	}

	if(flag)
	{

		node = node->parent;
		if(node!=NULL)
		{
			while(node!=NULL && (node->leftOff==(node->childnum-1)))
			{
				node = node->parent;
			}
			if(node!=NULL)
			{
				node->leftOff++;
				node = node->child[node->leftOff];
			}
		}
		return node;
	}
	return node->child[node->leftOff];
}
	


tokenStack* push(tokenStack* stack, token_type_enum tk)
{
	if(stack==NULL)
	{
		stack = (tokenStack*)malloc(sizeof(tokenStack));
		stack->tk = tk;
		stack->next = NULL;
		return stack;
	}
	
	tokenStack* temp = (tokenStack*)malloc(sizeof(tokenStack));
	temp->tk = tk;
	temp->next = stack;
	stack = temp;
	return stack;
}

tokenStack* pop(tokenStack* stack)
{
	if(stack==NULL)
		return stack;
	
	tokenStack* temp = stack;
	stack = stack->next;
	free(temp);
	return stack;
}

token_type_enum top(tokenStack *stack)
{
	if(stack==NULL)
		return NONE;
	else
		return stack->tk;
}

void stacktrace(tokenStack* stack)
{
	if(stack==NULL) return;
	while(stack!=NULL)
	{
		printf("%s ",trans[stack->tk]);
		stack = stack->next;
	}
	printf("\n");
}

tokenStack *expand(tokenStack* stack,rule r)
{
	tokenList* tail = r.tail;
	while(tail!=NULL)
	{
		if(tail->tk!=EPSILON)
			stack = push(stack,tail->tk);
		tail = tail->prev;
	}
	return stack;
}


void tokenizeWholeFile(FILE*fp, fileState* fs)
{
	tokenInfo ti = getNextToken(fp,fs);
	
	while(!(ti.token_type==NONE))
	{
		ti = getNextToken(fp,fs);
	}
	return;
}


tokenStack* flush(tokenStack* stack)
{
	tokenStack* temp;
	while(stack!=NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}



parseTree* parseInputSourceCode(char* filename, table tab, grammar g,grammar first)
{
	char* b = (char*)malloc(sizeof(char)*MAX_LENGTH);
    FILE* fp = fopen(filename,"r");
    
    fileState *fs = (fileState*)malloc(sizeof(fileState));
    
    fs->buffer = NULL;
    fs->filename = filename;
    tokenInfo ti;
    
    ti =  getNextToken(fp,fs);
    
    tokenStack *stack = NULL;
    
    stack = push(stack,startstate);
    
    int index;
    
    tokenList *list;
    
    parseTree* tree = createNewNode(mainFunction);
    
    
    
    parseTree* temp = tree;
    
    rule r;
    
    int flag=0;
    
    while(!(ti.token_type==NONE || stack==NULL))
    {
    	if(ti.token_type==NONE || ti.token_type==ERROR) break;
    	
    	while(top(stack)!=ti.token_type)
    	{
    		
    		index = tab[top(stack)][ti.token_type];
    		if(index==-1)
    		{
    			goto end;
			}
			r = g[index];
			stack = pop(stack);
			stack = expand(stack,r);
			//temp->leftOff++;
			temp = expandNode(temp, r);
			
			
		}
		
    	
    	
    	
    	stack = pop(stack);
    	
    	temp->token = ti;
    	temp = temp->parent;
    	
    	if(temp!=NULL)
    	{
    		while(temp->leftOff==(temp->childnum-1))
    		{
    			
    			temp = temp->parent;
    			if(temp==NULL)
    				break;
			}
			
			if(temp!=NULL)
			{
				
				temp->leftOff++;
				temp = temp->child[temp->leftOff];
			}
			else
			{
			}
		}
    	
    	ti = getNextToken(fp,fs);
    }
	
	
	
    end:
    
    
    
    if(stack==NULL && ti.token_type==NONE)
    {
    	printf("Parsing successful\n");
    	flag=1;
	}
	else
	{
		if(ti.token_type==ERROR)
		{
			printf("%s:The token %s for lexeme %s does not match at %d:%d.\nThe expected token (s) here are ",filename,"ERROR",ti.read_string, ti.cur_line, ti.cur_pos);
		}
		else
		{	
			printf("%s:The token %s for lexeme %s does not match at %d:%d.\nThe expected token (s) here are ",filename,trans[ti.token_type],ti.read_string, ti.cur_line, ti.cur_pos);
		}
		
		if(stack==NULL)
		{
			printf("<null>\n");
		}
		else
		{
			list = first[top(stack)].head;
			while(list!=NULL)
			{
				printf("%s, ",trans[list->tk]);
				list = list->next;
			}
			printf("\n");
		}
		
		stack = flush(stack);
	}
	
	tokenizeWholeFile(fp,fs);
	
    if(flag)
    return tree;
    else return NULL;
}

void printTreeNode(parseTree* tree, FILE* fp)
{
	
	if(tree->child==NULL)
	{
		if(tree->tk!=EPSILON)
		{
			fprintf(fp,"%-30s %-6d",tree->token.read_string,tree->token.cur_line);
			fprintf(fp,"%-30s",trans[tree->tk]);
			if(tree->token.token_type==NUM)
				fprintf(fp,"%-10d",tree->token.int_val);
			else if(tree->token.token_type==RNUM)
				fprintf(fp,"%-10f",tree->token.real_val);
			else
				fprintf(fp,"%-10s","NA");
			
			if(tree->parent!=NULL)
				fprintf(fp,"%-30s",trans[tree->parent->tk]);
			else
				fprintf(fp,"%-30s","ROOT");
			
			fprintf(fp,"%-4s","YES");
			fprintf(fp,"\n");
		}
		else
		{
			fprintf(fp,"%-30s %-6s","-----","-----");
			fprintf(fp,"%-30s",trans[tree->tk]);
			fprintf(fp,"%-10s","-----");
		
			if(tree->parent!=NULL)
				fprintf(fp,"%-30s",trans[tree->parent->tk]);
			else
				fprintf(fp,"%-30s","ROOT");
		
			fprintf(fp,"%-4s","YES");
		
			fprintf(fp,"%-30s\n",trans[tree->tk]);
		}
	}
	else
	{
		fprintf(fp,"%-30s %-6s","-----","-----");
		fprintf(fp,"%-30s",trans[tree->tk]);
		fprintf(fp,"%-10s","-----");
		
		if(tree->parent!=NULL)
			fprintf(fp,"%-30s",trans[tree->parent->tk]);
		else
			fprintf(fp,"%-30s","ROOT");
		
		fprintf(fp,"%-4s","NO");
		
		fprintf(fp,"%-30s\n",trans[tree->tk]);
	}
}
	
	


void recursePrint(parseTree* tree, FILE* fp)
{
	if(tree->child==NULL)
	{
		printTreeNode(tree,fp);
		return;
	}
	
	int x;
	for(x=0;x<tree->childnum;x++)
	{
		recursePrint(tree->child[x],fp);
	}
	printTreeNode(tree,fp);
	
	return;
}
	

void printParseTree(parseTree* tree, char* outfile)
{
	FILE* fp = fopen(outfile,"w");
	
	recursePrint(tree,fp);
}
