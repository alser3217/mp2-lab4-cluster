#include "statistics.h"

int Statistics::get_generated_tasks() {
  return generated_tasks;
}

int Statistics::get_tasks_in_queue() {
  return tasks_in_queue;
}

int Statistics::get_completed_tasks() {
  return completed_tasks;
}

int Statistics::get_not_completed_tasks() {
  return not_completed_tasks;
}

int Statistics::get_not_generated_tasks() {
  return not_generated_tasks;
}

int Statistics::get_did_nothing() {
  return did_nothing;
}

double Statistics::get_average_workload() {
  return average_workload;
}