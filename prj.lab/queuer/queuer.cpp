#include <stdexcept>
#include "queuer.h"

QueueR::Node::Node(d_type data, Node* next_node) : pri_data{data}, next{next_node} {}

QueueR::Node::~Node() { delete next; }

QueueR::QueueR() {}
QueueR::~QueueR() { delete head; }

d_type QueueR::peek() const { return head->pri_data; }

bool QueueR::is_empty() const { return (head == nullptr); }

d_type QueueR::pop() {
    if (is_empty()) throw std::out_of_range("Nothing to pop");

    d_type temp_data = head->pri_data;
    Node* temp_next = head->next;

    head->next = nullptr;
    delete head;

    head = temp_next;
    return temp_data;
}

void QueueR::insert(d_type data) {
    Node* new_node = new Node(data);
    if (is_empty() || head->pri_data > data) {
        new_node->next = head;
        head = new_node;
    } else {
        Node* temp = head;
        while ((temp->next != nullptr) && (temp->next->pri_data < data)) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}