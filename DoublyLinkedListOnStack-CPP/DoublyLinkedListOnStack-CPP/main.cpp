#include <iostream>
#include <string>
#include "stack.h"

using namespace std;


int main() {
    Stack test;
    cout << "Stack: " << test << ", length: " << test.size() << ", Status Code: " << test.getStatusCode() << endl;
    test.putElement(423);
    test.putElement(424);
    test.putElement(425);
    cout << "Stack: " << test << ", length: " << test.size() << ", Status Code: " << test.getStatusCode() << endl;
    test.removeElement();
    cout << "Stack after removing the element: " << test << ", length: " << test.size() << ", Status Code: " << test.getStatusCode() << endl;
    Stack copyStack(test);
    cout << "Copied Stack with copying constructor: " << copyStack << ", length: " << copyStack.size() << ", Status Code: " << copyStack.getStatusCode() << endl;
    Stack test2;
    test2.putElement(444);
    test2.putElement(445);
    test2.putElement(446);
    copyStack = test2;
    cout << "Stack after assignment operator: " << copyStack << ", length: " << copyStack.size() << ", Status Code: " << copyStack.getStatusCode() << endl;
}