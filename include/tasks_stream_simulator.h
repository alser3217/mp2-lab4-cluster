#ifndef __TASKS_STREAM_SIMULATOR__
#define __TASKS_STREAM_SIMULATOR__

#include "statistics.h"

class TasksStreamSimulator : public Statistics { 
  int number_of_tacts;
  int number_of_processors;
  int queue_size;
  double intensity;
public:
  TasksStreamSimulator(int _number_of_tacts, int _number_of_processors, int _queue_size, double _intensity) : number_of_tacts(_number_of_tacts),
  number_of_processors(_number_of_processors), queue_size(_queue_size), intensity(_intensity) {}
  void begin();
  double get_intensity();
};


#endif