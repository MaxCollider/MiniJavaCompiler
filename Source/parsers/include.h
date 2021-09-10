#include "semantic/Program.h"
#include "Operator/AdditionOperator.h"
#include "../../Statements/AllocateStatement.h"
#include "Operator/AndOperator.h"
#include "semantic/Arguments.h"
#include "semantic/ArrayType.h"
#include "../../Statements/AssertStatement.h"
#include "semantic/BooleanLiteral.h"
#include "semantic/VariableReference.h"
#include "../../Statements/ClassStatement.h"
#include "semantic/Classes.h"
#include "semantic/Declaration.h"
#include "semantic/Declarations.h"
#include "Operator/DivisionOperator.h"
#include "Operator/EqualityOperator.h"
#include "semantic/Expression.h"
#include "../../Statements/ExpressionStatement.h"
#include "../../Statements/ExtendsStatement.h"
#include "semantic/Formal.h"
#include "semantic/Formals.h"
#include "../../Statements/IfStatement.h"
#include "Operator/IndexationOperator.h"
#include "semantic/MethodInvocation.h"
#include "Operator/LengthOperator.h"
#include "Operator/LessOperator.h"
#include "semantic/LocalVariableDeclaration.h"
#include "semantic/Method.h"
#include "Operator/ModuloOperator.h"
#include "Operator/GreaterOperator.h"
#include "Operator/AssignmentOperator.h"
#include "Operator/MultiplicationOperator.h"
#include "Operator/NegationOperator.h"
#include "Operator/NotOperator.h"
#include "semantic/NumberLiteral.h"
#include "Operator/OrOperator.h"
#include "semantic/PrintlnFunction.h"
#include "semantic/ReturnStatement.h"
#include "semantic/SimpleType.h"
#include "../../Statements/Statement.h"
#include "../../Statements/Statements.h"
#include "Operator/SubtractionOperator.h"
#include "semantic/ThisExpression.h"
#include "semantic/ThisField.h"
#include "semantic/Type.h"
#include "semantic/VariableDeclaration.h"
#include "../../Statements/WhileStatement.h"