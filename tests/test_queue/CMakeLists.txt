cmake_minimum_required (VERSION 3.21.4)

set (This test_queue)

set (Sources
  test_queue.cpp
)

include_directories("../../include")


add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
  gtest_main
  Cluster_Imitation
)

add_test(
  NAME ${This}
  COMMAND ${This}
)