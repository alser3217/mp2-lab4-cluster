cmake_minimum_required(VERSION 2.8)

set (This sample)
project (${This})

include_directories("../include")
add_executable(${This}
  sample.cpp
)

target_link_libraries(${This} PUBLIC
  Cluster_Imitation
)
