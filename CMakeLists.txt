cmake_minimum_required(VERSION 2.8)

set (This Cluster_Imitation)
project (${This})

set(CMAKE_C_STANDART 99)
set(CMAKE_CXX_STANDART 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(tests)
add_subdirectory(samples)

include_directories("include")
include_directories("src")

set(Headers
  include/task.h
  include/cluster.h
  include/queue.h
  include/processor.h
  include/tasks_stream_simulator.h
  include/statistics.h
)

set(Sources
  src/task.cpp
  src/cluster.cpp
  samples/sample.cpp
  src/processor.cpp
  src/tasks_stream_simulator.cpp
  src/statistics.cpp
)

#add_executable (${This}
#  src/task.cpp
#  include/task.h
#  src/cluster.cpp
#  include/cluster.h
#  include/queue.h
#  samples/sample.cpp
#  include/processor.h
#  src/processor.cpp
#  include/tasks_stream_simulator.h
#  src/tasks_stream_simulator.cpp
#  include/statistics.h
#  src/statistics.cpp
#)

add_library(${This} STATIC ${Sources} ${Headers})