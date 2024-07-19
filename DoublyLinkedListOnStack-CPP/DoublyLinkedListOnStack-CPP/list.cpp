#include "list.h"

using namespace std;

List2D::List2D(const List2D& list) {
    initElement = nullptr;
    Node* temp = list.initElement;
    while (temp != nullptr) {
        push_back(temp->value);
        temp = temp->next;
    }
}

List2D::~List2D() {
    Node* nextNode = initElement;
    while (nextNode != nullptr) {
        nextNode = initElement->next;
        delete initElement;
        initElement = nextNode;
    }
}

void List2D::push_front(const int& a) {
    Node* newNode = new Node({ nullptr, initElement, a });
    if (initElement != nullptr)
        initElement->prev = newNode;
    initElement = newNode;
}
void List2D::push_back(const int& a) {
    Node* newNode = new Node({ lastElement(), nullptr, a });
    if (initElement == nullptr)
        initElement = newNode;
    else
        lastElement()->next = newNode;
}

int List2D::pop_back() {
    Node* lastNode = lastElement();
    if (lastNode == nullptr)
        return 0;
    int a = lastNode->value;
    lastNode->prev->next = nullptr;
    delete lastNode;
    return a;
}
int List2D::pop_front() {
    if (initElement == nullptr)
        return 0;
    int a = initElement->value;
    Node* temp = initElement->next;
    temp->prev = nullptr;
    delete initElement;
    initElement = temp;
    return a;
}
int List2D::sizeOfList() {
    if (initElement == nullptr)
        return 0;
    int size = 1;
    Node* nextNode = initElement;
    while (nextNode->next != nullptr) {
        size++;
        nextNode = nextNode->next;
    }
    return size;
}


string List2D::changeOnString() {
    string s = "";
    s += "[ ";
    Node* prevNode = lastElement();
    if (prevNode != nullptr) {
        s += to_string(prevNode->value);
        while (prevNode->prev != NULL) {
            prevNode = prevNode->prev;
            s += " , ";
            s += to_string(prevNode->value);
        }
    }
    s += " ] ";
    return s;
}
void List2D::clear() {
    Node* nextNode = initElement;
    while (nextNode != nullptr) {
        nextNode = initElement->next;
        delete initElement;
        initElement = nextNode;
    }
    initElement = nullptr;
}

Node* List2D::firstElement() {
    return initElement;
}
Node* List2D::lastElement() {
    if (initElement == nullptr)
        return nullptr;
    Node* nextNode = initElement;
    while (nextNode->next != nullptr) {
        nextNode = nextNode->next;
    }
    return nextNode;
}

ostream& operator<<(ostream& os, const List2D& obj) {
    Node* nextNode = obj.initElement;
    if (nextNode != nullptr) {
        os << nextNode->value;
        while (nextNode->next != NULL) {
            nextNode = nextNode->next;
            os << " , " << nextNode->value;
        }
    }
    return os;
}