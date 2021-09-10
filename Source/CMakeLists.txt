project(MiniJavaCompiler)
set(
    HEADERS
    driver.h
)

BISON_TARGET(
    Parser
        parsers/parser.y
    ${CMAKE_CURRENT_BINARY_DIR}/parsers/parser.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parsers/parser.hh
)

FLEX_TARGET(
    Scanner
    lexical/scanner.l
    ${CMAKE_CURRENT_BINARY_DIR}/lexical/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(Scanner Parser)

add_executable(
    MiniJavaCompiler
    main.cpp
    driver.cpp
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Scanner_OUTPUTS}
    Operator/AdditionOperator.cpp
        Statements/AllocateStatement.cpp
    Operator/AndOperator.cpp
    semantic/ArrayType.cpp
        Statements/AssertStatement.cpp
    semantic/BooleanLiteral.cpp
    semantic/VariableReference.cpp
        Statements/ClassStatement.cpp
    Operator/DivisionOperator.cpp
    Operator/EqualityOperator.cpp
        Statements/ExpressionStatement.cpp
        Statements/ExtendsStatement.cpp
    semantic/Formal.cpp
        Statements/IfStatement.cpp
    Operator/IndexationOperator.cpp
    semantic/MethodInvocation.cpp
    Operator/LengthOperator.cpp
    Operator/LessOperator.cpp
    semantic/LocalVariableDeclaration.cpp
    semantic/Method.cpp
    Operator/ModuloOperator.cpp
    Operator/AssignmentOperator.cpp
    Operator/GreaterOperator.cpp
    Operator/MultiplicationOperator.cpp
    Operator/NotOperator.cpp
    semantic/NumberLiteral.cpp
    Operator/OrOperator.cpp
    semantic/PrintlnFunction.cpp
    semantic/ReturnStatement.cpp
    semantic/SimpleType.cpp
        Statements/Statements.cpp
    Operator/SubtractionOperator.cpp
    semantic/ThisExpression.cpp
    semantic/ThisField.cpp
    semantic/VariableDeclaration.cpp
        Statements/WhileStatement.cpp
    Operator/NegationOperator.cpp
    semantic/Program.cpp
    visitors/PrintVisitor.cpp
    visitors/Interpretator.cpp
    visitors/InterpretationPreparator.cpp
    Objects/Object.cpp
    Objects/Int.cpp
    Objects/Boolean.cpp
    Objects/Array.cpp
)

target_include_directories(
    MiniJavaCompiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
)
