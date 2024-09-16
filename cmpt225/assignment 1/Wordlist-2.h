// Wordlist.h

#pragma once

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
// Do not use any other #includes
//
#include "Wordlist_base.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Wordlist : public Wordlist_base
{
    //
    // Use this Node to implement the doubly-linked list for the word list.
    // Don't change the Node struct in any way!
    //
private:
    struct Node
    {
        string word;
        Node *next;
        Node *prev;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    bool frozen = false;
    int size = 0;

    //helper function that allows to find word position and returns
    Node *findPosition(const string &s) const {
        for(Node *curr = head; curr != nullptr; curr = curr->next) {
            if(curr->word == s) {
                return curr;
            }
        }
        return nullptr;
    }
public:
    //
    // ... your code goes here ...
    //
    ~Wordlist() {
        while (head) {
            Node *next = head->next;
            delete head;
            head = next;
        }
    }

    bool is_frozen() const {
        return frozen;
    }
    //using the helper function to find the position
    //since helper function returns nullptr if the word does not exist
    //it returns true if it contains if not it returns false
    bool contains(const string &w) const {
        return findPosition(w) != nullptr;
    }

    //size increment each time the word is added from add_word
    int length() const {
        return size;
    }

    string get_word(int index) const {
        //throwing index out of bound if the index is greater than size of the list
        //or the user types less than 0
        if( index < 0 || index >= size ) {
            throw out_of_range("Index is out of bounds !");
        }
        Node *curr = head;
        for( int i = 0; i < index; i++ ) {
            curr = curr->next;
        }
        return curr->word;
    }

    void add_word(const string &w) {
        //checks if the list is frozen or if it already contains the word
        //if exit the function
        if(frozen || contains(w)) return;
        else {
            //creating new node with word being added
            Node *n = new Node{w,nullptr,tail};
            //if the list is empty, setting the new node to the head
            if(!head){
                head = n;
            //else link the new node to the last node
            } else { 
                tail->next = n;
            }
            //then the new node becomes the new tail
            tail = n; 
            //adding to the size since the word has been added
            ++size;
        }
    }

    void remove_word(const string &w) {
        //checking if the list is frozen else exit function
        if(frozen) return;
        //locate the word using findPosition helper function
        Node *removeThis = findPosition(w);
        //If the node been found do
        if(removeThis) {
            //checking if the node that needs to be deleted is not first node
            if(removeThis->prev) {
                removeThis->prev->next = removeThis->next;
            } else {
                head = removeThis->next;
            }
            //checking if the node that needs to be deleted is not last node
            if(removeThis->next) {
                removeThis->next->prev = removeThis->prev;
            } else {
                tail = removeThis->prev;
            }
            //remove if it checks all out
            delete removeThis;
            //decrement size since word is being removed from the list
            --size;
        }
    }

    vector<string *> get_sorted_index() {
        //checking if the list is not frozen
        if(!frozen) {
            //make the list fronze set to true
            frozen = true;
            vector<string*> words;

            //store the address of each word into vector 
            Node *curr = head;
            while(curr) {
                words.push_back(&curr->word);
                curr = curr->next;
            }
            //sorting the vector of pointers based on strings they point
            sort(words.begin(), words.end(), [](string *a, string *b) -> bool {
                return *a < *b;
            });
            return words;
        }
        return {};
    }


    //
    // ... you can write helper methods if you need them ...
    //

}; // class Wordlist

//
// ... you can write helper functions here (or before Wordlist) if you need them
// ...
//