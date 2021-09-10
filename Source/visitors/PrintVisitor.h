#pragma once

#include "Visitor.h"

#include <fstream>
#include <iostream>
#include <string>

class PrintVisitor: public Visitor {
 public:
    PrintVisitor(const std::string& filename);
    PrintVisitor(std::ostream* file);
    ~PrintVisitor();

    #define OVERRIDE_VISIT(BASE_ELEMENT_TYPE) void Visit(BASE_ELEMENT_TYPE* expression) override
    OVERRIDE_VISIT(Program);
    OVERRIDE_VISIT(ClassStatement);
    OVERRIDE_VISIT(Method);
    OVERRIDE_VISIT(VariableDeclaration);
    OVERRIDE_VISIT(AdditionOperator);
    OVERRIDE_VISIT(AllocateStatement);
    OVERRIDE_VISIT(DivisionOperator);
    OVERRIDE_VISIT(EqualityOperator);
    OVERRIDE_VISIT(AndOperator);
    OVERRIDE_VISIT(AssertStatement);
    OVERRIDE_VISIT(LengthOperator);
    OVERRIDE_VISIT(ReturnStatement);
    OVERRIDE_VISIT(NumberLiteral);
    OVERRIDE_VISIT(NegationOperator);
    OVERRIDE_VISIT(NotOperator);
    OVERRIDE_VISIT(Statements);
    OVERRIDE_VISIT(ExpressionStatement);
    OVERRIDE_VISIT(LessOperator);
    OVERRIDE_VISIT(LocalVariableDeclaration);
    OVERRIDE_VISIT(BooleanLiteral);
    OVERRIDE_VISIT(IndexationOperator);
    OVERRIDE_VISIT(MethodInvocation);
    OVERRIDE_VISIT(VariableReference);
    OVERRIDE_VISIT(OrOperator);
    OVERRIDE_VISIT(IfStatement);
    OVERRIDE_VISIT(ModuloOperator);
    OVERRIDE_VISIT(GreaterOperator);
    OVERRIDE_VISIT(SubtractionOperator);
    OVERRIDE_VISIT(PrintlnFunction);
    OVERRIDE_VISIT(AssignmentOperator);
    OVERRIDE_VISIT(ThisExpression);
    OVERRIDE_VISIT(MultiplicationOperator);
    OVERRIDE_VISIT(ThisField);
    OVERRIDE_VISIT(WhileStatement);
    #undef OVERRIDE_VISIT
 private:
    void PrintTabs();
    std::ostream * file_;
    std::ofstream stream_;
    int shift_right = 0;
};