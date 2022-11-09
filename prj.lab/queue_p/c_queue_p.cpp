#include <queue_p/c_queue_p.h>

#include <queue_p/queue_p.hpp>
#include <stdexcept>
#include <unordered_map>

class Manager {
   public:
    Manager(const Manager&) = delete;
    Manager& operator=(const Manager&) = delete;
    Manager(Manager&&) = delete;
    Manager& operator=(Manager&&) = delete;

    static Manager* get_singleton() {
        if (!_manager) {
            _manager = new Manager();
        }
        return _manager;
    }

    QueueHandler new_queue() noexcept {
        ++top_handle_id;
        QueueHandler handle_id = top_handle_id;
        handles[handle_id] = QueueP();
        return handle_id;
    }

    bool delete_queue(QueueHandler handle_id) noexcept {
        return handles.erase(handle_id) != 0;
    }

    inline void validate_handle_id(QueueHandler handle_id) {
        if (handles.find(handle_id) == handles.end()) throw std::invalid_argument("No such handle");
    }

    QueueHandler copy_queue(QueueHandler from) {
        validate_handle_id(from);
        QueueHandler to = new_queue();
        handles[to] = handles[from];
        return to;
    }

    bool is_empty(QueueHandler handle_id) {
        validate_handle_id(handle_id);
        return handles[handle_id].isEmpty();
    }

    int top_at(QueueHandler handle_id) {
        validate_handle_id(handle_id);
        return handles[handle_id].top();
    }

    void push_to(QueueHandler handle_id, int data) {
        validate_handle_id(handle_id);
        handles[handle_id].push(data);
    }

    void pop_from(QueueHandler handle_id) {
        validate_handle_id(handle_id);
        handles[handle_id].pop();
    }

   private:
    Manager() = default;
    ~Manager() = default;
    static Manager* _manager;
    std::unordered_map<QueueHandler, QueueP> handles;
    QueueHandler top_handle_id = 0;
};

const char* WhatIs(ErrorCode err) {
    switch (err) {
        case kGood:
            return "Ok";
        case kHandlerError:
            return "Invalid handler";
        case kOutOfRange:
            return "Out of range";
        default:
            return "Unknown";
    }
}

ErrorCode CreateQueue(QueueHandler* queue) {
    if (*queue != 0) {
        return kHandlerError;
    }
    *queue = Manager::get_singleton()->new_queue();
    return kGood;
}

ErrorCode DestroyQueue(QueueHandler* queue) {
    if (*queue == 0) {
        return kGood;
    }
    if (!Manager::get_singleton()->delete_queue(*queue)) {
        return kHandlerError;
    }
    *queue = 0;
    return kGood;
}

ErrorCode CloneQueue(QueueHandler source, QueueHandler* queue) {
    if (*queue != 0) {
        return kHandlerError;
    }
    try {
        *queue = Manager::get_singleton()->copy_queue(source);
    } catch (const std::invalid_argument& err) {
        return kHandlerError;
    }
    return kGood;
}

ErrorCode IsEmpty(QueueHandler queue, int32_t* result) {
    if (queue == 0) {
        return kHandlerError;
    }
    try {
        *result = Manager::get_singleton()->is_empty(queue);
    } catch (const std::invalid_argument& err) {
        return kHandlerError;
    }
    return kGood;
}

ErrorCode Top(QueueHandler queue, int32_t* result) {
    if (queue == 0) {
        return kHandlerError;
    }
    try {
        *result = Manager::get_singleton()->top_at(queue);
    } catch(const std::invalid_argument& err) { 
        return kHandlerError;
    } catch(const std::out_of_range& err) {
        return kOutOfRange;
    }
    return kGood;
}

ErrorCode Push(QueueHandler queue, int32_t value) {
    if (queue == 0) {
        return kHandlerError;
    }
    try {
        Manager::get_singleton()->push_to(queue, value);
    } catch (const std::invalid_argument& err) {
        return kHandlerError;
    }
    return kGood;
}

ErrorCode Pop(QueueHandler queue) {
    if (queue == 0) {
        return kHandlerError;
    }
    try {
        Manager::get_singleton()->pop_from(queue);
    } catch (const std::invalid_argument& err) {
        return kHandlerError;
    }
    return kGood;
}