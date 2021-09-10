%{
    #include <cerrno>
    #include <climits>
    #include <cstdlib>
    #include <cstring>
    #include <string>
    #include <iostream>
    #include "../driver.h"
    #include "../semantic/parser.hh"
%}

%option noyywrap nounput noinput batch debug

%option c++
%option yyclass="Scanner"

%{
  yy::parser::symbol_type make_NUMBER(
    const std::string &s,
    const yy::parser::location_type& loc
  );
  yy::parser::symbol_type make_BOOL(
    const std::string &s,
    const yy::parser::location_type& loc
  );
%}

id    [a-zA-Z_][a-zA-Z_0-9]*
int   [0-9]+
blank [ \t\r]
comment "/*"

%{
  # define YY_USER_ACTION  loc.columns(yyleng);
%}
%%
%{
  yy::location& loc = driver.location;
  loc.step();
%}

{blank}+   loc.step();
\n+        loc.lines(yyleng); loc.step();
"/*"([^*/]|[^*]"/"|"*"[^/])*"*"*"*/" ;
"//"[^\n] ;

"="        return yy::parser::make_ASSIGN(loc);
"*"        return yy::parser::make_STAR(loc);
"/"        return yy::parser::make_DIV(loc);
"%"        return yy::parser::make_MOD(loc);
"-"        return yy::parser::make_MINUS(loc);
"+"        return yy::parser::make_PLUS(loc);
"<"        return yy::parser::make_LESS(loc);
">"        return yy::parser::make_MORE(loc);
"=="       return yy::parser::make_EQ(loc);
"&&"       return yy::parser::make_AND(loc);
"||"       return yy::parser::make_OR(loc);
"!"        return yy::parser::make_NOT(loc);

"("        return yy::parser::make_LPAREN(loc);
")"        return yy::parser::make_RPAREN(loc);
";"        return yy::parser::make_SEMICOLON(loc);
"{"        return yy::parser::make_LEFTSCOPE(loc);
"}"        return yy::parser::make_RIGHTSCOPE(loc);
"["        return yy::parser::make_LEFTADDRESS(loc);
"]"        return yy::parser::make_RIGHTADDRESS(loc);
"."        return yy::parser::make_FIELD(loc);

"boolean"  return yy::parser::make_BOOLEAN(loc);
"int"      return yy::parser::make_INT(loc);
"void"     return yy::parser::make_VOID(loc);

"public"   return yy::parser::make_PUBLIC(loc);
"static"   return yy::parser::make_STATIC(loc);
"if"       return yy::parser::make_IF(loc);
"else"     return yy::parser::make_ELSE(loc);

"new"      return yy::parser::make_NEW(loc);
"this"     return yy::parser::make_THIS(loc);
"class"    return yy::parser::make_CLASS(loc);
"extends"  return yy::parser::make_EXTENDS(loc);
"main"     return yy::parser::make_MAIN(loc);
"return"   return yy::parser::make_RETURN(loc);
"System.out.println" return yy::parser::make_PRINT(loc);
"while"    return yy::parser::make_WHILE(loc);
"assert"   return yy::parser::make_ASSERT(loc);


"true"     return make_BOOL(yytext, loc);
"false"    return make_BOOL(yytext, loc);
{int}      return make_NUMBER(yytext, loc);
{id}       return yy::parser::make_IDENTIFIER(yytext, loc);
.          {
                throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));
           }
<<EOF>>    return yy::parser::make_END(loc);
%%

yy::parser::symbol_type make_NUMBER(
  const std::string &s,
  const yy::parser::location_type& loc
) {
  errno = 0;
  long n = strtol(s.c_str(), NULL, 10);
  if(!(INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error(loc, "integer is out of range: " + s);
  return yy::parser::make_NUMBER((int) n, loc);
}

yy::parser::symbol_type make_BOOL(
  const std::string &str,
  const yy::parser::location_type& location
) {
  return yy::parser::make_BOOL(str[0] == 't', location);
}