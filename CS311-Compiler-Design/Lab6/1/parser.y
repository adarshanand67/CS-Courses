%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <ostream>
#include "parser.tab.h"
using namespace std;

int yylex(void);
int yyerror(char *);

// Symbol Table
map<string, string> symbolTable;//{ "a", "int"}


void addEntry(string name, string type) {
    symbolTable[name] = type;
}

void printSymbolTable() {
    cout << "Symbol Table: " << endl;
    for (auto it = symbolTable.begin(); it != symbolTable.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void checkId(string id) {
    // Check if id exists in symbol table
    if (symbolTable.find(id) == symbolTable.end()) {
        cout << " ❗ Error: " << id << " is not declared" << endl;
    }
    cout << "The rule with ID is triggered " << id << endl;
}

void checkExpType(string id1, string id2) {
    // Check if the types of the two expressions are the same
    string type1 = symbolTable[id1];
    string type2 = symbolTable[id2];
    if(type1 != type2) {
        cout << "❗❗ Error: " << id1 << " and " << id2 << " are not of the same type" << endl;
    }
    if(type1=="bool" and type2=="int") {
        cout<< "❗❗ Cant handle bool and int types"<<endl;
    }
    cout<<"Satisfied typechecking with "<<id1<<" and "<<id2<<endl;
}

void checkExpWithType(string id1, string type) {
    // Check if the types of the two expressions are the same
    string type1 = symbolTable[id1];
    // string type2 = symbolTable[id2];
    if(type1 != type) {
        cout << "❗❗ Error: " << id1 << " and " << type << " are not of the same type" << endl;
    }
    if(type1=="bool" and type=="int") {
        cout<< "❗❗ Cant handle bool and int types"<<endl;
    }
    cout<<"Satisfied typechecking with "<<id1<<" and "<<type<<endl;
}
string varType;
%}


%union {
	double dval; // dval = double value
    int    vblno; // vblno = variable number
    char str[100]; // str = string
    char type[100]; // type = type of variable
};


%token INT FLOAT CHAR SEMICOLON COMMA ASSIGN IF ELSE AND OR NOT WHILE RELOP BOOLEAN
INTEGER_CONSTANT FLOAT_CONSTANT CHAR_CONSTANT FOR

%token <str> ID

%left '+' '-' /* 1 */
%left '*' '/' /* 2 */

%type <type> EXP TERM FACTOR // EXP = expression, TERM = term, FACTOR = factor

%%
prog: funcDef { printf("Accepted✅\n\n"); }

funcDef: type ID '(' argList ')' '{' declList stmtList '}'

argList: arg ',' arg
| /* epsilon */

arg: type ID

declList: decl SEMICOLON declList
| /* epsilon */

decl: type varList

varList: ID COMMA varList { addEntry($1, varType.c_str()); } /* int a,b,c; */
| ID { addEntry($1, varType.c_str()); } /* int a; */

type: INT {varType = "int";} /* int */
| FLOAT { varType = "float"; } /* float */
| CHAR { varType = "char"; } /* char */
| BOOLEAN { varType = "bool"; } /* boolean */


stmtList: stmt stmtList | stmt

stmt: assignStmt | ifStmt | whileStmt | forStmt |

<<<<<<< Updated upstream
assignStmt: ID ASSIGN EXP SEMICOLON { checkId($1);} /* a = 10; */
| type ID ASSIGN EXP SEMICOLON { checkId($2);} /* int a = 10; */
=======
assignStmt: ID ASSIGN EXP SEMICOLON { printf("The rule with ID, ASSIGN, EXP and SEMICOLON is triggered\n"); checkId($1); } /* a = 10; */
| ID INCREMENT SEMICOLON { printf("The rule with ID, INCREMENT and SEMICOLON is triggered\n"); checkId($1); } /* a++; */
| ID DECREMENT SEMICOLON { printf("The rule with ID, DECREMENT and SEMICOLON is triggered\n"); checkId($1); } /* a--; */
>>>>>>> Stashed changes

EXP: EXP '+' TERM { checkExpType($1, $3); }   /* a = 10 + 20; */
| EXP '-' TERM { checkExpType($1, $3); }   /* a = 10 - 20; */
| TERM

TERM: TERM '*' FACTOR { checkExpType($1, $3); }   /* a = 10 * 20; */
| TERM '/' FACTOR { checkExpType($1, $3); }   /* a = 10 / 20; */
| FACTOR

<<<<<<< Updated upstream
FACTOR: ID { checkExpType($1, $$); }   /* a */
| INTEGER_CONSTANT { checkExpWithType($$, "int"); }   /* 10 */
| FLOAT_CONSTANT { checkExpWithType($$, "float"); }   /* 10.5 */
| CHAR_CONSTANT { checkExpWithType($$, "char"); }   /* 'a' */
| '(' EXP ')' { checkExpType($2, $$); }   /* (a) */
=======
FACTOR: ID { printf("The rule with ID is triggered\n"); checkExpType($1, $$); }   /* a */
| INTEGER_CONSTANT { printf("The rule with INTEGER_CONSTANT is triggered\n"); checkExpWithType($$, "int"); }   /* 10 */
| FLOAT_CONSTANT { printf("The rule with FLOAT_CONSTANT is triggered\n"); checkExpWithType($$, "float"); }   /* 10.0 */
| CHAR_CONSTANT { printf("The rule with CHAR_CONSTANT is triggered\n"); checkExpWithType($$, "char"); }   /* 'a' */
| '(' EXP ')' { printf("The rule with (, EXP and ) is triggered\n"); }   /* (a) */
>>>>>>> Stashed changes

ifStmt: IF '(' bExp ')' '{' stmtList '}' /* if(a==10) { } */
| IF '(' bExp ')' '{' stmtList '}' ELSE '{' stmtList '}' /* if(a==10) { } else { } */
| IF '(' bExp ')' '{' stmtList '}' ELSE IF '(' bExp ')' '{' stmtList '}' ELSE '{' stmtList '}' /* if(a==10) { } else if(a==20) { } else { } */


bExp: EXP RELOP EXP | bExp AND bExp | bExp OR bExp | NOT bExp

whileStmt: WHILE '(' bExp ')' '{' stmtList '}'

forStmt: FOR '(' assignStmt bExp SEMICOLON ID ASSIGN EXP ')' '{' stmtList '}'

%%
int main()
{
    yyparse();
    printSymbolTable();
}


int yyerror(char *s)
{
    fprintf(stderr, "An error in the parser : %s\n", s);
}