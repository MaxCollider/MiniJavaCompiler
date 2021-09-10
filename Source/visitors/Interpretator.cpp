#include "Interpretator.h"
#include "PrintVisitor.h"

#include <parsers/include.h>
#include <Objects/Int.h>
#include <Objects/Boolean.h>
#include <Objects/Array.h>
#include "../Statements/Statement.h"
#include <visitors/InterpretationPreparator.h>

#include <iostream>
#include <cassert>

Other Allocate(Type* type, const std::map<std::string, ClassInformation>& class_information, int size = 0)
{
    auto type_name = type->toString();
    if (type_name.back() == ']') {
        return std::make_shared<ObjectArray>(type_name.substr(0, type_name.size()-2), size); 
    } else {
        if (type_name == "int")
            return std::make_shared<ObjectInt>(0);
        if (type_name == "boolean")
            return std::make_shared<ObjectBool>(false);
        auto it = class_information.find(type_name);
        if (it != class_information.end()){
            std::shared_ptr<Object> object = std::make_shared<Object>(type_name);
            for (VariableDeclaration* field: it->second.fields) {
                object->fields[field->name_] = Allocate(field->type_, class_information);
            }
            object->methods = it->second.methods;
            return object;
        }
        throw "Allocate error: unknown type '" + type_name + "'";
    }
}

Interpretator::Interpretator() {}

void Interpretator::Visit(Program* program) {
    InterpretionPreparator preparator;
    program->Accept(&preparator);
    class_informations = preparator.ExtractClassInformation();
    for (ClassStatement* item: program->classes_->store) {
        item->Accept(this);
    }
    try {
        program->main_->_declarations->store[0]->Accept(this);
    } catch (AssertStatement * expression) {
        PrintVisitor printer(&std::cout);
        expression->Accept(&printer);
    } catch (AssignmentOperator * move) {
        PrintVisitor printer(&std::cout);
        move->Accept(&printer); 
    } catch (std::string str) {
        std::cout << str << std::endl;
    } catch (...) {
        std::cout << "Somthing gone wrong!" << std::endl;
    }
}

void Interpretator::Visit(ClassStatement* decl) {}

void Interpretator::Visit(VariableDeclaration* var) {
    variables[var->name_] = Allocate(var->type_, class_informations);
}

void Interpretator::Visit(Method* method) {
    std::map<std::string, std::shared_ptr<Object>> old_variables = std::move(variables);
    variables = decltype(variables)();
    std::vector<Formal*>& formals = method->formal_->store;
    for (auto it = formals.rbegin(); it != formals.rend(); ++it){
        variables[(*it)->GetName()] = stack_.back();
        stack_.pop_back();
    }
    for (Statement* statementPtr: method->statements_->store) {
        statementPtr->Accept(this);
    }
    variables = std::move(old_variables);
}

void Interpretator::Visit(AdditionOperator* expression) {
    expression->first->Accept(this);
    std::shared_ptr<Object> lhs = std::move(stack_.back());
    stack_.pop_back();

    expression->second->Accept(this);
    std::shared_ptr<Object> rhs = std::move(stack_.back());
    stack_.pop_back();

    stack_.push_back(std::make_shared<ObjectInt>(lhs->GetInt() + rhs->GetInt()));
}

void Interpretator::Visit(AllocateStatement* expression) {
    int size = 1;
    if (expression->size) {
        expression->size->Accept(this);

        std::shared_ptr<Object> length = stack_.back();
        stack_.pop_back();
        size = length->GetInt();
    }
    if (size < 1)
        throw std::string("AllocateStatement error: bad size");
    stack_.push_back(Allocate(expression->type, class_informations, size));
}

void Interpretator::Visit(AndOperator* expression) {
    expression->first->Accept(this);
    std::shared_ptr<Object> lhs = std::move(stack_.back());
    stack_.pop_back();

    expression->second->Accept(this);
    std::shared_ptr<Object> rhs = std::move(stack_.back());
    stack_.pop_back();

    stack_.push_back(std::make_shared<ObjectBool>(lhs->GetBool() && rhs->GetBool()));
}

void Interpretator::Visit(AssertStatement* expression) {
    expression->_expr->Accept(this);

    std::shared_ptr<Object> assertion = stack_.back();
    stack_.pop_back();

    if (!assertion->GetBool()) {
        std::cout << "Asserting!" << std::endl;
        throw expression;
    }
}

void Interpretator::Visit(BooleanLiteral* expression) {
    stack_.push_back(std::make_shared<ObjectBool>(expression->value_));
}

void Interpretator::Visit(VariableReference* expression) {
    stack_.push_back(variables[expression->name_]);
}

void Interpretator::Visit(DivisionOperator* expression) {
    expression->first->Accept(this);
    std::shared_ptr<Object> numerator = std::move(stack_.back());
    stack_.pop_back();

    expression->second->Accept(this);
    std::shared_ptr<Object> denominator = std::move(stack_.back());
    stack_.pop_back();

    if (denominator->GetInt() == 0){
        throw std::string ("Division by zero");
    }
    stack_.push_back(std::make_shared<ObjectInt>(numerator->GetInt() / denominator->GetInt()));
}

void Interpretator::Visit(EqualityOperator* expression) {
    expression->first->Accept(this);
    std::shared_ptr<Object> first_ = std::move( stack_.back());
    stack_.pop_back();

    expression->second->Accept(this);
    std::shared_ptr<Object> second_ = std::move(stack_.back());
    stack_.pop_back();

    if (first_->GetClassName() != second_->GetClassName()){
        throw "Can't compare for equality objects of types " + first_->GetClassName() + " and " + second_->GetClassName();
    }
    if (dynamic_cast<ObjectInt*>(first_.get()) != nullptr) {
        stack_.push_back(std::make_shared<ObjectBool>(first_->GetInt() == second_->GetInt()));
    } else if (dynamic_cast<ObjectBool*>(first_.get()) != nullptr) {
        stack_.push_back(std::make_shared<ObjectBool>(first_->GetBool() == second_->GetBool()));
    } else {
        stack_.push_back(std::make_shared<ObjectBool>(first_ == second_));
    }
}

void Interpretator::Visit(ExpressionStatement* expression) {
    expression->_expr->Accept(this);
}

void Interpretator::Visit(IfStatement* expression) {
    expression->_cond->Accept(this);
    assert(!stack_.empty());
    std::shared_ptr<Object> condition_value = std::move(stack_.back());
    stack_.pop_back();
    if (condition_value->GetBool()) {
        expression->_then->Accept(this);
    }
    else if (expression->_if_else_ != nullptr) {
        expression->_if_else_->Accept(this);
    }
}

void Interpretator::Visit(IndexationOperator* expression) {
    expression->obj_->Accept(this);
    std::shared_ptr<Object> object = stack_.back();
    stack_.pop_back();
    expression->_index->Accept(this);
    std::shared_ptr<Object> index = stack_.back();
    stack_.pop_back();
    if (index->GetInt() < 0){
        throw std::string ("Bad indexation argument.");
    }
    stack_.push_back(object->GetArray()[index->GetInt()]);


//    value = expression->obj_->Accept(this)->GetArray()[Accept(expression->_index)->GetInt()];
}

void Interpretator::Visit(MethodInvocation* expression) {
    expression->expr_->Accept(this);
    assert(!stack_.empty());
    std::shared_ptr<Object> obj = std::move(stack_.back());
    stack_.pop_back();
    Method* method = obj->FindMethod(expression->name_);
    if (method == nullptr){
        throw "Method " + expression->name_ + " was not found.";
    }
    for (Expression* argument: expression->args_->store) {
        argument->Accept(this);
    }
    std::shared_ptr<Object> old_this = std::move(this_class);
    this_class = std::move(obj);
    method->Accept(this);
    this_class = std::move(old_this);
}

void Interpretator::Visit(LengthOperator* expression) {
    expression->expr_->Accept(this);
    std::shared_ptr<Object> array = stack_.back();
    stack_.pop_back();

    stack_.push_back(std::make_shared<ObjectInt>(static_cast<int>(array->GetArray().size())));
}

void Interpretator::Visit(LessOperator* expression) {
    expression->first->Accept(this);
    std::shared_ptr<Object> lhs = std::move(stack_.back());
    stack_.pop_back();

    expression->second->Accept(this);
    std::shared_ptr<Object> rhs = std::move(stack_.back());
    stack_.pop_back();

    stack_.push_back(std::make_shared<ObjectBool>(lhs->GetInt() < rhs->GetInt()));
}

void Interpretator::Visit(LocalVariableDeclaration* decl) {
    variables[((VariableDeclaration*)(decl->var_))->name_] = Allocate(((VariableDeclaration*)(decl->var_))->type_, class_informations);
}

void Interpretator::Visit(ModuloOperator* expression) {
    expression->first->Accept(this);
    std::shared_ptr<Object> lhs = std::move(stack_.back());
    stack_.pop_back();

    expression->second->Accept(this);
    std::shared_ptr<Object> rhs = std::move(stack_.back());
    stack_.pop_back();

    if (rhs->GetInt() == 0) {
        throw std::string("Taking remainder of division by zero!");
    }

    stack_.push_back(std::make_shared<ObjectInt>(lhs->GetInt() % rhs->GetInt()));
}

void Interpretator::Visit(GreaterOperator* expression) {
    expression->first->Accept(this);
    std::shared_ptr<Object> lhs = std::move(stack_.back());
    stack_.pop_back();

    expression->second->Accept(this);
    std::shared_ptr<Object> rhs = std::move(stack_.back());
    stack_.pop_back();

    stack_.push_back(std::make_shared<ObjectBool>(lhs->GetInt() > rhs->GetInt()));
}

void Interpretator::Visit(AssignmentOperator* assignment) {
    assignment->src_->Accept(this);
    std::shared_ptr<Object> src = stack_.back();
    stack_.pop_back();

    assignment->dest_->Accept(this);
    std::shared_ptr<Object> dst = stack_.back();
    stack_.pop_back();

//    if (src->GetClassName() != dst->GetClassName()){
//        throw "Can't assign a " + dst->GetClassName() + " to a variable of type " + src->GetClassName() + ".";
//    }
    if (dynamic_cast<ObjectBool*>(dst.get()) != nullptr)
        dst->GetBool() = src->GetBool();
    else if (dynamic_cast<ObjectInt*>(dst.get()) != nullptr)
        dst->GetInt() = src->GetInt();
    else {
        dst->GetArray() = src->GetArray();
    }
}

void Interpretator::Visit(MultiplicationOperator* expression) {
    expression->first->Accept(this);
    std::shared_ptr<Object> lhs = std::move(stack_.back());
    stack_.pop_back();

    expression->second->Accept(this);
    std::shared_ptr<Object> rhs = std::move(stack_.back());
    stack_.pop_back();

    stack_.push_back(std::make_shared<ObjectInt>(lhs->GetInt() * rhs->GetInt()));
}

void Interpretator::Visit(NegationOperator* expression) {
    expression->expr_->Accept(this);
    std::shared_ptr<Object> value = std::move(stack_.back());
    stack_.pop_back();

    stack_.push_back(std::make_shared<ObjectInt>(-value->GetInt()));
}

void Interpretator::Visit(NotOperator* expression) {
    expression->expr_->Accept(this);
    std::shared_ptr<Object> value = std::move(stack_.back());
    stack_.pop_back();

    stack_.push_back(std::make_shared<ObjectBool>(!value->GetBool()));
}

void Interpretator::Visit(NumberLiteral* expression) {
    stack_.push_back(std::make_shared<ObjectInt>(expression->value_));
}

void Interpretator::Visit(OrOperator* expression) {
    expression->first->Accept(this);
    std::shared_ptr<Object> first_ = std::move( stack_.back());
    stack_.pop_back();

    expression->second->Accept(this);
    std::shared_ptr<Object> second_ = std::move(stack_.back());
    stack_.pop_back();

    stack_.push_back(std::make_shared<ObjectBool>(first_->GetBool() || second_->GetBool()));
}

void Interpretator::Visit(PrintlnFunction* statment) {
    statment->expr_->Accept(this);
    assert(!stack_.empty());

    std::cout << stack_.back()->toString() << std::endl;
    stack_.pop_back();
}

void Interpretator::Visit(ReturnStatement* statment) {
    statment->expr_->Accept(this);
}

void Interpretator::Visit(Statements* block) {
    for (Statement* statement: block->store)
        statement->Accept(this);
}

void Interpretator::Visit(SubtractionOperator* expression) {
    expression->first->Accept(this);
    std::shared_ptr<Object> lhs = std::move(stack_.back());
    stack_.pop_back();

    expression->second->Accept(this);
    std::shared_ptr<Object> rhs = std::move(stack_.back());
    stack_.pop_back();

    stack_.push_back(std::make_shared<ObjectInt>(lhs->GetInt() - rhs->GetInt()));
}

void Interpretator::Visit(ThisExpression* expression) {
    if (!this_class) {
        throw std::string("There's no active object instance for \"this\" keyword.");
    }
    stack_.push_back(this_class);
}

void Interpretator::Visit(ThisField* expression) {
    stack_.push_back(this_class->FindField(expression->name_));
}

void Interpretator::Visit(WhileStatement* statment) {
    do {
        statment->_cond->Accept(this);
        std::shared_ptr<Object> condition_value = std::move(stack_.back());
        stack_.pop_back();

        if (condition_value->GetBool()) {
            statment->_then->Accept(this);
        } else {
            break;
        }
    } while (true);
}

Interpretator::~Interpretator() {}