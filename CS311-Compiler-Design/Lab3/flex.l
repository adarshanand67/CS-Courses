%{
  #include <bits/stdc++.h>
  #include <string.h>
  #include <iostream>
  using namespace std;
  #define MAX_VAR_LEN 31

  #define MAX 300
  std::map<string, int> mp; /* symbol table */

  void add_sym_tab(string word); /* add entry to symbol table */

  bool is_valid_var(const char *var); /* check if variable name is valid */

%}


%%


"short"|"float"|"double"|"bool"|"char"|"signed"|"unsigned"|"for"|"while"|"do"|"return"|"void"|"switch"|"break"|"case"|"continue"|"goto"|"long"|"static"|"union"|"default"|"class"|"public"|"private"|"protected" {printf("Keyword: %s\n", yytext);} /* 2. Keywords */


[a-zA-Z_][a-zA-Z0-9_]* {
    /* check if Identifier is valid or not */
    if (is_valid_var(yytext)) {
        printf("Identifier: %s\n", yytext);
        add_sym_tab(yytext);
    } else {
        printf("Error: Invalid variable name %s\n as it exceeds the maximum length of %d characters", yytext, MAX_VAR_LEN);
    }
}  /* 1. Identifiers */



-?[0-9]+ {printf("Integer constant: %s\n", yytext);} /* 3. Integer constants */

-?[0-9]*\.[0-9]+ {printf("Floating point constant: %s\n", yytext);} /* 4. Floating point constants */

"="|"+="|"-="|"*="|"/=" {printf("Arithmetic operator: %s\n", yytext);} /* 5. Arithmetic operators */

"<"|">"|"<="|">="|"==" {printf("Relational operator: %s\n", yytext);} /* 6. Relational operators */

";"|"("|")"|","|"["|"]"|"{"|"}" {printf("Special symbol: %s\n", yytext);} /* 7. Special symbols */


\/\*.*\*\/ { printf("Comments are ignored\n"); } /* Comments */

[ \t\r\n]+ { printf("Whitespace are ignored\n"); } /* White space */

. { printf("Invalid character %s\n", yytext); }  /* Invalid characters */

%%

bool is_valid_var(const char *var) {
    return strlen(var) <= MAX_VAR_LEN;
}

void add_sym_tab(string word){
    if(mp.find(word) == mp.end()){
        mp[word] = 1;
    }
    else{
        mp[word]++;
    }
}

void print_sym_tab(){
    for(auto it = mp.begin(); it != mp.end(); it++){
        printf("%s ", it->first.c_str());
    }
}


int main(int argc, char *argv[]) {
    yylex();
    printf("Number of entries in symbol table: %d\n", mp.size());
    printf("Symbol table: ");
    print_sym_tab();
    printf("\n");
    return 0;
}
