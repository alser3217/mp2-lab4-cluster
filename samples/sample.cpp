#include "task.h"
#include "cluster.h"
#include "queue.h"
#include "processor.h"
#include "tasks_stream_simulator.h"
#include <iostream>

int main() {
  TasksStreamSimulator simulator(1000, 64, 50, 0.4);
  simulator.begin();
  std::cout << "Number of generated tasks: " << simulator.get_generated_tasks() << std::endl;
  std::cout << "Number of tasks in queue: " << simulator.get_tasks_in_queue() << std::endl;
  std::cout << "Number of completed tasks: " << simulator.get_completed_tasks() << std::endl;
  std::cout << "Refuses (queue overflow): " << simulator.get_not_generated_tasks() << std::endl;
  std::cout << "Number of not completed tasks: " << simulator.get_not_completed_tasks() << std::endl;
  std::cout << "Cluster did nothing: " << simulator.get_did_nothing() << std::endl;
  std::cout << "Average workload: " << simulator.get_average_workload() * 100 << "%" << std::endl;
}