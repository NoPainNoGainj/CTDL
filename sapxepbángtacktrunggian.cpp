#include <iostream>
#define MAX 100  // Kích thu?c t?i da c?a ngan x?p

using namespace std;

// C?u trúc ngan x?p s? d?ng m?ng tinh
struct Stack {
    int arr[MAX];
    int top;
};

// Hàm kh?i t?o ngan x?p
void initializeStack(Stack &stack) {
    stack.top = -1;
}

// Hàm ki?m tra ngan x?p có r?ng không
bool isEmpty(Stack &stack) {
    return stack.top == -1;
}

// Hàm ki?m tra ngan x?p có d?y không
bool isFull(Stack &stack) {
    return stack.top == MAX - 1;
}

// Hàm d?y m?t ph?n t? vào ngan x?p
bool pushStack(Stack &stack, int value) {
    if (isFull(stack)) {
        cout << "Ngan x?p dã d?y! Không th? d?y ph?n t? " << value << " vào ngan x?p.\n";
        return false;
    }
    stack.arr[++stack.top] = value;
    return true;
}

// Hàm l?y ph?n t? t? d?nh ngan x?p
bool popStack(Stack &stack, int &value) {
    if (isEmpty(stack)) {
        //cout << "Ngan x?p r?ng! Không th? l?y ph?n t?.\n";
        return false;
    }
    value = stack.arr[stack.top--];
    return true;
}

// Hàm l?y ph?n t? ? d?nh ngan x?p mà không d?y nó ra
bool peekStack(Stack &stack, int &value) {
    if (isEmpty(stack)) {
        return false;
    }
    value = stack.arr[stack.top];
    return true;
}

// Hàm d? in các ph?n t? c?a ngan x?p t? du?i lên trên
void printStack(Stack &stack) {
    if (isEmpty(stack)) {
        cout << "Ngan x?p r?ng.\n";
        return;
    }
    cout << "Ngan x?p (t? du?i lên trên): ";
    for(int i = 0; i <= stack.top; i++) {
        cout << stack.arr[i] << " ";
    }
    cout << endl;
}

// Hàm d? s?p x?p ngan x?p s? d?ng ngan x?p trung gian
void sortStack(Stack &stack1, Stack &stack2) {
    int temp;
    while (!isEmpty(stack1)) {
        // L?y ph?n t? t? stack1
        if (popStack(stack1, temp)) {
            // D?n d?p stack2 và d?y các ph?n t? l?n hon temp tr? l?i stack1
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
            // Ð?y temp vào stack2
            pushStack(stack2, temp);
        }
    }
    
    // Ðua các ph?n t? dã s?p x?p t? stack2 v? stack1
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
    
    // Thêm các ph?n t? vào stack1
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

