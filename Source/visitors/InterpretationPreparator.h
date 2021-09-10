#pragma once

#include "TemplateVisitor.h"
#include <semantic/Expression.h>

#include <Objects/Object.h>

#include <string>
#include <map>

#include "visitors/ClassInformation.h"

class InterpretionPreparator: public TemplateVisitor<Other> {
public:
    InterpretionPreparator();
    ~InterpretionPreparator();

#define OVERRIDE_VISIT(name) void Visit(name*)
    OVERRIDE_VISIT(Program);
    OVERRIDE_VISIT(ClassStatement);
    OVERRIDE_VISIT(Method);
    OVERRIDE_VISIT(VariableDeclaration);

#define EMPTY_VISIT(name) OVERRIDE_VISIT(name){}
    EMPTY_VISIT(AdditionOperator);
    EMPTY_VISIT(AllocateStatement);
    EMPTY_VISIT(DivisionOperator);
    EMPTY_VISIT(EqualityOperator);
    EMPTY_VISIT(AndOperator);
    EMPTY_VISIT(AssertStatement);
    EMPTY_VISIT(LengthOperator);
    EMPTY_VISIT(ReturnStatement);
    EMPTY_VISIT(NumberLiteral);
    EMPTY_VISIT(NegationOperator);
    EMPTY_VISIT(NotOperator);
    EMPTY_VISIT(Statements);
    EMPTY_VISIT(ExpressionStatement);
    EMPTY_VISIT(LessOperator);
    EMPTY_VISIT(LocalVariableDeclaration);
    EMPTY_VISIT(BooleanLiteral);
    EMPTY_VISIT(IndexationOperator);
    EMPTY_VISIT(MethodInvocation);
    EMPTY_VISIT(VariableReference);
    EMPTY_VISIT(OrOperator);
    EMPTY_VISIT(IfStatement);
    EMPTY_VISIT(ModuloOperator);
    EMPTY_VISIT(GreaterOperator);
    EMPTY_VISIT(SubtractionOperator);
    EMPTY_VISIT(PrintlnFunction);
    EMPTY_VISIT(AssignmentOperator);
    EMPTY_VISIT(ThisExpression);
    EMPTY_VISIT(MultiplicationOperator);
    EMPTY_VISIT(ThisField);
    EMPTY_VISIT(WhileStatement);
#undef OVERRIDE_VISIT

    std::map<std::string, ClassInformation>&& ExtractClassInformation();
private:
    std::string current_class_name;
    std::map<std::string, ClassInformation> class_informations;
};