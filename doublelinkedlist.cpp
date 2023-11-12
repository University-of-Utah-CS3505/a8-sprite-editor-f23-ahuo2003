#include "doublelinkedlist.h"

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void DoubleLinkedList<T>::append(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void DoubleLinkedList<T>::prepend(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void DoubleLinkedList<T>::insertAfter(Node<T>* prevNode, const T& value) {
    if (!prevNode)
        return;

    Node<T>* newNode = new Node<T>(value);
    newNode->prev = prevNode;
    newNode->next = prevNode->next;

    if (prevNode->next)
        prevNode->next->prev = newNode;

    prevNode->next = newNode;

    if (prevNode == tail)
        tail = newNode;
}

template <typename T>
void DoubleLinkedList<T>::remove(Node<T>* node) {
    if (!node)
        return;

    if (node->prev)
        node->prev->next = node->next;
    else
        head = node->next;

    if (node->next)
        node->next->prev = node->prev;
    else
        tail = node->prev;

    delete node;
}
