#include <iostream>

#include "cluster.h"

Cluster::Cluster(int _number_of_processors) {
  if (_number_of_processors < 0 || _number_of_processors > MAX_PROCESSORS_CLUSTER_CONTAINS)
    throw "Cluster can't contain this amount of processors.";
  number_of_processors = _number_of_processors;
  for (int i = 0; i < number_of_processors; i++)
    processors.push_back(Processor());
}

int Cluster::free_processors() {
  int free = 0;
  for (int i = 0; i < number_of_processors; i++) {
    if (processors[i].is_free())
      free++;
  }
  return free;
}

void Cluster::update() {
  for (int i = 0; i < processors.size(); i++) {
    if(processors[i].get_busy_tacts())
      processors[i].decrease_tacts();
    processors[i].set_status();
  }
}

void Cluster::give(int number, int tacts) {
  int counter = 0, i = 0;
  while (counter < number) {
    if (processors[i].is_free()){
      processors[i].set_busy_tacts(tacts);
      processors[i].set_status();
      counter++;
    }
    i++;
  }
}

Cluster::Cluster(const Cluster& object) {
  processors = object.processors;
  number_of_processors = object.number_of_processors;
}

Cluster& Cluster::operator=(const Cluster& object) {
  if (this == &object)
    return *this;
  processors = object.processors;
  number_of_processors = object.number_of_processors;
  return *this;
}