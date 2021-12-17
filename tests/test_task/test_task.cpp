#include "gtest/gtest.h"
#include "task.h"
#include "task.cpp"

TEST (Task, can_create_task) {
  ASSERT_NO_THROW (Task ts(1, 3, 4));
}

TEST (Task, get_number_returns_right_value) {
  Task ts(1, 3, 4);
  EXPECT_EQ (1, ts.get_number());
}

TEST (Task, get_duration_returns_right_value) {
  Task ts(1, 3, 4);
  EXPECT_EQ (3, ts.get_duration());
}

TEST (Task, get_processors_needed_returns_right_value) {
  Task ts(1, 3, 4);
  EXPECT_EQ (4, ts.get_processors_needed());
}