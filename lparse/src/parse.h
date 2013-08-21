
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
     NUMBER = 258,
     WEIGHT = 259,
     MINIMIZE = 260,
     MAXIMIZE = 261,
     HIDE = 262,
     EXP = 263,
     FUNCTION = 264,
     FUNCSYMBOL = 265,
     IF = 266,
     NOT = 267,
     COMPUTE = 268,
     IDENTIFIER = 269,
     VARIABLE = 270,
     CONST = 271,
     EXTERNAL = 272,
     SHOW = 273,
     OPTION = 274,
     VARIABLEDEF = 275,
     LE = 276,
     GE = 277,
     EQ = 278,
     NEQ = 279,
     DOTS = 280,
     LT = 281,
     GT = 282,
     ASSIGN = 283,
     MOD = 284,
     COMMAS = 285,
     NORM = 286,
     METAPRIORITY = 287,
     TYPE = 288,
     PREDICATE = 289,
     NONDOMAIN = 290,
     UMINUS = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 74 "parse.yy"

   char *s;
   long l;
   ParseNode *pn;



/* Line 1676 of yacc.c  */
#line 96 "parse.cc.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


