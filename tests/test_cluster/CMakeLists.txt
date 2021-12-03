cmake_minimum_required(VERSION 2.8)

set (This test_cluster)

set (Sources
  test_cluster.cpp
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