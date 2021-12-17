#ifndef __CLUSTER__
#define __CLUSTER__

#include "processor.h"

#include <vector>

#define MAX_PROCESSORS_CLUSTER_CONTAINS 64

class Cluster {
  std::vector<Processor> processors;
  int number_of_processors;
public:
  Cluster(int _number_of_processors);
  Cluster(const Cluster& object);
  int free_processors();
  void update();
  void give(int number, int tacts);
  Cluster& operator=(const Cluster& object);
};

#endif