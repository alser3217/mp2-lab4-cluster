#ifndef __TASK__
#define __TASK__

class Task {
  int number;
  int execute_duration;
  int processors_needed;
public:
  Task(int _number = 0, int _execute_duration = 0, int _processors_needed = 0): number(_number), execute_duration(_execute_duration),
  processors_needed(_processors_needed) {}
  //~Task() {}
  int get_number();
  int get_duration();
  int get_processors_needed();
};

#endif