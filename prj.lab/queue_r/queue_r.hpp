#pragma once
#ifndef QueueR_H
#define QueueR_H

using d_type = int;

class QueueR {
   public:
    QueueR();
    bool isEmpty() const noexcept;
    const d_type top() const;
    void push(d_type);
    void pop() noexcept;
    ~QueueR();

   private:
    struct Node {
        Node(d_type data, Node* next_node = nullptr);
        d_type pri_data;
        Node *next = nullptr;  
        ~Node();  
    };

    Node *head = nullptr;
};

#endif