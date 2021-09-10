#include "Program.h"

Program::Program(
    Classes * classes,
    ClassStatement* main
): classes_(classes), main_(main) {}

void Program::Accept(Visitor* visitor) {
    visitor->Visit(this);
}