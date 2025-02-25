%{

#include <stdio.h>

int yylex(void);
int yyerror(char*);

%}
%token name number

%%
/* E → E + E|E ∗ E|id */
expr: expr '+' expr {  } /* E → E + E */
    | expr '*' expr {  } /* E → E ∗ E */
    | id {} /* E → id */
    ;

id : name {  }  /* id → name */
   | number {  }    /* id → number */
   ;

%%

int main(int argc, char **argv) {
	yyparse();
}

int yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}
