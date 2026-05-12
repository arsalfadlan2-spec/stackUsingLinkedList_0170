#include <iostream>

using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        this->data = value;
        this->next = nullptr;
    }
};

// Stack class using Linked List
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Menambah elemen ke tumpukan
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Berhasil push: " << value << endl;
    }

    // Menghapus elemen teratas
    void pop() {
        if (isEmpty()) {
            cout << "Stack Kosong! Tidak bisa pop." << endl;
            return;
        }
        Node* temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp; // Menghapus memori agar tidak leak
        cout << "Berhasil pop: " << poppedValue << endl;
    }

    // Melihat elemen teratas tanpa menghapus
    void peek() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
        } else {
            cout << "Elemen teratas: " << top->data << endl;
        }
    }

    // Menampilkan seluruh isi stack
    void display() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return;
        }
        Node* current = top;
        cout << "Isi Stack: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor untuk membersihkan memori saat program selesai
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n--- MENU STACK ---" << endl;
        cout << "1. Push\n2. Pop\n3. Peek & Display\n4. Exit" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                s.display();
                break;
            case 4:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Pilihan salah!" << endl;
        }
    } while (choice != 4);

    return 0;
}