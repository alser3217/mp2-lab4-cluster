cmake_minimum_required (VERSION 3.21.4)

set (This sample)
project (${This})

include_directories("../include")
add_executable(${This}
  sample.cpp
)

target_link_libraries(${This} PUBLIC
  Cluster_Imitation
)
