%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include <bits/stdc++.h>
using namespace std;

int yylex(void);
int yyerror(char *);

void createNewSymbolTableEntry();
void destroySymbolTableEntry();

void addSymbolTableEntry(string a, string b);
string getTypeFromSymbolTableEntry(string a);

struct TypeCheckResult {
    bool hasMismatch;
    string errorMessage;
};
TypeCheckResult checkTypes(string a, string b);

struct newType {
    string type;
    string errorMessage;
};
newType newResultantType(string a, string b);

void printSymbolTableEntry();

typedef struct TableEntry
{
  string id;
  string type;
} TableEntry;

vector<TableEntry> tableEntry(26);
stack<vector<TableEntry>> symbolTableEntry;

string varType;
%}

%union {
	double dval;
    int vblno;
    char vblid[10];
    char vbltype[10];
};

%token INT FLOAT CHAR BOOL SEMICOLON COMMA RELOP LOGOP WHILE IF ELSE FOR
%token <vblid> ID
%token <dval>  INT_CONST FLOAT_CONST
%type <vbltype> EXP TERM FACTOR
%left '+' '-'
%left '*' '/'
%left LOGOP
%nonassoc RELOP
%%

prog : funcDef { printf("Accepted✅\n"); }

funcDef : type ID {createNewSymbolTableEntry();} '(' argList ')' '{' declList stmtList '}' {destroySymbolTableEntry();}

argList : arg ',' arg | arg | ;
arg : type ID
    ;

type : INT { varType = "int"; }
    | FLOAT { varType = "float"; }
    | BOOL { varType = "bool"; }
    ;
declList : declList decl | decl;
decl : type varList SEMICOLON ;

varList : ID COMMA varList { addSymbolTableEntry(varType, $1); }
        | ID { addSymbolTableEntry(varType, $1); };

stmtList : stmtList stmt | stmt;
stmt : assignStmt SEMICOLON | ifStmt | whileStmt | forStmt;

assignStmt : type ID '=' EXP { addSymbolTableEntry(varType, $2); if(checkTypes(varType, $4).hasMismatch) { cout << "ERROR: TYPE MISMATCH!\n";} }
           | ID '=' EXP { string ID_type = getTypeFromSymbolTableEntry($1); if(ID_type == "") {cout << "ERROR: " << $1 << " called without declaration\n";}
            else { if(checkTypes(ID_type, $3).hasMismatch) { cout << "ERROR: TYPE MISMATCH!\n";} } }
           ;
EXP : EXP '+' TERM { strcpy($$, newResultantType($1, $3).type.c_str()); }
    | EXP '-' TERM { strcpy($$, newResultantType($1, $3).type.c_str()); }
    | TERM { strcpy($$, $1); }
    ;
TERM : TERM '*' FACTOR { strcpy($$, newResultantType($1, $3).type.c_str()); }
    | TERM '/' FACTOR { strcpy($$, newResultantType($1, $3).type.c_str()); }
    | FACTOR { strcpy($$, $1); }
    ;
FACTOR : ID  { string ID_type = getTypeFromSymbolTableEntry($1); if(ID_type == "") {cout << "ERROR: " << $1 << " called without declaration\n";}
                else { strcpy($$, ID_type.c_str()); cout << $$ << "\n";} }
    | INT_CONST { strcpy($$, "int");}
    | FLOAT_CONST { strcpy($$, "float"); }
    ;
bExp : bExp LOGOP bExp | EXP RELOP EXP;

ifStmt : IF'(' bExp ')' '{' {createNewSymbolTableEntry();} stmtList {destroySymbolTableEntry();} '}' elseStmt;

elseStmt : ELSE '{' {createNewSymbolTableEntry();} stmtList {destroySymbolTableEntry();} '}' | ELSE ifStmt | ;

whileStmt : WHILE '(' bExp ')' '{' {createNewSymbolTableEntry();} stmtList {destroySymbolTableEntry();} '}';

forStmt : FOR '(' assignStmt SEMICOLON bExp SEMICOLON assignStmt ')' '{' {createNewSymbolTableEntry();} stmtList {destroySymbolTableEntry();} '}';

%%


int main(int argc, char **argv)
{
    yyparse();
    printSymbolTableEntry();
}


// This function returns the type of the identifier passed as an argument.
string getTypeFromSymbolTableEntry(string id) {
    // Variable to store the type of the identifier.
    string ans = "";
    // Variable to store the index of the identifier in the symbol table.
    int name = id[0] - 'a';
    // Variable to store the symbol table.
    stack<vector<TableEntry>> temp;

    // Loop until the symbol table is empty.
    while (!symbolTableEntry.empty()) {
        // Get the top entry of the symbol table.
        vector<TableEntry> topSymTableEntry = symbolTableEntry.top();
        // Push the top entry of the symbol table to the temporary symbol table.
        temp.push(topSymTableEntry);
        // Pop the top entry of the symbol table.
        symbolTableEntry.pop();

        // Check if the identifier is present in the symbol table.
        if (topSymTableEntry[name].id != "") {
            // If the identifier is present in the symbol table, store its type in the variable.
            ans = topSymTableEntry[name].type;
            // Exit the loop.
            break;
        }
    }

    // Loop until the temporary symbol table is empty.
    while (!temp.empty()) {
        // Get the top entry of the temporary symbol table.
        vector<TableEntry> topSymTableEntry = temp.top();
        // Push the top entry of the temporary symbol table to the symbol table.
        symbolTableEntry.push(topSymTableEntry);
        // Pop the top entry of the temporary symbol table.
        temp.pop();
    }

    // Return the type of the identifier.
    return ans;
}

void createNewSymbolTableEntry()
{
    // create a new symbol table entry
    vector<TableEntry> tableEntry_new(26);

    // push it onto the stack
    symbolTableEntry.push(tableEntry_new);
}


void destroySymbolTableEntry()
{
    // pop the top symbol table entry off the stack
    symbolTableEntry.pop();
}

void addSymbolTableEntry(string type, string id)
{
    // Check that the symbol table is not empty
    if (symbolTableEntry.empty()) {
        cout << "ERROR: No symbol tableEntry found for variable" << id << endl;
        return;
    }

    // Get the top symbol table from the stack
    vector<TableEntry> &topSymTableEntry = symbolTableEntry.top();
    // Get the symbol table index for the variable name
    int name = id[0] - 'a';
    // Check that the variable name has not been used already
    if (topSymTableEntry[name].id != "") {
        cout << "ERROR: Variable " << id << " has already been declared in the current scope" << endl;
        return;
    }

    // Add the variable to the symbol table
    topSymTableEntry[name].id = id;
    topSymTableEntry[name].type = type;
    cout << "topSymTableEntry[" << name << "]= (" << id << ", " << type << ")\n";
}

newType newResultantType(string a, string b) // function newResultantType with two arguments
{
    newType result; // creates new type called result
    result.type = ""; // sets type of result to nothing
    result.errorMessage = ""; // sets error message of result to nothing

    if(a == b) { // if a is equal to b
        result.type = a; // set result type to a
        return result; // return result
    }
    if(a == "bool") { // if a is equal to bool
        result.type = b; // set result type to b
        return result; // return result
    }
    if(b == "bool") { // if b is equal to bool
        result.type = a; // set result type to a
        return result; // return result
    }
    if(a == "int") { // if a is equal to int
        result.type = b; // set result type to b
        return result; // return result
    }
    result.type = a; // set result type to a
    return result; // return result
}


// 1. Declare the function
TypeCheckResult checkTypes(string type1, string type2)
{
    // 2. Declare a local variable to hold the result
    TypeCheckResult result;
    // 3. Initialize the result
    result.hasMismatch = false;
    result.errorMessage = "";

    // 4. Check for a mismatch between the two types and set the result accordingly
    if (type1 != type2) {
        if (type1 == "bool" || type2 == "bool") {
            result.hasMismatch = true;
            result.errorMessage = "Error: type mismatch between bool and " + (type1 == "bool" ? type2 : type1) + ".";
        } else if (type1 == "int" || type2 == "int") {
            result.hasMismatch = true;
            result.errorMessage = "Error: type mismatch between int and " + (type1 == "int" ? type2 : type1) + ".";
        }
    }

    // 5. Return the result
    return result;
}

void printSymbolTableEntry(){
    // create a temporary stack to hold the symbol table entries
    stack<vector<TableEntry>> temp;
    // while the symbol table entries stack is not empty
    while(!symbolTableEntry.empty()){
        // get the top of the symbol table entries stack
        vector<TableEntry> topSymTableEntry = symbolTableEntry.top();
        // push the top of the symbol table entries stack onto the temporary stack
        temp.push(topSymTableEntry);
        // pop the top of the symbol table entries stack
        symbolTableEntry.pop();
    }
    // while the temporary stack is not empty
    while(!temp.empty()){
        // get the top of the temporary stack
        vector<TableEntry> topSymTableEntry = temp.top();
        // push the top of the symbol table entries stack onto the symbol table entries stack
        symbolTableEntry.push(topSymTableEntry);
        // pop the top of the temporary stack
        temp.pop();
        // for each entry in the symbol table
        for(int i = 0; i < 26; i++){
            // if the id of the symbol table entry is not empty
            if(topSymTableEntry[i].id != ""){
                // print the symbol table entry
                cout << "topSymTableEntry[" << i << "]= (" << topSymTableEntry[i].id << ", " << topSymTableEntry[i].type << ")\n";
            }
        }
    }
}


int yyerror(char *s)
{
    fprintf(stderr, "An error in the parser : %s\n", s);
}

