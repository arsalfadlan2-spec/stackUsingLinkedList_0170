#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        next = NULL;
    }
};

class Stack { // Menggunakan huruf kapital 'S' untuk membedakan dengan objek
private:
    Node *top;

public:
    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Push value: " << value << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node *temp = top;
        int poppedValue = temp->data;
        top = top->next;
        
        cout << "Popped value: " << poppedValue << endl;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            Node *current = top;
            cout << "Current Stack: ";
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    bool isEmpty() {
        return top == NULL; 
    }
};

int main() {
    Stack myStack;
    int choice = 0;
    int value;

    while (choice != 4) {
        cout << "--- Menu Stack ---" << endl;
        cout << "1. Push\n2. Pop\n3. Peek/Display\n4. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) { // Validasi jika input bukan angka
            cin.clear();
            while (cin.get() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                myStack.push(value);
                break;
            case 2:
                myStack.pop();
                break;
            case 3:
                myStack.peek();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
        cout << endl;
    }
    return 0;
}