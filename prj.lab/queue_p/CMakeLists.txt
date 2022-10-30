project(queue_p)

add_library(queue_p queue_p.hpp queue_p.cpp)
add_executable(queue_p_test queue_p_test.cpp)
target_link_libraries(queue_p_test queue_p)
