// ID 9c8e9a75094246cdd2d9884e896a9b8d

#include "task08.h"

OrderedList::OrderedList() : head(nullptr) {}

OrderedList::~OrderedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}

OrderedList::Node::Node(int value) : value(value), next(nullptr), parentList(nullptr) {}

int OrderedList::Node::getValue() const {
    return value;
}

OrderedList::Node* OrderedList::Node::getNext() const {
    return next;
}

void OrderedList::Node::setNext(Node* nextNode) {
    next = nextNode;
}

void OrderedList::Node::remove() {
    if (parentList != nullptr) {
        parentList->remove(value);
    }
}

OrderedList::Node* OrderedList::add(int value) {
    Node* newNode = new Node(value);
    newNode->parentList = this; 

    if (head == nullptr || head->getValue() > value) {
        newNode->setNext(head);
        head = newNode;
        return newNode;
    }

    Node* curr = head;
    while (curr->getNext() != nullptr && curr->getNext()->getValue() < value) {
        curr = curr->getNext();
    }

    newNode->setNext(curr->getNext());
    curr->setNext(newNode);

    return newNode;
}

OrderedList::Node* OrderedList::getNode(int value) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->getValue() == value) {
            return curr; 
        }
        curr = curr->getNext();
    }
    return nullptr;
}

void OrderedList::remove(int value) {
    if (head == nullptr) {
        return;
    }

    if (head->getValue() == value) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
        return;
    }

    Node* curr = head;
    while (curr->getNext() != nullptr && curr->getNext()->getValue() != value) {
        curr = curr->getNext();
    }

    if (curr->getNext() != nullptr) {
        Node* temp = curr->getNext();
        curr->setNext(curr->getNext()->getNext());
        delete temp;
    }
}
