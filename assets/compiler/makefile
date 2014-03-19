# Group no : 34
# Punit Singh Koura
# Manas Chauhan

driver: driver.c lexer.o parser.o Grammar.txt
	gcc -o  driver driver.c lexer.o parser.o

lexer.o: lexer.c lexerDef.h lexer.h
	gcc -c lexer.c
	
parser.o: parser.c parserDef.h lexerDef.h parser.h
	gcc -c parser.c
