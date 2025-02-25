%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

%%
[ \t]+ ;
\n           { printf("A newline is detected\n"); }
"+"          { printf("An operator %s is detected\n", yytext); return yytext[0];}
"*"          { printf("An operator %s is detected\n", yytext); return yytext[0];}
\/          { printf("An operator %s is detected\n", yytext); return yytext[0];}
"int"        { printf("An int declaration is detected\n"); return INT; }
"float"      { printf("A float declaration is detected\n"); return FLOAT; }
"char"      { printf("A char declaration is detected\n"); return CHAR; }
";"         { printf("A semicolon is detected\n"); return SEMICOLON; }
","         { printf("A comma is detected\n"); return COMMA; }
"="          { printf("An assignment operator is detected\n"); return ASSIGN; }
"if"         { printf("An if statement is detected\n"); return IF; }
"else"       { printf("An else statement is detected\n"); return ELSE; }
"&&"         { printf("An AND operator is detected\n"); return AND; }
"||"         { printf("An OR operator is detected\n"); return OR; }
"!"          { printf("A NOT operator is detected\n"); return NOT; }
"=="         { printf("An equality operator is detected\n"); return EQ; }
">="         { printf("A greater than or equal to operator is detected\n"); return GE; }
"<="         { printf("A less than or equal to operator is detected\n"); return LE; }
"<"          { printf("A less than operator is detected\n"); return LT; }
">"          { printf("A greater than operator is detected\n"); return GT; }
"!="         { printf("A not equal operator is detected\n"); return NE; }
"while"      { printf("A while loop is detected\n"); return WHILE; }
"return"     { printf("A return statement is detected\n"); return RETURN; }
[A-Za-z]+    { printf("An identifier %s is detected\n", yytext); return ID; }
[0-9]+       { printf("An integer constant %s is detected\n", yytext); return INTEGER_CONSTANT;}
[0-9]+.[0-9]+ { printf("A float constant %s is detected\n", yytext); return FLOAT_CONSTANT;}
.            { printf("Other character %s is detected\n", yytext); return yytext[0];}
%%
