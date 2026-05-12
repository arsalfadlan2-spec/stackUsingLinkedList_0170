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
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
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
        int poppedValue = temp->data; // Simpan data sebelum dihapus
        top = top->next;
        
        cout << "Popped value: " << poppedValue << endl;
        delete temp; // Menghapus node dari memori
    }

    // peek/display operation: Retrieve values without removing
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
        } else {
            Node *current = top;
            cout << "Current Stack (top to bottom): ";
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    // isEmpty operation: check if the stack is empty
    bool isEmpty() {
        return top == NULL; 
    }
};

int main() {
    stack myStack; // Hindari menamai objek sama dengan nama class (case-sensitive)
    
    int choice = 0;
    int value;

    while (choice != 4) { // Berubah ke 4 sesuai menu Exit
        cout << "--- Menu Stack ---" << endl;
        cout << "1. Push\n2. Pop\n3. Peek/Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
// End of the programm