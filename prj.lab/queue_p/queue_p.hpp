#pragma once
#ifndef QueueP_H
#define QueueP_H
#include <memory>

class QueueP {
   public:
    QueueP() = default;
    QueueP(const QueueP& other);
    QueueP& operator=(const QueueP& other);
    QueueP& operator=(const QueueP&& other);
    bool isEmpty() const noexcept;
    const int top() const;
    void push(int);
    void pop() noexcept;
    ~QueueP() = default;

   private:
    struct Node {
        Node(int data) : pri_data{data} {} 
        Node(const Node&) = delete;
        Node(Node&&) = default;
        Node& operator=(const Node&) = delete;
        Node& operator=(Node&&) = default;
        ~Node() = default;

        std::unique_ptr<Node> next{nullptr};
        int pri_data{0};
    };

    std::unique_ptr<Node> head = nullptr;
};

#endif