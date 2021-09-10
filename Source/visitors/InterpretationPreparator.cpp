#include "visitors/InterpretationPreparator.h"
#include "PrintVisitor.h"

#include <parsers/include.h>
#include <Objects/Int.h>


InterpretionPreparator::InterpretionPreparator() {}

void InterpretionPreparator::Visit(Program* program) {
    for (ClassStatement* classStatement: program->classes_->store) {
        classStatement->Accept(this);
    }
    program->classes_->store;
}

void InterpretionPreparator::Visit(ClassStatement* decl) {
    current_class_name = decl->_name;
    for (Declaration* f: decl->_declarations->store) {
        f->Accept(this);
    }
}

void InterpretionPreparator::Visit(VariableDeclaration* var) {
    class_informations[current_class_name].fields.push_back(var);
}

void InterpretionPreparator::Visit(Method* method) {
    class_informations[current_class_name].methods[method->name_] = method;
}

std::map<std::string, ClassInformation>&& InterpretionPreparator::ExtractClassInformation(){
    return std::move(class_informations);
}

InterpretionPreparator::~InterpretionPreparator() {}