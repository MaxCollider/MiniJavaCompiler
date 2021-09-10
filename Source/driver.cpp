#include "driver.h"
#include "visitors/PrintVisitor.h"
#include "visitors/Interpretator.h"


Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {
}


int Driver::parse(const std::string& File) {
    file = File;
    location.initialize(&file);
    scan_begin();
    parser.set_debug_level(trace_parsing);
    int answer = parser();

    if (program) {
      PrintVisitor printVisitor(File.substr(0, File.length() - 5) + ".ast");
      program->Accept(&printVisitor);

      Interpretator in;
      program->Accept(&in);
    }
    
    scan_end();
    return answer;
}

void Driver::scan_begin() {
    scanner.set_debug(trace_scanning);
  if (file.empty () || file == "-") {
  } else {
    stream.open(file);
    scanner.yyrestart(&stream);
  }
}

void Driver::scan_end()
{
    stream.close();
}

