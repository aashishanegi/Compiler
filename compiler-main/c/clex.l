%{

#include <stdlib.h>
#include <stdio.h>
#include "symboltable.h"
#include "tokens.h"

entry_t** symbol_table;
entry_t** constant_table;
int cmnt_strt = 0;

%}

%option yylineno
letter [a-zA-Z]
digit [0-9]
ws  [ \t\r\f\v]+
identifier (_|{letter})({letter}|{digit}|_){0,31}
hex [0-9a-f]

 /* Exclusive states */
%x CMNT
%x PREPROC

%%
  /* Keywords*/
"int"                             {printf("\t%-30s : %s\n",yytext,"Keyword");}
"long"                            {printf("\t%-30s : %s\n",yytext,"Keyword");}
"short"                           {printf("\t%-30s : %s\n",yytext,"Keyword");}
"for"                             {printf("\t%-30s : %s\n",yytext,"Keyword");}
"break"                           {printf("\t%-30s : %s\n",yytext,"Keyword");}
"continue"                        {printf("\t%-30s : %s\n",yytext,"Keyword");}
"if"                              {printf("\t%-30s : %s\n",yytext,"Keyword");}
"else"                            {printf("\t%-30s : %s\n",yytext,"Keyword");}
"return"                          {printf("\t%-30s : %s\n",yytext,"Keyword");}
"while"                           {printf("\t%-30s : %s\n",yytext,"Keyword");}
"do"                              {printf("\t%-30s : %s\n",yytext,"Keyword");}
"void"                            {printf("\t%-30s : %s\n",yytext,"Keyword");}
"elseif"                          {printf("\t%-30s : %s\n",yytext,"Keyword");}
"switch"                          {printf("\t%-30s : %s\n",yytext,"Keyword");}
"case"                            {printf("\t%-30s : %s\n",yytext,"Keyword");}
"const"                           {printf("\t%-30s : %s\n",yytext,"Keyword");}
"float"                           {printf("\t%-30s : %s\n",yytext,"Keyword");}
"double"                          {printf("\t%-30s : %s\n",yytext,"Keyword");}

{identifier}                      {printf("\t%-30s : %s\n", yytext,"IDENTIFIER");
                                  insert( symbol_table,yytext,IDENTIFIER );}
{ws}                              ;
[+\-]?[0][x|X]{hex}+[lLuU]?        {printf("\t%-30s : %s\n", yytext,"Constants");
									insert( constant_table,yytext,HEX_CONSTANT);}
[+\-]?{digit}+[lLuU]?              {printf("\t%-30s : %s\n", yytext,"Constants");
									insert( constant_table,yytext,DEC_CONSTANT);}
"/*"                              {cmnt_strt = yylineno; BEGIN CMNT;}
<CMNT>.|{ws}                      ;
<CMNT>\n                          {yylineno++;}
<CMNT>"*/"                        {BEGIN INITIAL;}
<CMNT>"/*"                        {printf("Line %3d: Nested comments are not valid!\n",yylineno);}
<CMNT><<EOF>>                     {printf("Line %3d: Unterminated comment\n", cmnt_strt); yyterminate();}
^"#include"                       {BEGIN PREPROC;}
<PREPROC>"<"[^<>\n]+">"            {printf("\t%-30s : %s\n",yytext,"HEADER_FILE");}
<PREPROC>{ws}                       ;
<PREPROC>\"[^"\n]+\"              {printf("\t%-30s : %s\n",yytext,"HEADER_FILE");}
<PREPROC>\n                       {yylineno++; BEGIN INITIAL;}
<PREPROC>.                        {printf("Line %3d: Illegal header file format \n",yylineno);}
"//".*                            ;

\"[^\"\n]*\"     {

  if(yytext[yyleng-2]=='\\') /* check if it was an escaped quote */
  {
    yyless(yyleng-1);       /* push the quote back if it was escaped */
    yymore();
  }
  else
  insert( constant_table,yytext,STRING);
 }

\"[^\"\n]*$                     {printf("Line %3d: Unterminated string %s\n",yylineno,yytext);}
{digit}+({letter}|_)+	        {printf("Line %3d: Illegal identifier name %s\n",yylineno,yytext);}
\n                              {yylineno++;}
"--"			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"++"			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"+="			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"-="			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"*="			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"/="			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"%="			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"->"			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"&&"			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"||"			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"<="			                {printf("\t%-30s : %s\n",yytext,"Operator");}
">="			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"=="			                {printf("\t%-30s : %s\n",yytext,"Operator");}
"!="		                  {printf("\t%-30s : %s\n",yytext,"Operator");}
";"			                  {printf("\t%-30s : %s\n",yytext,"Punctuation");}
"{"                       {printf("\t%-30s : %s\n",yytext,"Punctuation");}
"}"                       {printf("\t%-30s : %s\n",yytext,"Punctuation");}
","			                  {printf("\t%-30s : %s\n",yytext,"Punctuation");}
"="			                  {printf("\t%-30s : %s\n",yytext,"Operator");}
"("			                  {printf("\t%-30s : %s\n",yytext,"Punctuation");}
")"			                  {printf("\t%-30s : %s\n",yytext,"Punctuation");}
"["                       {printf("\t%-30s : %s\n",yytext,"Punctuation");}
"]"                       {printf("\t%-30s : %s\n",yytext,"Punctuation");}
"-"			                  {printf("\t%-30s : %s\n",yytext,"Operator");}
"+"			                  {printf("\t%-30s : %s\n",yytext,"Operator");}
"*"			                  {printf("\t%-30s : %s\n",yytext,"Operator");}
"/"		                    {printf("\t%-30s : %s\n",yytext,"Operator");}
"%"			                  {printf("\t%-30s : %s\n",yytext,"Operator");}
"<"			                  {printf("\t%-30s : %s\n",yytext,"Operator");}
">"			                  {printf("\t%-30s : %s\n",yytext,"Operator");}
"&"			                  {printf("\t%-30s : %s\n",yytext,"Special Symbol");}
.                         {printf("Line %3d: Illegal character %s\n",yylineno,yytext);}

%%
int yywrap() {
    // Add your yywrap logic here
    return 1; // Indicate end of input
}
int main()
{
  yyin=fopen("a.c","r");
  symbol_table=create_table();
  constant_table=create_table();
  yylex();
  printf("\n\tSymbol table");
  display(symbol_table);
  printf("\n\tConstants Table");
  display(constant_table);
  printf("NOTE: Please refer tokens.h for token meanings\n");
}