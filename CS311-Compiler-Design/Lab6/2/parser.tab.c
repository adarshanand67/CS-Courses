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

#line 114 "parser.tab.c"

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
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_47_3 = 47,                      /* $@3  */
  YYSYMBOL_elseStmt = 48,                  /* elseStmt  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_50_5 = 50,                      /* $@5  */
  YYSYMBOL_whileStmt = 51,                 /* whileStmt  */
  YYSYMBOL_52_6 = 52,                      /* $@6  */
  YYSYMBOL_53_7 = 53,                      /* $@7  */
  YYSYMBOL_forStmt = 54,                   /* forStmt  */
  YYSYMBOL_55_8 = 55,                      /* $@8  */
  YYSYMBOL_56_9 = 56                       /* $@9  */
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
#define YYLAST   101

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

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
static const yytype_int8 yyrline[] =
{
       0,    61,    61,    63,    63,    65,    65,    65,    66,    69,
      70,    71,    73,    73,    74,    76,    77,    79,    79,    80,
      80,    80,    80,    82,    83,    86,    87,    88,    90,    91,
      92,    94,    96,    97,    99,    99,   101,   101,   101,   103,
     103,   103,   103,   103,   105,   105,   105,   107,   107,   107
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
  "ifStmt", "$@2", "$@3", "elseStmt", "$@4", "$@5", "whileStmt", "$@6",
  "$@7", "forStmt", "$@8", "$@9", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      55,   -61,   -61,   -61,    34,   -61,    -6,   -61,   -61,    28,
      55,    -7,    30,    39,    48,    55,   -61,    55,   -61,    60,
      32,   -61,    68,    70,    56,    57,    58,    54,    67,   -61,
       0,   -61,    76,   -61,   -61,   -61,    60,   -61,    24,    24,
      45,    24,     2,   -61,    69,   -61,   -61,   -61,   -61,   -61,
     -61,    46,    42,   -61,    -5,    -2,    78,    49,    24,    59,
      24,    24,    24,    24,    24,    24,    63,    64,    24,    49,
      49,    42,    42,   -61,   -61,   -61,   -61,   -61,    16,    32,
      32,    45,    32,    32,    66,    65,    71,    73,   -61,    79,
     -61,    33,   -61,    32,   -61,   -61,    32,    32,    74,    32,
     -61,    75,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,    11,     0,     2,     0,     1,     3,     0,
       7,     0,     6,     0,     0,     0,     8,     0,     5,     0,
       0,    13,    16,     0,     0,     0,     0,     0,     0,    12,
       0,    18,     0,    20,    21,    22,     0,    14,     0,     0,
       0,     0,    16,     4,     0,    17,    19,    15,    31,    32,
      33,     0,    27,    30,     0,     0,     0,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      35,    25,    26,    28,    29,    34,    44,    36,     0,     0,
       0,     0,    45,    37,     0,     0,     0,     0,    46,    43,
      47,     0,    38,     0,    39,    42,    48,     0,     0,    40,
      49,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,   -61,   -61,   -61,    80,     7,   -61,    81,    62,
     -60,   -30,   -39,   -28,     9,    10,   -37,     3,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     9,    11,    12,    44,    20,    21,    23,
      30,    31,    32,    51,    52,    53,    54,    33,    80,    86,
      92,    97,   101,    34,    79,    85,    35,    93,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      45,    56,    55,     1,     2,    65,     3,     6,    65,     8,
      36,    24,    25,    57,    26,    27,    14,    13,    66,    82,
      83,    67,    13,    81,    19,    43,    65,    28,    75,    58,
      69,    78,    70,    96,     7,     1,     2,    99,     3,    48,
      49,    50,    84,    24,    25,    25,    26,    27,     1,     2,
      10,     3,    45,    45,    16,    60,    15,    94,     1,     2,
      27,     3,    63,    64,    61,    62,    45,    61,    62,    45,
      71,    72,    17,    73,    74,    22,    36,    37,    38,    39,
      40,    41,    42,    46,    59,    68,    58,    76,    77,    87,
      88,     0,    91,     0,    95,    18,    89,    90,    47,   100,
     102,    29
};

static const yytype_int8 yycheck[] =
{
      30,    40,    39,     3,     4,    10,     6,     0,    10,    15,
       8,    11,    12,    41,    14,    15,    23,    10,    23,    79,
      80,    23,    15,     7,    17,    25,    10,    20,    65,    27,
      58,    68,    60,    93,     0,     3,     4,    97,     6,    15,
      16,    17,    81,    11,    12,    12,    14,    15,     3,     4,
      22,     6,    82,    83,    15,     9,    26,    24,     3,     4,
      15,     6,    20,    21,    18,    19,    96,    18,    19,    99,
      61,    62,    24,    63,    64,    15,     8,     7,    22,    22,
      22,    27,    15,     7,    15,     7,    27,    24,    24,    23,
      25,    -1,    13,    -1,    91,    15,    25,    24,    36,    25,
      25,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,    29,    30,    34,     0,    15,    31,
      22,    32,    33,    34,    23,    26,    15,    24,    33,    34,
      35,    36,    15,    37,    11,    12,    14,    15,    34,    36,
      38,    39,    40,    45,    51,    54,     8,     7,    22,    22,
      22,    27,    15,    25,    34,    39,     7,    37,    15,    16,
      17,    41,    42,    43,    44,    44,    40,    41,    27,    15,
       9,    18,    19,    20,    21,    10,    23,    23,     7,    41,
      41,    42,    42,    43,    43,    44,    24,    24,    44,    52,
      46,     7,    38,    38,    40,    53,    47,    23,    25,    25,
      24,    13,    48,    55,    24,    45,    38,    49,    56,    38,
      25,    50,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    31,    30,    32,    32,    32,    33,    34,
      34,    34,    35,    35,    36,    37,    37,    38,    38,    39,
      39,    39,    39,    40,    40,    41,    41,    41,    42,    42,
      42,    43,    43,    43,    44,    44,    46,    47,    45,    49,
      50,    48,    48,    48,    52,    53,    51,    55,    56,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,    10,     3,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     3,     1,     2,     1,     2,
       1,     1,     1,     4,     3,     3,     3,     1,     3,     3,
       1,     1,     1,     1,     3,     3,     0,     0,    10,     0,
       0,     6,     2,     0,     0,     0,     9,     0,     0,    13
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
#line 61 "parser.y"
               { printf("Accepted✅\n"); }
#line 1217 "parser.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 63 "parser.y"
                  {createNewSymbolTableEntry();}
#line 1223 "parser.tab.c"
    break;

  case 4: /* funcDef: type ID $@1 '(' argList ')' '{' declList stmtList '}'  */
#line 63 "parser.y"
                                                                                           {destroySymbolTableEntry();}
#line 1229 "parser.tab.c"
    break;

  case 9: /* type: INT  */
#line 69 "parser.y"
           { varType = "int"; }
#line 1235 "parser.tab.c"
    break;

  case 10: /* type: FLOAT  */
#line 70 "parser.y"
            { varType = "float"; }
#line 1241 "parser.tab.c"
    break;

  case 11: /* type: BOOL  */
#line 71 "parser.y"
           { varType = "bool"; }
#line 1247 "parser.tab.c"
    break;

  case 15: /* varList: ID COMMA varList  */
#line 76 "parser.y"
                           { addSymbolTableEntry(varType, (yyvsp[-2].vblid)); }
#line 1253 "parser.tab.c"
    break;

  case 16: /* varList: ID  */
#line 77 "parser.y"
             { addSymbolTableEntry(varType, (yyvsp[0].vblid)); }
#line 1259 "parser.tab.c"
    break;

  case 23: /* assignStmt: type ID '=' EXP  */
#line 82 "parser.y"
                             { addSymbolTableEntry(varType, (yyvsp[-2].vblid)); if(checkTypes(varType, (yyvsp[0].vbltype)).hasMismatch) { cout << "ERROR: TYPE MISMATCH!\n";} }
#line 1265 "parser.tab.c"
    break;

  case 24: /* assignStmt: ID '=' EXP  */
#line 83 "parser.y"
                        { string ID_type = getTypeFromSymbolTableEntry((yyvsp[-2].vblid)); if(ID_type == "") {cout << "ERROR: " << (yyvsp[-2].vblid) << " called without declaration\n";}
            else { if(checkTypes(ID_type, (yyvsp[0].vbltype)).hasMismatch) { cout << "ERROR: TYPE MISMATCH!\n";} } }
#line 1272 "parser.tab.c"
    break;

  case 25: /* EXP: EXP '+' TERM  */
#line 86 "parser.y"
                   { strcpy((yyval.vbltype), newResultantType((yyvsp[-2].vbltype), (yyvsp[0].vbltype)).type.c_str()); }
#line 1278 "parser.tab.c"
    break;

  case 26: /* EXP: EXP '-' TERM  */
#line 87 "parser.y"
                   { strcpy((yyval.vbltype), newResultantType((yyvsp[-2].vbltype), (yyvsp[0].vbltype)).type.c_str()); }
#line 1284 "parser.tab.c"
    break;

  case 27: /* EXP: TERM  */
#line 88 "parser.y"
           { strcpy((yyval.vbltype), (yyvsp[0].vbltype)); }
#line 1290 "parser.tab.c"
    break;

  case 28: /* TERM: TERM '*' FACTOR  */
#line 90 "parser.y"
                       { strcpy((yyval.vbltype), newResultantType((yyvsp[-2].vbltype), (yyvsp[0].vbltype)).type.c_str()); }
#line 1296 "parser.tab.c"
    break;

  case 29: /* TERM: TERM '/' FACTOR  */
#line 91 "parser.y"
                      { strcpy((yyval.vbltype), newResultantType((yyvsp[-2].vbltype), (yyvsp[0].vbltype)).type.c_str()); }
#line 1302 "parser.tab.c"
    break;

  case 30: /* TERM: FACTOR  */
#line 92 "parser.y"
             { strcpy((yyval.vbltype), (yyvsp[0].vbltype)); }
#line 1308 "parser.tab.c"
    break;

  case 31: /* FACTOR: ID  */
#line 94 "parser.y"
             { string ID_type = getTypeFromSymbolTableEntry((yyvsp[0].vblid)); if(ID_type == "") {cout << "ERROR: " << (yyvsp[0].vblid) << " called without declaration\n";}
                else { strcpy((yyval.vbltype), ID_type.c_str()); cout << (yyval.vbltype) << "\n";} }
#line 1315 "parser.tab.c"
    break;

  case 32: /* FACTOR: INT_CONST  */
#line 96 "parser.y"
                { strcpy((yyval.vbltype), "int");}
#line 1321 "parser.tab.c"
    break;

  case 33: /* FACTOR: FLOAT_CONST  */
#line 97 "parser.y"
                  { strcpy((yyval.vbltype), "float"); }
#line 1327 "parser.tab.c"
    break;

  case 36: /* $@2: %empty  */
#line 101 "parser.y"
                            {createNewSymbolTableEntry();}
#line 1333 "parser.tab.c"
    break;

  case 37: /* $@3: %empty  */
#line 101 "parser.y"
                                                                    {destroySymbolTableEntry();}
#line 1339 "parser.tab.c"
    break;

  case 39: /* $@4: %empty  */
#line 103 "parser.y"
                    {createNewSymbolTableEntry();}
#line 1345 "parser.tab.c"
    break;

  case 40: /* $@5: %empty  */
#line 103 "parser.y"
                                                            {destroySymbolTableEntry();}
#line 1351 "parser.tab.c"
    break;

  case 44: /* $@6: %empty  */
#line 105 "parser.y"
                                   {createNewSymbolTableEntry();}
#line 1357 "parser.tab.c"
    break;

  case 45: /* $@7: %empty  */
#line 105 "parser.y"
                                                                           {destroySymbolTableEntry();}
#line 1363 "parser.tab.c"
    break;

  case 47: /* $@8: %empty  */
#line 107 "parser.y"
                                                                         {createNewSymbolTableEntry();}
#line 1369 "parser.tab.c"
    break;

  case 48: /* $@9: %empty  */
#line 107 "parser.y"
                                                                                                                 {destroySymbolTableEntry();}
#line 1375 "parser.tab.c"
    break;


#line 1379 "parser.tab.c"

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

#line 109 "parser.y"



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

