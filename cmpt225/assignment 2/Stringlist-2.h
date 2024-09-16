// Stringlist.h
/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Jea Oh Lee
// St.# : 301351043
// Email: jeaohl@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

//
// Do not use any other #includes or #pragmas in this file.
//

#pragma once

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

//enum used to store types of operations for undo method
enum OperationType {
    INSERT_BEFORE,
    REMOVE_AT,
    SET,
    ASSIGN,
    REMOVE_ALL
};

//struct to hold information for stack
struct StringStackNode{
    OperationType type;
    string value;
    int index;
    int size;
    StringStackNode *next;
};

class StringStack{
private:
    //top of the stack
    StringStackNode *head = nullptr;

public:
    //constructor
    StringStack() = default;

    //destructor
    ~StringStack() {
        while (!is_empty()) {
            StringStackNode* node = pop();
            delete node;
        }
    }
    //pop method in the stack to remove top node
    StringStackNode* pop(){ 
        assert(!is_empty()); //check if the stack is empty
        StringStackNode *p = head;
        head = head->next;
        return p;
    }
    //push method which addes new node to the stack
    void push(OperationType type,const string &s, int idx, int size){
        //cout << "size of " << size << endl;
        StringStackNode *n = new StringStackNode{type,s,idx,size,head};
        head = n;
    }

    //checking if the stack is empty
    bool is_empty(){
        return head == nullptr;
    }
};//class StringStack



class Stringlist{
private:
    //stack for undo
    StringStack undoStack;
    int cap;     // capacity
    string *arr; // array of strings
    int sz;      // size

    //
    // Helper function for throwing out_of_range exceptions.
    //
    void bounds_error(const string &s) const
    {
        throw out_of_range("Stringlist::" + s + " index out of bounds");
    }

    //
    // Helper function for checking index bounds.
    //
    void check_bounds(const string &s, int i) const
    {
        if (i < 0 || i >= sz)
        {
            bounds_error(s);
        }
    }

    //
    // Helper function for copying another array of strings.
    //
    void copy(const string *other)
    {
        for (int i = 0; i < sz; i++)
        {
            arr[i] = other[i];
        }
    }

    //
    // Helper function for checking capacity; doubles size of the underlying
    // array if necessary.
    //
    void check_capacity()
    {
        if (sz == cap)
        {
            cap *= 2;
            string *temp = new string[cap];
            for (int i = 0; i < sz; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
    }

public:
    //
    // Default constructor: makes an empty StringList.
    //
    Stringlist()
        : cap(10), arr(new string[cap]), sz(0)
    {
    }

    //
    // Copy constructor: makes a copy of the given StringList.
    //
    // Does *not* copy the undo stack, or any undo information from other.
    //
    Stringlist(const Stringlist &other)
        : cap(other.cap), arr(new string[cap]), sz(other.sz)
    {
        copy(other.arr);
    }

    //
    // destructor
    //
    ~Stringlist()
    {
        delete[] arr;
    }

    //
    // Assignment operator: makes a copy of the given StringList.
    //
    // undoable
    //
    // For undoing, when assigning different lists, the undo stack is NOT
    // copied:
    //
    //    lst1 = lst2; // lst1 undo stack is updated to be able to undo the
    //                 // assignment; lst1 does not copy lst2's stack
    //                 //
    //                 // lst2 is not change in any way
    //
    // Self-assignment is when you assign a list to itself:
    //
    //    lst1 = lst1;
    //
    // In this case, nothing happens to lst1. Both its string data and undo
    // stack are left as-is.
    //
    Stringlist &operator=(const Stringlist &other)
    {   
    if (this != &other)
    {
        //reverse push
        for (int i = sz - 1; i >= 0; i--) {
            undoStack.push(ASSIGN, arr[i], i, sz);
        }

        delete[] arr;
        cap = other.capacity();
        arr = new string[cap];
        sz = other.size();
        copy(other.arr);
    }
    return *this;
    }


    //
    // Returns the number of strings in the list.
    //
    int size() const { return sz; }

    //
    // Returns true if the list is empty, false otherwise.
    //
    bool empty() const { return size() == 0; }

    //
    // Returns the capacity of the list, i.e. the size of the underlying array.
    //
    int capacity() const { return cap; }

    //
    // Returns the string at the given index.
    //
    string get(int index) const
    {
        check_bounds("get", index);
        return arr[index];
    }

    //
    // Returns the index of the first occurrence of s in the list, or -1 if s is
    // not in the lst.
    //
    int index_of(const string &s) const
    {
        for (int i = 0; i < sz; i++)
        {
            if (arr[i] == s)
            {
                return i;
            }
        }
        return -1;
    }

    //
    // Returns true if s is in the list, false otherwise.
    //
    bool contains(const string &s) const
    {
        return index_of(s) != -1;
    }

    //
    // Returns a string representation of the list.
    //
    string to_string() const
    {
        string result = "{";
        for (int i = 0; i < size(); i++)
        {
            if (i > 0)
            {
                result += ", ";
            }
            result += "\"" + get(i) + "\"";
        }
        return result + "}";
    }

    //
    // Sets the string at the given index.
    //
    // undoable
    //
    void set(int index, string value)
    {
        check_bounds("set", index);
        undoStack.push(SET, arr[index], index, sz);
        arr[index] = value;
    }

    //
    // Insert s before index; if necessary, the capacity of the underlying array
    // is doubled.
    //
    // undoable
    //
    void insert_before(int index, const string &s,bool undo = false)
    {
        if (index < 0 || index > sz)
        { // allows insert at end, i == sz
            bounds_error("insert_before");
        }
        check_capacity();
        //pushing information undo stack
        if(undo == false){
            undoStack.push(INSERT_BEFORE,s,index, sz);
        }
        for (int i = sz; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = s;
        sz++;
    }

    //
    // Appends s to the end of the list; if necessary, the capacity of the
    // underlying array is doubled.
    //
    // undoable
    //
    void insert_back(const string &s)
    { 
        insert_before(size(), s);
    }

    //
    // Inserts s at the front of the list; if necessary, the capacity of the
    // underlying array is doubled.
    //
    // undoable
    //
    void insert_front(const string &s)
    {
        insert_before(0, s);
    }

    //
    // Removes the string at the given index; doesn't change the capacity.
    //
    // undoable
    //
    void remove_at(int index,bool undo = false)
    {
        check_bounds("remove_at", index);
        //pushing information for undo stack
        if(undo == false){
            undoStack.push(REMOVE_AT,arr[index],index, sz);
        }
        for (int i = index; i < sz - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        sz--;
    }

    //
    // Removes all strings from the list; doesn't change the capacity.
    //
    // undoable
    //
    void remove_all()
    {
        undoStack.push(REMOVE_ALL, "", 0, sz);
        for (int i = 0; i < sz; ++i) {
            arr[i].~string();  //call the destructor for each string.
        }
        sz = 0;
    }
    //
    // Removes the first occurrence of s in the list, and returns true. If s is
    // nowhere in the list, nothing is removed and false is returned.
    //
    // undoable
    //
    bool remove_first(const string &s)
    {
        int index = index_of(s);
        if (index == -1)
        {
            return false;
        }
        remove_at(index);
        return true;
    }

    //
    // Undoes the last operation that modified the list. Returns true if a
    // change was undone.
    //
    // If there is nothing to undo, does nothing and returns false.
    //
    bool undo()
    {
        if(undoStack.is_empty()) {
            return false;
        }
        //pop the top of the stack 
        StringStackNode* node = undoStack.pop();

        //switch statement with operation type stored in the stack
        switch(node->type) {
            case INSERT_BEFORE:
                remove_at(node->index,true); //remove the element that was inserted
                break;
            case SET:
                arr[node->index] = node->value; //set element at index to previous value
                break;
            case REMOVE_AT:
                //true flag allows track undo
                //when true dont push into the stack
                insert_before(node->index, node->value,true);
                break;
            case ASSIGN:
                sz = node->size; //reset the size to its previous state
                for(int i = 0; i < node->size; i++) { //loop to store strings to stack
                    StringStackNode *assignNode = undoStack.pop(); 
                    //getting the previous value of each string
                    arr[assignNode->index] = assignNode->value;
                    delete assignNode; //free memeory
                }
                // initialize remaining elements to empty
                for (int i = sz; i < cap; i++) {
                    arr[i] = "";
                }
                break;
            case REMOVE_ALL:
                //size set
                sz = node->size; //reset the size to its original
                for(int i = 0; i < node->size; i++) {
                    StringStackNode *assignNode = undoStack.pop();
                    arr[assignNode->index] = assignNode->value; //restore with previous value
                    delete assignNode; //free memeory
                }
                break;
        }//
        delete node;
        return true;
    }

}; // class Stringlist

//
// Prints list to in the format {"a", "b", "c"}.
//
ostream &operator<<(ostream &os, const Stringlist &lst)
{
    return os << lst.to_string();
}

//
// Returns true if the two lists are equal, false otherwise.
//
// Does *not* consider any undo information when comparing two Stringlists. All
// that matters is that they have the same strings in the same order.
//
bool operator==(const Stringlist &a, const Stringlist &b)
{
    if (a.size() != b.size())
    {
        return false;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a.get(i) != b.get(i))
        {
            return false;
        }
    }
    return true;
}

//
// Returns true if the two lists are not equal, false otherwise.
//
// Does *not* consider any undo information when comparing two Stringlists.
//
bool operator!=(const Stringlist &a, const Stringlist &b)
{
    return !(a == b);
}
