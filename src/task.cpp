#include "task.h"

int Task::get_number() {
  return number;
}

int Task::get_duration() {
  return execute_duration;
}

int Task::get_processors_needed() {
  return processors_needed;
}