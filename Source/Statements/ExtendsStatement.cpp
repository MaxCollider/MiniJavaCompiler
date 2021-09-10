#include "ExtendsStatement.h"

ExtendsStatement::ExtendsStatement(std::string name): title(name) {}

std::string ExtendsStatement::toString() {
    return std::string("extends ") + title;
}