#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <queuep/queuep.h>

TEST_CASE("Queue init") {
    CHECK_NOTHROW(QueueP());
}