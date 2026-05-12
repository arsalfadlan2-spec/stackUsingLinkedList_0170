#include <iostream>

using namespace std;

//node class representating a single node in the linked list
class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        next = NULL;
    }
};

//Stack class
class stack
{
private:
    Node *top;

public:
   stack()
    {
        top = NULL;
    }
    int push(int value)
    {
        Node *newnode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Push value: " << value << endl;
        return value;