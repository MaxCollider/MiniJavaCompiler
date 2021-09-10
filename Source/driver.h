#pragma once

#include <map>
#include <string>
#include <fstream>
#include <parsers/parser.hh>
#include <lexical/scanner.h>

#include "semantic/Program.h"

class Driver {
  public:
    Driver();

    int parse(const std::string& f);
    std::string file;
    bool trace_parsing;

    void scan_begin();
    void scan_end();

    bool trace_scanning;
    yy::location location;

    friend class Scanner;
    Scanner scanner;
    yy::parser parser;
    Program* program;
  private:
    std::ifstream stream;
};
