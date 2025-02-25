/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
// #include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
// map
#include <map>
using namespace std;

int yylex(void);
int yyerror(char *);

// void createNewSymbolTableEntry();
// void destroySymbolTableEntry();

// void addSymbolTableEntry(string a, string b);
// string getTypeFromSymbolTableEntry(string a);

// struct TypeCheckResult {
//     bool hasMismatch;
//     string errorMessage;
// };
// TypeCheckResult checkTypes(string a, string b);

// struct newType {
//     string type;
//     string errorMessage;
// };
// newType newResultantType(string a, string b);

// void printSymbolTableEntry();

// typedef struct TableEntry
// {
//   string id;
//   string type;
// } TableEntry;

// vector<TableEntry> tableEntry(26);
// stack<vector<TableEntry>> symbolTableEntry;

string varType;

// ; ModuleID = 'test.c'
// source_filename = "test.c"
// target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
// target triple = "x86_64-pc-linux-gnu"

// ; Function Attrs: noinline nounwind optnone uwtable
// define dso_local i32 @main() #0 {
string pre="; ModuleID = 'test.c'\n source_filename = \"test.c\"\n target datalayout = \"e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128\"\n target triple = \"x86_64-pc-linux-gnu\"\n\n";
string pre1= "; Function Attrs: noinline nounwind optnone uwtable\n define dso_local i32 @main() #0 {\n";


// attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

// !llvm.module.flags = !{!0, !1, !2, !3, !4}
// !llvm.ident = !{!5}

// !0 = !{i32 1, !"wchar_size", i32 4}
// !1 = !{i32 7, !"PIC Level", i32 2}
// !2 = !{i32 7, !"PIE Level", i32 2}
// !3 = !{i32 7, !"uwtable", i32 1}
// !4 = !{i32 7, !"frame-pointer", i32 2}
// !5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1"}
string post= "attributes #0 = { noinline nounwind optnone uwtable \"frame-pointer\"=\"all\" \"min-legal-vector-width\"=\"0\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"x86-64\" \"target-features\"=\"+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"tune-cpu\"=\"generic\" }\n\n !llvm.module.flags = !{!0, !1, !2, !3, !4}\n !llvm.ident = !{!5}\n\n !0 = !{i32 1, !\"wchar_size\", i32 4}\n !1 = !{i32 7, !\"PIC Level\", i32 2}\n !2 = !{i32 7, !\"PIE Level\", i32 2}\n !3 = !{i32 7, !\"uwtable\", i32 1}\n !4 = !{i32 7, !\"frame-pointer\", i32 2}\n !5 = !{!\"Ubuntu clang version 14.0.0-1ubuntu1\"}\n";

// ; Function Attrs: noinline nounwind optnone uwtable";
// File pointer to write in test.ll file
FILE *fp;
int var=2;
map<string, int> m;
map<string, int> values;
int operations=1;
int integerValue;

#line 154 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_BOOL = 6,                       /* BOOL  */
  YYSYMBOL_SEMICOLON = 7,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 8,                      /* COMMA  */
  YYSYMBOL_RELOP = 9,                      /* RELOP  */
  YYSYMBOL_LOGOP = 10,                     /* LOGOP  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_ID = 15,                        /* ID  */
  YYSYMBOL_INT_CONST = 16,                 /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 17,               /* FLOAT_CONST  */
  YYSYMBOL_18_ = 18,                       /* '+'  */
  YYSYMBOL_19_ = 19,                       /* '-'  */
  YYSYMBOL_20_ = 20,                       /* '*'  */
  YYSYMBOL_21_ = 21,                       /* '/'  */
  YYSYMBOL_22_ = 22,                       /* '('  */
  YYSYMBOL_23_ = 23,                       /* ')'  */
  YYSYMBOL_24_ = 24,                       /* '{'  */
  YYSYMBOL_25_ = 25,                       /* '}'  */
  YYSYMBOL_26_ = 26,                       /* ','  */
  YYSYMBOL_27_ = 27,                       /* '='  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_prog = 29,                      /* prog  */
  YYSYMBOL_funcDef = 30,                   /* funcDef  */
  YYSYMBOL_31_1 = 31,                      /* $@1  */
  YYSYMBOL_argList = 32,                   /* argList  */
  YYSYMBOL_arg = 33,                       /* arg  */
  YYSYMBOL_type = 34,                      /* type  */
  YYSYMBOL_declList = 35,                  /* declList  */
  YYSYMBOL_decl = 36,                      /* decl  */
  YYSYMBOL_varList = 37,                   /* varList  */
  YYSYMBOL_stmtList = 38,                  /* stmtList  */
  YYSYMBOL_stmt = 39,                      /* stmt  */
  YYSYMBOL_assignStmt = 40,                /* assignStmt  */
  YYSYMBOL_EXP = 41,                       /* EXP  */
  YYSYMBOL_TERM = 42,                      /* TERM  */
  YYSYMBOL_FACTOR = 43,                    /* FACTOR  */
  YYSYMBOL_bExp = 44,                      /* bExp  */
  YYSYMBOL_ifStmt = 45,                    /* ifStmt  */
  YYSYMBOL_elseStmt = 46,                  /* elseStmt  */
  YYSYMBOL_whileStmt = 47,                 /* whileStmt  */
  YYSYMBOL_forStmt = 48                    /* forStmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  94

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   272


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      22,    23,    20,    18,    26,    19,     2,    21,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,    25,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   115,   115,   121,   121,   121,   122,   125,
     126,   127,   131,   131,   133,   138,   150,   164,   164,   165,
     165,   165,   165,   177,   179,   195,   216,   216,   217,   227,
     228,   254,   261,   261,   271,   273,   273,   277,   280,   280,
     280,   284,   287
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "BOOL", "SEMICOLON", "COMMA", "RELOP", "LOGOP", "WHILE", "IF", "ELSE",
  "FOR", "ID", "INT_CONST", "FLOAT_CONST", "'+'", "'-'", "'*'", "'/'",
  "'('", "')'", "'{'", "'}'", "','", "'='", "$accept", "prog", "funcDef",
  "$@1", "argList", "arg", "type", "declList", "decl", "varList",
  "stmtList", "stmt", "assignStmt", "EXP", "TERM", "FACTOR", "bExp",
  "ifStmt", "elseStmt", "whileStmt", "forStmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-25)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     102,   -40,   -40,   -40,     7,   -40,    -6,   -40,    -3,   102,
      16,    -9,    33,    21,   102,   -40,   -40,   -40,   102,    44,
      87,   102,    60,    69,    58,    61,    73,    62,    82,     0,
     -40,    93,   -40,   -40,   -40,   -40,    44,   -40,    37,    37,
      81,    94,    80,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
      85,    92,   -40,    -5,     3,   111,     1,    96,    37,    37,
      37,    37,    37,    37,    37,    97,    98,    37,    96,    96,
      92,    92,   -40,   -40,   -40,    87,    87,    30,    17,    32,
      81,   -40,   110,   101,    -2,   -40,   103,    87,   -40,    87,
      52,    67,   -40,   -40
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,    11,     0,     2,     0,     1,     0,     7,
       0,     6,     0,     0,     0,     8,     3,     5,     0,     0,
       0,    13,    16,     0,     0,     0,     0,     0,     0,     0,
      18,     0,    20,    21,    22,    12,     0,    14,     0,     0,
       0,     0,     0,     4,    17,    19,    15,    32,    33,    34,
       0,    28,    31,     0,     0,     0,    33,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    36,
      26,    27,    29,    30,    35,     0,     0,     0,     0,     0,
       0,    41,    40,     0,     0,    37,     0,     0,    39,     0,
       0,     0,    38,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,   -40,   -40,   112,    51,   104,   -40,    95,
      -1,   -29,   -39,   -25,    56,    57,   -37,    45,   -40,   -40,
     -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,    18,    10,    11,    28,    20,    21,    23,
      29,    30,    31,    50,    51,    52,    53,    32,    85,    33,
      34
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    55,    54,     1,     2,    64,     3,     7,   -24,     8,
      25,    24,    25,    64,    26,    27,    57,    14,    65,     9,
       1,     2,    87,     3,   -24,    43,    66,    74,    24,    25,
      77,    26,    27,    68,    69,     1,     2,    80,     3,    13,
      64,    83,    81,    24,    25,    16,    26,    27,    15,    44,
      44,     6,    47,    48,    49,     1,     2,    82,     3,    22,
      12,    44,    44,    24,    25,    12,    26,    27,    36,    19,
       1,     2,    19,     3,    78,    79,    37,    92,    24,    25,
      38,    26,    27,    39,     1,     2,    90,     3,    91,    41,
       1,     2,    93,     3,    59,    40,    27,    42,    24,    25,
      45,    26,    27,    60,    61,     1,     2,    58,     3,    47,
      56,    49,    62,    63,    60,    61,    70,    71,    67,    72,
      73,    75,    76,    84,    86,    35,    17,    89,     0,    88,
       0,    46
};

static const yytype_int8 yycheck[] =
{
      29,    40,    39,     3,     4,    10,     6,     0,     7,    15,
      12,    11,    12,    10,    14,    15,    41,    26,    23,    22,
       3,     4,    24,     6,    23,    25,    23,    64,    11,    12,
      67,    14,    15,    58,    59,     3,     4,     7,     6,    23,
      10,    80,    25,    11,    12,    24,    14,    15,    15,    78,
      79,     0,    15,    16,    17,     3,     4,    25,     6,    15,
       9,    90,    91,    11,    12,    14,    14,    15,     8,    18,
       3,     4,    21,     6,    75,    76,     7,    25,    11,    12,
      22,    14,    15,    22,     3,     4,    87,     6,    89,    27,
       3,     4,    25,     6,     9,    22,    15,    15,    11,    12,
       7,    14,    15,    18,    19,     3,     4,    27,     6,    15,
      16,    17,    20,    21,    18,    19,    60,    61,     7,    62,
      63,    24,    24,    13,    23,    21,    14,    24,    -1,    84,
      -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,    29,    30,    34,     0,    15,    22,
      32,    33,    34,    23,    26,    15,    24,    33,    31,    34,
      35,    36,    15,    37,    11,    12,    14,    15,    34,    38,
      39,    40,    45,    47,    48,    35,     8,     7,    22,    22,
      22,    27,    15,    25,    39,     7,    37,    15,    16,    17,
      41,    42,    43,    44,    44,    40,    16,    41,    27,     9,
      18,    19,    20,    21,    10,    23,    23,     7,    41,    41,
      42,    42,    43,    43,    44,    24,    24,    44,    38,    38,
       7,    25,    25,    40,    13,    46,    23,    24,    45,    24,
      38,    38,    25,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    31,    30,    32,    32,    32,    33,    34,
      34,    34,    35,    35,    36,    37,    37,    38,    38,    39,
      39,    39,    39,    40,    40,    40,    41,    41,    41,    42,
      42,    42,    43,    43,    43,    44,    44,    45,    46,    46,
      46,    47,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,    10,     3,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     3,     1,     2,     1,     2,
       1,     1,     1,     4,     3,     3,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     3,     3,     8,     4,     2,
       0,     7,    11
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: funcDef  */
#line 103 "parser.y"
               { printf("Accepted✅\n"); { fp=fopen("test1.ll", "a"); fprintf(fp, "ret i32 0 \n}\n");
fprintf(fp, "%s", post.c_str());
fclose(fp); }
for(auto it: values){
        cout<<it.first<<" "<<it.second<<endl;
    }
 }
#line 1257 "parser.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 115 "parser.y"
                                     { fp=fopen("test1.ll", "w");
    // append pre and pre1 to test1.ll file
    fprintf(fp, "%s", pre.c_str());
    fprintf(fp, "%s", pre1.c_str());
    fclose(fp);
 }
#line 1268 "parser.tab.c"
    break;

  case 9: /* type: INT  */
#line 125 "parser.y"
           { varType = "int"; }
#line 1274 "parser.tab.c"
    break;

  case 10: /* type: FLOAT  */
#line 126 "parser.y"
            { varType = "float"; }
#line 1280 "parser.tab.c"
    break;

  case 11: /* type: BOOL  */
#line 127 "parser.y"
           { varType = "bool"; }
#line 1286 "parser.tab.c"
    break;

  case 14: /* decl: type varList SEMICOLON  */
#line 133 "parser.y"
                              { }
#line 1292 "parser.tab.c"
    break;

  case 15: /* varList: ID COMMA varList  */
#line 138 "parser.y"
                           {
    fp=fopen("test1.ll", "a");
    //   %2 = alloca i32, align 4
    fprintf(fp, "%%%d = alloca i32 , align 4 \n", operations);
    string varName = (yyvsp[-2].vblid);
    // cout<<varName<<endl;
    operations++;
    m[varName]=var;
    cout<<"m["<<varName<<"] = "<<m[varName]<<endl;
    var--;
    fclose(fp);
}
#line 1309 "parser.tab.c"
    break;

  case 16: /* varList: ID  */
#line 150 "parser.y"
             {
            fp=fopen("test1.ll", "a");
            string varName = (yyvsp[0].vblid);
            // cout<<varName<<endl;
            m[varName]=var;
            var--;

            fprintf(fp, "%%%d = alloca i32 , align 4 \n", operations);
            operations++;
            cout<<"m["<<varName<<"] = "<<m[varName]<<endl;
            // var++;
            fclose(fp);
        }
#line 1327 "parser.tab.c"
    break;

  case 23: /* assignStmt: type ID '=' EXP  */
#line 177 "parser.y"
                             { }
#line 1333 "parser.tab.c"
    break;

  case 24: /* assignStmt: ID '=' INT_CONST  */
#line 179 "parser.y"
                               {
                integerValue = (yyvsp[0].dval);
                // cout<<"integerValue = "<<integerValue<<endl;
                string varName = (yyvsp[-2].vblid);
                // cout<<"varName = "<<varName<<endl;
                cout<<"varName = "<<varName<<" integerValue = "<<integerValue<<endl;
                values[(yyvsp[-2].vblid)]=integerValue;
                // for(auto it:values) {
                //     cout<<it.first<<" "<<it.second<<endl;
                // }

                fp=fopen("test1.ll", "a");
                // store i32 6, i32* %1, align 4
                fprintf(fp, "store i32 %d, i32* %%%d, align 4 \n", integerValue, m[varName]);
                fclose(fp);
            }
#line 1354 "parser.tab.c"
    break;

  case 25: /* assignStmt: ID '=' EXP  */
#line 195 "parser.y"
                         {
                // get the value of the variable from EXP which is char*
                string varName = (yyvsp[-2].vblid);
                cout<<"varName = "<<varName<<endl;

                // int val = yyvsp[0].dval;
                // values[varName]=val;
                // cout << "val = " << val << endl;

                cout<<"varName = "<<varName<<" integerValue = "<<integerValue<<endl;
                values[(yyvsp[-2].vblid)]=integerValue;

                }
#line 1372 "parser.tab.c"
    break;

  case 28: /* EXP: TERM  */
#line 218 "parser.y"
{
}
#line 1379 "parser.tab.c"
    break;

  case 30: /* TERM: TERM '/' FACTOR  */
#line 228 "parser.y"
                 {
    // b=a/7
    //   %3 = load i32, i32* %1, align 4
    string varName = (yyvsp[-2].vbltype);
    string res = (yyval.vbltype);
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
#line 1410 "parser.tab.c"
    break;

  case 31: /* TERM: FACTOR  */
#line 254 "parser.y"
         {}
#line 1416 "parser.tab.c"
    break;

  case 33: /* FACTOR: INT_CONST  */
#line 261 "parser.y"
                        {
    // load int_const
    // %2 = alloca i32, align 4
    // store i32 5, i32* %2, align 4
    cout<<"$1 = "<<(yyvsp[0].dval)<<endl;
    integerValue = (yyvsp[0].dval);
    cout<<"integerValue = "<<integerValue<<endl;
   ;
}
#line 1430 "parser.tab.c"
    break;


#line 1434 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 288 "parser.y"



int main(int argc, char **argv)
{
    yyparse();
    /* printSymbolTableEntry(); */
}


/* // This function returns the type of the identifier passed as an argument.
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
 */

int yyerror(char *s)
{
    fprintf(stderr, "An error in the parser : %s\n", s);
}

