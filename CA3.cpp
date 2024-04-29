#include <iostream>
#include <string>

using namespace std;

// Structure to represent a student record
struct Student {
    int rollNumber;
    string name;
    string contact;
    string email;
    float percentage;
    Student* left;
    Student* right;
};

// Function to create a new student node
Student* createStudent(int rollNumber, const string& name, const string& contact, const string& email, float percentage) {
    Student* newNode = new Student;
    newNode->rollNumber = rollNumber;
    newNode->name = name;
    newNode->contact = contact;
    newNode->email = email;
    newNode->percentage = percentage;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a new student record into the BST
Student* insert(Student* root, int rollNumber, const string& name, const string& contact, const string& email, float percentage) {
    // If the tree is empty, create a new node and return it
    if (root == nullptr) {
        return createStudent(rollNumber, name, contact, email, percentage);
    }

    // Compare the email address of the new student with the current node's email
    if (email < root->email) {
        // If the email is less than the current node's email, insert in the left subtree
        root->left = insert(root->left, rollNumber, name, contact, email, percentage);
    } else if (email > root->email) {
        // If the email is greater than the current node's email, insert in the right subtree
        root->right = insert(root->right, rollNumber, name, contact, email, percentage);
    } else {
        // If the email already exists, do nothing (Assuming no duplicates allowed)
        cout << "Email already exists: " << email << endl;
    }

    return root;
}

// Function to search for a student record using their email address
Student* search(Student* root, const string& email) {
    // If the tree is empty or the email is found at the root, return the root
    if (root == nullptr || root->email == email) {
        return root;
    }

    // If the email is less than the root's email, search in the left subtree
    if (email < root->email) {
        return search(root->left, email);
    }
    // If the email is greater than the root's email, search in the right subtree
    else {
        return search(root->right, email);
    }
}

// Function to display student record details
void displayStudent(Student* student) {
    if (student != nullptr) {
        cout << "Roll Number: " << student->rollNumber << endl;
        cout << "Name: " << student->name << endl;
        cout << "Contact: " << student->contact << endl;
        cout << "Email: " << student->email << endl;
        cout << "Percentage: " << student->percentage << endl;
        cout << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

int main() {
    // Create an empty BST
    Student* root = nullptr;

    // Insert some sample student records
    root = insert(root, 101, "John Doe", "1234567890", "john.doe@example.com", 85.5);
    root = insert(root, 102, "Jane Smith", "9876543210", "jane.smith@example.com", 78.3);
    root = insert(root, 103, "Alice Johnson", "3456789012", "alice.johnson@example.com", 91.7);
    // char choice;
    // do {
    //     root = insert(root);
    //     cout << "Do you want to insert another student record? (y/n): ";
    //     cin >> choice;
    // } while (choice == 'y' || choice == 'Y');

    // Search for a student record using email address
    string searchEmail = "jane.smith@example.com";
    cout << "Searching for student with email: " << searchEmail << endl;
    Student* foundStudent = search(root, searchEmail);
    displayStudent(foundStudent);

    // Search for a non-existent student
    string nonExistentEmail = "nonexistent@example.com";
    cout << "Searching for student with email: " << nonExistentEmail << endl;
    foundStudent = search(root, nonExistentEmail);
    displayStudent(foundStudent);

    // Cleanup (free memory)
    // Add code for cleanup if needed

    return 0;
}
