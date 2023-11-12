#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    void append(const T& value);
    void prepend(const T& value);
    void insertAfter(Node<T>* prevNode, const T& value);
    void remove(Node<T>* node);

    // Add other functions as needed
};

#endif // DOUBLELINKEDLIST_H
