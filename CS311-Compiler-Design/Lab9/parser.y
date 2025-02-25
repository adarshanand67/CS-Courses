%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
 #include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int yylex(void);
int yyerror(char *);


string varType;
string pre="; ModuleID = 'test.c'\n source_filename = \"test.c\"\n target datalayout = \"e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128\"\n target triple = \"x86_64-pc-linux-gnu\"\n\n";
string pre1= "; Function Attrs: noinline nounwind optnone uwtable\n define dso_local i32 @main() #0 {\n";

string post= "attributes #0 = { noinline nounwind optnone uwtable \"frame-pointer\"=\"all\" \"min-legal-vector-width\"=\"0\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"x86-64\" \"target-features\"=\"+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"tune-cpu\"=\"generic\" }\n\n !llvm.module.flags = !{!0, !1, !2, !3, !4}\n !llvm.ident = !{!5}\n\n !0 = !{i32 1, !\"wchar_size\", i32 4}\n !1 = !{i32 7, !\"PIC Level\", i32 2}\n !2 = !{i32 7, !\"PIE Level\", i32 2}\n !3 = !{i32 7, !\"uwtable\", i32 1}\n !4 = !{i32 7, !\"frame-pointer\", i32 2}\n !5 = !{!\"Ubuntu clang version 14.0.0-1ubuntu1\"}\n";

FILE *fp;
int var=3;
map<string, int> m; // map to store variable name and its value
map<string, int> values; // map to store variable name and its lexical value

vector<int> B_falseList;
vector<int> B_trueList;

vector<int> B1_falseList;
vector<int> B1_trueList;

vector<int> B2_falseList;
vector<int> B2_trueList;

int firstTrue=0,secondTrue=0;
int operations=1;

int loader=1; // times loaded

int integerValue;

%}

%union {
	double dval;
    int vblno;
    char vblid[10];
    char vbltype[10];
};

%token INT FLOAT CHAR BOOL SEMICOLON COMMA LOGOP WHILE IF ELSE FOR GT LT GE LE EQ NE AND OR NOT PLUS MINUS MUL DIV MOD ASSIGN
%token <vblid> ID
%token <dval>  INT_CONST FLOAT_CONST
%type <vbltype> EXP TERM FACTOR
%left '+' '-'
%left '*' '/'
%left LOGOP
/* %nonassoc RELOP */
%%

/* add this to file */
/* ret i32 0 */
prog : funcDef { printf("Accepted✅\n"); { fp=fopen("test1.ll", "a"); fprintf(fp, "ret i32 0 \n}\n");
fprintf(fp, "%s", post.c_str());
fclose(fp); }
for(auto it: values){
        cout<<it.first<<" "<<it.second<<endl;
    }
 }
    ;

/* funcDef : type ID {createNewSymbolTableEntry();} '(' argList ')' '{' declList stmtList '}' {destroySymbolTableEntry();} */
// open file pointer to write in test1.ll file
/* funcDef : type ID '(' argList ')' '{' declList stmtList '}'; */
funcDef : type ID '(' argList ')' '{'{ fp=fopen("test1.ll", "w");
    // append pre and pre1 to test1.ll file
    fprintf(fp, "%s", pre.c_str());
    fprintf(fp, "%s", pre1.c_str());
    // %1 = alloca i32 , align 4
    fprintf(fp, "%%%d = alloca i32 , align 4 \n", operations); // return 0 values
    operations++;
    fclose(fp);
 } declList stmtList '}';
argList : arg ',' arg | arg | ;
arg : type ID
    ;

type : INT { varType = "int"; }
    | FLOAT { varType = "float"; }
    | BOOL { varType = "bool"; }
    ;

    /* int a,b */
declList :  decl declList | decl;

decl : type varList SEMICOLON { }

/* varList : ID COMMA varList { addSymbolTableEntry(varType, $1); }
        | ID { addSymbolTableEntry(varType, $1); }; */

varList : ID COMMA varList {
    fp=fopen("test1.ll", "a");
    //   %2 = alloca i32, align 4
    //   store i32 0, i32* %1, align 4
    fprintf(fp, "%%%d = alloca i32 , align 4 \n", operations);
    fprintf(fp,"store i32 0, i32* %%%d, align 4\n",1);//loader
    string varName = $1;
    // cout<<varName<<endl;

    operations++;
    m[varName]=var;
    m["ret"]=1;
    cout<<"m["<<varName<<"] = "<<m[varName]<<endl;
    var--;
    fclose(fp);
}
        | ID {
            fp=fopen("test1.ll", "a");
            string varName = $1;
            // cout<<varName<<endl;
            m[varName]=var;
            var--;

            fprintf(fp, "%%%d = alloca i32 , align 4 \n", operations);
            operations++;
            cout<<"m["<<varName<<"] = "<<m[varName]<<endl;
            // var++;
            fclose(fp);
        }

stmtList : stmtList stmt | stmt
stmt : assignStmt SEMICOLON | ifStmt | whileStmt | forStmt;


/* %1 = alloca i32, align 4 */
assignStmt : type ID '=' EXP { }
/* store i32 5, i32* %1, align 4 */
            | ID '=' INT_CONST {
                integerValue = $3;
                // cout<<"integerValue = "<<integerValue<<endl;
                string varName = $1;
                // cout<<"varName = "<<varName<<endl;
                cout<<"varName = "<<varName<<" integerValue = "<<integerValue<<endl;
                values[$1]=integerValue;

                fp=fopen("test1.ll", "a");
                // store i32 6, i32* %1, align 4
                fprintf(fp, "store i32 %d, i32* %%%d, align 4 \n", integerValue, m[varName]);
                fclose(fp);
            }
            | ID '=' EXP {
                // get the value of the variable from EXP which is char*
                string varName = $1;
                cout<<"varName = "<<varName<<endl;

                // int val = yyvsp[0].dval;
                // values[varName]=val;
                // cout << "val = " << val << endl;

                cout<<"varName = "<<varName<<" integerValue = "<<integerValue<<endl;
                values[$1]=integerValue;

                }
            | ID '=' ID '+' INT_CONST {
                // fp=fopen("test1.ll", "a");
                // string varName = $1;
                // fprintf(fp, "_:\n");
                // // // %12 = load i32, i32* %2, align 4
                // fprintf(fp, "%%%d = load i32, i32* %%%d, align 4 \n", operations, m[varName]);
                // int toAdd = $5;
                // // // %13 = add nsw i32 %12, 1
                // fprintf(fp, "%%%d = add nsw i32 %%%d, %d \n", operations+1, operations, toAdd);
                // // // cout<<"🎈 varName = "<<varName<<" toAdd = "<<toAdd<<"current value = "<<values[varName]<<endl;
                // // m[varName]+=toAdd;
                // // store i32 %13, i32* %2, align 4
                // fprintf(fp, "store i32 %%%d, i32* %%%d, align 4 \n", operations+1, m[varName]);
                // // br label %17
                // // B1_falseList
                // fprintf(fp, "br label %%%d \n", B1_falseList.back());
                // fclose(fp);
            }
            | ID '=' ID '-' INT_CONST
            {
                fp=fopen("test1.ll", "a");
                // a = a - 1;
                // %12 = load i32, i32* %2, align 4
                string varName = $1;
                int toSub = $5;
                fprintf(fp, "%%%d = load i32, i32* %%%d, align 4 \n", operations, m[varName]);
                // %13 = sub nsw i32 %12, 1
                fprintf(fp, "%%%d = sub nsw i32 %%%d, %d \n", operations+1, operations, toSub);
                // cout<<"🎈 varName = "<<varName<<" toAdd = "<<toAdd<<"current value = "<<values[varName]<<endl;
                m[varName]-=toSub;
                // store i32 %13, i32* %2, align 4
                fprintf(fp, "store i32 %%%d, i32* %%%d, align 4 \n", operations+1, m[varName]);
                // cout<<"varName = "<<varName<<" newVal = "<<newVal<<endl;
                // br label %17
                // B1_falseList
                // fprintf(fp, "br label %%%d \n", B1_falseList.back());
                if(B1_falseList.size()>0)
                    // fprintf(fp, "br label %%%d \n", B1_falseList.back());
                    fprintf(fp, "br label _\n\n");
                fclose(fp);
            }


EXP : EXP '+' TERM | EXP '-' TERM |
 TERM
{
}
 ;


TERM : TERM '*' FACTOR |
 TERM '/' FACTOR {
    // b=a/7
    //   %3 = load i32, i32* %1, align 4
    string varName = $1;
    string res = $$;
    cout<<"varName inside expression of division = "<<varName<<endl;
    cout<<"res inside expression of division = "<<res<<endl;
    int val = values[varName];
    cout<<"val = "<<val<<endl;

    fp=fopen("test1.ll", "a");
    fprintf(fp, "%%%d = load i32, i32* %%%d, align 4 \n", operations, m[varName]);
    operations++;

    // div
    // %4 = sdiv i32 %3, 7
    fprintf(fp, "%%%d = sdiv i32 %%%d, %d \n", operations, operations-1, integerValue);
    operations++;

    // store i32 %4, i32* %2, align 4
    fprintf(fp, "store i32 %%%d, i32* %%%d, align 4 \n", operations-1, m[varName]);
    // values[varName]=val/integerValue;
    integerValue = values[varName] / integerValue;
    fclose(fp);

 }
| FACTOR {}

FACTOR : ID | INT_CONST {
    // load int_const
    // %2 = alloca i32, align 4
    // store i32 5, i32* %2, align 4
    cout<<"$1 = "<<$1<<endl;
    integerValue = $1;
    cout<<"integerValue = "<<integerValue<<endl;
   ;
}

 | FLOAT_CONST ;
    ;
bExp : bExp OR bExp | bExp AND bExp | NOT bExp
 | EXP GT EXP {
    // a>b || b>a
    string first = $1;
    string second = $3;
    // %4 = load i32, i32* %2, align 4
    fp=fopen("test1.ll", "a");
    fprintf(fp, "%%%d = load i32, i32* %%%d, align 4 \n", operations, m[first]);
    operations++;
    //   %5 = load i32, i32* %3, align 4
    fprintf(fp, "%%%d = load i32, i32* %%%d, align 4 \n", operations, m[second]);
    operations++;
    // %6 = icmp sgt i32 %4, %5
    fprintf(fp, "%%%d = icmp sgt i32 %%%d, %%%d \n", operations, operations-2, operations-1);
    operations++;
    fprintf(fp, "br i1 %%%d, label _, label %%%d \n\n", operations-1, operations);

    string key=first+">"+second;
    if(key=="a>b"){
        fprintf(fp, "%d: \n", operations);
        operations++;
        B1_falseList.push_back(operations);
    }
    else if(key=="b>a"){
        fprintf(fp, "%d: \n", operations);
        operations++;
        B2_falseList.push_back(operations);
    }
    fclose(fp);
 }

/* ifStmt : IF'(' bExp ')' '{' {createNewSymbolTableEntry();} stmtList {destroySymbolTableEntry();} '}' elseStmt; */

ifStmt : IF '(' bExp ')' '{' stmtList '}' elseStmt

/* elseStmt : ELSE '{' {createNewSymbolTableEntry();} stmtList {destroySymbolTableEntry();} '}' | ELSE ifStmt | ; */
elseStmt : ELSE '{' stmtList '}'

| ELSE ifStmt | ;


/* whileStmt : WHILE '(' bExp ')' '{' {createNewSymbolTableEntry();} stmtList {destroySymbolTableEntry();} '}'; */
whileStmt : WHILE '(' bExp ')' '{' stmtList '}';

/* forStmt : FOR '(' assignStmt SEMICOLON bExp SEMICOLON assignStmt ')' '{' {createNewSymbolTableEntry();} stmtList {destroySymbolTableEntry();} '}'; */
forStmt : FOR '(' assignStmt SEMICOLON bExp SEMICOLON assignStmt ')' '{' stmtList '}';
%%


int main(int argc, char **argv)
{
    yyparse();
    /* printSymbolTableEntry(); */
}

int yyerror(char *s)
{
    fprintf(stderr, "An error in the parser : %s\n", s);
}

