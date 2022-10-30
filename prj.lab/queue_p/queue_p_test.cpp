#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <queue_p/queue_p.hpp>
#include <vector>
#include <random>

TEST_CASE("[queuep] - QueueR init") {
    CHECK_NOTHROW(QueueP());
}

TEST_CASE("[queuep] - Top empty QueueP") {
    QueueP q{};
    CHECK_THROWS_AS(q.top(), std::out_of_range);
}

TEST_CASE("[queuep] - Usual") {
    QueueP q{};
    q.push(10);
    q.push(5);
    q.push(10);
    q.push(11);
    q.push(10);
    q.push(-1);

    CHECK_EQ(q.top(), -1);
    q.pop();
    CHECK_EQ(q.top(), 5);
    q.pop();
    CHECK_EQ(q.top(), 10);
    q.pop();
    CHECK_EQ(q.top(), 10);
    q.pop();
    CHECK_EQ(q.top(), 10);
    q.pop();
    CHECK_EQ(q.top(), 11);
    
}

TEST_CASE("[queuep] - Simulate") {
    QueueP q{};
    std::vector<int> v{};
    int temp = 0;

    for (size_t i = 0; i < 10000; i++)
    {
        temp = rand();
        v.push_back(temp);
        q.push(temp);
    }
    std::sort(v.begin(), v.end());
    for (auto el : v)
    {
        CHECK_EQ(q.top(), el);
        q.pop();
    }
    CHECK_THROWS(q.top());
}