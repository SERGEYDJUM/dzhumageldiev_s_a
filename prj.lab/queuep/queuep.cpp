#include <stdexcept>
#include "queuep.h"

QueueP::Node::Node(d_type data) : pri_data{data} {}
QueueP::Node::~Node() {}

QueueP::QueueP() {}
QueueP::~QueueP() {}

d_type QueueP::peek() const { return head->pri_data; }

bool QueueP::is_empty() const { return (head == nullptr); }

d_type QueueP::pop() {
    if (is_empty()) throw std::out_of_range("Nothing to pop");
    d_type popped_data = head->pri_data;
    head = std::move(head->next);
    return popped_data;
}

void QueueP::insert(d_type data) {
    std::unique_ptr<Node> new_node{ new Node(data) };
    if (is_empty() || ((head->pri_data) > data)) {
        (new_node->next) = std::move(head);
        head = std::move(new_node);
    } else {
        auto temp = &head;
        while ((((*temp)->next) != nullptr) && (((*temp)->next->pri_data) < data))
            temp = &((*temp)->next);
        (new_node->next) = std::move((*temp)->next);
        ((*temp)->next) = std::move(new_node);
    }
}