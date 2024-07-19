#include "stack.h"

using namespace std;

Stack::Stack(const Stack& stack) : List2D() {
    Node* temp = stack.initElement;
    while (temp != nullptr) {
        push_back(temp->value);
        temp = temp->next;
    }
    status = stack.status;
}

Stack::~Stack() {
    Node* nextNode = initElement;
    while (nextNode != nullptr) {
        nextNode = initElement->next;
        delete initElement;
        initElement = nextNode;
    }
}

void Stack::putElement(const int& a) {
    this->push_back(a);
    status = StackStatus::OK;
}
int Stack::removeElement() {
    if (sizeOfList() == 0)
        status = StackStatus::EMPTY;
    return pop_back();
}

string Stack::getStatusCode() {
    switch (status) {
    case StackStatus::EMPTY:
        return "EMPTY";
        break;
    case StackStatus::OK:
        return "OK";
        break;
    }
}

Stack& Stack::operator= (const Stack& stack) {
    Node* nextNode = initElement;
    while (nextNode != nullptr) {
        nextNode = initElement->next;
        delete initElement;
        initElement = nextNode;
    }
    Node* temp = stack.initElement;
    while (temp != nullptr) {
        push_back(temp->value);
        temp = temp->next;
    }
    status = stack.status;
    return *this;
};

ostream& operator<<(ostream& os, Stack& obj) {
    os << obj.changeOnString();
    return os;
}