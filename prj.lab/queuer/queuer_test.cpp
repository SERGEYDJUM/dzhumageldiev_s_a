#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <queuer/queuer.h>

TEST_CASE("[queuer] - QueueR init") {
    CHECK_NOTHROW(QueueR());
}

TEST_CASE("[queuer] - Pop empty QueueR") {
    QueueR q{};
    CHECK_THROWS_AS(q.pop(), std::out_of_range);
}

TEST_CASE("[queuer] - Usual work") {
    QueueR q{};
    q.insert(10);
    q.insert(5);
    q.insert(10);
    q.insert(11);
    q.insert(10);
    q.insert(-1);

    CHECK_EQ(q.pop(), -1);
    CHECK_EQ(q.pop(), 5);
    CHECK_EQ(q.pop(), 10);
    CHECK_EQ(q.pop(), 10);
    CHECK_EQ(q.pop(), 10);
    CHECK_EQ(q.pop(), 11);
    CHECK_THROWS(q.pop());
}