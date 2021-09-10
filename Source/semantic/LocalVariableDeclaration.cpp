#include "LocalVariableDeclaration.h"

LocalVariableDeclaration::LocalVariableDeclaration(Declaration * variable): var_(variable) {}

void LocalVariableDeclaration::Accept(Visitor* visitor) {
    visitor->Visit(this);
}