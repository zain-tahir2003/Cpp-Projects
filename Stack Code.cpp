#include <iostream>
using namespace std;

// Stack class using array
class Stack {
private:
    int* stack;     // Array to store stack elements
    int top;        // Top of the stack
    int maxsize;    // Maximum size of the stack

public:
    // Constructor to initialize the stack
    Stack(int size) {
        maxsize = size;
        stack = new int[maxsize];
        top = -1; // Stack is initially empty
    }

    // Destructor to release memory
    ~Stack() {
        if (stack != nullptr) {
            delete[] stack;
        }
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (top == maxsize - 1) {
            cout << "Stack overflow! Cannot push the item.\n";
        } else {
            stack[++top] = value;
            cout << value << " is pushed successfully in the stack.\n";
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (top == -1) {
            cout << "Stack underflow! No elements to pop.\n";
        } else {
            cout << stack[top--] << " is popped from the stack.\n";
        }
    }

    // Function to display stack elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int stacksize, choice, value;

    cout << "Enter the maximum size of the stack: ";
    cin >> stacksize;

    // Create stack object
    Stack mystack(stacksize);

    // Menu-driven program
    do {
        cout << "\nChoose an option from the menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                mystack.push(value);
                break;
            case 2:
                mystack.pop();
                break;
            case 3:
                mystack.display();
                break;
            case 4:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
