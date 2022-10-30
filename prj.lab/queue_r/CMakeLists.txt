project(queue_r)

add_library(queue_r queue_r.hpp queue_r.cpp)
add_executable(queue_r_test queue_r_test.cpp)
target_link_libraries(queue_r_test queue_r)
