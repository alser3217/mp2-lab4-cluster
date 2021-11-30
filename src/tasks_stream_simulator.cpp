#include "tasks_stream_simulator.h"
#include "queue.h"
#include "cluster.h"
#include "processor.h"
#include "task.h"
#include "statistics.h"

#include <random>
#include <ctime>
#include <vector>
#include <iostream>

TasksStreamSimulator::TasksStreamSimulator(std::vector<double> parameters) {
  number_of_tacts = parameters[0];
  number_of_processors = parameters[1];
  queue_size = parameters[2];
  intensity = parameters[3];
}

int generate_int(int min, int max) { 
  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_int_distribution<> dis(min, max);
  return dis(engine);
}

double generate_double(int min, int max) { 
  std::random_device rd;
  std::mt19937 engine(rd());
  std::uniform_real_distribution<> dis(min, max);
  return dis(engine);
}

double TasksStreamSimulator::get_intensity() {
  return intensity;
}

void TasksStreamSimulator::begin() {
  int counter_of_tasks = 0;
  int tasks_per_tact;
  int sum_of_busy_processors_per_tact = 0;
  TQueue<Task> call_queue(queue_size);
  Cluster cluster(number_of_processors);
  for (int i = 0; i < number_of_tacts; i++) {
    if (generate_double(0, 1) <= intensity) {
      counter_of_tasks++;
      tasks_per_tact = generate_int(1, 3);
      for (int i = 0; i < tasks_per_tact; i++)
        if(!call_queue.is_full()) {
          call_queue.push(Task(counter_of_tasks, generate_int(1, 3), generate_int(1, 4)));
          generated_tasks++;
        }
        else
          not_generated_tasks++;
    }
    if (call_queue.front().get_processors_needed() <= cluster.free_processors())
      while (call_queue.front().get_processors_needed() <= cluster.free_processors() && !call_queue.is_empty()) {
        cluster.give(call_queue.front().get_processors_needed(), call_queue.front().get_duration());
        if (call_queue.front().get_duration() + i < number_of_tacts)
          completed_tasks++;
        else
          not_completed_tasks++;
        call_queue.pop();
      }
    if (cluster.free_processors() == number_of_processors)
      did_nothing++;
    sum_of_busy_processors_per_tact += (number_of_processors - cluster.free_processors());
  }
  average_workload = static_cast<double>(sum_of_busy_processors_per_tact) / (static_cast<double>(number_of_tacts) * static_cast<double>(number_of_processors));
  tasks_in_queue = call_queue.current_size();
}