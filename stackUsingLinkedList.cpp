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

    // pop operation: Remove the topmost element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        // Menampilkan data yang baru saja menjadi top setelah pop
        // Catatan: Logika pada gambar menunjukkan top->data, bukan temp->data
        cout << "Popped value: " << top->data << endl; 
        delete temp;
    }

    // peek/top operation: Retrive the value of the topset element witchout removing
    void peek() {
        if (top == NULL) {
            cout << "List is empty." << endl;
        } else {
            Node *current = top;
            while (current != NULL) {
                cout << current->data << " " << endl;
                current = current->next;
            }
        }
    }

    // isEmpty operation: check of the stack is empty
    bool isEmpty() {
        return top == NULL; // Return true if the top pointer is null
    }
};
