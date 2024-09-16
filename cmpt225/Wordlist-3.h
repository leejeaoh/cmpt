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

/*
    citation 
    
    The AVL tree implementation is inspired by geeksforgeeks
    Reference URL : https://www.geeksforgeeks.org/insertion-in-an-avl-tree/
    Note : the implementation has been adapted and modified to fit the assignment requirement

*/

//
// Do not use any other #includes
//
#include "Wordlist_base.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//
// IMPORTANT: no global variables are permitted in this file!
//
// It is okay to define helper functions defined outside the class.
//

class Wordlist : public Wordlist_base
{
    //
    // Use this Node to implement an AVL tree for the word list. You can *add*
    // extra variables/methods/features to this struct if you like, but you must
    // keep its name the same, and also keep the word, count, left, and right
    // variables as defined.
    //
private:
    struct Node
    {   
        int height; //height of the node for AVL balancing 
        string word;
        int count;
        Node *left;
        Node *right;
    };

    Node *root = nullptr;

    //creating new node with given string word
    Node* newNode(string word) {
        Node* node = new Node();
        node->word = word;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        node->count = 1;
        return node;
    }

    //returns height of the node
    int height(Node *N) const {
        if (N == nullptr) {
            return 0;
        }
        return N->height;
    }

    //finding and getting the balance factor of a node
    int getBalance(Node *N) {
        if(N == NULL) {
            return 0;
        }
        return height(N->left) - height(N->right);
    }

    //inserting word into avl tree
    Node* insert(Node* node, string word) {
        //performing normal BST insertion
        if(node == NULL) {
            return (newNode(word)); 
        }
        if(word < node->word) {
            node->left = insert(node->left, word);
        } else if (word > node->word) {
            node->right = insert(node->right, word);
        } else {
            //duplicate word found
            node->count++; //increment count
            return node;
        }

        //update height
        node->height = 1 + max(height(node->left), height(node->right));

        //getting balance factor of the node
        int balance = getBalance(node);

        //if the node is not balanced use rotation 
        // left left 
        if(balance > 1 && word < node->left->word) {
            return rightRotate(node);
        }

        // right right
        if(balance < -1 && word > node->right->word) {
            return leftRotate(node);
        }

        //left right
        if(balance > 1 && word > node->left->word) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        //right left
        if(balance < -1 && word < node->right->word) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        //performing rotation
        x->right = y;
        y->left = T2;

        //updating heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        //returning new root
        return x;
    }

    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        //performing rotation
        y->left = x;
        x->right = T2;

        //updating height
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        //return new root
        return y;
    }
public:
    //
    // IMPORTANT: root is the only variable that can be defined in this class.
    // It should point to the top node of your AVL tree. When root == nullptr,
    // the tree is empty.
    //
    // No variables other than root are permitted!
    //
    int get_count(const string &w) const override {
        Node *curr = root;
        while(curr != nullptr) {
            if(w < curr->word) {
                curr = curr->left;
            } else if(w > curr->word) {
                curr = curr->right;
            } else {
                return curr->count; //returns count if word found
            }
        }
        return 0;//when word not found
    }

    //helper : counts number of nodes in the tree
    int countNodes(Node *node) const {
        if (node == nullptr) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int num_different_words() const override {
        return countNodes(root);
    }

    //helper : counts number of words in the tree
    int countTotalWords(Node* node) const {
        if (node == nullptr) return 0;
        return node->count + countTotalWords(node->left) + countTotalWords(node->right);
    }

    int total_words() const override {
        return countTotalWords(root);
    }

    void findMostFrequent(Node* node, string &word, int &maxCount) const {
        if (node != nullptr) {
            findMostFrequent(node->left, word, maxCount);
            if (node->count > maxCount) {
                maxCount = node->count;
                word = node->word;
            }
            findMostFrequent(node->right, word, maxCount);
        }
    }

    string most_frequent() const override {
        string word = "";
        int maxCount = 0;
        findMostFrequent(root, word, maxCount);
        return word + " " + to_string(maxCount);
    }

    int countSingletons(Node* node) const {
        if (node == nullptr) return 0;
        int count = (node->count == 1) ? 1 : 0;
        return count + countSingletons(node->left) + countSingletons(node->right);
    }

    int num_singletons() const override {
        return countSingletons(root);
    }

    void inOrderPrint(Node* node, int& count) const {
        if (node != nullptr) {
            inOrderPrint(node->left, count);
            cout << count << ". {\"" << node->word << "\", " << node->count << "}" << endl;
            count++;
            inOrderPrint(node->right, count);
        }
    }

    void print_words() const override {
        int count = 1;
        inOrderPrint(root, count);
    }

    bool is_sorted() const override {
        return true;
    }


    void add_word(const string &w) override {
        root = insert(root,w);
    }

    //constructor - initialize empty word list
    Wordlist() : root(nullptr) {}
    //constructor - reads words from a file into the word list
    Wordlist(const string &filename) : root(nullptr) {
        ifstream file(filename);
        string word;
        if (!file) {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }
        while (file >> word) {
            add_word(word);
        }
    }
    //destructor - deallocates all node in the tree
    ~Wordlist() {
        destroyTree(root);
    }

    //helper : destroy tree
    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }


}; // class Wordlist

//
// Make sure to thoroughly test your code as you go!
//
