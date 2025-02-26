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

#include "global.h"

int errorno = 0;
int tempCountAddress = 0;
std::vector<int> listID;
std::vector<int> listArgs;
int offset = 8;
int localOffset = 0;
bool contextGlobal = true;
int startLabel;

int yylex();
void yyerror(const char* s);

#line 87 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_VAR = 7,                        /* VAR  */
  YYSYMBOL_NUM = 8,                        /* NUM  */
  YYSYMBOL_LABEL = 9,                      /* LABEL  */
  YYSYMBOL_PROC = 10,                      /* PROC  */
  YYSYMBOL_NONE = 11,                      /* NONE  */
  YYSYMBOL_BEG = 12,                       /* BEG  */
  YYSYMBOL_END = 13,                       /* END  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_ADDOP = 15,                     /* ADDOP  */
  YYSYMBOL_MULOP = 16,                     /* MULOP  */
  YYSYMBOL_WRITE = 17,                     /* WRITE  */
  YYSYMBOL_READ = 18,                      /* READ  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_THEN = 20,                      /* THEN  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_WHILE = 22,                     /* WHILE  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_RELOP = 24,                     /* RELOP  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_FUNCTION = 26,                  /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 27,                 /* PROCEDURE  */
  YYSYMBOL_OR_ = 28,                       /* OR_  */
  YYSYMBOL_AND_ = 29,                      /* AND_  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* ';'  */
  YYSYMBOL_33_ = 33,                       /* '.'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_38_1 = 38,                      /* $@1  */
  YYSYMBOL_39_2 = 39,                      /* $@2  */
  YYSYMBOL_40_3 = 40,                      /* $@3  */
  YYSYMBOL_identifier_list = 41,           /* identifier_list  */
  YYSYMBOL_declarations = 42,              /* declarations  */
  YYSYMBOL_type = 43,                      /* type  */
  YYSYMBOL_standerd_type = 44,             /* standerd_type  */
  YYSYMBOL_subprogram_declarations = 45,   /* subprogram_declarations  */
  YYSYMBOL_subprogram_declaration = 46,    /* subprogram_declaration  */
  YYSYMBOL_47_4 = 47,                      /* $@4  */
  YYSYMBOL_subprogram_head = 48,           /* subprogram_head  */
  YYSYMBOL_49_5 = 49,                      /* $@5  */
  YYSYMBOL_50_6 = 50,                      /* $@6  */
  YYSYMBOL_arguments = 51,                 /* arguments  */
  YYSYMBOL_parametr_list = 52,             /* parametr_list  */
  YYSYMBOL_parametr = 53,                  /* parametr  */
  YYSYMBOL_compound_statement = 54,        /* compound_statement  */
  YYSYMBOL_optional_statments = 55,        /* optional_statments  */
  YYSYMBOL_statement_list = 56,            /* statement_list  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_58_7 = 58,                      /* @7  */
  YYSYMBOL_59_8 = 59,                      /* @8  */
  YYSYMBOL_60_9 = 60,                      /* @9  */
  YYSYMBOL_61_10 = 61,                     /* @10  */
  YYSYMBOL_62_11 = 62,                     /* @11  */
  YYSYMBOL_variable = 63,                  /* variable  */
  YYSYMBOL_procedure_statement = 64,       /* procedure_statement  */
  YYSYMBOL_expression_list = 65,           /* expression_list  */
  YYSYMBOL_expression = 66,                /* expression  */
  YYSYMBOL_simple_expression = 67,         /* simple_expression  */
  YYSYMBOL_term = 68,                      /* term  */
  YYSYMBOL_factor = 69                     /* factor  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
      30,    31,     2,     2,    34,     2,    33,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    32,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    22,    22,    25,    30,    22,    39,    40,    44,    59,
      63,    67,    68,    72,    73,    77,    77,    89,    89,   109,
     109,   132,   139,   143,   144,   148,   161,   167,   168,   172,
     173,   177,   180,   181,   182,   184,   187,   182,   193,   196,
     193,   204,   210,   219,   223,   226,   249,   252,   258,   259,
     265,   266,   273,   281,   284,   290,   291,   304,   305,   331,
     332,   333
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
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "ID", "INT",
  "REAL", "VAR", "NUM", "LABEL", "PROC", "NONE", "BEG", "END", "ASSIGN",
  "ADDOP", "MULOP", "WRITE", "READ", "IF", "THEN", "ELSE", "WHILE", "DO",
  "RELOP", "NOT", "FUNCTION", "PROCEDURE", "OR_", "AND_", "'('", "')'",
  "';'", "'.'", "','", "':'", "$accept", "program", "$@1", "$@2", "$@3",
  "identifier_list", "declarations", "type", "standerd_type",
  "subprogram_declarations", "subprogram_declaration", "$@4",
  "subprogram_head", "$@5", "$@6", "arguments", "parametr_list",
  "parametr", "compound_statement", "optional_statments", "statement_list",
  "statement", "@7", "@8", "@9", "@10", "@11", "variable",
  "procedure_statement", "expression_list", "expression",
  "simple_expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      10,     4,    18,   -67,   -67,    -3,    21,   -67,    14,    19,
      25,   -67,   -67,   -67,    46,    21,    20,     5,    51,    63,
      60,    49,   -67,    69,   -67,   -67,    40,    50,   -67,   -67,
     -67,   -67,    52,   -67,    55,    55,   -10,    56,    57,    11,
     -67,   -67,    75,    59,   -67,    68,   -67,   -67,     2,   -67,
      21,    58,    64,    11,    11,    11,    62,   -67,    13,    13,
      11,   -67,   -67,    41,    79,   -67,    11,   -67,    40,    11,
     -67,    43,    48,   -67,    69,   -67,    30,   -67,    32,    37,
      11,    79,   -67,    66,    78,    13,    11,    13,    13,    13,
      76,   -67,   -67,    69,   -67,    21,    70,   -67,    11,   -67,
     -67,    42,   -67,   -67,    79,    -5,    79,    79,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,    40,    40,    80,   -67,   -67,
      40,   -67
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     0,     6,     0,     0,
       0,     3,     7,     9,    14,     0,     4,     0,     0,     0,
       0,     0,    15,     0,    17,    19,    28,     0,    13,     9,
      11,    12,     0,    10,    22,    22,    44,     0,     0,     0,
      38,    33,     0,    27,    29,     0,    32,     5,     0,     8,
       0,     0,     0,     0,     0,     0,    43,    59,     0,     0,
       0,    57,    34,    48,    50,    55,     0,    26,     0,     0,
      16,     0,     0,    23,     0,    20,     0,    46,     0,     0,
       0,    51,    61,     0,     0,     0,     0,     0,     0,     0,
       0,    30,    31,     0,    21,     0,     0,    45,     0,    42,
      41,     0,    60,    35,    52,    49,    54,    53,    56,    39,
      25,    24,    18,    47,    58,     0,     0,     0,    40,    36,
       0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,     1,    71,    12,    29,   -67,
     -67,   -67,   -67,   -67,   -67,    72,   -67,     9,   -14,   -67,
     -67,   -66,   -67,   -67,   -67,   -67,   -67,   -26,   -67,   -43,
     -38,    22,   -55,   -54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     5,    13,    20,    71,    14,    32,    33,    16,
      21,    29,    22,    34,    35,    51,    72,    73,    41,    42,
      43,    44,    84,   115,   120,    66,   116,    61,    46,    76,
      77,    63,    64,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      45,    62,    91,    81,   -43,    82,    27,     8,     3,    15,
      85,    78,    79,     1,    26,    56,    17,    56,     4,    57,
      53,    57,    83,    87,    88,     7,    58,     6,    90,    12,
     104,    92,   106,   107,    70,   108,    59,   101,    59,    10,
      23,    60,    45,    60,    36,     9,    18,    19,    10,   117,
     118,    11,    26,    15,   121,    24,    85,    37,    38,    39,
     113,    97,    40,    99,    98,    86,    98,    25,   100,    87,
      88,    98,    26,   114,    30,    31,    98,    10,    93,    94,
      95,    28,    69,    47,    49,    50,    54,    55,    67,    45,
      45,    68,    80,    74,    45,    89,    75,   102,   103,   109,
      48,   119,   112,    96,   111,   110,     0,    52,   105
};

static const yytype_int8 yycheck[] =
{
      26,    39,    68,    58,    14,    59,    20,     6,     4,     7,
      15,    54,    55,     3,    12,     4,    15,     4,     0,     8,
      30,     8,    60,    28,    29,     4,    15,    30,    66,     4,
      85,    69,    87,    88,    48,    89,    25,    80,    25,    34,
      35,    30,    68,    30,     4,    31,    26,    27,    34,   115,
     116,    32,    12,     7,   120,     4,    15,    17,    18,    19,
      98,    31,    22,    31,    34,    24,    34,     4,    31,    28,
      29,    34,    12,    31,     5,     6,    34,    34,    35,    31,
      32,    32,    14,    33,    32,    30,    30,    30,    13,   115,
     116,    32,    30,    35,   120,    16,    32,    31,    20,    23,
      29,    21,    32,    74,    95,    93,    -1,    35,    86
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    37,     4,     0,    38,    30,     4,    41,    31,
      34,    32,     4,    39,    42,     7,    45,    41,    26,    27,
      40,    46,    48,    35,     4,     4,    12,    54,    32,    47,
       5,     6,    43,    44,    49,    50,     4,    17,    18,    19,
      22,    54,    55,    56,    57,    63,    64,    33,    42,    32,
      30,    51,    51,    30,    30,    30,     4,     8,    15,    25,
      30,    63,    66,    67,    68,    69,    61,    13,    32,    14,
      54,    41,    52,    53,    35,    32,    65,    66,    65,    65,
      30,    68,    69,    66,    58,    15,    24,    28,    29,    16,
      66,    57,    66,    35,    31,    32,    44,    31,    34,    31,
      31,    65,    31,    20,    68,    67,    68,    68,    69,    23,
      43,    53,    32,    66,    31,    59,    62,    57,    57,    21,
      60,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    38,    39,    40,    37,    41,    41,    42,    42,
      43,    44,    44,    45,    45,    47,    46,    49,    48,    50,
      48,    51,    51,    52,    52,    53,    54,    55,    55,    56,
      56,    57,    57,    57,    58,    59,    60,    57,    61,    62,
      57,    57,    57,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    69,
      69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,    13,     1,     3,     6,     0,
       1,     1,     1,     3,     0,     0,     4,     0,     7,     0,
       5,     3,     0,     1,     3,     3,     3,     1,     0,     1,
       3,     3,     1,     1,     0,     0,     0,     9,     0,     0,
       6,     4,     4,     1,     1,     4,     1,     3,     1,     3,
       1,     2,     3,     3,     3,     1,     3,     1,     4,     1,
       3,     2
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
  case 2: /* $@1: %empty  */
#line 22 "parser.y"
               {
        startLabel = newLabel();
    }
#line 1224 "parser.cpp"
    break;

  case 3: /* $@2: %empty  */
#line 25 "parser.y"
    {
        listID.clear();
    }
#line 1232 "parser.cpp"
    break;

  case 4: /* $@3: %empty  */
#line 30 "parser.y"
    {
        //main label
        gencode_label(startLabel);
    }
#line 1241 "parser.cpp"
    break;

  case 6: /* identifier_list: ID  */
#line 39 "parser.y"
       { listID.push_back(yyvsp[0]); }
#line 1247 "parser.cpp"
    break;

  case 7: /* identifier_list: identifier_list ',' ID  */
#line 40 "parser.y"
                             { listID.push_back(yyvsp[0]); }
#line 1253 "parser.cpp"
    break;

  case 8: /* declarations: declarations VAR identifier_list ':' type ';'  */
#line 44 "parser.y"
                                                  { 
        int size = (yyvsp[-1] == INT) ? 4 : 8;
        for (int id : listID) {
            symtable[id].type = yyvsp[-1];
            symtable[id].token = VAR;
            symtable[id].isGlobal = contextGlobal;
            if (contextGlobal) {
                symtable[id].address = tempCountAddress;
                tempCountAddress += size;
            } else {
                symtable[id].address = getLocalAddress(size);
            }
        }
        listID.clear();
    }
#line 1273 "parser.cpp"
    break;

  case 15: /* $@4: %empty  */
#line 77 "parser.y"
                    {
        contextGlobal = false;
        localOffset = 0;
        gencode_startFunc();
    }
#line 1283 "parser.cpp"
    break;

  case 16: /* subprogram_declaration: subprogram_head $@4 declarations compound_statement  */
#line 81 "parser.y"
                                      {
        int stackSize = newNumber(-localOffset);
        gencode_endFunc(stackSize);
        contextGlobal = true;
    }
#line 1293 "parser.cpp"
    break;

  case 17: /* $@5: %empty  */
#line 89 "parser.y"
                {
        gencode_label(yyvsp[0]);
    }
#line 1301 "parser.cpp"
    break;

  case 18: /* subprogram_head: FUNCTION ID $@5 arguments ':' standerd_type ';'  */
#line 91 "parser.y"
                                      {
        offset = 8;
        symtable[yyvsp[-5]].token = FUNCTION;
        symtable[yyvsp[-5]].type = yyvsp[-1];
        symtable[yyvsp[-5]].address = offset;
        symtable[yyvsp[-5]].isGlobal = false;
        symtable[yyvsp[-5]].isReference = true;

        std::vector<symbol_t>args;
        for(auto arg: listArgs) {
            symbol_t id = symtable[arg];
            args.push_back(newArgument(id.type));
        }

        symtable[yyvsp[-5]].arguments = args;
        listArgs.clear();

    }
#line 1324 "parser.cpp"
    break;

  case 19: /* $@6: %empty  */
#line 109 "parser.y"
                   {
        offset = 4;
        gencode_label(yyvsp[0]);
    }
#line 1333 "parser.cpp"
    break;

  case 20: /* subprogram_head: PROCEDURE ID $@6 arguments ';'  */
#line 112 "parser.y"
                    {

        symtable[yyvsp[-3]].token = PROCEDURE;
        symtable[yyvsp[-3]].address = offset;
        symtable[yyvsp[-3]].isGlobal = false;
        symtable[yyvsp[-3]].isReference = true;

        std::vector<symbol_t>args;
        for(auto arg: listArgs) {
            symbol_t id = symtable[arg];
            args.push_back(newArgument(id.type));
        }

        symtable[yyvsp[-3]].arguments = args;
        listArgs.clear();

    }
#line 1355 "parser.cpp"
    break;

  case 21: /* arguments: '(' parametr_list ')'  */
#line 132 "parser.y"
                          {
        std::vector<int>::iterator arg;
        for (arg = listArgs.end() - 1; arg >= listArgs.begin(); arg--) {
            offset += 4; // Size of reference
            symtable[*arg].address = offset;
        }
    }
#line 1367 "parser.cpp"
    break;

  case 25: /* parametr: identifier_list ':' type  */
#line 148 "parser.y"
                             {
        for (auto symbolIndex : listID) {
            symtable[symbolIndex].type = yyvsp[0];
            symtable[symbolIndex].token = VAR;
            symtable[symbolIndex].isGlobal = false;
            symtable[symbolIndex].isReference = true;
        }
        listArgs.insert(listArgs.end(), listID.begin(), listID.end());
        listID.clear();
    }
#line 1382 "parser.cpp"
    break;

  case 31: /* statement: variable ASSIGN expression  */
#line 177 "parser.y"
                               { 
        gencode_mov(yyvsp[0], yyvsp[-2]);
    }
#line 1390 "parser.cpp"
    break;

  case 34: /* @7: %empty  */
#line 182 "parser.y"
                    {
       yyval = yyvsp[0];
    }
#line 1398 "parser.cpp"
    break;

  case 35: /* @8: %empty  */
#line 184 "parser.y"
           {
       yyval = gencode_then(yyvsp[-1]);
    }
#line 1406 "parser.cpp"
    break;

  case 36: /* @9: %empty  */
#line 187 "parser.y"
                   {
       yyval = gencode_else(yyvsp[-2]);
    }
#line 1414 "parser.cpp"
    break;

  case 37: /* statement: IF expression @7 THEN @8 statement ELSE @9 statement  */
#line 190 "parser.y"
              {
        gencode_label(yyvsp[-1]);
    }
#line 1422 "parser.cpp"
    break;

  case 38: /* @10: %empty  */
#line 193 "parser.y"
            {
        yyval = gencode_while();
    }
#line 1430 "parser.cpp"
    break;

  case 39: /* @11: %empty  */
#line 196 "parser.y"
                  {
        int label = newLabel();
        gencode_while_do(yyvsp[-1],label);
        yyval = label;
    }
#line 1440 "parser.cpp"
    break;

  case 40: /* statement: WHILE @10 expression DO @11 statement  */
#line 201 "parser.y"
              {
       gencode_end_while(yyvsp[-1] ,yyvsp[-4]);
    }
#line 1448 "parser.cpp"
    break;

  case 41: /* statement: READ '(' expression_list ')'  */
#line 204 "parser.y"
                                   { 
        for (auto id : listID) {
            gencode_read(id);
        }
        listID.clear();
    }
#line 1459 "parser.cpp"
    break;

  case 42: /* statement: WRITE '(' expression_list ')'  */
#line 210 "parser.y"
                                    { 
        for (auto id : listID) {
            gencode_write(id);
        }
        listID.clear();
    }
#line 1470 "parser.cpp"
    break;

  case 44: /* procedure_statement: ID  */
#line 223 "parser.y"
       {
        gencode_call(yyvsp[0]); //procedura bez argumentów
    }
#line 1478 "parser.cpp"
    break;

  case 45: /* procedure_statement: ID '(' expression_list ')'  */
#line 226 "parser.y"
                                 {
        symbol_t proc = symtable[yyvsp[-3]];

        if (proc.arguments.size() != listID.size()) {
            yyerror("Zła ilość argumentów procedury!");
        }

        int incsp = 0;

        for (int i = 0; i < int(listID.size()); i++) { 
            symbol_t expected = proc.arguments[i];
            gencode_push(listID[i], expected);
            incsp += 4;
        }
        listID.clear();
        gencode_call(yyvsp[-3]);

        int index = newNumber(incsp);
        gencode_incsp(index);
    }
#line 1503 "parser.cpp"
    break;

  case 46: /* expression_list: expression  */
#line 249 "parser.y"
               {
        listID.push_back(yyvsp[0]);
    }
#line 1511 "parser.cpp"
    break;

  case 47: /* expression_list: expression_list ',' expression  */
#line 252 "parser.y"
                                     {
        listID.push_back(yyvsp[0]);
    }
#line 1519 "parser.cpp"
    break;

  case 49: /* expression: simple_expression RELOP simple_expression  */
#line 259 "parser.y"
                                                {
       yyval = gencode_relop(yyvsp[-1], yyvsp[-2], yyvsp[0]);
    }
#line 1527 "parser.cpp"
    break;

  case 50: /* simple_expression: term  */
#line 265 "parser.y"
         { yyval = yyvsp[0]; }
#line 1533 "parser.cpp"
    break;

  case 51: /* simple_expression: ADDOP term  */
#line 266 "parser.y"
                 {
        if (yyvsp[-1] == SUB) {
            yyval = gencode_sign(yyvsp[0]);
        } else {
            yyval = yyvsp[0];
        }
    }
#line 1545 "parser.cpp"
    break;

  case 52: /* simple_expression: simple_expression ADDOP term  */
#line 273 "parser.y"
                                   { 
        if (yyvsp[-1] == ADD) {
            yyval = gencode_op("add", yyvsp[-2], yyvsp[0]);
        }
        else if (yyvsp[-1] == SUB) {
            yyval = gencode_op("sub", yyvsp[-2], yyvsp[0]);
        }
    }
#line 1558 "parser.cpp"
    break;

  case 53: /* simple_expression: simple_expression AND_ term  */
#line 281 "parser.y"
                                  {
        yyval = gencode_logic("and", yyvsp[-2], yyvsp[0]);
    }
#line 1566 "parser.cpp"
    break;

  case 54: /* simple_expression: simple_expression OR_ term  */
#line 284 "parser.y"
                                 {
        yyval = gencode_logic("or", yyvsp[-2], yyvsp[0]);
    }
#line 1574 "parser.cpp"
    break;

  case 55: /* term: factor  */
#line 290 "parser.y"
           { yyval = yyvsp[0]; }
#line 1580 "parser.cpp"
    break;

  case 56: /* term: term MULOP factor  */
#line 291 "parser.y"
                        {
        if (yyvsp[-1] == MUL) {
            yyval = gencode_op("mul", yyvsp[-2], yyvsp[0]);
        }
        else if (yyvsp[-1] == DIV) {
            yyval = gencode_op("div", yyvsp[-2], yyvsp[0]);
        }
        else if (yyvsp[-1] == MOD) {
            yyval = gencode_op("mod", yyvsp[-2], yyvsp[0]);
        }
    }
#line 1596 "parser.cpp"
    break;

  case 57: /* factor: variable  */
#line 304 "parser.y"
             { yyval = yyvsp[0]; }
#line 1602 "parser.cpp"
    break;

  case 58: /* factor: ID '(' expression_list ')'  */
#line 305 "parser.y"
                                 {
       
        symbol_t func = symtable[yyvsp[-3]];
        if(func.arguments.size() != listID.size()) {
            yyerror("Zła ilość argumentów funkcji!");
        }

        int incsp = 0;

        for(int id = 0; id < int(listID.size()); ++id) { 
            symbol_t expected = func.arguments[id];
            gencode_push(listID[id], expected);
            incsp += 4;
        }
        listID.clear();
        
        //push result
        int result = newTemp(func.type);
        gencode_push(result, newArgument(func.type));
        incsp += 4;

        yyval = result;
        gencode_call(yyvsp[-3]);
        int index = newNumber(incsp);
        gencode_incsp(index);
    }
#line 1633 "parser.cpp"
    break;

  case 59: /* factor: NUM  */
#line 331 "parser.y"
          { yyval = yyvsp[0]; }
#line 1639 "parser.cpp"
    break;

  case 60: /* factor: '(' expression ')'  */
#line 332 "parser.y"
                          { yyval = yyvsp[-1]; }
#line 1645 "parser.cpp"
    break;

  case 61: /* factor: NOT factor  */
#line 333 "parser.y"
                 {
       yyval = gencode_not(yyvsp[0]);
    }
#line 1653 "parser.cpp"
    break;


#line 1657 "parser.cpp"

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

#line 338 "parser.y"


void yyerror(const char* s) {
    printf("\n\nBłąd \"%s\" w linii %d\n", s, lineno);
    errorno++;
}

const char *token_name(int token) {
    return yytname[YYTRANSLATE(token)];
}

int getTempAddress(int size) {
    if(contextGlobal) {
        int temp = tempCountAddress;
        tempCountAddress+=size;
        return temp;
    }
    return 0;
}

int getLocalAddress(int size) {
    localOffset -= size;
    return localOffset;
}
