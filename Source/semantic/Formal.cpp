#include "Formal.h"

Formal::Formal(Type * type, std::string title): type_(type), name_(std::move(title)) {}

std::string Formal::toString() {
    return type_->toString() + " " + name_;
}

std::string Formal::GetName(){
    return name_;
}