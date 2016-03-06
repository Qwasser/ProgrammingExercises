#include <stdexcept>
#include <vector>

#include "list_node.h"

template <class T> class SimpleStack {
public:
    T pop();
    void push(T object);
    T peek();

    std::vector<T> toVector();

    bool isEmpty() {
        return current_size == 0;
    }

    size_t size() {
        return current_size;
    }

private:
    ListNode<T> * top = nullptr;
    size_t current_size = 0;
};

template <class T> T SimpleStack<T>::pop() {
    if (!top) {
        throw std::out_of_range("Pop on empty stack");
    }

    ListNode<T> * old_top = top;
    top = top->next;
    current_size--;

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

template <class T> void SimpleStack<T>::push(T item) {
    ListNode<T> * new_node = new ListNode<T>;
    new_node->next = top;
    new_node->data = item;
    top = new_node;
    current_size++;
}

template <class T> T SimpleStack<T>::peek() {
    if(top) {
        return top->data;
    }
    else {
        throw std::out_of_range("Peek on empty stack");
    }
}

template <class T> std::vector<T> SimpleStack<T>::toVector() {
    std::vector<T> result;
    result.reserve(current_size);

    ListNode<T> * node = top;
    while(node) {
        result.push_back(node->data);
        node = node->next;
    }
    return result;
}
