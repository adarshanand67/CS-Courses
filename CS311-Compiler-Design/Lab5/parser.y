%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
%}

%union {
	double dval; // dval = double value
    int    vblno; // vblno = variable number
    char str[100]; // str = string
};


%token INT FLOAT CHAR SEMICOLON COMMA ASSIGN IF ELSE AND OR NOT WHILE RELOP
INTEGER_CONSTANT FLOAT_CONSTANT CHAR_CONSTANT STRING_CONSTANT FOR INCREMENT DECREMENT

%token <str> ID

%left '+' '-' /* 1 */
%left '*' '/' /* 2 */

%%
prog: funcDef { printf("Accepted✅\n"); }

funcDef: type ID '(' argList ')' '{' declList stmtList '}' { printf("The rule with type, ID, argList, declList and stmtList is triggered\n"); } /* int main() { } */

argList: arg ',' arg { printf("The rule with arg and comma is triggered\n"); }
| /* epsilon */ { printf("The rule with epsilon is triggered\n"); } /* int main() */

arg: type ID { printf("The rule with type and ID is triggered\n"); } /* int a */

declList: decl SEMICOLON declList  { printf("The rule with declList, SEMICOLON and decl is triggered\n"); } /* int a;int b; */
| /* epsilon */ { printf("The rule with epsilon is triggered\n"); }

decl: type varList { printf("The rule with type and varList is triggered\n"); } /* int a,b,c; */

varList: ID COMMA varList { printf("The rule with ID and varList is triggered\n");
addEntry($1, varType.c_str()); } /* int a,b,c; */
| ID { printf("The rule with ID is triggered\n");
addEntry($1, varType.c_str());
 } /* int a,b,c; */

type: INT { printf("The rule with INT is triggered\n"); strcpy(varType, "int"); } /* int a; */
| FLOAT { printf("The rule with FLOAT is triggered\n"); strcpy(varType, "float"); } /* float a; */
| CHAR { printf("The rule with CHAR is triggered\n"); strcpy(varType, "char"); } /* char a; */

stmtList: stmtList stmt { printf("The rule with stmtList and stmt is triggered\n"); }
| stmt { printf("The rule with stmt is triggered\n"); }

stmt: assignStmt { printf("The rule with assignStmt is triggered\n"); } /* a = 10; */
| ifStmt { printf("The rule with ifStmt is triggered\n"); } /* if(a==10) { } */
| whileStmt { printf("The rule with whileStmt is triggered\n"); }   /* while(a==10) { } */
| forStmt { printf("The rule with forStmt is triggered\n"); }   /* for(a=1;a<10;a++) { } */

assignStmt: ID ASSIGN EXP SEMICOLON { printf("The rule with ID, ASSIGN, EXP and SEMICOLON is triggered\n"); } /* a = 10; */
| ID INCREMENT SEMICOLON { printf("The rule with ID, INCREMENT and SEMICOLON is triggered\n"); } /* a++; */
| ID DECREMENT SEMICOLON { printf("The rule with ID, DECREMENT and SEMICOLON is triggered\n"); } /* a--; */

EXP: EXP '+' TERM { printf("The rule with EXP, +, TERM is triggered\n"); } /* a = 10 + 20; */
| EXP '-' TERM { printf("The rule with EXP, -, TERM is triggered\n"); } /* a = 10 - 20; */
| TERM { printf("The rule with TERM is triggered\n"); } /* a = 10; */

TERM: TERM '*' FACTOR { printf("The rule with TERM, *, FACTOR is triggered\n"); }   /* a = 10 * 20; */
| TERM '/' FACTOR { printf("The rule with TERM, /, FACTOR is triggered\n"); }   /* a = 10 / 20; */
| FACTOR { printf("The rule with FACTOR is triggered\n"); } /* a */

FACTOR: ID { printf("The rule with ID is triggered\n"); }   /* a */
| INTEGER_CONSTANT { printf("The rule with INTEGER_CONSTANT is triggered\n"); }   /* 10 */
| FLOAT_CONSTANT { printf("The rule with FLOAT_CONSTANT is triggered\n"); }   /* 10.0 */
| CHAR_CONSTANT { printf("The rule with CHAR_CONSTANT is triggered\n"); }   /* 'a' */
| STRING_CONSTANT { printf("The rule with STRING_CONSTANT is triggered\n"); }   /* "Hello" */
| '(' EXP ')' { printf("The rule with (, EXP and ) is triggered\n"); }   /* (a) */

ifStmt: IF '(' bExp ')' '{' stmtList '}' { printf("The rule with IF, bExp, stmtList is triggered\n"); }
/* if(a==10) { } */
| IF '(' bExp ')' '{' stmtList '}' ELSE '{' stmtList '}' { printf("The rule with IF, bExp, stmtList, ELSE and stmtList is triggered\n"); }
/* if(a==10) { } else { } */
| IF '(' bExp ')' '{' stmtList '}' ELSE IF '(' bExp ')' '{' stmtList '}' ELSE '{' stmtList '}' { printf("The rule with IF, bExp, stmtList, ELSE, IF, bExp, stmtList and ELSE is triggered\n"); }
/* if(a==10) { } else if(a==20) { } else { } */


bExp: EXP RELOP EXP { printf("The rule with EXP, RELOP and EXP is triggered\n"); } /* a==10 */
| bExp AND bExp { printf("The rule with bExp, AND and bExp is triggered\n"); } /* a==10 && b==20 */
| bExp OR bExp { printf("The rule with bExp, OR and bExp is triggered\n"); } /* a==10 || b==20 */
| NOT bExp { printf("The rule with NOT and bExp is triggered\n"); } /* !(a==10) */

whileStmt: WHILE '(' bExp ')' '{' stmtList '}' { printf("The rule with WHILE, bExp and stmtList is triggered\n"); } /* while(a==10) { } */


forStmt: FOR '(' assignStmt bExp SEMICOLON ID ASSIGN EXP ')' '{' stmtList '}' { printf("The rule with FOR, assignStmt, bExp, assignStmt, stmtList is triggered\n"); } /* for(int i =0;i<n;i++) */

%%
int main()
{
    yyparse();
}


int yyerror(char *s)
{
    fprintf(stderr, "An error in the parser : %s\n", s);
}