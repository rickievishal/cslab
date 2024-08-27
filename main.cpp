#include <iostream>
using namespace std;

// Node class to represent each element in the list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// List class to manage the linked list
class List {
private:
    Node* head;

public:
    List() {
        head = nullptr;
    }

    // Function to add a node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to remove a node with a specific value
    void remove(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return;

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free up memory
    ~List() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    List myList;

    myList.append(10);
    myList.append(20);
    myList.append(30);
    myList.append(40);

    cout << "List after appending elements: ";
    myList.display();

    myList.remove(20);
    cout << "List after removing 20: ";
    myList.display();

    myList.remove(10);
    cout << "List after removing 10: ";
    myList.display();

    return 0;
}
