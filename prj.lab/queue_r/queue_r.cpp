#include <stdexcept>
#include <queue_r/queue_r.hpp>

QueueR::Node::Node(d_type data, Node* next_node) : pri_data{data}, next{next_node} {}
QueueR::Node::~Node() { delete next; }

QueueR::QueueR() {}
QueueR::~QueueR() { delete head; }

const d_type QueueR::top() const { 
    if (isEmpty()) throw std::out_of_range("Nothing to pop");
    return head->pri_data; 
}

bool QueueR::isEmpty() const noexcept { return (head == nullptr); }

void QueueR::pop() noexcept {
    if (!isEmpty()) {
        d_type temp_data = head->pri_data;
        Node* temp_next = head->next;

        head->next = nullptr;
        delete head;

        head = temp_next;
    }
}

void QueueR::push(d_type data) {
    Node* new_node = new Node(data);
    if (isEmpty() || head->pri_data > data) {
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