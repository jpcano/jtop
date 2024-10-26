#include <iostream>

#include "linux_parser.h"
#include "ncurses_display.h"
#include "processor.h"
#include "system.h"

int main() {
  System system;

  NCursesDisplay::Display(system);
  //  for (auto p : LinuxParser::CpuUtilization()) {
  // std::cout << "out: " << p << std::endl;
  //}

  // std::cout << "out: " << LinuxParser::CpuUtilization() << std::endl;
}