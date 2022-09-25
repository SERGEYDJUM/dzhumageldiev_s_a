project(queuer)

add_library(queuer queuer.h queuer.cpp)
add_executable(queuer_test queuer_test.cpp)
target_link_libraries(queuer_test queuer)
