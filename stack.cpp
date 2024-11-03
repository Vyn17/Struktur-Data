#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack structure
struct Stack {
    Node* top;
    int count;

    // Constructor
    Stack() {
        top = NULL;
        count = 0;
    }
};

bool isEmpty(Stack& stack) {
    return stack.top == NULL;
}

bool isFull() {
    Node* temp = new (nothrow) Node;
    if (temp == NULL) {
        return true;
    }
    delete temp;
    return false;
}

bool push(Stack& stack, int data) {
    if (isFull()) {
        cout << "Stack overflow. Cannot push " << data << endl;
        return false;
    } else {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = stack.top;
        stack.top = newNode;
        stack.count++;
        return true;
    }
}

bool pop(Stack& stack, int& dataOut) {
    if (isEmpty(stack)) {
        cout << "Stack underflow. Cannot pop." << endl;
        return false;
    } else {
        Node* temp = stack.top;
        dataOut = temp->data;
        stack.top = stack.top->next;
        delete temp;
        stack.count--;
        return true;
    }
}

bool top(Stack& stack, int& dataOut) {
    if (isEmpty(stack)) {
        cout << "Stack is empty. No top element." << endl;
        return false;
    } else {
        dataOut = stack.top->data;
        return true;
    }
}

int stackCount(Stack& stack) {
    return stack.count;
}

void destroyStack(Stack& stack) {
    while (!isEmpty(stack)) {
        Node* temp = stack.top;
        stack.top = stack.top->next;
        delete temp;
    }
    stack.count = 0;
    cout << "Stack destroyed." << endl;
}

int main() {
    Stack stack;
    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push data\n";
        cout << "2. Pop data\n";
        cout << "3. Peek top element\n";
        cout << "4. Display stack count\n";
        cout << "5. Destroy stack\n";
        cout << "6. Exit\n";
        cout << "Choose an operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                if (push(stack, data)) {
                    cout << "Data " << data << " pushed to stack.\n";
                }
                break;
            case 2:
                if (pop(stack, data)) {
                    cout << "Popped element: " << data << endl;
                }
                break;
            case 3:
                if (top(stack, data)) {
                    cout << "Top element is: " << data << endl;
                }
                break;
            case 4:
                cout << "Stack count: " << stackCount(stack) << endl;
                break;
            case 5:
                destroyStack(stack);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please choose again.\n";
        }
    } while (choice != 6);

    return 0;
}

