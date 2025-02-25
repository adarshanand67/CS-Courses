%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
%}


%token ID INTEGER_CONSTANT FLOAT_CONSTANT INT FLOAT CHAR SEMICOLON COMMA ASSIGN IF ELSE AND OR NOT EQ GE LE LT GT NE WHILE RETURN

%%
prog: funcDef { printf("Accepted✅\n"); }

funcDef: type ID '(' argList ')' '{' declList stmtList '}' { printf("The rule with type, ID, argList, declList and stmtList is triggered\n"); }

argList: arg ',' arg { printf("The rule with arg and comma is triggered\n"); }
| /* epsilon */ { printf("The rule with epsilon is triggered\n"); }

arg: type ID { printf("The rule with type and ID is triggered\n"); }

declList: decl SEMICOLON declList  { printf("The rule with declList, SEMICOLON and decl is triggered\n"); }
| /* epsilon */ { printf("The rule with epsilon is triggered\n"); }

decl: type varList { printf("The rule with type and varList is triggered\n"); }

varList: ID COMMA varList { printf("The rule with ID and varList is triggered\n"); }
| ID { printf("The rule with ID is triggered\n"); }

type: INT { printf("The rule with INT is triggered\n"); }
| FLOAT { printf("The rule with FLOAT is triggered\n"); }
| CHAR { printf("The rule with CHAR is triggered\n"); }

stmtList: /* epsilon */ { printf("The rule with epsilon is triggered\n"); }
%%

int main()
{
    yyparse();
}


int yyerror(char *s)
{
    fprintf(stderr, "An error in the parser : %s\n", s);
}