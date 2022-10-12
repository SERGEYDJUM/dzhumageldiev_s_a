#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <queuer/queuer.h>
#include <vector>
#include <random>

TEST_CASE("[queuer] - QueueR init") {
    CHECK_NOTHROW(QueueR());
}

TEST_CASE("[queuer] - Pop empty QueueR") {
    QueueR q{};
    CHECK_THROWS_AS(q.top(), std::out_of_range);
}

TEST_CASE("[queuer] - Usual") {
    QueueR q{};
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

TEST_CASE("[queuer] - Stress") {
    QueueR q{};
    std::vector<d_type> v{};
    d_type temp = 0;

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