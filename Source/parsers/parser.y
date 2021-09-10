%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;

    #include <declarations.h>
    #include "include.h"
}

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.h"
    #include "parsers/location.hh"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    DIV "/"
    MOD "%"
    LESS "<"
    MORE ">"
    EQ "=="
    AND "&&"
    OR "||"
    NOT "!"

    LPAREN "("
    RPAREN ")"
    LEFTSCOPE "{"
    RIGHTSCOPE "}"
    SEMICOLON ";"
    LEFTADDRESS "["
    RIGHTADDRESS "]"
    FIELD "."
    
    INT "int"
    BOOLEAN "boolean"
    VOID "void"

    NEW "new"
    THIS "this"
    CLASS "class"
    EXTENDS "extends"
    PUBLIC "public"
    ELSE "else"
    ASSERT "assert"
    STATIC "static"
    MAIN "main"
    RETURN "return"
    PRINT "System.out.println"
    
    IF "if"
    WHILE "while"
;

%token <bool> BOOL "bool"
%token <int> NUMBER "number"
%token <std::string> IDENTIFIER "identifier"


%nterm <Expression*> lvalue
%nterm <Expression*> field_invocation
%nterm <Expression*> method_invocation
%nterm <Expression*> expr
%nterm <Arguments*> arguments_any
%nterm <Arguments*> arguments 
%nterm <Statement*> local_var_declaration
%nterm <Statement*> statement
%nterm <Statements*> statements
%nterm <std::string> array_type
%nterm <std::string> simple_type
%nterm <Type*> type
%nterm <Formal*> formal
%nterm <Formals*> formals_any
%nterm <Formals*> formals
%nterm <Declaration*> var_declaration
%nterm <Declaration*> method_declaration
%nterm <Declaration*> declaration
%nterm <Declarations*> declarations
%nterm <ExtendsStatement*> extends
%nterm <ClassStatement*> class_declaration
%nterm <ClassStatement*> main_class
%nterm <Classes*> class_declarations
%nterm <Program*> program

%left "&&" "||"
%left "<" ">" "=" "<=" ">=" "=="
%left "+" "-"
%left "*" "/" "%"


%%
%start program;

program: main_class class_declarations END { $2->Add($1); $$ = new Program($2, $1); driver.program = $$; }

class_declarations: %empty { $$ = new Classes(); }
    | class_declarations class_declaration { $1->Add($2); $$ = $1; }

main_class: "class" "identifier" "{" "public" "static" "void" "main" "(" ")" "{" statements "}" "}" {
        auto tmp = new Declarations();
        tmp->Add(new Method("main", new SimpleType("void"), new Formals(), $11));
        $$ = new ClassStatement($2, new ExtendsStatement(), tmp);
    }

class_declaration: "class" "identifier" extends "{" declarations "}" { $$ = new ClassStatement($2, $3, $5); }

extends: %empty { $$ = new ExtendsStatement(); }
    | "extends" "identifier" { $$ = new ExtendsStatement($2); }

declarations: %empty { $$ = new Declarations(); }
    | declarations declaration { $1->Add($2); $$ = $1; }

declaration: var_declaration { $$ = $1; }
    | method_declaration { $$ = $1; }

var_declaration: type "identifier" ";" { $$ = new VariableDeclaration($1, $2); }

method_declaration: "public" type "identifier" "(" formals ")" "{" statements "}" { $$ = new Method($3, $2, $5, $8); }

statements: %empty { $$ = new Statements(); }
    | statements statement { $1->Add($2); $$ = $1; }

formals: %empty { $$ = new Formals(); }
    | formals_any { $$ = $1; }

formals_any: formal { $$ = new Formals(); $$->Add($1); }
    | formals_any "," formal { $1->Add($3); $$ = $1; }

formal: type "identifier" { $$ = new Formal($1, $2); }

type: simple_type { $$ = new SimpleType($1); }
    | array_type { $$ = new ArrayType($1); }

simple_type: "int" { $$ = "int"; }
    | "boolean" { $$ = "boolean"; }
    | "void" { $$ = "void"; }
    | "identifier" { $$ = $1; }

array_type: simple_type "[" "]" { $$ = $1; }

statement: "assert" "(" expr ")" ";" { $$ = new AssertStatement($3); }
    | local_var_declaration { $$ = $1; }
    | "{" statements "}" { $$ = $2; }
    | "if" "(" expr ")" statement { $$ = new IfStatement($3, $5); }
    | "if" "(" expr ")" statement "else" statement { $$ = new IfStatement($3, $5, $7); }
    | "while" "(" expr ")" statement { $$ = new WhileStatement($3, $5); }
    | "System.out.println" "(" expr ")" ";" { $$ = new PrintlnFunction($3); }
    | lvalue "=" expr ";" { $$ = new AssignmentOperator($1, $3); }
    | "return" expr ";" { $$ = new ReturnStatement($2); }
    | method_invocation ";" { $$ = new ExpressionStatement($1); }

local_var_declaration: var_declaration { $$ = new LocalVariableDeclaration($1); }

method_invocation: expr "." "identifier" "(" arguments ")" { $$ = new MethodInvocation($1, $3, $5); }
    | "this" "." "identifier" "(" arguments ")" { $$ = new MethodInvocation(new ThisExpression(), $3, $5); }

arguments: %empty { $$ = new Arguments(); }
    | arguments_any { $$ = $1; }

arguments_any: expr { $$ = new Arguments(); $$->Add($1); }
    | arguments_any "," expr { $1->Add($3); $$ = $1; }

field_invocation: "this" "." "identifier" { $$ = new ThisField($3); }
    | "this" "." "identifier" "[" expr "]" { $$ = new IndexationOperator(new ThisField($3), $5); }

lvalue: "identifier" { $$ = new VariableReference($1); }
    | "identifier" "[" expr "]" { $$ = new IndexationOperator(new VariableReference($1), $3); }
    | field_invocation { $$ = $1; }


expr: "-" expr { $$ = new NegationOperator($2); }
    | expr "&&" expr { $$ = new AndOperator($1, $3); }
    | expr "||" expr { $$ = new OrOperator($1, $3); }
    | expr "<" expr { $$ = new LessOperator($1, $3); }
    | expr ">" expr { $$ = new GreaterOperator($1, $3); }
    | expr "==" expr { $$ = new EqualityOperator($1, $3); }
    | expr "+" expr { $$ = new AdditionOperator($1, $3); }
    | expr "-" expr { $$ = new SubtractionOperator($1, $3); }
    | expr "*" expr { $$ = new MultiplicationOperator($1, $3); }
    | expr "/" expr { $$ = new DivisionOperator($1, $3); }
    | expr "%" expr { $$ = new ModuloOperator($1, $3); }
    | expr "[" expr "]" { $$ = new IndexationOperator($1, $3); }
    | expr "." "length" { $$ = new LengthOperator($1); }
    | "new" simple_type "[" expr "]" { $$ = new AllocateStatement(new ArrayType($2), $4); }
    | "new" simple_type "(" ")" { $$ = new AllocateStatement(new SimpleType($2)); }
    | "!" expr { $$ = new NotOperator($2); }
    | "(" expr ")" { $$ = $2; }
    | "identifier" { $$ = new VariableReference($1); }
    | "number" { $$ = new NumberLiteral($1); }
    | "this" { $$ = new ThisExpression(); }
    | "bool" { $$ = new BooleanLiteral($1); }
    | method_invocation { $$ = $1; }
    | field_invocation { $$ = $1; }

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
