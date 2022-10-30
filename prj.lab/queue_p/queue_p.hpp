#pragma once
#ifndef QueueP_H
#define QueueP_H
#include <memory>

class QueueP {
   public:
    QueueP() = default;
    bool isEmpty() const noexcept;
    const int top() const;
    void push(int);
    void pop() noexcept;
    ~QueueP() = default;

   private:
    struct Node {
        Node(int data) : pri_data{data} {} 
        ~Node() = default;
        
        std::unique_ptr<Node> next = nullptr;
        int pri_data;
    };

    std::unique_ptr<Node> head = nullptr;
};

#endif