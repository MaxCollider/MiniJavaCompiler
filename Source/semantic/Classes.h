#pragma once

#include "../Collector.h"
#include "../Statements/ClassStatement.h"

class Classes: public Collector<ClassStatement*> {};