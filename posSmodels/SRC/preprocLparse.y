// Copyright (C) 2005 Claire Lef�vre, Pascal Nicolas
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
// http://www.gnu.org/copyleft/gpl.html
//
// claire.lefevre@univ-angers.fr       pascal.nicolas@univ-angers.fr
//

//
// syntax for  a possibilistic normal logic program
//
%{
#include <stdio.h>
#include <string.h>
#include <set>
#include <iterator>
using namespace std;
#define YYERROR_VERBOSE
#define YYSTYPE char*
void yyerror(char* mess);
int yylex();
class ltstring{
public:	bool operator()(const char* s1,const char* s2)const{
		return strcmp(s1,s2)<0;
	}
};
typedef set<char*,ltstring> set_car;
set_car Degres;
%}

%token IF NUM SEPAR COMMENT CAR DEF

%%

prog :
	/* rien */
	| prog item
	;
item :
	NUM  regle 	{Degres.insert($1);printf("%s  nu__(%s).",$2,$1);}
	| SEPAR		{printf("%s",$1);}
	| COMMENT	{printf("%s",$1);}
	| DEF		{printf("%s",$1);}
	| error	'.'	{yyerrok;}
	;
regle :
	chaine '.'		{$$=(char*)malloc(strlen($1)+3);
				strcpy($$,$1);
				strcat($$,":-");}
	| IF chaine '.'		{$$=(char*)malloc(strlen($2)+4);
				 strcpy($$, $1);
				 strcat($$, $2);
				 strcat($$,",");}
	| chaine IF chaine '.'	{$$=(char*)malloc(strlen($1)+strlen($3)+4);
				 strcpy($$, $1);
				 strcat($$, $2);
				 strcat($$, $3);
				 strcat($$,",");}
	;
chaine :
	element			{$$=$1;}
	| chaine element	{$$=(char*)malloc(strlen($1)+strlen($2)+1);
				 strcpy($$, $1);
				 strcat($$, $2);}
	;
element :
	CAR		{$$=$1;}
	| SEPAR		{$$=$1;}
	| NUM		{$$=$1;}
	;
	
%%
#include "preprocLparse.lex.c"

int main(int argc, char** argv){
if (argc>1){
	FILE* f = fopen (argv[1],"r");
	if (!f){
	  fprintf(stderr, "impossible to open %s \n", argv[1]);
	  exit(1);
	}
	yyin = f;
}	
yyparse();
if (yynerrs) return 1;
printf("\n#external nu__(X).\n");
for(set_car::iterator i=Degres.begin(); i!=Degres.end(); i++){
	printf("nu__(%s).\n",*i);
}	
return 0;
}

void yyerror(char* mess){
fprintf(stderr,"%s \n",mess);
}



