#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <queuep/queuep.h>
#include <vector>
#include <random>

TEST_CASE("[queuep] - QueueR init") {
    CHECK_NOTHROW(QueueP());
}

TEST_CASE("[queuep] - Pop empty QueueP") {
    QueueP q{};
    CHECK_THROWS_AS(q.pop(), std::out_of_range);
}

TEST_CASE("[queuep] - Usual") {
    QueueP q{};
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
    
}

TEST_CASE("[queuep] - Simulate") {
    QueueP q{};
    std::vector<d_type> v{};
    d_type temp = 0;

    for (size_t i = 0; i < 10000; i++)
    {
        temp = rand();
        v.push_back(temp);
        q.insert(temp);
    }
    std::sort(v.begin(), v.end());
    for (auto el : v)
    {
        CHECK_EQ(q.pop(), el);
    }
    CHECK_THROWS(q.pop());
}