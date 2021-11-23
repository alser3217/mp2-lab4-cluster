#include "processor.h"

bool Processor::is_free() {
  return free;
}

void Processor::decrease_tacts() {
  busy_tacts--;
}

int Processor::get_busy_tacts() {
  return busy_tacts;
}

void Processor::set_status() {
  if (!busy_tacts)
    free = true;
  else
    free = false;
}

void Processor::set_busy_tacts(int tacts) {
  busy_tacts = tacts;
}