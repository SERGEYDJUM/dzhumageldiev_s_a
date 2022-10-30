#pragma once
#ifndef QueueP_H
#define QueueP_H
#include <memory>

using d_type = int;

class QueueP {
   public:
    QueueP();
    bool isEmpty() const noexcept;
    const d_type top() const;
    void push(d_type);
    void pop() noexcept;
    ~QueueP();

   private:
    struct Node {
        Node(d_type data);
        d_type pri_data;
        std::unique_ptr<Node> next = nullptr;  
        ~Node();  
    };

    std::unique_ptr<Node> head = nullptr;
};

#endif