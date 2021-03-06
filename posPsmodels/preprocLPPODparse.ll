/*
 Copyright (C) 2009 Roberto Confalonieri
 
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
http://www.gnu.org/copyleft/gpl.html

confalonieri@lsi.upc.edu

*/
 
/*
lexical definitions for a logic program with possibilistic ordered disjunction
*/

%option nounput
%option noyywrap 
number		[0-9]+

%%
:-		{ yylval =(char*)malloc(strlen(yytext)+1);
		 strcpy(yylval,yytext); return (IF);}
"."		return(yytext[0]);
{number}	{ yylval =(char*)malloc(strlen(yytext)+1);
		 strcpy(yylval,yytext); return(NUM);}
[ \t\n]		{ yylval =(char*)malloc(strlen(yytext)+1);
		 strcpy(yylval,yytext); return(SEPAR);}
#[^.]*\.	{ yylval =(char*)malloc(strlen(yytext)+1);
		 strcpy(yylval,yytext); return(DEF);}	 
\%.*\n		{ yylval =(char*)malloc(strlen(yytext)+1);
		 strcpy(yylval,yytext); return(COMMENT);}
. |
".." |
\"[^"]*\" 	 { yylval =(char*)malloc(strlen(yytext)+1);
		 strcpy(yylval,yytext); return(CAR);} /* other(s) character(s) */ 
%%

