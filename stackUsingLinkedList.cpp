#include <iostream>

using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
    int data;
    Node *next;

    Node() {
        next = NULL;
    }
};

// Stack class
class stack {
private:
    Node *top; // pointer to the top node of the stack

public:
    stack() {
        top = NULL;
    }

    int push(int value) {
        Node *newnode = new Node();
        newnode->data = value;
        newnode->next = top;
        top = newnode;
        cout << "Push value: " << value << endl;
        return value;
    }
