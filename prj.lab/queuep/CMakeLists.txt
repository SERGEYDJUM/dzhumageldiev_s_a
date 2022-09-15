project(queuep)

add_library(queuep queuep.h queuep.cpp)
add_executable(queuep_test queuep_test.cpp)
target_link_libraries(queuep_test queuep)
