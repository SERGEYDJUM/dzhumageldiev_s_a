#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <queue/queue.h>

TEST_CASE("Queue init") {
    CHECK_NOTHROW(Queue());
}