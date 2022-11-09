#include <stdexcept>
#include <queue_p/queue_p.hpp>

QueueP::QueueP(const QueueP& other) {
    if (!other.isEmpty()) {
        int next_value = other.head->pri_data;
        head = std::make_unique<Node>(Node(next_value));
        auto this_p = &head;
        auto other_p = &other.head;
        while ((*other_p)->next) {
            next_value = (*other_p)->next->pri_data;
            (*this_p)->next = std::make_unique<Node>(Node(next_value));
            other_p = &((*other_p)->next);
            this_p = &((*this_p)->next);
        }
    }
}

QueueP& QueueP::operator=(const QueueP& other) {
    if (&other == this) return *this;
    *this = std::move(QueueP(other));
    return *this;
}

QueueP& QueueP::operator=(const QueueP&& other) {
    *this = std::move(other);
    return *this;
}

const int QueueP::top() const { 
    if (isEmpty()) throw std::out_of_range("No items in queue");
    return head->pri_data; 
}

bool QueueP::isEmpty() const noexcept { return (head == nullptr); }

void QueueP::pop() noexcept {
    if (!isEmpty()) head = std::move(head->next);
}

void QueueP::push(int data) {
    std::unique_ptr<Node> new_node{ new Node(data) };   
    if (isEmpty() || ((head->pri_data) > data)) {
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