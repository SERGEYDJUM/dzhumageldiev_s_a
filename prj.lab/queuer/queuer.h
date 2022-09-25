#pragma once
#ifndef QueueR_H
#define QueueR_H

using d_type = int;

class QueueR {
   public:
    QueueR();
    bool is_empty() const;
    d_type peek() const;
    void insert(d_type);
    d_type pop();
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