#ifndef SIMPLEDATASTRUCTURES_SIMPLE_STACK_H_
#define SIMPLEDATASTRUCTURES_SIMPLE_STACK_H_

#include <stdexcept>
#include <vector>

#include "list_node.h"

template <class T> class SimpleStack {
public:
    T Pop();
    void Push(T object);
    T Peek();

    std::vector<T> ToVector();

    bool is_empty() {
        return current_size_ == 0;
    }

    size_t size() {
        return current_size_;
    }

private:
    ListNode<T> * top_ = nullptr;
    size_t current_size_ = 0;
};

template <class T> T SimpleStack<T>::Pop() {
    if (!top_) {
        throw std::out_of_range("Pop on empty stack");
    }

    ListNode<T> * old_top = top_;
    top_ = top_->next;
    current_size_--;

    try {
        T item = old_top->data;
        delete old_top;
        return item;
    }
    catch (...) {
        delete old_top;
        throw;
    }
}

template <class T> void SimpleStack<T>::Push(T item) {
    ListNode<T> * new_node = new ListNode<T>;
    new_node->next = top_;
    new_node->data = item;
    top_ = new_node;
    current_size_++;
}

template <class T> T SimpleStack<T>::Peek() {
    if(top_) {
        return top_->data;
    }
    else {
        throw std::out_of_range("Peek on empty stack");
    }
}

template <class T> std::vector<T> SimpleStack<T>::ToVector() {
    std::vector<T> result;
    result.reserve(current_size_);

    ListNode<T> * node = top_;
    while(node) {
        result.push_back(node->data);
        node = node->next;
    }
    return result;
}

#endif  // SIMPLEDATASTRUCTURES_SIMPLE_STACK_H_
