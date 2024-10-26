#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();

 private:
  long PrevIdle_ = 0;
  long PrevTotal_ = 0;
};

#endif