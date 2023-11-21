
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 31 "parser.y"

	int data_type;
	entry_t* entry;



/* Line 1676 of yacc.c  */
#line 163 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


