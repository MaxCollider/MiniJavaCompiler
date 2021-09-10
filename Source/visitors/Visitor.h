#pragma once
#include <semantic/classes_declaration.h>
class Visitor {
 public:
    #define DECLARE_VISIT(BASE_ELEMENT_TYPE) virtual void Visit(BASE_ELEMENT_TYPE* expression) = 0;
    DECLARE_VISIT(Program);
    DECLARE_VISIT(ClassStatement);
    DECLARE_VISIT(Method);
    DECLARE_VISIT(VariableDeclaration);
    DECLARE_VISIT(AdditionOperator);
    DECLARE_VISIT(AllocateStatement);
    DECLARE_VISIT(DivisionOperator);
    DECLARE_VISIT(EqualityOperator);
    DECLARE_VISIT(AndOperator);
    DECLARE_VISIT(AssertStatement);
    DECLARE_VISIT(LengthOperator);
    DECLARE_VISIT(ReturnStatement);
    DECLARE_VISIT(NumberLiteral);
    DECLARE_VISIT(NegationOperator);
    DECLARE_VISIT(NotOperator);
    DECLARE_VISIT(Statements);
    DECLARE_VISIT(ExpressionStatement);
    DECLARE_VISIT(LessOperator);
    DECLARE_VISIT(LocalVariableDeclaration);
    DECLARE_VISIT(BooleanLiteral);
    DECLARE_VISIT(IndexationOperator);
    DECLARE_VISIT(MethodInvocation);
    DECLARE_VISIT(VariableReference);
    DECLARE_VISIT(OrOperator);
    DECLARE_VISIT(IfStatement);
    DECLARE_VISIT(ModuloOperator);
    DECLARE_VISIT(GreaterOperator);
    DECLARE_VISIT(SubtractionOperator);
    DECLARE_VISIT(PrintlnFunction);
    DECLARE_VISIT(AssignmentOperator);
    DECLARE_VISIT(ThisExpression);
    DECLARE_VISIT(MultiplicationOperator);
    DECLARE_VISIT(ThisField);
    DECLARE_VISIT(WhileStatement);
};

#include <semantic/Sample.h>