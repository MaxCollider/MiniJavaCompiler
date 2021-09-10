#pragma once

#include "TemplateVisitor.h"
#include <semantic/Expression.h>

#include <Objects/Object.h>

#include <string>
#include <map>

#include "visitors/ClassInformation.h"

class Interpretator: public TemplateVisitor<Other> {
 public:
    Interpretator();
    ~Interpretator();

    #define OVERRIDE_VISIT(name) void Visit(name*) override
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

    std::map<std::string, std::shared_ptr<Object>> variables;
private:
    std::shared_ptr<Object> this_class;
    std::vector<std::shared_ptr<Object>> stack_;
    std::map<std::string, ClassInformation> class_informations;
};