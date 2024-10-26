#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

int Process::Pid() const { return pid_; }

float Process::CpuUtilization() const {
  return LinuxParser::CpuUtilization(Pid());
}

string Process::Command() const { return LinuxParser::Command(Pid()); }

string Process::Ram() const {
  string ramKB_str = LinuxParser::Ram(Pid());
  int d = stoi(ramKB_str) / 1000;
  return to_string(d);
}

string Process::User() const { return LinuxParser::User(Pid()); }

long int Process::UpTime() const { return LinuxParser::UpTime(Pid()); }

bool Process::operator<(const Process& r) const {
  return CpuUtilization() < r.CpuUtilization();
}