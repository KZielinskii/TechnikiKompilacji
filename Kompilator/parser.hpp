/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    ID = 259,                      /* ID  */
    INT = 260,                     /* INT  */
    REAL = 261,                    /* REAL  */
    VAR = 262,                     /* VAR  */
    NUM = 263,                     /* NUM  */
    LABEL = 264,                   /* LABEL  */
    PROC = 265,                    /* PROC  */
    NONE = 266,                    /* NONE  */
    BEG = 267,                     /* BEG  */
    END = 268,                     /* END  */
    ASSIGN = 269,                  /* ASSIGN  */
    ADDOP = 270,                   /* ADDOP  */
    MULOP = 271,                   /* MULOP  */
    WRITE = 272,                   /* WRITE  */
    READ = 273,                    /* READ  */
    IF = 274,                      /* IF  */
    THEN = 275,                    /* THEN  */
    ELSE = 276,                    /* ELSE  */
    WHILE = 277,                   /* WHILE  */
    DO = 278,                      /* DO  */
    RELOP = 279,                   /* RELOP  */
    NOT = 280,                     /* NOT  */
    FUNCTION = 281,                /* FUNCTION  */
    PROCEDURE = 282,               /* PROCEDURE  */
    OR_ = 283,                     /* OR_  */
    AND_ = 284                     /* AND_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
