#ifndef SIMPLEDATASTRUCTURES_LIST_NODE_H_
#define SIMPLEDATASTRUCTURES_LIST_NODE_H_

template <class T> struct ListNode {
public:
    T data;
    ListNode * next = nullptr;
};

#endif  // SIMPLEDATASTRUCTURES_LIST_NODE_H_
