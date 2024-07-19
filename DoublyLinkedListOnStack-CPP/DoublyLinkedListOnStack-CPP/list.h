#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    int value;
};

class List2D {
protected:
    Node* initElement;
public:
    List2D() : initElement(nullptr) {};
    List2D(const List2D& list);
    ~List2D();
    void push_front(const int& a);
    void push_back(const int& a);
    int pop_back();
    int pop_front();
    Node* firstElement();
    Node* lastElement();
    friend ostream& operator<<(ostream& os, const List2D& obj);
    string changeOnString();
    int sizeOfList();
    void clear();
};