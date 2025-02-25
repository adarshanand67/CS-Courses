%option noyywrap

/* Adarsh Anand - 2003101 */

%{
    int maxLength = 0;
    char maxString[1000];
%}

digit [0-9]
alphabet [a-zA-Z]
alphanumeric {digit}|{alphabet}
letter {alphabet}+
float [+-]?{digit}+\.?{digit}*

%%
{alphabet}{alphanumeric}+ {
    int length = strlen(yytext);
    printf("Identifier: %s - length: %d \n", yytext, length);
    if (length > maxLength) {
        maxLength = length;
        strcpy(maxString, yytext);
    }
}

{float} {
    printf("Identifier: %s - length: %d \n", yytext, strlen(yytext));
}

.|\n { }
%%
int main() {
    yylex();
    printf("Longest identifier: %d -> %s \n", maxLength, maxString);
    return 0;
}