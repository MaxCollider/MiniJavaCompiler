#include "MethodInvocation.h"

MethodInvocation::MethodInvocation(
    Expression * expr,
    std::string name,
    Arguments * args
): expr_(expr), name_(std::move(name)), args_(args) {}

void MethodInvocation::Accept(Visitor* visitor) {
    visitor->Visit(this);
}