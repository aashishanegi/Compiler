%{

#include <stdlib.h>
#include <stdio.h>
#include "symboltable.h"
#include "tokens.h"

entry_t** symbol_table;
entry_t** constant_table;
int cmnt_strt = 0;
int token_count = 0;

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
"num"                             {printf("\t%-30s : %s\n",yytext,"Integer Keyword"); token_count++;}
"bignum"                          {printf("\t%-30s : %s\n",yytext,"Long Keyword"); token_count++;}
"smallnum"                        {printf("\t%-30s : %s\n",yytext,"Short Keyword"); token_count++;}
"alphabet"                        {printf("\t%-30s : %s\n",yytext,"Char Keyword"); token_count++;}
"sentence"                        {printf("\t%-30s : %s\n",yytext,"String Keyword"); token_count++;}
"as"                              {printf("\t%-30s : %s\n",yytext,"For Keyword"); token_count++;}
"gap"                             {printf("\t%-30s : %s\n",yytext,"Break Keyword"); token_count++;}
"go_on"                           {printf("\t%-30s : %s\n",yytext,"Continue Keyword"); token_count++;}
"condition"                       {printf("\t%-30s : %s\n",yytext,"If Keyword"); token_count++;}
"another"                         {printf("\t%-30s : %s\n",yytext,"Else Keyword"); token_count++;}
"give"                            {printf("\t%-30s : %s\n",yytext,"Return Keyword"); token_count++;}
"span"                            {printf("\t%-30s : %s\n",yytext,"While Keyword"); token_count++;}
"execute"                         {printf("\t%-30s : %s\n",yytext,"Do Keyword"); token_count++;}
"null"                            {printf("\t%-30s : %s\n",yytext,"Void Keyword"); token_count++;}
"lock"                            {printf("\t%-30s : %s\n",yytext,"Switch Keyword"); token_count++;}
"key"                             {printf("\t%-30s : %s\n",yytext,"Case Keyword"); token_count++;}
"fixed"                           {printf("\t%-30s : %s\n",yytext,"Const Keyword"); token_count++;}
"deci"                            {printf("\t%-30s : %s\n",yytext,"Float Keyword"); token_count++;}
"doubledeci"                      {printf("\t%-30s : %s\n",yytext,"Double Keyword"); token_count++;}
"imp"                             {printf("\t%-30s : %s\n",yytext,"Main Identifier"); token_count++;}
"out"                             {printf("\t%-30s : %s\n",yytext,"printf Identifier"); token_count++;}
"or"                              {printf("\t%-30s : %s\n",yytext,"Else if Keyword"); token_count++;}
"find"                            {printf("\t%-30s : %s\n",yytext,"Scanf Keyword"); token_count++;}

{identifier}                      {printf("\t%-30s : %s\n", yytext,"Identifier");
                                  insert( symbol_table,yytext,Identifier );
                                  token_count++;}
{ws}                              ;
[+\-]?[0][x|X]{hex}+[lLuU]?        {printf("\t%-30s : %s\n", yytext,"Constants");
                                    insert( constant_table,yytext,HEX_CONSTANT);
                                    token_count++;}
[+\-]?{digit}+[lLuU]?              {printf("\t%-30s : %s\n", yytext,"Constants");
                                    insert( constant_table,yytext,DEC_CONSTANT);
                                    token_count++;}
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
  token_count++;
 }

\"[^\"\n]*$                     {printf("Line %3d: Unterminated string %s\n",yylineno,yytext);}
{digit}+({letter}|_)+          {printf("Line %3d: Illegal identifier name %s\n",yylineno,yytext);}
\n                              {yylineno++;}
"--"                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"++"                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"+="                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"-="                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"*="                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"/="                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"%="                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"->"                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"&&"                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"||"                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"<="                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
">="                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"=="                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"!="                          {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
";"                           {printf("\t%-30s : %s\n",yytext,"Punctuation"); token_count++;}
"{"                           {printf("\t%-30s : %s\n",yytext,"Punctuation"); token_count++;}
"}"                           {printf("\t%-30s : %s\n",yytext,"Punctuation"); token_count++;}
","                           {printf("\t%-30s : %s\n",yytext,"Punctuation"); token_count++;}
"="                           {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"("                           {printf("\t%-30s : %s\n",yytext,"Punctuation"); token_count++;}
")"                           {printf("\t%-30s : %s\n",yytext,"Punctuation"); token_count++;}
"["                           {printf("\t%-30s : %s\n",yytext,"Punctuation"); token_count++;}
"]"                           {printf("\t%-30s : %s\n",yytext,"Punctuation"); token_count++;}
"-"                           {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"+"                           {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"*"                           {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"/"                           {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"%"                           {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"<"                           {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
">"                           {printf("\t%-30s : %s\n",yytext,"Operator"); token_count++;}
"&"                           {printf("\t%-30s : %s\n",yytext,"Special Symbol"); token_count++;}
":"                           {printf("\t%-30s : %s\n",yytext,"Special Symbol"); token_count++;}
.                             {printf("Line %3d: Illegal character %s\n",yylineno,yytext);}

%%
int yywrap() {
    return 1;
}

int main() {
  yyin = fopen("prog1.txt", "r");
  symbol_table = create_table();
  constant_table = create_table();
  yylex();
  printf("\n\tSymbol table");
  display(symbol_table);
  printf("\n\tConstants Table");
  display(constant_table);
  printf("Total Tokens Generated: %d\n", token_count);
  printf("NOTE: Please refer tokens.h for token meanings\n");
}
