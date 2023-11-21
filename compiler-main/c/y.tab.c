
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

	#include <stdlib.h>
	#include <stdio.h>
	int yyerror(char *msg);

	#include "symboltable.h"
	#include "lex.yy.c"

	#define SYMBOL_TABLE symbol_table_list[current_scope].symbol_table

  extern entry_t** constant_table;

	int current_dtype;

	table_t symbol_table_list[NUM_TABLES];

	int is_declaration = 0;
	int is_loop = 0;
	int is_func = 0;
	int func_type;

	int param_list[10];
	int p_idx = 0;
	int p=0;
    int rhs = 0;

	void type_check(int,int,int);


/* Line 189 of yacc.c  */
#line 103 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     DEC_CONSTANT = 259,
     HEX_CONSTANT = 260,
     CHAR_CONSTANT = 261,
     FLOAT_CONSTANT = 262,
     STRING = 263,
     LOGICAL_AND = 264,
     LOGICAL_OR = 265,
     LS_EQ = 266,
     GR_EQ = 267,
     EQ = 268,
     NOT_EQ = 269,
     MUL_ASSIGN = 270,
     DIV_ASSIGN = 271,
     MOD_ASSIGN = 272,
     ADD_ASSIGN = 273,
     SUB_ASSIGN = 274,
     INCREMENT = 275,
     DECREMENT = 276,
     ASIIGN = 277,
     ADD = 278,
     SUB = 279,
     MUL = 280,
     DIV = 281,
     MOD = 282,
     LESS = 283,
     GREATER = 284,
     PUNCTUATION = 285,
     SHORT = 286,
     INT = 287,
     LONG = 288,
     LONG_LONG = 289,
     SIGNED = 290,
     UNSIGNED = 291,
     CONST = 292,
     VOID = 293,
     CHAR = 294,
     FLOAT = 295,
     IF = 296,
     FOR = 297,
     WHILE = 298,
     CONTINUE = 299,
     BREAK = 300,
     RETURN = 301,
     DO = 302,
     SWITCH = 303,
     CASE = 304,
     UMINUS = 305,
     LOWER_THAN_ELSE = 306,
     ELSE = 307
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define DEC_CONSTANT 259
#define HEX_CONSTANT 260
#define CHAR_CONSTANT 261
#define FLOAT_CONSTANT 262
#define STRING 263
#define LOGICAL_AND 264
#define LOGICAL_OR 265
#define LS_EQ 266
#define GR_EQ 267
#define EQ 268
#define NOT_EQ 269
#define MUL_ASSIGN 270
#define DIV_ASSIGN 271
#define MOD_ASSIGN 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define INCREMENT 275
#define DECREMENT 276
#define ASIIGN 277
#define ADD 278
#define SUB 279
#define MUL 280
#define DIV 281
#define MOD 282
#define LESS 283
#define GREATER 284
#define PUNCTUATION 285
#define SHORT 286
#define INT 287
#define LONG 288
#define LONG_LONG 289
#define SIGNED 290
#define UNSIGNED 291
#define CONST 292
#define VOID 293
#define CHAR 294
#define FLOAT 295
#define IF 296
#define FOR 297
#define WHILE 298
#define CONTINUE 299
#define BREAK 300
#define RETURN 301
#define DO 302
#define SWITCH 303
#define CASE 304
#define UMINUS 305
#define LOWER_THAN_ELSE 306
#define ELSE 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 31 "parser.y"

	int data_type;
	entry_t* entry;



/* Line 214 of yacc.c  */
#line 250 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 262 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,     2,     2,    58,     2,     2,
      63,    64,    56,    54,    50,    55,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    67,
      52,    51,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,     2,    66,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    12,    13,    14,    23,
      26,    28,    31,    33,    36,    38,    40,    42,    44,    47,
      49,    51,    54,    56,    59,    61,    63,    65,    67,    68,
      72,    74,    77,    79,    81,    82,    87,    90,    91,    93,
      95,    97,    99,   102,   105,   108,   111,   115,   116,   124,
     125,   134,   140,   148,   149,   156,   160,   163,   166,   170,
     172,   174,   176,   178,   181,   183,   187,   189,   193,   197,
     201,   205,   209,   213,   217,   221,   224,   226,   228,   230,
     234,   238,   242,   246,   250,   253,   256,   259,   262,   264,
     266,   268,   270,   272,   274,   276,   278,   280,   284,   288,
     292,   296,   300,   304,   307,   309,   311,   313,   315,   317,
     319,   324,   326,   328,   333,   337,   341,   343,   345
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      71,     0,    -1,    71,    72,    -1,    72,    -1,    73,    -1,
      95,    -1,    -1,    -1,    76,   104,    74,    63,    81,    64,
      75,    85,    -1,    78,    77,    -1,    78,    -1,    56,    77,
      -1,    56,    -1,    79,    80,    -1,    80,    -1,    35,    -1,
      36,    -1,    32,    -1,    31,    32,    -1,    31,    -1,    33,
      -1,    33,    32,    -1,    34,    -1,    34,    32,    -1,    39,
      -1,    40,    -1,    38,    -1,    82,    -1,    -1,    82,    50,
      83,    -1,    83,    -1,    76,   104,    -1,    85,    -1,    88,
      -1,    -1,    65,    86,    87,    66,    -1,    87,    84,    -1,
      -1,    92,    -1,    89,    -1,    93,    -1,    95,    -1,   110,
      67,    -1,    46,    67,    -1,    44,    67,    -1,    45,    67,
      -1,    46,   100,    67,    -1,    -1,    42,    63,    98,    98,
      64,    90,    84,    -1,    -1,    42,    63,    98,    98,    99,
      64,    91,    84,    -1,    41,    63,    99,    64,    84,    -1,
      41,    63,    99,    64,    84,    62,    84,    -1,    -1,    43,
      63,    99,    64,    94,    84,    -1,    76,    96,    67,    -1,
      96,    67,    -1,   102,    67,    -1,    96,    50,    97,    -1,
      97,    -1,   101,    -1,   104,    -1,   108,    -1,    99,    67,
      -1,    67,    -1,    99,    50,   100,    -1,   100,    -1,   100,
      53,   100,    -1,   100,    52,   100,    -1,   100,    13,   100,
      -1,   100,    14,   100,    -1,   100,    11,   100,    -1,   100,
      12,   100,    -1,   100,     9,   100,    -1,   100,    10,   100,
      -1,    59,   100,    -1,   106,    -1,   101,    -1,   102,    -1,
     103,   105,   106,    -1,   103,   105,   108,    -1,   103,   105,
     110,    -1,   103,   105,   102,    -1,   102,   105,   102,    -1,
     104,    20,    -1,   104,    21,    -1,    21,   104,    -1,    20,
     104,    -1,   104,    -1,   108,    -1,     3,    -1,    51,    -1,
      18,    -1,    19,    -1,    15,    -1,    16,    -1,    17,    -1,
     106,    54,   106,    -1,   106,    55,   106,    -1,   106,    56,
     106,    -1,   106,    57,   106,    -1,   106,    58,   106,    -1,
      63,   106,    64,    -1,    55,   106,    -1,   104,    -1,   107,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,   104,
      68,   109,    69,    -1,   107,    -1,   104,    -1,   104,    63,
     111,    64,    -1,   104,    63,    64,    -1,   111,    50,   112,
      -1,   112,    -1,   100,    -1,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    89,    92,    93,    98,   104,    97,   118,
     120,   124,   125,   128,   129,   132,   133,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   150,   151,   154,
     155,   159,   163,   164,   169,   169,   179,   180,   184,   185,
     186,   187,   188,   189,   198,   199,   201,   211,   211,   212,
     212,   215,   216,   219,   219,   222,   224,   225,   228,   229,
     232,   233,   234,   238,   239,   242,   243,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   263,
     264,   265,   266,   267,   270,   271,   272,   273,   275,   276,
     279,   295,   296,   297,   298,   299,   300,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   314,   315,   316,   317,
     320,   351,   352,   355,   361,   369,   370,   373,   374
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DEC_CONSTANT",
  "HEX_CONSTANT", "CHAR_CONSTANT", "FLOAT_CONSTANT", "STRING",
  "LOGICAL_AND", "LOGICAL_OR", "LS_EQ", "GR_EQ", "EQ", "NOT_EQ",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "INCREMENT", "DECREMENT", "ASIIGN", "ADD", "SUB", "MUL", "DIV", "MOD",
  "LESS", "GREATER", "PUNCTUATION", "SHORT", "INT", "LONG", "LONG_LONG",
  "SIGNED", "UNSIGNED", "CONST", "VOID", "CHAR", "FLOAT", "IF", "FOR",
  "WHILE", "CONTINUE", "BREAK", "RETURN", "DO", "SWITCH", "CASE", "','",
  "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS",
  "LOWER_THAN_ELSE", "ELSE", "'('", "')'", "'{'", "'}'", "';'", "'['",
  "']'", "$accept", "starter", "builder", "function", "$@1", "$@2", "type",
  "pointer", "data_type", "sign_specifier", "type_specifier",
  "argument_list", "arguments", "arg", "stmt", "compound_stmt", "$@3",
  "statements", "single_stmt", "for_block", "$@4", "$@5", "if_block",
  "while_block", "$@6", "declaration", "declaration_list", "sub_decl",
  "expression_stmt", "expression", "sub_expr", "assignment_expr",
  "unary_expr", "lhs", "identifier", "assign_op", "arithmetic_expr",
  "constant", "array_access", "array_index", "function_call",
  "parameter_list", "parameter", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      44,    61,    60,    62,    43,    45,    42,    47,    37,    33,
     305,   306,   307,    40,    41,   123,   125,    59,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    74,    75,    73,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    83,    84,    84,    86,    85,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    90,    89,    91,
      89,    92,    92,    94,    93,    95,    95,    95,    96,    96,
      97,    97,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   102,   102,   102,   102,   103,   103,
     104,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   107,   107,   107,   107,
     108,   109,   109,   110,   110,   111,   111,   112,   112
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     0,     0,     8,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     0,     3,
       1,     2,     1,     1,     0,     4,     2,     0,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     0,     7,     0,
       8,     5,     7,     0,     6,     3,     2,     2,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     4,     3,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    90,     0,     0,    19,    17,    20,    22,    15,    16,
      26,    24,    25,     0,     3,     4,     0,    10,     0,    14,
       5,     0,    59,    60,     0,     0,    88,    89,    87,    86,
      18,    21,    23,     1,     2,     0,     0,    88,    12,     9,
      13,     0,    56,    94,    95,    96,    92,    93,    91,    57,
       0,     0,    84,    85,     0,    55,     0,    11,    58,    83,
       0,   106,   107,   108,   109,     0,     0,    82,   104,    79,
     105,    80,    81,   112,   111,     0,    28,   104,   103,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,    27,
      30,   102,   118,     0,   114,   117,    77,    78,   104,    76,
      89,     0,   116,    97,    98,    99,   100,   101,    31,     7,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,    29,    73,    74,    71,    72,    69,    70,
      68,    67,   115,    34,     8,    37,     0,     0,     0,     0,
       0,     0,     0,    35,     0,    36,    32,    33,    39,    38,
      40,    41,    88,     0,     0,     0,     0,    44,    45,    43,
       0,    42,     0,    66,    64,     0,     0,     0,    46,     0,
       0,     0,    63,    53,    65,    51,    47,     0,     0,     0,
       0,    49,    54,    52,    48,     0,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    56,   122,   144,    39,    17,    18,
      19,    88,    89,    90,   145,   146,   135,   136,   147,   148,
     180,   185,   149,   150,   178,   151,    21,    22,   165,   166,
     163,    96,    97,    25,    98,    50,    99,    70,   100,    75,
     153,   101,   102
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const yytype_int16 yypact[] =
{
     417,  -132,     2,     2,   -20,  -132,     5,    15,  -132,  -132,
    -132,  -132,  -132,   396,  -132,  -132,    23,   -17,   448,  -132,
    -132,   -36,  -132,  -132,    -9,   391,   236,   -35,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,   -22,   391,   167,   -17,  -132,
    -132,    23,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
      23,    96,  -132,  -132,   397,  -132,    -8,  -132,  -132,  -132,
     117,  -132,  -132,  -132,  -132,    72,    72,  -132,    47,   367,
    -132,  -132,  -132,  -132,  -132,   -12,   438,  -132,  -132,   404,
     260,    72,    72,    72,    72,    72,  -132,     2,     8,    14,
    -132,  -132,  -132,   330,  -132,   329,  -132,   391,   337,   367,
    -132,   -16,  -132,    74,    74,  -132,  -132,  -132,  -132,  -132,
     438,  -132,   330,   330,   330,   330,   330,   330,   330,   330,
     324,  -132,    21,  -132,     7,   361,  -132,  -132,    18,    18,
    -132,  -132,  -132,  -132,  -132,  -132,   207,    34,    57,    65,
      67,    79,   101,  -132,    23,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,   327,    81,   330,   216,   330,  -132,  -132,  -132,
     162,  -132,    48,   329,  -132,   216,   -14,    61,  -132,   330,
     256,   305,  -132,  -132,   329,    87,  -132,    69,   256,   256,
     256,  -132,  -132,  -132,  -132,   256,  -132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,   137,  -132,  -132,  -132,     4,   114,  -132,  -132,
     135,  -132,  -132,    44,    46,    35,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,   113,   -15,   120,    -3,  -131,
     -24,    33,    11,  -132,     0,   138,    58,   111,    22,  -132,
     116,  -132,    62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -89
static const yytype_int16 yytable[] =
{
      26,    35,    28,    29,    16,     1,    43,    44,    45,    46,
      47,    24,    30,    26,    41,   -62,    37,    16,   114,   115,
     116,   117,    27,   162,    24,   167,     1,    36,    41,   114,
     115,    42,   -62,    23,   120,    27,   169,    31,    27,    38,
     177,    26,    48,     2,     3,    55,    23,    32,   121,    23,
      60,    68,    36,   172,    73,    76,    95,    86,    49,   118,
     119,    59,    67,    27,   110,    77,    77,    52,    53,   111,
     118,   119,   109,    71,    23,     1,    61,    62,    63,    64,
      87,    77,    77,    77,    77,    77,   133,   108,   124,   125,
     126,   127,   128,   129,   130,   131,    95,   154,   169,     1,
      61,    62,    63,    64,     1,    61,    62,    63,    64,    69,
      80,   169,   170,    20,    87,    54,     2,     3,   160,   169,
     155,     2,     3,    78,    79,   173,    20,    65,   156,    35,
      83,    84,    85,   181,   157,    66,   152,    52,    53,   103,
     104,   105,   106,   107,    26,   174,   158,    24,   161,   179,
      34,    65,    57,    40,   123,    36,    65,   134,    27,    66,
      93,    58,   171,    51,    66,    74,    27,    72,   159,    23,
     152,   112,   113,   114,   115,   116,   117,    23,   152,   152,
     152,    24,   132,     0,     0,   152,     0,    52,    53,    24,
      24,    24,    27,     0,     0,     0,    24,     0,     0,     0,
      27,    27,    27,    23,     0,     0,     0,    27,     0,     0,
       1,    23,    23,    23,   118,   119,   175,   -61,    23,     1,
      61,    62,    63,    64,   182,   183,   184,     2,     3,   168,
      -6,   186,     0,     0,   -61,    54,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,   137,   138,
     139,   140,   141,   142,     0,     0,    52,    53,     0,     1,
       0,     0,     0,     1,    61,    62,    63,    64,    92,     0,
       0,    65,   133,   143,     0,    93,     2,     3,     0,    66,
       2,     3,     0,   164,     0,     0,   -61,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,   137,   138,   139,
     140,   141,   142,   -61,    54,     0,     0,     0,     1,    61,
      62,    63,    64,     0,     0,    65,     0,     0,     0,    93,
       0,   133,     0,    66,    94,     2,     3,     1,    61,    62,
      63,    64,    92,     1,    61,    62,    63,    64,   112,   113,
     114,   115,   116,   117,     2,     3,     0,    52,    53,     0,
       2,     3,   -88,   -88,   -88,   -88,   -88,    52,    53,     0,
      65,     0,     0,     0,    93,     0,     0,     0,    66,   176,
     112,     0,   114,   115,   116,   117,     0,   -61,     0,    65,
       0,   118,   119,    93,     0,    65,     0,    66,   -88,    93,
      80,     0,     0,    66,   -61,    54,    33,     0,     0,     1,
       1,    61,    62,    63,    64,    54,    43,    44,    45,    46,
      47,     0,     0,   118,   119,     0,     2,     3,     0,     0,
       1,    81,    82,    83,    84,    85,     0,     4,     5,     6,
       7,     8,     9,     0,    10,    11,    12,     2,     3,     0,
       0,     0,    48,     0,     0,     0,     0,     0,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,    91,     4,
       5,     6,     7,     8,     9,     0,    10,    11,    12,     4,
       5,     6,     7,     0,     0,     0,    10,    11,    12
};

static const yytype_int16 yycheck[] =
{
       0,    16,     2,     3,     0,     3,    15,    16,    17,    18,
      19,     0,    32,    13,    50,    50,    16,    13,    11,    12,
      13,    14,     0,   154,    13,   156,     3,    16,    50,    11,
      12,    67,    67,     0,    50,    13,    50,    32,    16,    56,
     171,    41,    51,    20,    21,    67,    13,    32,    64,    16,
      50,    51,    41,    67,    54,    63,    80,    69,    67,    52,
      53,    50,    51,    41,    50,    65,    66,    20,    21,    93,
      52,    53,    64,    51,    41,     3,     4,     5,     6,     7,
      76,    81,    82,    83,    84,    85,    65,    87,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    63,    50,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    51,
      63,    50,    64,     0,   110,    68,    20,    21,   142,    50,
      63,    20,    21,    65,    66,    64,    13,    55,    63,   144,
      56,    57,    58,    64,    67,    63,   136,    20,    21,    81,
      82,    83,    84,    85,   144,   169,    67,   136,    67,    62,
      13,    55,    38,    18,   110,   144,    55,   122,   136,    63,
      59,    41,   165,    25,    63,    54,   144,    51,    67,   136,
     170,     9,    10,    11,    12,    13,    14,   144,   178,   179,
     180,   170,   120,    -1,    -1,   185,    -1,    20,    21,   178,
     179,   180,   170,    -1,    -1,    -1,   185,    -1,    -1,    -1,
     178,   179,   180,   170,    -1,    -1,    -1,   185,    -1,    -1,
       3,   178,   179,   180,    52,    53,   170,    50,   185,     3,
       4,     5,     6,     7,   178,   179,   180,    20,    21,    67,
      63,   185,    -1,    -1,    67,    68,    20,    21,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    20,    21,    -1,     3,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    55,    65,    66,    -1,    59,    20,    21,    -1,    63,
      20,    21,    -1,    67,    -1,    -1,    50,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    67,    68,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    55,    -1,    -1,    -1,    59,
      -1,    65,    -1,    63,    64,    20,    21,     3,     4,     5,
       6,     7,     8,     3,     4,     5,     6,     7,     9,    10,
      11,    12,    13,    14,    20,    21,    -1,    20,    21,    -1,
      20,    21,    15,    16,    17,    18,    19,    20,    21,    -1,
      55,    -1,    -1,    -1,    59,    -1,    -1,    -1,    63,    64,
       9,    -1,    11,    12,    13,    14,    -1,    50,    -1,    55,
      -1,    52,    53,    59,    -1,    55,    -1,    63,    51,    59,
      63,    -1,    -1,    63,    67,    68,     0,    -1,    -1,     3,
       3,     4,     5,     6,     7,    68,    15,    16,    17,    18,
      19,    -1,    -1,    52,    53,    -1,    20,    21,    -1,    -1,
       3,    54,    55,    56,    57,    58,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    20,    21,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    20,    21,    31,    32,    33,    34,    35,    36,
      38,    39,    40,    71,    72,    73,    76,    78,    79,    80,
      95,    96,    97,   101,   102,   103,   104,   108,   104,   104,
      32,    32,    32,     0,    72,    96,   102,   104,    56,    77,
      80,    50,    67,    15,    16,    17,    18,    19,    51,    67,
     105,   105,    20,    21,    68,    67,    74,    77,    97,   102,
     104,     4,     5,     6,     7,    55,    63,   102,   104,   106,
     107,   108,   110,   104,   107,   109,    63,   104,   106,   106,
      63,    54,    55,    56,    57,    58,    69,    76,    81,    82,
      83,    64,     8,    59,    64,   100,   101,   102,   104,   106,
     108,   111,   112,   106,   106,   106,   106,   106,   104,    64,
      50,   100,     9,    10,    11,    12,    13,    14,    52,    53,
      50,    64,    75,    83,   100,   100,   100,   100,   100,   100,
     100,   100,   112,    65,    85,    86,    87,    41,    42,    43,
      44,    45,    46,    66,    76,    84,    85,    88,    89,    92,
      93,    95,   104,   110,    63,    63,    63,    67,    67,    67,
     100,    67,    99,   100,    67,    98,    99,    99,    67,    50,
      64,    98,    67,    64,   100,    84,    64,    99,    94,    62,
      90,    64,    84,    84,    84,    91,    84
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {
																						func_type = current_dtype;
																						is_declaration = 0;
																						current_scope = create_new_scope();
																					}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {
																						is_declaration = 0;
																						fill_parameter_list((yyvsp[(2) - (6)].entry),param_list,p_idx);
																						p_idx = 0;
																						is_func = 1;
																						p=1;
																					}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {
																						is_func = 0;
																					}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {is_declaration = 1; }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {is_declaration = 1; }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {current_dtype = INT;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {current_dtype = SHORT;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {current_dtype = SHORT;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {current_dtype = LONG;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {current_dtype = LONG;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {current_dtype = LONG_LONG;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {current_dtype = LONG_LONG;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {current_dtype = CHAR;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {current_dtype = FLOAT;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {current_dtype = VOID;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {param_list[p_idx++] = (yyvsp[(2) - (2)].entry)->data_type;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {
																		if(!p)current_scope = create_new_scope();
																		else p = 0;
																}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    {current_scope = exit_scope();}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {
																	if(is_func)
																	{
																		if(func_type != VOID)
																			yyerror("return type (VOID) does not match function type");
																	}
																  else yyerror("return statement not inside function definition");
																}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {if(!is_loop) {yyerror("Illegal use of continue");}}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {if(!is_loop) {yyerror("Illegal use of break");}}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    {
																	if(is_func)
																	{
																		if(func_type != (yyvsp[(2) - (3)].data_type))
																			yyerror("return type does not match function type");
																	}
																	else yyerror("return statement not in function definition");
															 }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {is_loop = 1;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {is_loop = 0;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {is_loop = 1;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {is_loop = 0;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {is_loop = 1;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {is_loop = 0;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {is_declaration = 0; }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),2); (yyval.data_type) = (yyvsp[(1) - (3)].data_type);}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    {(yyval.data_type) = (yyvsp[(2) - (2)].data_type);}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].data_type);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].data_type);}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].data_type);}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),1); (yyval.data_type) = (yyvsp[(3) - (3)].data_type); rhs=0;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),1); (yyval.data_type) = (yyvsp[(3) - (3)].data_type);rhs=0;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),1); (yyval.data_type) = (yyvsp[(3) - (3)].data_type);rhs=0;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),1); (yyval.data_type) = (yyvsp[(3) - (3)].data_type);rhs=0;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 267 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),1); (yyval.data_type) = (yyvsp[(3) - (3)].data_type);rhs=0;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 270 "parser.y"
    {(yyval.data_type) = (yyvsp[(1) - (2)].entry)->data_type;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    {(yyval.data_type) = (yyvsp[(1) - (2)].entry)->data_type;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    {(yyval.data_type) = (yyvsp[(2) - (2)].entry)->data_type;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    {(yyval.data_type) = (yyvsp[(2) - (2)].entry)->data_type;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].entry)->data_type;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].data_type);}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {
                                                                    if(is_declaration
                                                                    && !rhs) 
                                                                    {
                                                                        (yyvsp[(1) - (1)].entry) = insert(SYMBOL_TABLE,yytext,INT_MAX,current_dtype);
                                                                        if((yyvsp[(1) - (1)].entry) == NULL) yyerror("Redeclaration of variable");
                                                                    }
                                                                    else
                                                                    {
                                                                        (yyvsp[(1) - (1)].entry) = search_recursive(yytext);
                                                                        if((yyvsp[(1) - (1)].entry) == NULL) yyerror("Variable not declared");
                                                                    }
                                                                    (yyval.entry) = (yyvsp[(1) - (1)].entry);
                                                            }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 295 "parser.y"
    {rhs=1;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    {rhs=1;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 297 "parser.y"
    {rhs=1;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    {rhs=1;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    {rhs=1;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    {rhs=1;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 303 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),0);}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 304 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),0);}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),0);}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),0);}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    {type_check((yyvsp[(1) - (3)].data_type),(yyvsp[(3) - (3)].data_type),0);}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 308 "parser.y"
    {(yyval.data_type) = (yyvsp[(2) - (3)].data_type);}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {(yyval.data_type) = (yyvsp[(2) - (2)].data_type);}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 310 "parser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].entry)->data_type;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 311 "parser.y"
    {(yyval.data_type) = (yyvsp[(1) - (1)].entry)->data_type;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    {(yyvsp[(1) - (1)].entry)->is_constant=1; (yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 315 "parser.y"
    {(yyvsp[(1) - (1)].entry)->is_constant=1; (yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    {(yyvsp[(1) - (1)].entry)->is_constant=1; (yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 317 "parser.y"
    {(yyvsp[(1) - (1)].entry)->is_constant=1; (yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    {
																															if(is_declaration)
																															{
																																if((yyvsp[(3) - (4)].entry)->value <= 0)
																																	yyerror("size of array is not positive");

																																else
                                                                                                                                if((yyvsp[(3) - (4)].entry)->is_constant && !rhs)
																																	(yyvsp[(1) - (4)].entry)->array_dimension = (yyvsp[(3) - (4)].entry)->value;
																																	else if(rhs){
																																	{
																																if((yyvsp[(3) - (4)].entry)->value > (yyvsp[(1) - (4)].entry)->array_dimension)
																																	yyerror("Array index out of bound");

																																if((yyvsp[(3) - (4)].entry)->value < 0)
																																	yyerror("Array index cannot be negative");
																															}
																															}
																															}

																															else if((yyvsp[(3) - (4)].entry)->is_constant)
																															{
																																if((yyvsp[(3) - (4)].entry)->value > (yyvsp[(1) - (4)].entry)->array_dimension)
																																	yyerror("Array index out of bound");

																																if((yyvsp[(3) - (4)].entry)->value < 0)
																																	yyerror("Array index cannot be negative");
																															}
																															(yyval.data_type) = (yyvsp[(1) - (4)].entry)->data_type;
																														}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 351 "parser.y"
    {(yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 352 "parser.y"
    {(yyval.entry) = (yyvsp[(1) - (1)].entry);}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 355 "parser.y"
    {
																													(yyval.data_type) = (yyvsp[(1) - (4)].entry)->data_type;
																													check_parameter_list((yyvsp[(1) - (4)].entry),param_list,p_idx);
																													p_idx = 0;
																												}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 361 "parser.y"
    {
							 																						 (yyval.data_type) = (yyvsp[(1) - (3)].entry)->data_type;
																													 check_parameter_list((yyvsp[(1) - (3)].entry),param_list,p_idx);
																													 p_idx = 0;
																												}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 373 "parser.y"
    {param_list[p_idx++] = (yyvsp[(1) - (1)].data_type);}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 374 "parser.y"
    {param_list[p_idx++] = STRING;}
    break;



/* Line 1455 of yacc.c  */
#line 2335 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 376 "parser.y"


void type_check(int left, int right, int flag)
{
	if(left != right)
	{
		switch(flag)
		{
			case 0: yyerror("Type mismatch in arithmetic expression"); break;
			case 1: yyerror("Type mismatch in assignment expression"); break;
			case 2: yyerror("Type mismatch in logical expression"); break;
		}
	}
}

int main(int argc, char *argv[])
{
	 int i;
	 for(i=0; i<NUM_TABLES;i++)
	 {
	  symbol_table_list[i].symbol_table = NULL;
	  symbol_table_list[i].parent = -1;
	 }

	constant_table = create_table();
  symbol_table_list[0].symbol_table = create_table();
	yyin = fopen(argv[1], "r");

	if(!yyparse())
	{
		printf("\nPARSING COMPLETE\n\n\n");
	}
	else
	{
			printf("\nPARSING FAILED!\n\n\n");
	}


	printf("SYMBOL TABLES\n\n");
	display_all();

	printf("CONSTANT TABLE");
	display_constant_table(constant_table);


	fclose(yyin);
	return 0;
}

int yyerror(char *msg)
{
	printf("Line no: %d Error message: %s Token: %s\n", yylineno, msg, yytext);
	exit(0);
}
