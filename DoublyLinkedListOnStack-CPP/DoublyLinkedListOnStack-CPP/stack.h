#pragma once

#include <string>
#include <iostream>
#include "list.h"

using namespace std;

enum class StackStatus { EMPTY = 0, OK = 1 };

class Stack : public List2D {
private:
    StackStatus status = StackStatus::EMPTY;

public:
    Stack() : List2D() {};
    Stack(const Stack& Stack);
    ~Stack();
    void putElement(const int& a);
    int removeElement();
    string getStatusCode();
    friend ostream& operator<<(ostream& os, Stack& obj);
    inline int size() { return sizeOfList(); }
    friend ostream& operator<<(ostream& os, Stack& obj);
    Stack& operator= (const Stack& Stack);
};