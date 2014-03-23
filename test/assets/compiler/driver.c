/**
	Driver file.
	
	Group No : 34
	Punit Singh Koura
	Manas Chauhan
*/

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"


int main(int argc,char**argv)
{
    
    printf("First and follow set automated. \nBoth lexical and syntax modules implemented\n");
    printf("\n");
    
    if(argc!=4)
    {
    	printf("Usage - <filename> <ParseTreeOutFileName> <Option>\n");
    	printf("Option 1 for printing token list\nOption 2 for parsing to verify syntactic correctness");
    	printf(" of the input source code\nOption 3 for creating and printing parse tree\n");
		return -1;
	}
    
    
    int option = atoi(argv[3]);
    
    int x,y;
    
    int ** fol = (int**)malloc(sizeof(int*)*NO_OF_TERM_NONTERM);
	
	int**fst;
	
	for(x=0;x<NO_OF_TERM_NONTERM;x++)
	{
		fol[x] = (int*)malloc(sizeof(int)*NO_OF_TERM_NONTERM);
		for(y=0;y<NO_OF_TERM_NONTERM;y++)
		{
			fol[x][y] = 0;
		}
	}
    
    if(option==1)
    {
    	Buffer b = (char*)malloc(sizeof(char)*MAX_LENGTH);
		FILE* fp = fopen(argv[1],"r");
		
		fileState *fs = (fileState*)malloc(sizeof(fileState));
		
		fs->buffer = NULL;
		fs->filename = argv[1];
		tokenInfo ti;
		
		ti =  getNextToken(fp,fs);
		
		while(!(ti.token_type==NONE))
		{
		    //printToken(ti);
		    if(ti.token_type!=ERROR)
		    	printf("%s %s\n",reverseTranslate(ti.token_type),ti.read_string);
		    ti =  getNextToken(fp,fs);
		}
    }
    else if(option==2)
    {
    	grammar g = (grammar)populateGrammar("Grammar.txt");
    	
    	fst = findFirst(g);
    	
		grammar first = convertFirstToGrammar(fst);
		
		findFollow(g, fst, fol);
		
		grammar follow = convertFollowToGrammar(fol);
		
		table tab = (table) createParseTable(g,first,follow);
		
		parseTree* tree =  parseInputSourceCode(argv[1],tab,g,first);
		
		printGrammar(first,0,NO_OF_TERM_NONTERM);
		printGrammar(follow,0,NO_OF_TERM_NONTERM);
		
    }
    else if(option==3)
    {
    	grammar g = (grammar)populateGrammar("Grammar.txt");
    	
    	fst = findFirst(g);
    	
		grammar first = convertFirstToGrammar(fst);
		
		findFollow(g, fst, fol);
		
		grammar follow = convertFollowToGrammar(fol);
		
		table tab = (table) createParseTable(g,first,follow);
		
		parseTree* tree =  parseInputSourceCode(argv[1],tab,g,first);
    	
    	if(tree!=NULL)
    	{
    		printParseTree(tree,argv[2]);
    		printf("Tree has been printed to %s\n",argv[2]);
		}
    	else printf("Tree could not be generated due to parsing errors.\n");
	}
	else
	{
		printf("Incorrect option. Try Again\n");
	}
    
    return 0;
}
