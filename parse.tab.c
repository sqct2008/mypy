/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "includes/parse.y" /* yacc.c:339  */

  //#include <string>
  #include "includes/ast.h"
	int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
  unsigned depthOfFunc = 0;
  unsigned depthOfClass = 0;
  PoolOfNodes& pool = PoolOfNodes::getInstance();

#line 77 "parse.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AMPEREQUAL = 258,
    AMPERSAND = 259,
    AND = 260,
    AS = 261,
    ASSERT = 262,
    AT = 263,
    BACKQUOTE = 264,
    BAR = 265,
    BREAK = 266,
    CIRCUMFLEX = 267,
    CIRCUMFLEXEQUAL = 268,
    CLASS = 269,
    COLON = 270,
    COMMA = 271,
    CONTINUE = 272,
    DEDENT = 273,
    DEF = 274,
    DEL = 275,
    DOT = 276,
    DOUBLESLASH = 277,
    DOUBLESLASHEQUAL = 278,
    DOUBLESTAR = 279,
    DOUBLESTAREQUAL = 280,
    ELIF = 281,
    ELSE = 282,
    ENDMARKER = 283,
    EQEQUAL = 284,
    EQUAL = 285,
    EXCEPT = 286,
    EXEC = 287,
    FINALLY = 288,
    FOR = 289,
    FROM = 290,
    GLOBAL = 291,
    GREATER = 292,
    GREATEREQUAL = 293,
    GRLT = 294,
    IF = 295,
    IMPORT = 296,
    IN = 297,
    INDENT = 298,
    IS = 299,
    LAMBDA = 300,
    LBRACE = 301,
    LEFTSHIFT = 302,
    LEFTSHIFTEQUAL = 303,
    LESS = 304,
    LESSEQUAL = 305,
    LPAR = 306,
    LSQB = 307,
    MINEQUAL = 308,
    MINUS = 309,
    NAME = 310,
    NEWLINE = 311,
    NOT = 312,
    NOTEQUAL = 313,
    INT = 314,
    FLOAT = 315,
    OR = 316,
    PASS = 317,
    PERCENT = 318,
    PERCENTEQUAL = 319,
    PLUS = 320,
    PLUSEQUAL = 321,
    PRINT = 322,
    RAISE = 323,
    RBRACE = 324,
    RETURN = 325,
    RIGHTSHIFT = 326,
    RIGHTSHIFTEQUAL = 327,
    RPAR = 328,
    RSQB = 329,
    SEMI = 330,
    SLASH = 331,
    SLASHEQUAL = 332,
    STAR = 333,
    STAREQUAL = 334,
    STRING = 335,
    TILDE = 336,
    TRY = 337,
    VBAREQUAL = 338,
    WHILE = 339,
    WITH = 340,
    YIELD = 341,
    NUMBER = 342
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 35 "includes/parse.y" /* yacc.c:355  */

  Node* node;
  char *id;
  long integer;
  long double floatnumber;

#line 212 "parse.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 241 "parse.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   925

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  148
/* YYNRULES -- Number of rules.  */
#define YYNRULES  319
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  480

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    46,    46,    49,    52,    53,    56,    57,    60,    61,
      64,    66,    70,    71,    74,    75,    78,    78,    84,    86,
      90,    91,    94,    95,    98,    99,   102,   103,   106,   107,
     110,   111,   114,   115,   118,   119,   122,   123,   126,   127,
     130,   132,   136,   137,   140,   152,   153,   154,   155,   156,
     157,   158,   159,   162,   221,   233,   235,   239,   249,   253,
     255,   257,   259,   261,   263,   265,   267,   269,   271,   273,
     275,   279,   280,   283,   303,   307,   327,   331,   332,   335,
     336,   339,   342,   345,   346,   347,   348,   349,   352,   355,
     358,   359,   362,   365,   366,   369,   370,   373,   374,   377,
     378,   381,   384,   387,   388,   391,   392,   393,   396,   397,
     400,   401,   404,   405,   408,   409,   412,   413,   416,   417,
     420,   423,   424,   427,   428,   431,   432,   435,   436,   437,
     438,   439,   440,   441,   442,   445,   445,   451,   452,   455,
     455,   461,   461,   467,   467,   473,   474,   477,   478,   481,
     482,   485,   486,   489,   492,   493,   496,   497,   500,   501,
     504,   505,   508,   509,   512,   513,   516,   517,   520,   521,
     524,   525,   528,   529,   532,   533,   536,   538,   542,   543,
     546,   548,   552,   554,   558,   560,   564,   566,   569,   571,
     573,   575,   577,   579,   581,   583,   585,   587,   589,   593,
     595,   598,   600,   603,   605,   608,   610,   645,   647,   651,
     653,   669,   671,   675,   677,   701,   703,   705,   707,   711,
     732,   736,   738,   740,   744,   746,   750,   751,   755,   773,
     795,   813,   815,   817,   819,   821,   825,   827,   831,   833,
     837,   839,   843,   845,   849,   857,   861,   863,   880,   882,
     899,   900,   903,   908,   910,   914,   915,   918,   919,   922,
     923,   924,   927,   928,   931,   932,   935,   936,   939,   940,
     943,   944,   947,   962,   979,   981,   998,   999,  1002,  1003,
    1006,  1008,  1012,  1012,  1016,  1016,  1022,  1023,  1026,  1043,
    1063,  1067,  1068,  1071,  1072,  1075,  1077,  1079,  1083,  1085,
    1089,  1090,  1093,  1094,  1097,  1098,  1101,  1102,  1105,  1106,
    1109,  1110,  1113,  1114,  1117,  1119,  1141,  1142,  1145,  1146
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMPEREQUAL", "AMPERSAND", "AND", "AS",
  "ASSERT", "AT", "BACKQUOTE", "BAR", "BREAK", "CIRCUMFLEX",
  "CIRCUMFLEXEQUAL", "CLASS", "COLON", "COMMA", "CONTINUE", "DEDENT",
  "DEF", "DEL", "DOT", "DOUBLESLASH", "DOUBLESLASHEQUAL", "DOUBLESTAR",
  "DOUBLESTAREQUAL", "ELIF", "ELSE", "ENDMARKER", "EQEQUAL", "EQUAL",
  "EXCEPT", "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GREATER",
  "GREATEREQUAL", "GRLT", "IF", "IMPORT", "IN", "INDENT", "IS", "LAMBDA",
  "LBRACE", "LEFTSHIFT", "LEFTSHIFTEQUAL", "LESS", "LESSEQUAL", "LPAR",
  "LSQB", "MINEQUAL", "MINUS", "NAME", "NEWLINE", "NOT", "NOTEQUAL", "INT",
  "FLOAT", "OR", "PASS", "PERCENT", "PERCENTEQUAL", "PLUS", "PLUSEQUAL",
  "PRINT", "RAISE", "RBRACE", "RETURN", "RIGHTSHIFT", "RIGHTSHIFTEQUAL",
  "RPAR", "RSQB", "SEMI", "SLASH", "SLASHEQUAL", "STAR", "STAREQUAL",
  "STRING", "TILDE", "TRY", "VBAREQUAL", "WHILE", "WITH", "YIELD",
  "NUMBER", "$accept", "start", "file_input", "pick_NEWLINE_stmt",
  "star_NEWLINE_stmt", "decorator", "opt_arglist", "decorators",
  "decorated", "funcdef", "$@1", "parameters", "varargslist",
  "opt_EQUAL_test", "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME",
  "pick_STAR_DOUBLESTAR", "opt_COMMA", "fpdef", "fplist",
  "star_fpdef_notest", "stmt", "simple_stmt", "star_SEMI_small_stmt",
  "small_stmt", "expr_stmt", "pick_yield_expr_testlist", "star_EQUAL",
  "augassign", "print_stmt", "star_COMMA_test", "opt_test",
  "plus_COMMA_test", "opt_test_2", "del_stmt", "pass_stmt", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "yield_stmt", "raise_stmt",
  "opt_COMMA_test", "opt_test_3", "import_stmt", "import_name",
  "import_from", "pick_dotted_name", "pick_STAR_import", "import_as_name",
  "dotted_as_name", "import_as_names", "star_COMMA_import_as_name",
  "dotted_as_names", "dotted_name", "global_stmt", "star_COMMA_NAME",
  "exec_stmt", "assert_stmt", "compound_stmt", "if_stmt", "$@2",
  "star_ELIF", "while_stmt", "$@3", "for_stmt", "$@4", "try_stmt", "$@5",
  "except_Finally", "plus_except", "opt_ELSE", "opt_FINALLY", "with_stmt",
  "star_COMMA_with_item", "with_item", "except_clause", "pick_AS_COMMA",
  "opt_AS_COMMA", "suite", "plus_stmt", "testlist_safe",
  "plus_COMMA_old_test", "old_test", "old_lambdef", "test", "opt_IF_ELSE",
  "or_test", "and_test", "not_test", "comparison", "comp_op", "expr",
  "xor_expr", "and_expr", "shift_expr", "pick_LEFTSHIFT_RIGHTSHIFT",
  "arith_expr", "pick_PLUS_MINUS", "term", "pick_multop", "factor",
  "pick_unop", "power", "star_trailer", "atom",
  "pick_yield_expr_testlist_comp", "opt_yield_test", "opt_listmaker",
  "opt_dictorsetmaker", "plus_STRING", "listmaker", "testlist_comp",
  "lambdef", "trailer", "subscriptlist", "star_COMMA_subscript",
  "subscript", "opt_test_only", "opt_sliceop", "sliceop", "exprlist",
  "star_COMMA_expr", "testlist", "dictorsetmaker", "star_test_COLON_test",
  "pick_for_test_test", "pick_for_test", "classdef", "$@6", "$@7",
  "opt_testlist", "arglist", "star_argument_COMMA", "star_COMMA_argument",
  "opt_DOUBLESTAR_test", "pick_argument", "argument", "opt_comp_for",
  "list_iter", "list_for", "list_if", "comp_iter", "comp_for", "comp_if",
  "testlist1", "yield_expr", "star_DOT", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342
};
# endif

#define YYPACT_NINF -335

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-335)))

#define YYTABLE_NINF -285

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -335,    47,  -335,   322,  -335,   821,    38,   821,  -335,    60,
    -335,    63,   215,  -335,   215,   215,  -335,    71,   821,    38,
      73,   821,   191,   821,  -335,  -335,  -335,    78,  -335,  -335,
    -335,  -335,   740,   821,   821,  -335,  -335,    87,   821,   821,
     821,  -335,  -335,   133,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,     1,    70,  -335,   867,   130,   138,   150,     6,
      46,    13,  -335,   215,  -335,  -335,    54,  -335,    33,  -335,
    -335,   148,  -335,    10,  -335,    34,   151,  -335,   130,  -335,
      27,   123,   126,    17,  -335,   154,  -335,   155,    36,   821,
     157,     0,    86,   104,  -335,   141,  -335,   103,  -335,  -335,
     146,   105,  -335,  -335,   821,  -335,  -335,   167,  -335,  -335,
     169,  -335,   181,  -335,  -335,  -335,  -335,    52,   174,    78,
      78,  -335,    78,  -335,  -335,  -335,  -335,  -335,   135,  -335,
    -335,   152,  -335,   215,   215,   215,   215,  -335,  -335,   215,
    -335,  -335,   215,  -335,  -335,  -335,  -335,   215,  -335,    44,
    -335,  -335,  -335,  -335,  -335,   191,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,   191,   821,   140,   120,  -335,
    -335,   821,   147,   182,   153,   180,   821,   821,   -11,   158,
     184,   186,  -335,    38,   156,  -335,   821,   162,    -3,  -335,
     163,  -335,   173,   821,   215,   194,  -335,  -335,  -335,   194,
    -335,  -335,   215,   194,  -335,  -335,   203,   194,   821,  -335,
     581,  -335,   145,   215,  -335,   643,   821,    12,    70,  -335,
    -335,  -335,   130,   138,   150,     6,    46,    13,  -335,   171,
     215,   120,   772,  -335,   177,  -335,  -335,  -335,  -335,  -335,
     149,  -335,   682,  -335,   821,   581,   159,   212,   215,   213,
     219,   185,   222,  -335,  -335,  -335,  -335,   189,   581,  -335,
    -335,  -335,  -335,  -335,   166,   225,   821,   233,   141,   210,
     821,  -335,  -335,   211,  -335,   821,   238,  -335,  -335,   213,
     216,  -335,   124,   581,   581,   821,   130,  -335,  -335,  -335,
     821,  -335,  -335,   190,   234,   243,   188,  -335,   249,  -335,
     209,   821,   821,    30,  -335,   252,  -335,   200,  -335,  -335,
     205,   581,   130,   821,  -335,  -335,   206,   221,   266,  -335,
    -335,   267,  -335,   260,  -335,  -335,     7,  -335,   270,  -335,
    -335,    78,   838,  -335,   821,  -335,  -335,   501,   821,   273,
    -335,   122,   274,   265,  -335,  -335,  -335,  -335,   277,  -335,
     278,   821,  -335,  -335,  -335,   821,  -335,  -335,   226,  -335,
     286,  -335,  -335,  -335,   581,  -335,  -335,   185,   136,    -3,
     247,   821,  -335,    45,   288,    50,   290,  -335,   246,  -335,
    -335,   421,    43,   581,   289,   275,   294,   581,  -335,  -335,
     723,  -335,   295,   296,  -335,   581,   265,  -335,   821,  -335,
    -335,  -335,   298,   838,  -335,  -335,  -335,   838,   299,   838,
    -335,  -335,  -335,   838,   302,  -335,  -335,  -335,  -335,   821,
    -335,  -335,   581,   300,  -335,   581,  -335,  -335,   821,  -335,
    -335,   789,  -335,  -335,  -335,   304,   821,    91,  -335,   838,
      50,  -335,   838,  -335,  -335,  -335,   581,  -335,  -335,   821,
    -335,   581,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,     0,     1,     0,     0,     0,    88,     0,
      89,     0,     0,     3,     0,     0,   319,     0,     0,     0,
      25,   243,   239,   241,   222,   232,     4,     0,   233,   234,
      82,   221,    76,    94,    91,   245,   223,     0,     0,     0,
     317,     6,    13,     0,   134,   132,     5,    38,    43,    44,
      45,    46,    47,    48,    83,    84,    85,    87,    86,    49,
      99,   100,    50,    51,    52,    39,   127,   128,   129,   130,
     131,    74,   179,   180,   182,   185,   186,   199,   201,   203,
     205,   209,   213,     0,   220,   227,   235,   177,    58,   133,
      92,   126,   118,     0,   314,     0,   282,    16,   271,    81,
     124,     0,     0,     0,   122,     0,   116,   101,   111,     0,
       0,     0,    74,     0,   242,    74,   238,     0,   237,   236,
      74,     0,   240,   184,     0,    71,    74,    98,    90,   143,
       0,   155,   157,   316,    12,    15,    14,     0,   273,     0,
       0,   176,     0,   190,   189,   191,   193,   195,   197,   188,
     192,     0,   194,     0,     0,     0,     0,   207,   208,     0,
     212,   211,     0,   218,   217,   216,   215,     0,   219,   225,
     244,    64,    66,    70,    69,     0,    67,    60,    63,    59,
      68,    62,    61,    65,    54,     0,     0,     0,   290,     9,
     231,     0,     0,     0,     0,   269,     0,     0,     0,   318,
     103,   120,   135,     0,     0,   251,     0,     0,     0,    32,
       0,    20,    23,     0,     0,    31,   275,   280,   230,    31,
     248,   228,     0,    31,   246,   229,    80,    31,     0,    93,
       0,   139,     0,     0,    41,     0,   272,     0,   181,   183,
     198,   196,   187,   200,   202,   204,   206,   210,   214,     0,
       0,   290,   263,   226,    58,    56,    55,    53,   125,   119,
       0,    10,     0,   315,   287,     0,    25,     0,   268,    96,
       0,     0,   109,   105,   102,   115,   107,     0,     0,   117,
     110,   250,    29,    37,     0,    27,     0,    31,   277,     0,
      30,   281,   249,     0,   247,     0,    31,    72,    75,    96,
       0,   164,     0,     0,     0,     0,   156,    40,    42,    73,
       0,   254,   224,     0,     0,   260,     0,   258,     0,    57,
       0,     0,     0,   301,   288,    31,   286,     0,   285,    19,
       0,     0,   270,     0,   123,   141,     0,     0,   113,   121,
     138,    35,    33,     0,    28,    22,    24,    21,    31,   274,
     278,     0,     0,    78,    30,    79,    97,     0,   159,     0,
     144,   150,     0,   150,   153,   154,   178,   252,     0,   253,
     256,   263,     8,   297,   292,     0,   298,   300,   289,   295,
       0,    18,    17,    95,     0,   106,   108,   112,   150,    34,
       0,    30,   279,   311,    25,   305,   169,   173,   172,    77,
     167,     0,   163,     0,     0,   152,     0,     0,   140,   259,
     255,   262,   265,   294,   299,     0,   150,   114,     0,   136,
      36,    26,     0,     0,   310,   308,   309,     0,     0,     0,
     304,   302,   303,     0,    31,   165,   166,   160,   161,     0,
     158,   146,     0,     0,   145,     0,   148,   257,   267,   261,
     264,     0,   296,   283,   142,     0,     0,   313,   175,     0,
     307,   171,    30,   168,   162,   149,     0,   147,   266,     0,
     291,     0,   276,   312,   174,   306,   170,   151,   293,   137
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -335,  -335,  -335,  -335,  -335,   268,    69,  -335,  -335,   279,
    -335,  -335,  -246,  -335,  -335,  -335,  -335,  -204,  -200,  -335,
    -335,  -327,    -2,  -335,    89,  -335,   142,    67,  -335,  -335,
       2,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,    26,  -335,  -335,  -335,  -335,  -335,  -335,   -55,
     131,    64,  -335,  -335,    20,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -334,  -335,  -335,  -335,    32,   -23,  -335,  -335,  -233,
    -335,  -335,  -335,  -320,  -335,    -5,  -335,  -136,   204,    -6,
    -335,  -335,    -8,   192,   193,   187,  -335,   201,  -335,   178,
    -335,   -73,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,   -65,   -24,  -335,
    -335,    -1,  -335,   -29,  -335,  -335,  -335,  -335,   308,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,   -99,  -335,  -101,
     241,  -335,   -93,  -103,  -335,  -335,     3,  -335
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    41,     3,    42,   260,    43,    44,    45,
     194,   267,   110,   287,   111,   344,   211,   291,   212,   284,
     341,    46,   301,   137,    48,    49,   254,   184,   185,    50,
     138,   125,   296,   297,    51,    52,    53,    54,    55,    56,
      57,    58,   334,   229,    59,    60,    61,   102,   274,   275,
     106,   276,   338,   107,   108,    62,   201,    63,    64,    65,
      66,   278,   388,    67,   303,    68,   384,    69,   230,   360,
     361,   405,   444,    70,   232,   131,   362,   439,   440,   302,
     401,   395,   434,   396,   397,    71,   141,    72,    73,    74,
      75,   153,    76,    77,    78,    79,   159,    80,   162,    81,
     167,    82,    83,    84,   169,    85,   116,   117,   121,   113,
      86,   122,   118,    87,   253,   316,   370,   317,   318,   449,
     450,    99,   195,    88,   114,   348,   349,   216,    89,   192,
     193,   327,   261,   262,   413,   452,   324,   325,   376,   430,
     431,   432,   424,   425,   426,    95,    90,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    47,    94,   237,    98,   128,   100,    98,   283,   217,
     168,   133,   220,   105,   101,   292,   112,   115,   120,   294,
     330,   123,   -30,   298,   207,   119,    93,   126,   127,   408,
     400,   187,   328,   130,   132,   163,   171,   154,   199,   310,
     271,   139,   204,   190,   272,   340,   172,     4,   208,   437,
     191,   208,   209,   157,   419,   209,   173,   187,   174,   438,
     375,   188,   140,   175,   214,   249,   189,   273,   250,   196,
     363,   364,    92,   140,   436,   142,   164,   158,   210,   214,
     -30,   176,   454,   347,   222,   423,   177,     7,   109,   165,
     429,   166,   355,    92,   248,   251,   252,   178,   382,   179,
     160,   213,   129,   457,   205,   180,   140,   458,   234,   460,
     181,   161,   182,   461,   215,    96,   183,   219,    97,   226,
     214,   379,   223,   200,    21,   214,   104,   235,   227,    22,
      23,   423,    24,    25,   170,    27,   239,    28,    29,   474,
     154,     6,   476,    31,   392,   242,   255,     9,   428,   404,
     155,   416,    11,   358,   156,   358,   255,   359,    35,    36,
     304,   305,   418,   404,   186,   197,  -284,   198,   270,   202,
     441,   203,   206,   218,   446,   214,   221,   312,   256,   225,
     222,   258,   453,   228,   231,   350,   263,   233,   256,   420,
     236,   269,   240,   -11,   241,   259,   268,   265,   264,  -104,
       7,   281,   277,   286,   266,   187,    98,   175,   288,   465,
     290,   280,   467,   289,    98,   393,   398,   282,   285,   295,
     377,   293,   320,   299,     7,   306,   311,   331,   337,   333,
     463,   309,   329,   477,   335,   326,    20,    21,   479,   342,
     272,   343,    22,    23,   339,    24,    25,   315,    27,   346,
      28,    29,   351,   352,   354,   368,    31,   323,  -262,   357,
     332,    21,   369,   367,   371,   372,    22,    23,   378,    24,
      25,    35,    36,   380,    28,    29,   386,    40,   381,   385,
      31,   345,   387,   389,   390,   309,   391,   398,   403,   407,
     353,   398,   404,   398,   410,    35,    36,   398,   409,   -30,
     132,   415,   421,   427,   442,   366,   433,   140,   443,   445,
     448,   134,   451,   456,   459,   466,   373,   374,   462,   471,
     313,   319,   135,   398,   308,   356,   398,   257,   383,     5,
       6,     7,   417,     8,   279,   336,     9,   365,   406,    10,
     247,    11,    12,   245,   238,   447,   243,   412,   244,   399,
      13,   136,   470,   402,    14,    47,    15,    16,    17,   475,
     246,   224,    18,    19,   473,     0,   411,    20,    21,     0,
     414,     0,     0,    22,    23,     0,    24,    25,    26,    27,
       0,    28,    29,     0,    30,     0,   422,    31,     0,    32,
      33,     0,    34,     0,     0,     0,     0,     0,     0,    47,
       0,     0,    35,    36,    37,   315,    38,    39,    40,     0,
       0,     0,     0,   455,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     0,     8,     0,   464,     9,     0,     0,    10,   435,
      11,    12,     0,   468,     0,     0,   323,     0,     0,     0,
       0,   472,     0,    14,     0,    15,    16,    17,     0,     0,
       0,    18,    19,     0,   478,     0,    20,    21,     0,     0,
       0,     0,    22,    23,     0,    24,    25,     0,    27,     0,
      28,    29,     0,    30,     0,     0,    31,     0,    32,    33,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    37,     0,    38,    39,    40,     5,     6,
       7,     0,     8,     0,     0,     9,     0,     0,    10,     0,
      11,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,    15,    16,    17,     0,     0,
       0,    18,    19,     0,     0,     0,    20,    21,     0,     0,
       0,     0,    22,    23,     0,    24,    25,     0,    27,     0,
      28,    29,     0,    30,     0,     0,    31,     0,    32,    33,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    36,    37,     0,    38,    39,    40,     5,     0,
       7,     0,     8,     0,     0,     0,     0,     0,    10,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,    16,    17,     0,     0,
       0,     0,    19,     0,     0,     0,    20,    21,     0,     0,
       0,     0,    22,    23,     0,    24,    25,   300,    27,     0,
      28,    29,     0,    30,     0,     0,    31,     0,    32,    33,
       5,    34,     7,     0,     8,     0,     0,     0,     0,     0,
      10,    35,    36,    12,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,    16,    17,
       0,     0,     0,     0,    19,     0,     0,     0,    20,    21,
       0,     7,     0,     0,    22,    23,     0,    24,    25,   307,
      27,     0,    28,    29,     0,    30,   321,     0,    31,     0,
      32,    33,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    36,     0,     0,    20,    21,    40,
       0,     0,     7,    22,    23,     0,    24,    25,  -263,    27,
       0,    28,    29,     0,   314,     0,     0,    31,     0,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     322,     0,    35,    36,     0,     0,     0,     0,    20,    21,
       0,     0,     0,     0,    22,    23,     0,    24,    25,     0,
      27,     7,    28,    29,     0,    20,    21,     0,    31,     0,
       0,    22,    23,   314,    24,    25,     0,    27,     7,    28,
      29,     0,     0,    35,    36,    31,     0,     0,     0,     0,
       0,   124,     0,   469,     0,     0,     0,    20,    21,     0,
      35,    36,     0,    22,    23,     0,    24,    25,     0,    27,
       7,    28,    29,     0,    20,    21,     0,    31,     0,     0,
      22,    23,     0,    24,    25,     0,    27,     7,    28,    29,
       0,     0,    35,    36,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,     0,    35,
      36,     0,    22,    23,     0,    24,    25,     0,    27,     0,
      28,    29,     0,   394,    21,     0,    31,     0,     0,    22,
      23,     0,    24,    25,     0,    27,   143,    28,    29,     0,
       0,    35,    36,    31,   144,   145,   146,     0,     0,   147,
       0,   148,     0,     0,     0,     0,   149,   150,    35,    36,
       0,     0,     0,     0,   151,   152
};

static const yytype_int16 yycheck[] =
{
       5,     3,     7,   139,    12,    34,    14,    15,   208,   112,
      83,    40,   115,    18,    15,   219,    21,    22,    23,   223,
     266,    27,    15,   227,    24,    22,     6,    32,    33,   363,
     357,    21,   265,    38,    39,    22,     3,    10,    21,    27,
      51,    40,     6,     9,    55,   278,    13,     0,    51,     6,
      16,    51,    55,    47,   388,    55,    23,    21,    25,    16,
      30,    51,    61,    30,    34,    21,    56,    78,    24,    42,
     303,   304,    55,    61,   401,     5,    63,    71,    78,    34,
      73,    48,   416,   287,    34,    40,    53,     9,    15,    76,
      40,    78,   296,    55,   167,    51,    52,    64,   331,    66,
      54,    15,    15,   423,   109,    72,    61,   427,    56,   429,
      77,    65,    79,   433,   112,    55,    83,   115,    55,   124,
      34,   325,   120,   103,    46,    34,    55,    75,   126,    51,
      52,    40,    54,    55,    80,    57,   142,    59,    60,   459,
      10,     8,   462,    65,   348,   153,   175,    14,   394,    27,
      12,   384,    19,    31,     4,    31,   185,    33,    80,    81,
      15,    16,    26,    27,    16,    42,    15,    41,   197,    15,
     403,    16,    15,    69,   407,    34,    73,   250,   175,    74,
      34,   186,   415,    16,    15,   288,   191,     6,   185,   389,
      16,   196,    57,    73,    42,    55,    16,    15,    51,    41,
       9,   206,    16,    30,    51,    21,   214,    30,   213,   442,
      16,    55,   445,   214,   222,   351,   352,    55,    55,    16,
     323,   222,    73,   228,     9,   233,    55,    15,     6,    16,
     434,   236,    73,   466,    15,   264,    45,    46,   471,    73,
      55,    16,    51,    52,    55,    54,    55,   252,    57,    16,
      59,    60,    42,    42,    16,    21,    65,   262,    15,    43,
     268,    46,    74,    73,    15,    56,    51,    52,    16,    54,
      55,    80,    81,    73,    59,    60,    55,    86,    73,    73,
      65,   286,    16,    16,    24,   290,    16,   423,    15,    15,
     295,   427,    27,   429,    16,    80,    81,   433,    21,    73,
     305,    15,    55,    15,    15,   310,    16,    61,    33,    15,
      15,    43,    16,    15,    15,    15,   321,   322,    16,    15,
     251,   254,    43,   459,   235,   299,   462,   185,   333,     7,
       8,     9,   387,    11,   203,   271,    14,   305,   361,    17,
     162,    19,    20,   156,   140,   410,   154,   371,   155,   354,
      28,    43,   451,   358,    32,   357,    34,    35,    36,   460,
     159,   120,    40,    41,   457,    -1,   371,    45,    46,    -1,
     375,    -1,    -1,    51,    52,    -1,    54,    55,    56,    57,
      -1,    59,    60,    -1,    62,    -1,   391,    65,    -1,    67,
      68,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,   401,
      -1,    -1,    80,    81,    82,   410,    84,    85,    86,    -1,
      -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,
       9,    -1,    11,    -1,   439,    14,    -1,    -1,    17,    18,
      19,    20,    -1,   448,    -1,    -1,   451,    -1,    -1,    -1,
      -1,   456,    -1,    32,    -1,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    -1,   469,    -1,    45,    46,    -1,    -1,
      -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,    -1,
      59,    60,    -1,    62,    -1,    -1,    65,    -1,    67,    68,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    -1,    84,    85,    86,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    -1,    17,    -1,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,    -1,
      59,    60,    -1,    62,    -1,    -1,    65,    -1,    67,    68,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    -1,    84,    85,    86,     7,    -1,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    51,    52,    -1,    54,    55,    56,    57,    -1,
      59,    60,    -1,    62,    -1,    -1,    65,    -1,    67,    68,
       7,    70,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    80,    81,    20,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    46,
      -1,     9,    -1,    -1,    51,    52,    -1,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    24,    -1,    65,    -1,
      67,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    -1,    -1,    45,    46,    86,
      -1,    -1,     9,    51,    52,    -1,    54,    55,    15,    57,
      -1,    59,    60,    -1,    21,    -1,    -1,    65,    -1,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    81,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    51,    52,    -1,    54,    55,    -1,
      57,     9,    59,    60,    -1,    45,    46,    -1,    65,    -1,
      -1,    51,    52,    21,    54,    55,    -1,    57,     9,    59,
      60,    -1,    -1,    80,    81,    65,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    24,    -1,    -1,    -1,    45,    46,    -1,
      80,    81,    -1,    51,    52,    -1,    54,    55,    -1,    57,
       9,    59,    60,    -1,    45,    46,    -1,    65,    -1,    -1,
      51,    52,    -1,    54,    55,    -1,    57,     9,    59,    60,
      -1,    -1,    80,    81,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    80,
      81,    -1,    51,    52,    -1,    54,    55,    -1,    57,    -1,
      59,    60,    -1,    45,    46,    -1,    65,    -1,    -1,    51,
      52,    -1,    54,    55,    -1,    57,    29,    59,    60,    -1,
      -1,    80,    81,    65,    37,    38,    39,    -1,    -1,    42,
      -1,    44,    -1,    -1,    -1,    -1,    49,    50,    80,    81,
      -1,    -1,    -1,    -1,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,    92,     0,     7,     8,     9,    11,    14,
      17,    19,    20,    28,    32,    34,    35,    36,    40,    41,
      45,    46,    51,    52,    54,    55,    56,    57,    59,    60,
      62,    65,    67,    68,    70,    80,    81,    82,    84,    85,
      86,    91,    93,    95,    96,    97,   109,   110,   112,   113,
     117,   122,   123,   124,   125,   126,   127,   128,   129,   132,
     133,   134,   143,   145,   146,   147,   148,   151,   153,   155,
     161,   173,   175,   176,   177,   178,   180,   181,   182,   183,
     185,   187,   189,   190,   191,   193,   198,   201,   211,   216,
     234,   173,    55,   142,   173,   233,    55,    55,   180,   209,
     180,   209,   135,   235,    55,   173,   138,   141,   142,    15,
     100,   102,   173,   197,   212,   173,   194,   195,   200,   234,
     173,   196,   199,   177,    71,   119,   173,   173,   211,    15,
     173,   163,   173,   211,    93,    97,   216,   111,   118,    40,
      61,   174,     5,    29,    37,    38,    39,    42,    44,    49,
      50,    57,    58,   179,    10,    12,     4,    47,    71,   184,
      54,    65,   186,    22,    63,    76,    78,   188,   189,   192,
      80,     3,    13,    23,    25,    30,    48,    53,    64,    66,
      72,    77,    79,    83,   115,   116,    16,    21,    51,    56,
       9,    16,   217,   218,    98,   210,    42,    42,    41,    21,
     142,   144,    15,    16,     6,   173,    15,    24,    51,    55,
      78,   104,   106,    15,    34,   118,   215,   231,    69,   118,
     231,    73,    34,   118,   228,    74,   173,   118,    16,   131,
     156,    15,   162,     6,    56,    75,    16,   175,   176,   177,
      57,    42,   180,   181,   182,   183,   185,   187,   189,    21,
      24,    51,    52,   202,   114,   211,   234,   114,   173,    55,
      94,   220,   221,   173,    51,    15,    51,    99,    16,   173,
     211,    51,    55,    78,   136,   137,   139,    16,   149,   138,
      55,   173,    55,   106,   107,    55,    30,   101,   173,   209,
      16,   105,   105,   209,   105,    16,   120,   121,   105,   173,
      56,   110,   167,   152,    15,    16,   180,    56,   112,   173,
      27,    55,   189,    94,    21,   173,   203,   205,   206,   115,
      73,    24,    78,   173,   224,   225,   211,   219,   167,    73,
     100,    15,   180,    16,   130,    15,   139,     6,   140,    55,
     167,   108,    73,    16,   103,   173,    16,   105,   213,   214,
     231,    42,    42,   173,    16,   105,   130,    43,    31,    33,
     157,   158,   164,   167,   167,   163,   173,    73,    21,    74,
     204,    15,    56,   173,   173,    30,   226,   231,    16,   105,
      73,    73,   167,   173,   154,    73,    55,    16,   150,    16,
      24,    16,   105,   175,    45,   169,   171,   172,   175,   173,
     109,   168,   173,    15,    27,   159,   164,    15,   159,    21,
      16,   173,   206,   222,   173,    15,   167,   137,    26,   159,
     106,    55,   173,    40,   230,   231,   232,    15,   100,    40,
     227,   228,   229,    16,   170,    18,   109,     6,    16,   165,
     166,   167,    15,    33,   160,    15,   167,   205,    15,   207,
     208,    16,   223,   167,   159,   173,    15,   171,   171,    15,
     171,   171,    16,   105,   173,   167,    15,   167,   173,    24,
     225,    15,   173,   230,   171,   227,   171,   167,   173,   167
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    98,    97,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   123,   124,   124,   124,   124,   124,   125,   126,
     127,   127,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   134,   135,   135,   136,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   144,   144,   145,   145,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   147,   149,   148,   150,   150,   152,
     151,   154,   153,   156,   155,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   162,   162,   163,   163,   164,   164,
     165,   165,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   173,   174,   174,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   179,   180,
     180,   181,   181,   182,   182,   183,   183,   184,   184,   185,
     185,   186,   186,   187,   187,   188,   188,   188,   188,   189,
     189,   190,   190,   190,   191,   191,   192,   192,   193,   193,
     193,   193,   193,   193,   193,   193,   194,   194,   195,   195,
     196,   196,   197,   197,   198,   198,   199,   199,   200,   200,
     201,   201,   202,   202,   202,   203,   203,   204,   204,   205,
     205,   205,   206,   206,   207,   207,   208,   208,   209,   209,
     210,   210,   211,   211,   212,   212,   213,   213,   214,   214,
     215,   215,   217,   216,   218,   216,   219,   219,   220,   221,
     221,   222,   222,   223,   223,   224,   224,   224,   225,   225,
     226,   226,   227,   227,   228,   228,   229,   229,   230,   230,
     231,   231,   232,   232,   233,   233,   234,   234,   235,   235
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,     6,     3,
       1,     0,     2,     1,     2,     2,     0,     6,     3,     2,
       2,     4,     2,     0,     4,     0,     3,     0,     3,     2,
       1,     0,     1,     3,     3,     2,     3,     0,     1,     1,
       4,     3,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     3,     0,     3,     0,     3,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     1,     2,     0,     3,     0,     1,
       1,     2,     4,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     3,     0,     1,     3,     1,     3,
       3,     3,     0,     5,     2,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     7,     5,     0,     0,
       6,     0,     8,     0,     5,     3,     3,     4,     3,     3,
       0,     3,     0,     5,     3,     0,     3,     1,     3,     1,
       1,     1,     2,     0,     1,     4,     2,     1,     3,     1,
       3,     2,     1,     1,     4,     3,     2,     1,     4,     0,
       1,     3,     1,     3,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     4,     2,     2,     0,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     0,     1,     0,     2,     1,     2,     3,     2,     3,
       4,     3,     3,     3,     2,     3,     2,     3,     0,     3,
       1,     4,     1,     0,     1,     0,     2,     1,     3,     2,
       3,     0,     3,     2,     4,     2,     5,     0,     1,     2,
       1,     2,     0,     8,     0,     5,     1,     0,     2,     3,
       0,     3,     0,     3,     0,     2,     4,     2,     2,     3,
       1,     0,     1,     1,     5,     4,     3,     2,     1,     1,
       5,     4,     3,     2,     1,     3,     2,     1,     2,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 10:
#line 65 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1909 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 1915 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 78 "includes/parse.y" /* yacc.c:1646  */
    { ++depthOfFunc; }
#line 1921 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 79 "includes/parse.y" /* yacc.c:1646  */
    {
      --depthOfFunc;
    }
#line 1929 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 85 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1935 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 87 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = new TuplesLiteral; pool.add((yyval.node)); }
#line 1941 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 131 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-3].node); }
#line 1947 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 133 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 1953 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 141 "includes/parse.y" /* yacc.c:1646  */
    { 
      // No output when meeting assignment
      AssBinaryNode* ass = dynamic_cast<AssBinaryNode*>((yyvsp[0].node)); 
      if(!ass) {
        (yyvsp[0].node) -> eval() -> print(); 
        std::cout << std::endl;
      }
      else 
        (yyvsp[0].node) -> eval(); 
      (yyval.node) = (yyvsp[0].node);
    }
#line 1969 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 163 "includes/parse.y" /* yacc.c:1646  */
    {
      Node* rhs;
      switch((yyvsp[-1].integer)){
        case PLUSEQUAL:
          rhs = new AddBinaryNode(const_cast<Literal*>((yyval.node)->eval()), (yyvsp[0].node));
          pool.add(rhs);
          (yyval.node) = new AssBinaryNode((yyval.node), rhs);
          pool.add((yyval.node));
          break;
        case MINEQUAL:
          rhs = new SubBinaryNode(const_cast<Literal*>((yyval.node)->eval()), (yyvsp[0].node));
          pool.add(rhs);
          (yyval.node) = new AssBinaryNode((yyval.node), rhs);
          pool.add((yyval.node));
          break;
 	      case STAREQUAL:
          rhs = new MulBinaryNode(const_cast<Literal*>((yyval.node)->eval()), (yyvsp[0].node)); 
          pool.add(rhs);
          (yyval.node) = new AssBinaryNode((yyval.node), rhs);
          pool.add((yyval.node));
          break;
	      case SLASHEQUAL:
          rhs = new DivBinaryNode(const_cast<Literal*>((yyval.node)->eval()), (yyvsp[0].node));
          pool.add(rhs);
          (yyval.node) = new AssBinaryNode((yyval.node), rhs);
          pool.add((yyval.node));
          break;
	      case PERCENTEQUAL:
          rhs = new ModBinaryNode(const_cast<Literal*>((yyval.node)->eval()), (yyvsp[0].node));
          pool.add(rhs);
          (yyval.node) = new AssBinaryNode((yyval.node), rhs);
          pool.add((yyval.node));
          break;
	      case AMPEREQUAL:
          break;
	      case VBAREQUAL:
          break;
	      case CIRCUMFLEXEQUAL:
          break;
	      case LEFTSHIFTEQUAL:
          break;
	      case RIGHTSHIFTEQUAL:
          break;
	      case DOUBLESTAREQUAL:
          rhs = new PowBinaryNode(const_cast<Literal*>((yyval.node)->eval()), (yyvsp[0].node));
          pool.add(rhs);
          (yyval.node) = new AssBinaryNode((yyval.node), rhs);
          pool.add((yyval.node));
          break;
	      case DOUBLESLASHEQUAL:
          rhs = new DoubleSlashBinaryNode(const_cast<Literal*>((yyval.node)->eval()), (yyvsp[0].node));
          pool.add(rhs);
          (yyval.node) = new AssBinaryNode((yyval.node), rhs);
          pool.add((yyval.node));
          break;
     
      }
    }
#line 2032 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 222 "includes/parse.y" /* yacc.c:1646  */
    {
      if((yyvsp[0].node)) {
        (yyval.node) = new AssBinaryNode((yyvsp[-1].node), (yyvsp[0].node));
        pool.add((yyval.node));
      }
      else {
        (yyval.node) = (yyvsp[-1].node);
      }
    }
#line 2046 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 234 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2052 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 236 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2058 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 240 "includes/parse.y" /* yacc.c:1646  */
    { 
      if((yyvsp[0].node)) {
        (yyval.node) = new AssBinaryNode((yyvsp[-1].node), (yyvsp[0].node)); 
        pool.add((yyval.node));
      }
      else {
        (yyval.node) = (yyvsp[-1].node);
      }
    }
#line 2072 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 250 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2078 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 254 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = PLUSEQUAL; }
#line 2084 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 256 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = MINEQUAL; }
#line 2090 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 258 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = STAREQUAL; }
#line 2096 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 260 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = SLASHEQUAL; }
#line 2102 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 262 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = PERCENTEQUAL; }
#line 2108 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 264 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = AMPEREQUAL; }
#line 2114 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 266 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = VBAREQUAL; }
#line 2120 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 268 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = CIRCUMFLEXEQUAL; }
#line 2126 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 270 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = LEFTSHIFTEQUAL; }
#line 2132 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 272 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = RIGHTSHIFTEQUAL; }
#line 2138 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 274 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = DOUBLESTAREQUAL; }
#line 2144 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 276 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = DOUBLESLASHEQUAL; }
#line 2150 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 284 "includes/parse.y" /* yacc.c:1646  */
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>((yyvsp[-2].node));
      IdentNode* idNode = dynamic_cast<IdentNode*>((yyvsp[0].node));
      if(tuples) {
        if(idNode) 
          tuples -> add_back(idNode);
        else
          tuples -> add_back(const_cast<Literal*>((yyvsp[0].node)->eval()));
        (yyval.node) = tuples;
      }
      else {
        if(idNode)
          tuples = new TuplesLiteral(idNode);
        else
          tuples = new TuplesLiteral(const_cast<Literal*>((yyvsp[0].node)->eval()));
        (yyval.node) = tuples;
        pool.add((yyval.node));
      }
    }
#line 2174 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 304 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2180 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 308 "includes/parse.y" /* yacc.c:1646  */
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>((yyvsp[-1].node));
      if(tuples) {
        tuples -> add_front(const_cast<Literal*>((yyvsp[-2].node)->eval()));
        const std::list<Node*>& elements = tuples -> getVec();
        std::list<Node*>::const_iterator it = elements.begin();
        while(it!=elements.end()){
          (*it) -> eval() -> print();
          it++;
          if(it==elements.end()) {}
          else
            std::cout << ' ';
        }
      }
      else {
        (yyvsp[-2].node) -> eval() -> print();
      }
      std::cout << std::endl;
    }
#line 2204 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 328 "includes/parse.y" /* yacc.c:1646  */
    { std::cout << std::endl; }
#line 2210 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 445 "includes/parse.y" /* yacc.c:1646  */
    { ++depthOfFunc; }
#line 2216 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 446 "includes/parse.y" /* yacc.c:1646  */
    {
      --depthOfFunc;
    }
#line 2224 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 455 "includes/parse.y" /* yacc.c:1646  */
    { ++depthOfFunc; }
#line 2230 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 456 "includes/parse.y" /* yacc.c:1646  */
    {
      --depthOfFunc;
    }
#line 2238 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 461 "includes/parse.y" /* yacc.c:1646  */
    { ++depthOfFunc; }
#line 2244 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 462 "includes/parse.y" /* yacc.c:1646  */
    {
      --depthOfFunc;
    }
#line 2252 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 467 "includes/parse.y" /* yacc.c:1646  */
    { ++depthOfFunc; }
#line 2258 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 468 "includes/parse.y" /* yacc.c:1646  */
    {
      --depthOfFunc;
    }
#line 2266 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 537 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2272 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 539 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2278 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 547 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2284 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 549 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2290 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 553 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2296 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 555 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2302 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 559 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2308 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 561 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2314 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 565 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2320 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 570 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = LESS; }
#line 2326 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 572 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = GREATER; }
#line 2332 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 574 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = EQEQUAL; }
#line 2338 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 576 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = GREATEREQUAL; }
#line 2344 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 578 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = LESSEQUAL; }
#line 2350 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 580 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = GRLT; }
#line 2356 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 582 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = NOTEQUAL; }
#line 2362 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 584 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = IN; }
#line 2368 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 586 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = -IN; }
#line 2374 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 588 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = IS; }
#line 2380 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 590 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = -IS; }
#line 2386 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 594 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2392 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 599 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2398 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 604 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2404 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 609 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2410 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 611 "includes/parse.y" /* yacc.c:1646  */
    { Node* rhs;
      IntLiteral* _intLiteral = dynamic_cast<IntLiteral*>(const_cast<Literal*>((yyvsp[-2].node)->eval()));
      switch((yyvsp[-1].integer)){
        case LEFTSHIFT:
          if(_intLiteral) {
            IntLiteral* intNode = new IntLiteral(2);
            pool.add(intNode);
            rhs = new PowBinaryNode(intNode, (yyvsp[0].node));
            pool.add(rhs);
            (yyval.node) = new MulBinaryNode(_intLiteral, rhs);
            pool.add((yyval.node));
          }
          else 
            throw "error";
          break;
        case RIGHTSHIFT:
          if(_intLiteral) {
            IntLiteral* intNode = new IntLiteral(2);
            pool.add(intNode);
            rhs = new PowBinaryNode(intNode, (yyvsp[0].node));
            pool.add(rhs);
            (yyval.node) = new DivBinaryNode(_intLiteral, rhs);
            pool.add((yyval.node));
          }
          else 
            throw "error";
          break;
        default:
          break;
      }
    }
#line 2446 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 646 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = LEFTSHIFT; }
#line 2452 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 648 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = RIGHTSHIFT; }
#line 2458 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 652 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2464 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 654 "includes/parse.y" /* yacc.c:1646  */
    { switch((yyvsp[-1].integer)){
        case PLUS:
          (yyval.node) = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
          pool.add((yyval.node));
          break;
        case MINUS:
          (yyval.node) = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
          pool.add((yyval.node));
          break;
        default:
          break;
      }
    }
#line 2482 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 670 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = PLUS; }
#line 2488 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 672 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = MINUS; }
#line 2494 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 676 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2500 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 678 "includes/parse.y" /* yacc.c:1646  */
    { switch((yyvsp[-1].integer)){
        case STAR:
          (yyval.node) = new MulBinaryNode((yyvsp[-2].node), (yyvsp[0].node)); 
          pool.add((yyval.node));
          break;
        case SLASH:
          (yyval.node) = new DivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
          pool.add((yyval.node));
          break;
        case PERCENT:
          (yyval.node) = new ModBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
          pool.add((yyval.node));
          break;
        case DOUBLESLASH:
          (yyval.node) = new DoubleSlashBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
          pool.add((yyval.node));
          break;
        default:
          break;
      }
    }
#line 2526 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 702 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = STAR; }
#line 2532 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 704 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = SLASH; }
#line 2538 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 706 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = PERCENT; }
#line 2544 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 708 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = DOUBLESLASH; }
#line 2550 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 712 "includes/parse.y" /* yacc.c:1646  */
    {
      Node* lhs;
      switch((yyvsp[-1].integer)) {
        case PLUS:
          (yyval.node) = (yyvsp[0].node); 
          break; 
        case MINUS:
          lhs = new IntLiteral(0);
          pool.add(lhs);
          (yyval.node) = new SubBinaryNode(lhs, (yyvsp[0].node));
          pool.add((yyval.node));
          break; 
        case TILDE:
          lhs = new IntLiteral(-1);
          pool.add(lhs);
          (yyval.node) = new SubBinaryNode(lhs, (yyvsp[0].node));
          pool.add((yyval.node));
          break; 
      }
    }
#line 2575 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 733 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2581 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 737 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = PLUS; }
#line 2587 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 739 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = MINUS; }
#line 2593 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 741 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.integer) = TILDE; }
#line 2599 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 745 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = new PowBinaryNode((yyvsp[-3].node), (yyvsp[0].node)); pool.add((yyval.node)); }
#line 2605 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 747 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2611 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 752 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2617 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 756 "includes/parse.y" /* yacc.c:1646  */
    { 
      if((yyvsp[-1].node)) {
        TuplesLiteral* _tuple = dynamic_cast<TuplesLiteral*>((yyvsp[-1].node));
        if(_tuple){
          _tuple->setType(tuple);
          (yyval.node) = _tuple;
        }
        else 
          (yyval.node) = (yyvsp[-1].node); 
      } 
      else { 
        TuplesLiteral* _tuple = new TuplesLiteral(); 
        _tuple->setType(tuple); 
        (yyval.node) = _tuple;
        pool.add((yyval.node)); 
      } 
    }
#line 2639 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 774 "includes/parse.y" /* yacc.c:1646  */
    { 
      if((yyvsp[-1].node)) {
        TuplesLiteral* _tuple = dynamic_cast<TuplesLiteral*>((yyvsp[-1].node));
        if(_tuple){
          _tuple->setType(list);
          (yyval.node) = _tuple;
        }
        else {
          TuplesLiteral* new_tuple = new TuplesLiteral((yyvsp[-1].node)); 
          new_tuple->setType(list); 
          (yyval.node) = new_tuple;
          pool.add((yyval.node)); 
        }
      } 
      else { 
        TuplesLiteral* _tuple = new TuplesLiteral(); 
        _tuple->setType(list); 
        (yyval.node) = _tuple;
        pool.add((yyval.node)); 
      } 
    }
#line 2665 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 796 "includes/parse.y" /* yacc.c:1646  */
    { 
      if((yyvsp[-1].node)) {
        TuplesLiteral* _tuple = dynamic_cast<TuplesLiteral*>((yyvsp[-1].node));
        if(_tuple){
          _tuple->setType(set);
          (yyval.node) = _tuple;
        }
        else 
          (yyval.node) = (yyvsp[-1].node); 
      } 
      else { 
        TuplesLiteral* _tuple = new TuplesLiteral(); 
        _tuple->setType(set); 
        (yyval.node) = _tuple;
        pool.add((yyval.node)); 
      } 
    }
#line 2687 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 814 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2693 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 816 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = new IdentNode((yyvsp[0].id)); pool.add((yyval.node)); delete [] (yyvsp[0].id);       }
#line 2699 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 818 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = new IntLiteral((yyvsp[0].integer)); pool.add((yyval.node));       }
#line 2705 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 820 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = new FloatLiteral((yyvsp[0].floatnumber)); pool.add((yyval.node));     }
#line 2711 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 822 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2717 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 826 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2723 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 828 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2729 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 832 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2735 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 834 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2741 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 838 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2747 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 840 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2753 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 844 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2759 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 846 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2765 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 244:
#line 850 "includes/parse.y" /* yacc.c:1646  */
    { 
      Node* rhs = new StrLiteral((yyvsp[0].id));
      pool.add(rhs);
      (yyval.node) = new AddBinaryNode((yyvsp[-1].node), rhs); 
      pool.add((yyval.node));
      delete [] (yyvsp[0].id);
    }
#line 2777 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 858 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = new StrLiteral((yyvsp[0].id)); pool.add((yyval.node)); delete [] (yyvsp[0].id); }
#line 2783 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 862 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2789 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 864 "includes/parse.y" /* yacc.c:1646  */
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>((yyvsp[-1].node));
      if(tuples) {
        IdentNode* idNode = dynamic_cast<IdentNode*>((yyvsp[-2].node));
        if(idNode)
          tuples -> add_front(idNode);
        else
          tuples -> add_front(const_cast<Literal*>((yyvsp[-2].node)->eval()));
        (yyval.node) = tuples;
      }
      else {
        (yyval.node) = (yyvsp[-2].node);
      }
    }
#line 2808 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 881 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2814 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 883 "includes/parse.y" /* yacc.c:1646  */
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>((yyvsp[-1].node));
      if(tuples) {
        IdentNode* idNode = dynamic_cast<IdentNode*>((yyvsp[-2].node));
        if(idNode)
          tuples -> add_front(idNode);
        else
          tuples -> add_front(const_cast<Literal*>((yyvsp[-2].node)->eval()));
        (yyval.node) = tuples;
      }
      else {
        (yyval.node) = (yyvsp[-2].node);
      }
    }
#line 2833 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 904 "includes/parse.y" /* yacc.c:1646  */
    { //FIXIT: type 
      //$2->setType(tuple); 
      (yyval.node) = (yyvsp[-1].node); 
    }
#line 2842 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 909 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2848 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 911 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2854 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 948 "includes/parse.y" /* yacc.c:1646  */
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>((yyvsp[-1].node));
      if(tuples) {
        IdentNode* idNode = dynamic_cast<IdentNode*>((yyvsp[-2].node));
        if(idNode)
          tuples -> add_front(idNode);
        else
          tuples -> add_front(const_cast<Literal*>((yyvsp[-2].node)->eval()));
        (yyval.node) = tuples;
      }
      else {
        (yyval.node) = (yyvsp[-2].node);
      }
    }
#line 2873 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 963 "includes/parse.y" /* yacc.c:1646  */
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>((yyvsp[0].node));
      if(tuples) {
        IdentNode* idNode = dynamic_cast<IdentNode*>((yyvsp[-1].node));
        if(idNode)
          tuples -> add_front(idNode);
        else
          tuples -> add_front(const_cast<Literal*>((yyvsp[-1].node)->eval()));
        (yyval.node) = tuples;
      }
      else {
        (yyval.node) = (yyvsp[-1].node);
      }
    }
#line 2892 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 980 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2898 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 982 "includes/parse.y" /* yacc.c:1646  */
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>((yyvsp[0].node));
      if(tuples) {
        IdentNode* idNode = dynamic_cast<IdentNode*>((yyvsp[-1].node));
        if(idNode)
          tuples -> add_front(idNode);
        else
          tuples -> add_front(const_cast<Literal*>((yyvsp[-1].node)->eval()));
        (yyval.node) = tuples;
      }
      else {
        (yyval.node) = (yyvsp[-1].node);
      }
    }
#line 2917 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1007 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2923 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1009 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2929 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1012 "includes/parse.y" /* yacc.c:1646  */
    { ++depthOfClass; }
#line 2935 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1013 "includes/parse.y" /* yacc.c:1646  */
    {
      --depthOfClass;
    }
#line 2943 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1016 "includes/parse.y" /* yacc.c:1646  */
    { ++depthOfClass; }
#line 2949 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1017 "includes/parse.y" /* yacc.c:1646  */
    {
      --depthOfClass;
    }
#line 2957 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1027 "includes/parse.y" /* yacc.c:1646  */
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>((yyvsp[-1].node));
      if(tuples) {
        IdentNode* idNode = dynamic_cast<IdentNode*>((yyvsp[-1].node));
        if(idNode)
          tuples -> add_back(idNode);
        else
          tuples -> add_back(const_cast<Literal*>((yyvsp[-1].node)->eval()));
        (yyval.node) = tuples;
      }
      else {
        (yyval.node) = (yyvsp[0].node);
      }
    }
#line 2976 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1044 "includes/parse.y" /* yacc.c:1646  */
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>((yyvsp[-2].node));
      IdentNode* idNode = dynamic_cast<IdentNode*>((yyvsp[-1].node));
      if(tuples) {
        if(idNode) 
          tuples -> add_back(idNode);
        else
          tuples -> add_back(const_cast<Literal*>((yyvsp[-1].node)->eval()));
        (yyval.node) = tuples;
      }
      else {
        if(idNode)
          tuples = new TuplesLiteral(idNode);
        else
          tuples = new TuplesLiteral(const_cast<Literal*>((yyvsp[-1].node)->eval()));
        (yyval.node) = tuples;
        pool.add((yyval.node));
      }
    }
#line 3000 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1064 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 3006 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1076 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 3012 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1078 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 3018 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1080 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 3024 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1084 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 3030 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1086 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 3036 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1118 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3042 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1120 "includes/parse.y" /* yacc.c:1646  */
    {
      TuplesLiteral* tuples = dynamic_cast<TuplesLiteral*>((yyvsp[-2].node));
      IdentNode* idNode = dynamic_cast<IdentNode*>((yyvsp[0].node));
      if(tuples) {
        if(idNode) 
          tuples -> add_back(idNode);
        else
          tuples -> add_back(const_cast<Literal*>((yyvsp[0].node)->eval()));
        (yyval.node) = tuples;
      }
      else {
        if(idNode)
          tuples = new TuplesLiteral(idNode);
        else
          tuples = new TuplesLiteral(const_cast<Literal*>((yyvsp[0].node)->eval()));
        (yyval.node) = tuples;
        pool.add((yyval.node));
      }
    }
#line 3066 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 3070 "parse.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
  return yyresult;
}
#line 1149 "includes/parse.y" /* yacc.c:1906  */

#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}

