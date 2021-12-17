#include "gtest/gtest.h"
#include "queue.h"

TEST (TQueue, can_create_queue_with_positive_size) {
  ASSERT_NO_THROW (TQueue<int> qu(5));
}

TEST (TQueue, cant_create_queue_with_negative_size) {
  ASSERT_ANY_THROW (TQueue<int> qu(-4));
}

TEST (TQueue, cant_create_queue_with_too_large_size) {
  ASSERT_ANY_THROW (TQueue<int> qu(MAX_QUEUE_SIZE + 1));
}

TEST (TQueue, size_retuns_right_value) {
  TQueue<int> qu(5);
  EXPECT_EQ (5, qu.size());
}

TEST (TQueue, current_size_retuns_right_value) {
  TQueue<int> qu(5);
  EXPECT_EQ (0, qu.current_size());
}

TEST (TQueue, front_retuns_bottom_value) {
  TQueue<int> qu(5);
  qu.push(4);
  EXPECT_EQ (4, qu.front());
}

TEST (TQueue, push_changes_current_size_of_the_queue) {
  TQueue<int> qu(5);
  qu.push(4);
  EXPECT_EQ (1, qu.current_size());
}

TEST (TQueue, pop_retuns_bottom_value) {
  TQueue<int> qu(5);
  qu.push(4);
  EXPECT_EQ (4, qu.pop());
}

TEST (TQueue, front_does_not_delete_bottom_element) {
  TQueue<int> qu(5);
  qu.push(4);
  qu.front();
  EXPECT_EQ (1, qu.current_size());
}

TEST (TQueue, pop_deletes_bottom_element) {
  TQueue<int> qu(5);
  qu.push(4);
  qu.pop();
  EXPECT_EQ (0, qu.current_size());
}

TEST (TQueue, checks_if_queue_is_empty_returns_true) {
  TQueue<int> qu(5);
  EXPECT_EQ (true, qu.is_empty());
}

TEST (TQueue, checks_if_queue_is_empty_returns_false) {
  TQueue<int> qu(5);
  qu.push(4);
  EXPECT_EQ (false, qu.is_empty());
}

TEST (TQueue, checks_if_queue_is_full_returns_true) {
  TQueue<int> qu(1);
  qu.push(5);
  EXPECT_EQ (true, qu.is_full());
}

TEST (TQueue, checks_if_queue_is_full_returns_false) {
  TQueue<int> qu(1);
  EXPECT_EQ (false, qu.is_full());
}