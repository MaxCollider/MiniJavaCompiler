#include "PrintVisitor.h"

#include <parsers/include.h>

#include <iostream>

PrintVisitor::PrintVisitor(const std::string& filename) : stream_(filename), file_(&stream_) {}
PrintVisitor::PrintVisitor(std::ostream* file): file_(file) {}

void PrintVisitor::Visit(Program* program) {
    (*file_) << "Program:" << std::endl;

    ++shift_right;
    for (ClassStatement* decl: program->classes_->store)
        decl->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(ClassStatement* decl) {
    PrintTabs();
    (*file_) << "ClassStatement " << decl->_name << " " << decl->_extends->toString() << std::endl;

    ++shift_right;
    for (Declaration* field: decl->_declarations->store)
        field->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(VariableDeclaration* var) {
    PrintTabs();
    (*file_) << "VariableDeclaration: " << var->toString() << std::endl;
}

void PrintVisitor::Visit(Method* method) {
    PrintTabs();
    (*file_) << "Method: " << method->type_->toString() << " " << method->name_ << "(";
    ++shift_right;
    for (Formal* formal: method->formal_->store) {
        (*file_) << "\n";
        PrintTabs();
        (*file_) << formal->toString() << ",";
    }
    --shift_right;
    if (method->formal_->store.size()) {
        (*file_) << "\n";
        PrintTabs();
    }
    (*file_) << ")" << std::endl;

    ++shift_right;
    method->statements_->Accept(this);
    --shift_right;
}


void PrintVisitor::Visit(AdditionOperator* expression) {
    PrintTabs();
    (*file_) << "AdditionOperator is:" << std::endl;

    ++shift_right;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(AllocateStatement* expression) {
    PrintTabs();
    (*file_) << "AllocateStatement: " << expression->type->toString() << std::endl;

    if (expression->size) {
        ++shift_right;
        expression->size->Accept(this);
        --shift_right;
    }
}

void PrintVisitor::Visit(AndOperator* expression) {
    PrintTabs();
    (*file_) << "AndOperator is:" << std::endl;

    ++shift_right;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(AssertStatement* expression) {
    PrintTabs();
    (*file_) << "AssertStatement is:" << std::endl;

    ++shift_right;
    expression->_expr->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(BooleanLiteral* expression) {
    PrintTabs();
    (*file_) << "BooleanLiteral:" << expression->value_ << std::endl;
}

void PrintVisitor::Visit(VariableReference* expression) {
    PrintTabs();
    (*file_) << "VariableReference " << expression->name_ << std::endl;
}

void PrintVisitor::Visit(DivisionOperator* expression) {
    PrintTabs();
    (*file_) << "DivisionOperator:" << std::endl;

    ++shift_right;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(EqualityOperator* expression) {
    PrintTabs();
    (*file_) << "EqualityOperator:" << std::endl;

    ++shift_right;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(MultiplicationOperator* expression) {
    PrintTabs();

    (*file_) << "MultiplicationOperator: " << std::endl;
    ++shift_right;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(ExpressionStatement* expression) {
    PrintTabs();
    (*file_) << "ExpressionStatement: " << std::endl;

    ++shift_right;
    expression->_expr->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(IndexationOperator* expression) {
    PrintTabs();
    (*file_) << "IndexationOperator: " << std::endl;

    ++shift_right;
    expression->obj_->Accept(this);
    expression->_index->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(IfStatement* expression) {
    PrintTabs();
    (*file_) << "IfStatement: " << std::endl;

    ++shift_right;
    expression->_cond->Accept(this);
    expression->_then->Accept(this);
    if (expression->_if_else_)
        expression->_if_else_->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(LessOperator* expression) {
    PrintTabs();
    (*file_) << "LessOperator: " << std::endl;

    ++shift_right;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(AssignmentOperator* assignment) {
    PrintTabs();
    (*file_) << "AssignmentOperator: " << std::endl;
    ++shift_right;
    assignment->dest_->Accept(this);
    assignment->src_->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(LengthOperator* expression) {
    PrintTabs();
    (*file_) << "LengthOperator: " << std::endl;

    ++shift_right;
    expression->expr_->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(LocalVariableDeclaration* decl) {
    PrintTabs();
    (*file_) << "LocalVariableDeclaration: " << decl->var_->toString() << std::endl;
}

void PrintVisitor::Visit(ModuloOperator* expression) {
    PrintTabs();
    (*file_) << "ModuloOperator: " << std::endl;

    ++shift_right;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(WhileStatement* statment) {
    PrintTabs();
    (*file_) << "WhileStatement: " << std::endl;

    ++shift_right;
    statment->_cond->Accept(this);
    statment->_then->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(MethodInvocation* expression) {
    PrintTabs();
    (*file_) << "MethodInvocation: " << expression->name_ << std::endl;

    ++shift_right;
    expression->expr_->Accept(this);
    PrintTabs();
    (*file_) << "Arguments: " << std::endl;
    ++shift_right;
    for (Expression* argument: expression->args_->store)
        argument->Accept(this);
    shift_right -= 2;
}

void PrintVisitor::Visit(GreaterOperator* expression) {
    PrintTabs();
    (*file_) << "GreaterOperator: " << std::endl;

    ++shift_right;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(NegationOperator* expression) {
    PrintTabs();
    (*file_) << "NegationOperator: " << std::endl;
    ++shift_right;
    expression->expr_->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(NotOperator* expression) {
    PrintTabs();
    (*file_) << "NotOperator: " << std::endl;
    ++shift_right;
    expression->expr_->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(NumberLiteral* expression) {
    PrintTabs();
    (*file_) << "NumberLiteral: " << expression->value_ << std::endl;
}

void PrintVisitor::Visit(OrOperator* expression) {
    PrintTabs();

    (*file_) << "OrOperator: " << std::endl;
    ++shift_right;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(PrintlnFunction* statment) {
    PrintTabs();
    (*file_) << "PrintlnFunction: " << std::endl;
    ++shift_right;
    statment->expr_->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(ReturnStatement* statment) {
    PrintTabs();
    (*file_) << "ReturnStatement: " << std::endl;
    ++shift_right;
    statment->expr_->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(Statements* block) {
    PrintTabs();
    (*file_) << "Statements: " << std::endl;

    ++shift_right;
    for (Statement* statment: block->store)
        statment->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(SubtractionOperator* expression) {
    PrintTabs();
    (*file_) << "SubtractionOperator: " << std::endl;

    ++shift_right;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --shift_right;
}

void PrintVisitor::Visit(ThisExpression* expression) {
    PrintTabs();
    (*file_) << "ThisExpression" << std::endl;
}

void PrintVisitor::Visit(ThisField* expression) {
    PrintTabs();
    (*file_) << "ThisExpression." << expression->name_ << std::endl;
}

PrintVisitor::~PrintVisitor() {
    if (!file_)
        stream_.close();
}

void PrintVisitor::PrintTabs() {
    for (int i = 0; i < shift_right; ++i) {
        (*file_) << '\t';
    }
}