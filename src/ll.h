#pragma once
#include <iostream>
#include <vector>

#include "snakebody.h"

namespace snakelinkedlist {

// TODO templatize the list?...
// TODO iterators?...

// Specialied linked list class
class LinkedList {

public:
    LinkedList();                                         // Default constructor
    explicit LinkedList(const std::vector<SnakeBodySegment> &values);  // Initilize from vector

    // Big 5
    LinkedList(const LinkedList& source);                 // Copy constructor
    LinkedList(LinkedList&& source) noexcept;             // Move constructor
    ~LinkedList();                                        // Destructor
    LinkedList& operator=(const LinkedList& source);      // Copy assignment operator
    LinkedList& operator=(LinkedList&& source) noexcept;  // Move assignment operator

    void push_front(SnakeBodySegment value);             // Push value on front
    void push_back(SnakeBodySegment value);              // Push value on back
    SnakeBodySegment front() const;                      // Access the front value
    SnakeBodySegment back() const;                       // Access the back valueW
    void pop_front();                       // remove front element
    void pop_back();                        // remove back element
    int size() const;                       // return number of elements
    std::vector<SnakeBodySegment> GetVector() const;     // return a vector of the values
    bool empty() const;                     // check if empty
    void clear();                           // clear the contents
    void RemoveNth(int n);                  // remove the Nth emement from the front
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
    bool operator==(const LinkedList &rhs) const;
};

bool operator!=(const LinkedList& lhs, const LinkedList &rhs);

} // namespace snakelinkedlist
