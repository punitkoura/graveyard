/**
	lexer.c
	
	Group no : 34
	Punit Singh Koura
	Manas Chauhan
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"

/**
	We can uncomment the next line to view debugging information on the
	tokens being tokenized.
*/

//#define ENABLE_DEBUG 1

int printfDummy(char* a,...)
{
    //nothing
    return 0;
}

#if defined ENABLE_DEBUG
#define debugPrint printf
#else
#define debugPrint printfDummy
#endif

const char* keyword[11] = {"end","int","real","string","matrix","if","else","endif","read","print","function"};

const char alphabets[52] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

const char numbers[10] = "0123456789";


const token_type_enum keywordbase = END;

size_t getStream(FILE* fp, Buffer B,BufferSize k)
{
	size_t size =  fread(B, sizeof(char), k, fp);
	if(feof(fp))
	{
	    B[size] = '$';
    }
    size++;
	return size;
}





tokenInfo makeToken(int lineno, int colmno, token_type_enum token_type, 
     char* read_string)
{
    tokenInfo newToken;
    newToken.cur_line = lineno;	
	newToken.cur_pos = colmno;
	
	newToken.token_type = token_type;
	
	newToken.int_val = 0;
	newToken.real_val = 0.0;
	strcpy(newToken.read_string,read_string);
	
	if(token_type==NUM)
	{
	    newToken.int_val = atoi(read_string);
    }
	   
	else if(token_type==RNUM)    
	{
	    newToken.real_val = atof(read_string);
    }
	
	return newToken;
}


boolean isInside(char c,const char* arr, int lo, int hi)
//Checks if the character c is in arr
{
    
    if(lo>hi) return false;
    
    int mid = (lo+hi)/2;
    if(c==arr[mid])
        return true;
    
    if(c>arr[mid])
        return isInside(c,arr,mid+1,hi);
    else 
        return isInside(c,arr,lo,mid-1);
    
}



token_type_enum checkKeyword(char* temp)
{
    int x;
    
    for(x=0;x<11;x++)
    {
        if(strcmp(temp,keyword[x])==0)
        {
            return keywordbase+x;
        }
    }
    return ID;
}


void printToken(tokenInfo head)
{

    debugPrint("line %d colm %d token_type %d read_string %s int %d real %.2f\n",
    head.cur_line,head.cur_pos,head.token_type,
    head.read_string,head.int_val,head.real_val);

    return;
}


int updateFileState(FILE* fp,fileState *fstate)
{
    if(fstate->buffer[fstate->lookahead]=='\n')
    {
        fstate->colmno = 1;
        fstate->lineno++;
    }
    else
    {
        fstate->colmno++;
    }
    
    fstate->lookahead++;
    
    
    if(fstate->lookahead==fstate->size-1)
    {
        fstate->size = getStream(fp,fstate->buffer,MAX_LENGTH);
        //if(fstate->size==0) return 1;
        fstate->lookahead = 0;
    }
    return 0;
}
    


tokenInfo getNextToken(FILE* fp, fileState* fstate)
{
    //size_t size;
    
    if(fstate->buffer==NULL)
    {
        fstate->buffer = (char*)malloc(sizeof(char)*MAX_LENGTH);
        fstate->size = getStream(fp,fstate->buffer,MAX_LENGTH);
        fstate->lookahead = 0;
        fstate->lineno = 1;
        fstate->colmno = 1;
    }
    
    Buffer temp = (Buffer)malloc(sizeof(char)*MAX_LENGTH_TOKEN);
    
    
    
    state mystate;
    mystate = start;
    
    int bufferIndex;
    
    int startline;
    int startcolm;

    token_type_enum type = NONE;

    tokenInfo token;
    
    int returnVal;
    int idcount;
    
    while(1)
    {
        switch(mystate)
        {
            case start:
            startlabel:
                startline = fstate->lineno;
                startcolm = fstate->colmno;
                idcount=0;
                bufferIndex = 0;
                if(fstate->buffer[fstate->lookahead]=='=')
                    mystate = oneequal;
                else if(fstate->buffer[fstate->lookahead]=='>')
                    mystate = greater;
                else if(fstate->buffer[fstate->lookahead]=='<')
                    mystate = less;
                else if(fstate->buffer[fstate->lookahead]=='@')
                {
                    token = makeToken(startline, startcolm, SIZE, "@");
                    updateFileState(fp,fstate);
                    debugPrint("SIZE\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]=='+')
                {
                    token = makeToken(startline, startcolm, PLUS, "+");
                    updateFileState(fp,fstate);
                    debugPrint("PLUS\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]=='-')
                {
                    token = makeToken(startline, startcolm, MINUS, "-");
                    updateFileState(fp,fstate);
                    debugPrint("MINUS\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]=='*')
                {
                    token = makeToken(startline, startcolm, MUL, "*");
                    updateFileState(fp,fstate);
                    debugPrint("MUL\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]=='/')
                {
                    token = makeToken(startline, startcolm, DIV, "/");
                    updateFileState(fp,fstate);
                    debugPrint("DIV\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]=='[')
                {
                    token = makeToken(startline, startcolm, SQO, "[");
                    updateFileState(fp,fstate);
                    debugPrint("SQO\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]=='(')
                {
                    token = makeToken(startline, startcolm, OP,"(");
                    updateFileState(fp,fstate);
                    debugPrint("OP\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]==']')
                {
                    token = makeToken(startline, startcolm, SQC, "]");
                    updateFileState(fp,fstate);
                    debugPrint("SQC\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]==')')
                {
                    token = makeToken(startline, startcolm, CL, ")");
                    updateFileState(fp,fstate);
                    debugPrint("CL\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]==';')
                {
                    token = makeToken(startline, startcolm, SEMICOLON, ";");
                    updateFileState(fp,fstate);
                    debugPrint("SEMICOLON\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]==',')
                {
                    token = makeToken(startline, startcolm, COMMA, ",");
                    updateFileState(fp,fstate);
                    debugPrint("COMMA\n");
                    return token;
                }
                else if(fstate->buffer[fstate->lookahead]=='#')
                {
                    mystate = dumb;
                }
                else if(fstate->buffer[fstate->lookahead]=='_')
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = funid;
                }
                else if(isInside(fstate->buffer[fstate->lookahead],numbers,0,9))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = num;
                }
                else if(isInside(fstate->buffer[fstate->lookahead],alphabets,0,51))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = id;
                    idcount++;
                }
                else if(fstate->buffer[fstate->lookahead]=='"')
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = stringbegin;
                }
                else if(fstate->buffer[fstate->lookahead]=='.')
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = logicalbegin;
                }
                
                else if(isspace(fstate->buffer[fstate->lookahead]))
                {
                    mystate = start;
                }
                else if(fstate->buffer[fstate->lookahead] == '$')
                {
                    return makeToken(startline,startcolm,NONE,"$");
                }
                else
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    temp[bufferIndex+1] = '\0';
                    mystate = error;
                }
                break;
            
            case error:
                printf("%s:%d:%d:Unknown lexeme %s\n",fstate->filename,startline,startcolm,temp);
                
                if(isspace(fstate->buffer[fstate->lookahead]))
                	goto errorhandle;
                
                mystate = gotowhite;
                bufferIndex = 0;
                break;
                
            case errorid:
                printf("%s:Identifier at %d:%d is longer than 20 characters.\n",fstate->filename,startline,startcolm);
                
                if(isspace(fstate->buffer[fstate->lookahead]))
                	goto errorhandle;
                
                mystate = gotowhite;
                bufferIndex = 0;
                break;
            
            case gotowhite:
            errorhandle:
                if(isspace(fstate->buffer[fstate->lookahead]))
                {
                    //mystate = start;
                    token = makeToken(startline, startcolm, ERROR, temp);
                    updateFileState(fp,fstate);
                    debugPrint("ERROR\n");
                    return token;
                }
                break;
            
            case oneequal:
                if(fstate->buffer[fstate->lookahead]=='=')
                {
                    mystate = start;
                    token = makeToken(startline, startcolm, EQ, "==");
                    updateFileState(fp,fstate);
                    return token;
                    debugPrint("EQ\n");
                }
                    
                else if(fstate->buffer[fstate->lookahead]=='/')
                    mystate = equalnot;
                else
                {
                    token = makeToken(startline, startcolm, ASSIGNOP, "=");
                    
                    debugPrint("ASSIGNOP\n");
                    return token;
                    mystate = start;
                    goto startlabel;
                }
                break;
            
            case greater:
                if(fstate->buffer[fstate->lookahead]=='=')
                {
                    token = makeToken(startline, startcolm, GE, ">=");
                    
                    debugPrint("GE\n");
                    updateFileState(fp,fstate);
                    return token;
                    mystate = start;
                }
                else
                {
                    token = makeToken(startline, startcolm, GT, ">");
                    
                    debugPrint("GT\n");
                    return token;
                    mystate = start;
                    goto startlabel;
                }
                break;
            
            case less:
                if(fstate->buffer[fstate->lookahead]=='=')
                {
                    token = makeToken(startline, startcolm, LE, "<=");
                    
                    debugPrint("LE\n");
                    updateFileState(fp,fstate);
                    return token;
                    mystate = start;
                }
                else
                {
                    token = makeToken(startline, startcolm, LT, "<");
                    
                    debugPrint("LT\n");
                    return token;
                    mystate = start;
                    goto startlabel;
                }
                break;
            
            case equalnot:
                if(fstate->buffer[fstate->lookahead]=='=')
                {
                    token = makeToken(startline, startcolm, NE, "=/=");
                    
                    debugPrint("NE\n");
                    updateFileState(fp,fstate);
                    return token;
                    mystate = start;
                }
                else
                {
                    mystate = error;
                }
                break;
            
            case funid:
                if(isInside(fstate->buffer[fstate->lookahead],alphabets,0,51))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = funidalpha;
                }
                else
                {
                    mystate = error;
                }
                break;
                
                    
            case funidalpha:
                if(isInside(fstate->buffer[fstate->lookahead],alphabets,0,51)||
                    isInside(fstate->buffer[fstate->lookahead],numbers,0,9))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = funidalpha;
                }
                else
                {
                    temp[bufferIndex] = '\0';
                    bufferIndex = 0;
                    
                    if(strcmp(temp,"_main")==0)
                        type = MAIN;
                    else
                        type = FUNID;
                    
                    token = makeToken(startline, startcolm, type, temp);
                    
                                        
                    debugPrint("FUNID %s\n",temp);
                    return token;
                    /*
                    mystate = start;
                    goto startlabel;
                    */
                }
                break;
                
            case id:
                if(isInside(fstate->buffer[fstate->lookahead],alphabets,0,51))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = id;
                    idcount++;
                    if(idcount>20)
                    {
                        mystate=errorid;
                        break;
                    }
                }
                else if(isInside(fstate->buffer[fstate->lookahead],numbers,0,9))
                {
                	temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = idnum;
                    idcount++;
                    if(idcount>20)
                    {
                        mystate=errorid;
                        break;
                    }
                    
                	
                }
                else
                {
                    temp[bufferIndex] = '\0';
                    bufferIndex = 0;
                    
                    idcount++;
                    
                    
                    type = checkKeyword(temp);
                    
                    token = makeToken(startline, startcolm, type, temp);
                    
                    
                    debugPrint("ID %s\n",temp);
                    return token;
                    mystate = start;
                    goto startlabel;
                }
                break;
            
            case idnum:
            	if(isInside(fstate->buffer[fstate->lookahead],numbers,0,9))
            	{
            		temp[bufferIndex] = fstate->buffer[fstate->lookahead];
            		temp[bufferIndex+1] = '\0';
                    bufferIndex = 0;
                    
            		mystate=error;
            		break;
        		}
        		else
        		{
                    temp[bufferIndex] = '\0';
                    bufferIndex = 0;
                    idcount++;
                    
                    token = makeToken(startline, startcolm, ID, temp);
                    debugPrint("ID %s\n",temp);
                    //updateFileState(fp,fstate);
                    return token;
                    
                    
                    mystate = start;
        		}
        		break;
        		
        			
            
            case dumb:
                if(fstate->buffer[fstate->lookahead]=='\n')
                mystate = start;
                break;
                
            case stringbegin:
                if(isInside(fstate->buffer[fstate->lookahead],alphabets,0,51))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = stringbeginalpha;
                }
                else if(isspace(fstate->buffer[fstate->lookahead]))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = stringbeginalpha;
                }
                else
                {
                    mystate = error;
                }
                
                break;
                
            case stringbeginalpha:
                if(isInside(fstate->buffer[fstate->lookahead],alphabets,0,51))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = stringbeginalpha;
                }
                else if(fstate->buffer[fstate->lookahead]=='"')
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    temp[bufferIndex+1] = '\0';
                    bufferIndex = 0;
                    
                    token = makeToken(startline, startcolm, STR, temp);
                    
                    
                    debugPrint("STR %s\n",temp);
                    updateFileState(fp,fstate);
                    return token;
                    mystate = start;
                }
                else if(isspace(fstate->buffer[fstate->lookahead]))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = stringbeginalpha;
                }
                else
                {
                    mystate = error;
                }
                break;
                
            case logicalbegin:
                if(isInside(fstate->buffer[fstate->lookahead],alphabets,0,51))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = logicalalpha;
                }
                else
                {
                    mystate = error;
                }   
                
                break;
            
            case logicalalpha:
                if(isInside(fstate->buffer[fstate->lookahead],alphabets,0,51))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = logicalalpha;
                }
                
                else if(fstate->buffer[fstate->lookahead]=='.')
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    temp[bufferIndex+1] = '\0';
                    bufferIndex = 0;
                    
                    if(strcmp(temp,".and.")==0)
                    {
                        type = AND;
                    }
                    else if(strcmp(temp,".or.")==0)
                    {
                        type = OR;
                    }
                    else if(strcmp(temp,".not.")==0)
                    {
                        type = NOT;
                    }
                    else
                        type = NONE;
                    
                    
                    if(type==NONE)
                    {
                        mystate = error;
                    }
                    else
                    {
                        debugPrint("LogicalOp %s\n",temp);
                        token = makeToken(startline, startcolm, type, temp);
                        updateFileState(fp,fstate);
                        return token;
                        mystate = start;
                    }
                    
                }
                else
                {
                    mystate = error;
                }
                break;
            
            case num:
                if(isInside(fstate->buffer[fstate->lookahead],numbers,0,9))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = num;
                }
                else if(fstate->buffer[fstate->lookahead]=='.')
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = numdot;
                }
                else
                {
                    temp[bufferIndex] = '\0';
                    bufferIndex=0;
                    
                    token = makeToken(startline, startcolm, NUM, temp);
                    
                    
                    debugPrint("NUM %s\n",temp);
                    return token;
                    mystate = start;
                    goto startlabel;
                }
                break;
            
            case numdot:
                if(isInside(fstate->buffer[fstate->lookahead],numbers,0,9))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    bufferIndex++;
                    mystate = numdot1;
                }
                else if(isInside(fstate->buffer[fstate->lookahead],alphabets,0,51))
                {
                    temp[--bufferIndex] = '\0';
                    bufferIndex = 0;
                    
                    token = makeToken(startline, startcolm, NUM, temp);
                    debugPrint("NUM %s\n",temp);
                    
                    fstate->lookahead--;
                    return token;
                }
                else
                {
                    mystate = error;
                }
                break;
                
            case numdot1:
                if(isInside(fstate->buffer[fstate->lookahead],numbers,0,9))
                {
                    temp[bufferIndex] = fstate->buffer[fstate->lookahead];
                    temp[bufferIndex+1] = '\0';
                    bufferIndex = 0;
                    
                    token = makeToken(startline, startcolm, RNUM, temp);
                    debugPrint("RNUM %s\n",temp);
                    updateFileState(fp,fstate);
                    return token;
                    mystate = start;
                }
                else
                {
                    mystate = error;
                }
                break;
            
            
        }
        
        updateFileState(fp,fstate);
    }
    
    
}
