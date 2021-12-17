#include "gtest/gtest.h"
#include "processor.h"
#include "processor.cpp"

TEST (Processor, can_create_processor) {
  ASSERT_NO_THROW (Processor pr(3, 1));
}

TEST (Processor, is_free_returns_right_value) {
  Processor pr(5, 1);
  EXPECT_EQ (true, pr.is_free());
}

TEST (Processor, get_busy_tacts_returns_right_value) {
  Processor pr(5, 1);
  EXPECT_EQ (5, pr.get_busy_tacts());
}

TEST (Processor, set_status_sets_is_free) {
  Processor pr(0, 0);
  pr.set_status();
  EXPECT_EQ (true, pr.is_free());
}

TEST (Processor, set_busy_tacts_sets_busy_tacts) {
  Processor pr(4, 0);
  pr.set_busy_tacts(5);
  EXPECT_EQ (5, pr.get_busy_tacts());
}

TEST (Processor, decrease_tacts_decreases_busy_tacts) {
  Processor pr(4, 0);
  pr.decrease_tacts();
  EXPECT_EQ (3, pr.get_busy_tacts());
}
