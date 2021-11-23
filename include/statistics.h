#ifndef __STATISTICS__
#define __STATISTICS__

class Statistics {
protected:
  int generated_tasks = 0;
  int not_generated_tasks = 0;
  int tasks_in_queue = 0;
  int completed_tasks = 0;
  int not_completed_tasks = 0;
  int did_nothing = 0;
  double average_workload = 0;
public:
  int get_generated_tasks();
  int get_tasks_in_queue();
  int get_completed_tasks();
  int get_not_completed_tasks();
  int get_not_generated_tasks();
  int get_did_nothing();
  double get_average_workload();
};


#endif