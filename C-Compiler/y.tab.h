/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    TYPE_IDENTIFIER = 259,
    FLOAT_CONSTANT = 260,
    INTEGER_CONSTANT = 261,
    CHARACTER_CONSTANT = 262,
    STRING_LITERAL = 263,
    PLUS = 264,
    MINUS = 265,
    STAR = 266,
    PERCENT = 267,
    ASSIGN = 268,
    PLUSPLUS = 269,
    MINUSMINUS = 270,
    ARROW = 271,
    LSS = 272,
    GTR = 273,
    LEQ = 274,
    GEQ = 275,
    EQL = 276,
    NEQ = 277,
    DOTDOTDOT = 278,
    AMP = 279,
    AMPAMP = 280,
    BAR = 281,
    BARBAR = 282,
    COLON = 283,
    SEMICOLON = 284,
    PERIOD = 285,
    COMMA = 286,
    EXCL = 287,
    SLASH = 288,
    LP = 289,
    RP = 290,
    LB = 291,
    RB = 292,
    LR = 293,
    RR = 294,
    AUTO_SYM = 295,
    STATIC_SYM = 296,
    SIZEOF_SYM = 297,
    BREAK_SYM = 298,
    DEFAULT_SYM = 299,
    ENUM_SYM = 300,
    RETURN_SYM = 301,
    STRUCT_SYM = 302,
    SWITCH_SYM = 303,
    TYPEDEF_SYM = 304,
    UNION_SYM = 305,
    WHILE_SYM = 306,
    IF_SYM = 307,
    CASE_SYM = 308,
    CONTINUE_SYM = 309,
    DO_SYM = 310,
    ELSE_SYM = 311,
    FOR_SYM = 312
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define TYPE_IDENTIFIER 259
#define FLOAT_CONSTANT 260
#define INTEGER_CONSTANT 261
#define CHARACTER_CONSTANT 262
#define STRING_LITERAL 263
#define PLUS 264
#define MINUS 265
#define STAR 266
#define PERCENT 267
#define ASSIGN 268
#define PLUSPLUS 269
#define MINUSMINUS 270
#define ARROW 271
#define LSS 272
#define GTR 273
#define LEQ 274
#define GEQ 275
#define EQL 276
#define NEQ 277
#define DOTDOTDOT 278
#define AMP 279
#define AMPAMP 280
#define BAR 281
#define BARBAR 282
#define COLON 283
#define SEMICOLON 284
#define PERIOD 285
#define COMMA 286
#define EXCL 287
#define SLASH 288
#define LP 289
#define RP 290
#define LB 291
#define RB 292
#define LR 293
#define RR 294
#define AUTO_SYM 295
#define STATIC_SYM 296
#define SIZEOF_SYM 297
#define BREAK_SYM 298
#define DEFAULT_SYM 299
#define ENUM_SYM 300
#define RETURN_SYM 301
#define STRUCT_SYM 302
#define SWITCH_SYM 303
#define TYPEDEF_SYM 304
#define UNION_SYM 305
#define WHILE_SYM 306
#define IF_SYM 307
#define CASE_SYM 308
#define CONTINUE_SYM 309
#define DO_SYM 310
#define ELSE_SYM 311
#define FOR_SYM 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
