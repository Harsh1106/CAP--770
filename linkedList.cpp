#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr;  // Initialize the head of the linked list to nullptr
    int choice;

    do {
        cout << "1. Insert at the front\n2. Insert at the end\n3. Print the list\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Insert at the front
                int value;
                cout << "Enter the value to insert at the front: ";
                cin >> value;

                // Create a new node
                Node* newNode = new Node;
                newNode->data = value;
                newNode->next = head;

                // Update the head to point to the new node
                head = newNode;

                cout << "Value inserted at the front successfully.\n";
                break;
            }

            case 2: {
                // Insert at the end
                int value;
                cout << "Enter the value to insert at the end: ";
                cin >> value;

                // Create a new node
                Node* newNode = new Node;
                newNode->data = value;
                newNode->next = nullptr;

                if (head == nullptr) {
                    // If the list is empty, set the new node as the head
                    head = newNode;
                } else {
                    // Otherwise, traverse to the last node and add the new node
                    Node* current = head;
                    while (current->next != nullptr) {
                        current = current->next;
                        
                    }
                    current->next = newNode;
                }

                cout << "Value inserted at the end successfully.\n";
                break;
            }

            case 3: {
                // Print the list
                cout << "Linked List: ";
                Node* current = head;
                while (current != nullptr) {
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
                break;
            }

            case 0:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 0);

    // Clean up: free memory allocated for nodes
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}