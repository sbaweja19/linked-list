// intlist.cpp
// Implements class IntList
// Sanil Baweja, 10/17/19

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) : first(0) {
    Node* n = source.first;
    while (n) {
        append(n->info);
        n = n->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    Node* n = first;
    while(n != 0){
        Node* next = n->next;
        delete n;
        n = next;
    }
    
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* n = first;
    while(n) {
        sum += n->info;
        n = n->next;
    }
    return sum; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    bool contains = false;
    Node* n = first;
    while (n) {
        if (n->info == value)
        {
            contains = true;
            break;
        }
        else
            n = n->next;

    }
    return contains; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* n = first;
    if (first == 0)
        return 0;
    int max = first->info;
    while (n){
        if (n->info > max)
            max = n->info;
        n = n->next;
    }
    return max; 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (first == 0)
        return 0;
    double s = sum(), c = count();
    return s/c;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node* p = new Node;
        p->info = value;
        p->next = first;
        first = p;
    }
    // IMPLEMENT
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source) {
    //IMPLEMENT
    if (&source != this){
        //this->~IntList();
        //this->IntList(source);
        Node* n = first;
        while(n != 0){
            Node* next = n->next;
            delete n;
            n = next;
        }
        first =0;
        if (source.first != 0){
            first = new Node;
            first -> info = source.first -> info;
            n = source.first -> next;
            while (n) {
                append(n->info);
                n = n->next;
            }
        }
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
