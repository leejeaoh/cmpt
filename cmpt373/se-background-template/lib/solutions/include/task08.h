// ID 9c8e9a75094246cdd2d9884e896a9b8d
#pragma once

#include "Support.h"
#include <memory>

class OrderedList {
public:
    class Node { //nested Node class
    public:
        Node(int value); //constructor for initializing node with value

        // methods needed
        int getValue() const;
        Node* getNext() const;
        void remove();  // removes this node
        void setNext(Node* nextNode);

    private: 
        int value;
        Node* next;
        OrderedList* parentList; //pointer to the parent list

        friend class OrderedList;
    };

    OrderedList(); //constructor
    ~OrderedList(); //destructor
    Node* add(int value); //adds a node to the list
    Node* getNode(int value); //gets the node with a specific value
    void remove(int value); //removes the node with the given value

private:
    Node* head;
};
