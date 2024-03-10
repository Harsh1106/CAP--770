// // without using stack
// #include <iostream>
// #include <string>

// using namespace std;

// bool isBalanced(const string& expression) {
//     int openCount = 0;  // Counter for opening brackets
//     int closeCount = 0; // Counter for closing brackets

//     // Iterate through each character in the expression
//     for (char c : expression) {
//         // Increment open count for opening brackets
//         if (c == '(') {
//             openCount++;
//         } else if (c == ')') {  // Decrement close count for closing brackets
//             closeCount++;

//             // Check if closing bracket appears before any opening bracket (unbalanced)
//             if (closeCount > openCount) {
//                 return false;
//             }
//         }
//     }

//     // Balanced if both counts are equal (all opening brackets have a closing pair)
//     return openCount == closeCount;
// }

// int main() {
//     string expression;

//     cout << "Enter an expression: ";
//     getline(cin, expression);

//     if (isBalanced(expression)) {
//         cout << "Expression is balanced" << endl;
//     } else {
//         cout << "Expression is unbalanced" << endl;
//     }

//     return 0;
// }


// with stack
#include <iostream>
#include <cstring> // Use cstring for strlen instead of deprecated strcpy

using namespace std;

// Define the structure for the stack
struct Stack {
    char stk[20]; // Maximum size of the stack
    int top;

    // Constructor (optional) to initialize top to -1
    Stack() {
        top = -1;
    }
};

// Push a character onto the stack
void push(Stack& s, char item) {
    if (s.top == (20 - 1)) { // Check for full stack
        cout << "Stack overflow\n";
    } else {
        s.top++;
        s.stk[s.top] = item;
    }
}

// Pop a character from the stack
char pop(Stack& s) {
    if (s.top == -1) {
        cout << "Stack underflow\n";
        return '\0'; // Return a null character to indicate error
    } else {
        return s.stk[s.top--];
    }
}

int main() {
    char exp[20];
    Stack s; // Create a stack object
    int i;

    cout << "Enter the expression: ";
    cin >> exp; // Use `cin` for cleaner input

    for (i = 0; i < strlen(exp); i++) {
        switch (exp[i]) {
            case '(':
            case '[':
            case '{':
                push(s, exp[i]);
                break;
            case ')':
            case ']':
            case '}':
                char popped_char = pop(s);
                if (popped_char == '\0') { // Handle stack underflow
                    cout << "Unbalanced expression\n";
                    break;
                } else if ((exp[i] == ')' && popped_char != '(') ||
                           (exp[i] == ']' && popped_char != '[') ||
                           (exp[i] == '}' && popped_char != '{')) {
                    cout << "Unbalanced expression\n";
                    break;
                }
                break;
            default:
                break; // Ignore other characters
        }
    }

    if (s.top == -1) {
        cout << "Balanced expression\n";
    } else {
        cout << "Unbalanced expression\n";
    }

    return 0;
}
