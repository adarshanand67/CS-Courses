%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

%%

[0-9]* {return number;}
[ \t] ;
[a-z] {return name;}
"$"   {return 0;}
\n    {return yytext[0];}
.     {return yytext[0];}
%%
