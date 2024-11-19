#include <iostream>
#define MAX 100  // K�ch thu?c t?i da c?a ngan x?p

using namespace std;

// C?u tr�c ngan x?p s? d?ng m?ng tinh
struct Stack {
    int arr[MAX];
    int top;
};

// H�m kh?i t?o ngan x?p
void initializeStack(Stack &stack) {
    stack.top = -1;
}

// H�m ki?m tra ngan x?p c� r?ng kh�ng
bool isEmpty(Stack &stack) {
    return stack.top == -1;
}

// H�m ki?m tra ngan x?p c� d?y kh�ng
bool isFull(Stack &stack) {
    return stack.top == MAX - 1;
}

// H�m d?y m?t ph?n t? v�o ngan x?p
bool pushStack(Stack &stack, int value) {
    if (isFull(stack)) {
        cout << "Ngan x?p d� d?y! Kh�ng th? d?y ph?n t? " << value << " v�o ngan x?p.\n";
        return false;
    }
    stack.arr[++stack.top] = value;
    return true;
}

// H�m l?y ph?n t? t? d?nh ngan x?p
bool popStack(Stack &stack, int &value) {
    if (isEmpty(stack)) {
        //cout << "Ngan x?p r?ng! Kh�ng th? l?y ph?n t?.\n";
        return false;
    }
    value = stack.arr[stack.top--];
    return true;
}

// H�m l?y ph?n t? ? d?nh ngan x?p m� kh�ng d?y n� ra
bool peekStack(Stack &stack, int &value) {
    if (isEmpty(stack)) {
        return false;
    }
    value = stack.arr[stack.top];
    return true;
}

// H�m d? in c�c ph?n t? c?a ngan x?p t? du?i l�n tr�n
void printStack(Stack &stack) {
    if (isEmpty(stack)) {
        cout << "Ngan x?p r?ng.\n";
        return;
    }
    cout << "Ngan x?p (t? du?i l�n tr�n): ";
    for(int i = 0; i <= stack.top; i++) {
        cout << stack.arr[i] << " ";
    }
    cout << endl;
}

// H�m d? s?p x?p ngan x?p s? d?ng ngan x?p trung gian
void sortStack(Stack &stack1, Stack &stack2) {
    int temp;
    while (!isEmpty(stack1)) {
        // L?y ph?n t? t? stack1
        if (popStack(stack1, temp)) {
            // D?n d?p stack2 v� d?y c�c ph?n t? l?n hon temp tr? l?i stack1
            int top2;
            while (!isEmpty(stack2)) {
                if (!peekStack(stack2, top2)) {
                    break;
                }
                if (top2 > temp) {
                    popStack(stack2, top2);
                    pushStack(stack1, top2);
                } else {
                    break;
                }
            }
            // �?y temp v�o stack2
            pushStack(stack2, temp);
        }
    }
    
    // �ua c�c ph?n t? d� s?p x?p t? stack2 v? stack1
    while (!isEmpty(stack2)) {
        if (popStack(stack2, temp)) {
            pushStack(stack1, temp);
        }
    }
}

int main() {
    Stack stack1, stack2;
    initializeStack(stack1);
    initializeStack(stack2);
    
    // Th�m c�c ph?n t? v�o stack1
    pushStack(stack1, 34);
    pushStack(stack1, 3);
    pushStack(stack1, 31);
    pushStack(stack1, 98);
    pushStack(stack1, 92);
    pushStack(stack1, 23);
    
    cout << "Ngan x?p ban d?u:\n";
    printStack(stack1);
    
    // S?p x?p ngan x?p
    sortStack(stack1, stack2);
    
    cout << "Ngan x?p sau khi s?p x?p:\n";
    printStack(stack1);
    
    return 0;
}

