#include "processor.h"

#include <iostream>
#include <string>
#include <vector>

#include "linux_parser.h"

using namespace LinuxParser;
using std::string;
using std::vector;

float Processor::Utilization() {
  vector<string> cpu = LinuxParser::CpuUtilization();
  if (cpu.empty()) return 0.0;

  long user = stol(cpu[0]);
  long nice = stol(cpu[1]);
  long system = stol(cpu[2]);
  long idle = stol(cpu[3]);
  long iowait = stol(cpu[4]);
  long irq = stol(cpu[5]);
  long softirq = stol(cpu[6]);
  long steal = stol(cpu[7]);
  // long guest = stol(cpu[8]);
  // long guest_nice = stol(cpu[9]);

  long Idle = idle + iowait;
  long NonIdle = user + nice + system + irq + softirq + steal;
  long Total = Idle + NonIdle;

  long totald = Total - PrevTotal_;
  long idled = Idle - PrevIdle_;

  float utilization = (totald - idled) / (1.0 * totald);

  PrevIdle_ = Idle;
  PrevTotal_ = Total;

  return utilization;
}