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
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* ';'  */
  YYSYMBOL_31_ = 31,                       /* '.'  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_33_ = 33,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_37_2 = 37,                      /* $@2  */
  YYSYMBOL_identifier_list = 38,           /* identifier_list  */
  YYSYMBOL_declarations = 39,              /* declarations  */
  YYSYMBOL_type = 40,                      /* type  */
  YYSYMBOL_standerd_type = 41,             /* standerd_type  */
  YYSYMBOL_subprogram_declarations = 42,   /* subprogram_declarations  */
  YYSYMBOL_subprogram_declaration = 43,    /* subprogram_declaration  */
  YYSYMBOL_44_3 = 44,                      /* $@3  */
  YYSYMBOL_subprogram_head = 45,           /* subprogram_head  */
  YYSYMBOL_46_4 = 46,                      /* $@4  */
  YYSYMBOL_47_5 = 47,                      /* $@5  */
  YYSYMBOL_arguments = 48,                 /* arguments  */
  YYSYMBOL_parametr_list = 49,             /* parametr_list  */
  YYSYMBOL_parametr = 50,                  /* parametr  */
  YYSYMBOL_compound_statement = 51,        /* compound_statement  */
  YYSYMBOL_optional_statments = 52,        /* optional_statments  */
  YYSYMBOL_statement_list = 53,            /* statement_list  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_55_6 = 55,                      /* @6  */
  YYSYMBOL_56_7 = 56,                      /* @7  */
  YYSYMBOL_57_8 = 57,                      /* @8  */
  YYSYMBOL_58_9 = 58,                      /* @9  */
  YYSYMBOL_59_10 = 59,                     /* @10  */
  YYSYMBOL_60_11 = 60,                     /* @11  */
  YYSYMBOL_variable = 61,                  /* variable  */
  YYSYMBOL_procedure_statement = 62,       /* procedure_statement  */
  YYSYMBOL_expression_list = 63,           /* expression_list  */
  YYSYMBOL_expression = 64,                /* expression  */
  YYSYMBOL_simple_expression = 65,         /* simple_expression  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_factor = 67                     /* factor  */
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
#define YYLAST   110

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      28,    29,     2,     2,    32,     2,    31,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    30,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    22,    22,    27,    22,    36,    37,    41,    56,    60,
      64,    65,    69,    70,    74,    74,    86,    86,   107,   107,
     130,   137,   141,   142,   146,   159,   165,   166,   170,   171,
     175,   178,   179,   180,   182,   185,   180,   191,   193,   196,
     191,   203,   209,   218,   222,   225,   231,   234,   240,   241,
     247,   248,   255,   266,   267,   280,   281,   307,   308,   309
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
  "RELOP", "NOT", "FUNCTION", "PROCEDURE", "'('", "')'", "';'", "'.'",
  "','", "':'", "$accept", "program", "$@1", "$@2", "identifier_list",
  "declarations", "type", "standerd_type", "subprogram_declarations",
  "subprogram_declaration", "$@3", "subprogram_head", "$@4", "$@5",
  "arguments", "parametr_list", "parametr", "compound_statement",
  "optional_statments", "statement_list", "statement", "@6", "@7", "@8",
  "@9", "@10", "@11", "variable", "procedure_statement", "expression_list",
  "expression", "simple_expression", "term", "factor", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      52,    59,    70,   -65,   -65,    43,    68,   -65,    21,    44,
      69,   -65,   -65,    71,    68,   -16,    -9,    72,    73,    63,
      49,   -65,    61,   -65,   -65,    25,    50,   -65,   -65,   -65,
     -65,    53,   -65,    54,    54,    -8,    56,    58,    10,   -65,
      67,    57,   -65,    74,    75,   -65,   -65,     0,   -65,    68,
      60,    62,    10,    10,    10,    66,   -65,    11,    11,    10,
     -65,   -65,    30,    79,   -65,   -65,     9,   -65,    10,   -65,
      36,   -13,   -65,    61,   -65,    27,   -65,    28,    32,    10,
      79,   -65,    76,    77,    11,    10,    11,   -65,    10,   -65,
      61,   -65,    68,    78,   -65,    10,   -65,   -65,    33,   -65,
     -65,    79,    83,   -65,    80,   -65,   -65,   -65,   -65,   -65,
       9,   -65,    81,     9,   -65,   -65,     9,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     0,     5,     0,     0,
       0,     8,     6,    13,     0,     3,     0,     0,     0,     0,
       0,    14,     0,    16,    18,    27,     0,    12,     8,    10,
      11,     0,     9,    21,    21,    44,     0,     0,     0,    32,
       0,    26,    28,     0,     0,    31,     4,     0,     7,     0,
       0,     0,     0,     0,     0,    43,    57,     0,     0,     0,
      55,    33,    48,    50,    53,    25,    37,    38,     0,    15,
       0,     0,    22,     0,    19,     0,    46,     0,     0,     0,
      51,    59,     0,     0,     0,     0,     0,    29,     0,    30,
       0,    20,     0,     0,    45,     0,    42,    41,     0,    58,
      34,    52,    49,    54,     0,    24,    23,    17,    47,    56,
      37,    39,     0,    37,    35,    40,    37,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   -65,    34,    82,    14,    17,   -65,   -65,
     -65,   -65,   -65,   -65,    65,   -65,     8,   -15,   -65,   -65,
     -64,   -65,   -65,   -65,   -65,   -65,   -65,   -25,   -65,   -45,
     -37,    16,   -54,   -53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     5,    19,    70,    13,    31,    32,    15,    20,
      28,    21,    33,    34,    50,    71,    72,    39,    40,    41,
      42,    83,   110,   116,    43,    88,   113,    60,    45,    75,
      76,    62,    63,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    61,    87,    80,    26,    81,   -43,    14,    77,    78,
      17,    18,    25,    35,    55,    55,    91,    92,    56,    56,
      52,    25,    82,    10,    22,    57,    36,    37,    38,    35,
     101,    89,    69,   103,    98,    58,    58,    25,    59,    59,
       8,    44,    36,    37,    38,    84,   112,   -37,    16,   115,
       9,   104,   117,    10,    85,     1,    94,    96,   108,    95,
      95,    97,   109,     3,    95,    95,    29,    30,    10,    90,
       4,     6,     7,    12,    11,    25,    23,    24,    14,    27,
      65,    46,    49,    48,    53,    44,    54,    66,    44,    68,
      93,    44,    74,    73,    79,    86,    67,   100,    84,    51,
     106,   102,   114,   111,   105,    99,     0,     0,   107,     0,
      47
};

static const yytype_int8 yycheck[] =
{
      25,    38,    66,    57,    19,    58,    14,     7,    53,    54,
      26,    27,    12,     4,     4,     4,    29,    30,     8,     8,
      28,    12,    59,    32,    33,    15,    17,    18,    19,     4,
      84,    68,    47,    86,    79,    25,    25,    12,    28,    28,
       6,    66,    17,    18,    19,    15,   110,    22,    14,   113,
      29,    88,   116,    32,    24,     3,    29,    29,    95,    32,
      32,    29,    29,     4,    32,    32,     5,     6,    32,    33,
       0,    28,     4,     4,    30,    12,     4,     4,     7,    30,
      13,    31,    28,    30,    28,   110,    28,    30,   113,    14,
      73,   116,    30,    33,    28,    16,    22,    20,    15,    34,
      92,    85,    21,    23,    90,    29,    -1,    -1,    30,    -1,
      28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    35,     4,     0,    36,    28,     4,    38,    29,
      32,    30,     4,    39,     7,    42,    38,    26,    27,    37,
      43,    45,    33,     4,     4,    12,    51,    30,    44,     5,
       6,    40,    41,    46,    47,     4,    17,    18,    19,    51,
      52,    53,    54,    58,    61,    62,    31,    39,    30,    28,
      48,    48,    28,    28,    28,     4,     8,    15,    25,    28,
      61,    64,    65,    66,    67,    13,    30,    22,    14,    51,
      38,    49,    50,    33,    30,    63,    64,    63,    63,    28,
      66,    67,    64,    55,    15,    24,    16,    54,    59,    64,
      33,    29,    30,    41,    29,    32,    29,    29,    63,    29,
      20,    66,    65,    67,    64,    40,    50,    30,    64,    29,
      56,    23,    54,    60,    21,    54,    57,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    36,    37,    35,    38,    38,    39,    39,    40,
      41,    41,    42,    42,    44,    43,    46,    45,    47,    45,
      48,    48,    49,    49,    50,    51,    52,    52,    53,    53,
      54,    54,    54,    55,    56,    57,    54,    58,    59,    60,
      54,    54,    54,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    66,    66,    67,    67,    67,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,    12,     1,     3,     6,     0,     1,
       1,     1,     3,     0,     0,     4,     0,     7,     0,     5,
       3,     0,     1,     3,     3,     3,     1,     0,     1,     3,
       3,     1,     1,     0,     0,     0,     9,     0,     0,     0,
       7,     4,     4,     1,     1,     4,     1,     3,     1,     3,
       1,     2,     3,     1,     3,     1,     4,     1,     3,     2
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
#line 1217 "parser.cpp"
    break;

  case 3: /* $@2: %empty  */
#line 27 "parser.y"
    {
        //main label
        gencode_label(startLabel);
    }
#line 1226 "parser.cpp"
    break;

  case 5: /* identifier_list: ID  */
#line 36 "parser.y"
       { listID.push_back(yyvsp[0]); }
#line 1232 "parser.cpp"
    break;

  case 6: /* identifier_list: identifier_list ',' ID  */
#line 37 "parser.y"
                             { listID.push_back(yyvsp[0]); }
#line 1238 "parser.cpp"
    break;

  case 7: /* declarations: declarations VAR identifier_list ':' type ';'  */
#line 41 "parser.y"
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
#line 1258 "parser.cpp"
    break;

  case 14: /* $@3: %empty  */
#line 74 "parser.y"
                    {
        contextGlobal = false;
        localOffset = 0;
        gencode_startFunc();
    }
#line 1268 "parser.cpp"
    break;

  case 15: /* subprogram_declaration: subprogram_head $@3 declarations compound_statement  */
#line 78 "parser.y"
                                      {
        int stackSize = newNumber(-localOffset);
        gencode_endFunc(stackSize);
        contextGlobal = true;
    }
#line 1278 "parser.cpp"
    break;

  case 16: /* $@4: %empty  */
#line 86 "parser.y"
                {
        gencode_label(yyvsp[0]);
    }
#line 1286 "parser.cpp"
    break;

  case 17: /* subprogram_head: FUNCTION ID $@4 arguments ':' standerd_type ';'  */
#line 88 "parser.y"
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
#line 1310 "parser.cpp"
    break;

  case 18: /* $@5: %empty  */
#line 107 "parser.y"
                   {
        gencode_label(yyvsp[0]);
    }
#line 1318 "parser.cpp"
    break;

  case 19: /* subprogram_head: PROCEDURE ID $@5 arguments ';'  */
#line 109 "parser.y"
                    {

        offset = 8;
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
#line 1341 "parser.cpp"
    break;

  case 20: /* arguments: '(' parametr_list ')'  */
#line 130 "parser.y"
                          {
        std::vector<int>::iterator arg;
        for (arg = listArgs.end() - 1; arg >= listArgs.begin(); arg--) {
            offset += 4; // Size of reference
            symtable[*arg].address = offset;
        }
    }
#line 1353 "parser.cpp"
    break;

  case 24: /* parametr: identifier_list ':' type  */
#line 146 "parser.y"
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
#line 1368 "parser.cpp"
    break;

  case 30: /* statement: variable ASSIGN expression  */
#line 175 "parser.y"
                               { 
        gencode_mov(yyvsp[0], yyvsp[-2]);
    }
#line 1376 "parser.cpp"
    break;

  case 33: /* @6: %empty  */
#line 180 "parser.y"
                    {
       yyval = gencode_if(yyvsp[0]);
    }
#line 1384 "parser.cpp"
    break;

  case 34: /* @7: %empty  */
#line 182 "parser.y"
           {
       yyval = gencode_then(yyvsp[-1]);
    }
#line 1392 "parser.cpp"
    break;

  case 35: /* @8: %empty  */
#line 185 "parser.y"
                   {
       yyval = gencode_else(yyvsp[-2]);
    }
#line 1400 "parser.cpp"
    break;

  case 36: /* statement: IF expression @6 THEN @7 statement ELSE @8 statement  */
#line 188 "parser.y"
              {
        gencode_label(yyvsp[-1]);
    }
#line 1408 "parser.cpp"
    break;

  case 37: /* @9: %empty  */
#line 191 "parser.y"
      {
        yyval = newLabel();
    }
#line 1416 "parser.cpp"
    break;

  case 38: /* @10: %empty  */
#line 193 "parser.y"
           {
        yyval = gencode_while();
    }
#line 1424 "parser.cpp"
    break;

  case 39: /* @11: %empty  */
#line 196 "parser.y"
                  {
        int temp = gencode_if(yyvsp[-1]);
        yyval = gencode_while_then(temp,yyvsp[-4]);
        
    }
#line 1434 "parser.cpp"
    break;

  case 40: /* statement: @9 WHILE @10 expression DO @11 statement  */
#line 200 "parser.y"
                {
       gencode_end_while(yyvsp[-6] ,yyvsp[-4]);
    }
#line 1442 "parser.cpp"
    break;

  case 41: /* statement: READ '(' expression_list ')'  */
#line 203 "parser.y"
                                   { 
        for (auto id : listID) {
            gencode_read(id);
        }
        listID.clear();
    }
#line 1453 "parser.cpp"
    break;

  case 42: /* statement: WRITE '(' expression_list ')'  */
#line 209 "parser.y"
                                    { 
        for (auto id : listID) {
            gencode_write(id);
        }
        listID.clear();
    }
#line 1464 "parser.cpp"
    break;

  case 44: /* procedure_statement: ID  */
#line 222 "parser.y"
       {
        
    }
#line 1472 "parser.cpp"
    break;

  case 45: /* procedure_statement: ID '(' expression_list ')'  */
#line 225 "parser.y"
                                 {

    }
#line 1480 "parser.cpp"
    break;

  case 46: /* expression_list: expression  */
#line 231 "parser.y"
               {
        listID.push_back(yyvsp[0]);
    }
#line 1488 "parser.cpp"
    break;

  case 47: /* expression_list: expression_list ',' expression  */
#line 234 "parser.y"
                                     {
        listID.push_back(yyvsp[0]);
    }
#line 1496 "parser.cpp"
    break;

  case 49: /* expression: simple_expression RELOP simple_expression  */
#line 241 "parser.y"
                                                {
       yyval = gencode_relop(yyvsp[-1], yyvsp[-2], yyvsp[0]);
    }
#line 1504 "parser.cpp"
    break;

  case 50: /* simple_expression: term  */
#line 247 "parser.y"
         { yyval = yyvsp[0]; }
#line 1510 "parser.cpp"
    break;

  case 51: /* simple_expression: ADDOP term  */
#line 248 "parser.y"
                 {
        if (yyvsp[-1] == SUB) {
            yyval = gencode_sign(yyvsp[0]);
        } else {
            yyval = yyvsp[0];
        }
    }
#line 1522 "parser.cpp"
    break;

  case 52: /* simple_expression: simple_expression ADDOP term  */
#line 255 "parser.y"
                                   { 
        if (yyvsp[-1] == ADD) {
            yyval = gencode_op("add", yyvsp[-2], yyvsp[0]);
        }
        else if (yyvsp[-1] == SUB) {
            yyval = gencode_op("sub", yyvsp[-2], yyvsp[0]);
        }
    }
#line 1535 "parser.cpp"
    break;

  case 53: /* term: factor  */
#line 266 "parser.y"
           { yyval = yyvsp[0]; }
#line 1541 "parser.cpp"
    break;

  case 54: /* term: term MULOP factor  */
#line 267 "parser.y"
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
#line 1557 "parser.cpp"
    break;

  case 55: /* factor: variable  */
#line 280 "parser.y"
             { yyval = yyvsp[0]; }
#line 1563 "parser.cpp"
    break;

  case 56: /* factor: ID '(' expression_list ')'  */
#line 281 "parser.y"
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
#line 1594 "parser.cpp"
    break;

  case 57: /* factor: NUM  */
#line 307 "parser.y"
          { yyval = yyvsp[0]; }
#line 1600 "parser.cpp"
    break;

  case 58: /* factor: '(' expression ')'  */
#line 308 "parser.y"
                          { yyval = yyvsp[-1]; }
#line 1606 "parser.cpp"
    break;

  case 59: /* factor: NOT factor  */
#line 309 "parser.y"
                 {
       yyval = gencode_not(yyvsp[0]);
    }
#line 1614 "parser.cpp"
    break;


#line 1618 "parser.cpp"

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

#line 314 "parser.y"


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
