%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    // #include <bits/stdc++.h>
    #include "parser.tab.h"
    using namespace std;
%}

digit [0-9]
letter [a-zA-Z]
underscore [_]
letter_or_digit_or_underscore {digit}|{letter}|{underscore}
letter_or_underscore {letter}|{underscore}

%%
[ \t]+ ;

"while"                                     { printf("Keyword : %s is detected\n", yytext); return WHILE; }
"for"                                       { printf("Keyword : %s is detected\n", yytext); return FOR; }
"if"                                        { printf("Keyword : %s is detected\n", yytext); return IF; }
"else"                                      { printf("Keyword : %s is detected\n", yytext); return ELSE; }

"int"                                       { printf("Type : %s is detected\n", yytext); return INT; }
"float"                                     { printf("Type : %s is detected\n", yytext); return FLOAT; }
"char"                                      { printf("Type : %s is detected\n", yytext); return CHAR; }
"bool"                                      { printf("Type : %s is detected\n", yytext); return BOOL; }

","                                         { printf("Symbol : %s is detected\n",yytext); return COMMA; }
";"                                         { printf("Symbol : %s is detected\n",yytext); return SEMICOLON; }

">"|"<"|">="|"<="|"=="|"!="                 { printf("Relational operator : %s is detected\n", yytext); return RELOP; }
"&&"|"||"|"!"                               { printf("Logical operator : %s is detected\n", yytext); return LOGOP; }

{letter}+                                   { printf("Identifier : %s is detected\n", yytext); strcpy(yylval.vblid, yytext); return ID; }
{digit}+                                    { printf("Integer constant : %s is detected\n", yytext); yylval.dval = atof(yytext); return INT_CONST;}
{digit}+"."{digit}+                         { printf("Floating point constant : %s is detected\n", yytext); yylval.dval = atof(yytext); return FLOAT_CONST; }

\n                                          { }
.                                           { printf("Other Symbol : %s\n", yytext); return yytext[0];}
%%
