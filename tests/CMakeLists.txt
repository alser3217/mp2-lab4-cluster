cmake_minimum_required(VERSION 2.8)

set (This unit_tests)

include_directories("../include")
include_directories("../src")

add_subdirectory(./test_cluster)
add_subdirectory(./test_processor)
add_subdirectory(./test_task)
add_subdirectory(./test_queue)