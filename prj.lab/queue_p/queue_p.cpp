#include <stdexcept>
#include <queue_p/queue_p.hpp>

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