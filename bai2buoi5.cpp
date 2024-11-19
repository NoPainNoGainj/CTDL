#include <iostream>
using namespace std;
typedef int data;
struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top; 
};
void init(Stack &S) {
    S.top = NULL;
}

bool isEmpty(Stack S) {
    return S.top == NULL;
}

Node* taoNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(Stack &S, int value) {
    Node* newNode = taoNode(value);
    newNode->next = S.top;
    S.top = newNode;
}
int pop(Stack &S) {
    if (!isEmpty(S)) {
        Node* temp = S.top;
        int value = temp->data;
        S.top = S.top->next;
        delete temp;
        return value;
    }
    return -1;
}
int rN(int n) {
    Stack S;
    init(S);
    while (n > 0) {
        int d = n % 10;
        push(S, d);
        n /= 10;
    }
    int rdN = 0;
    int m = 1;

    while (!isEmpty(S)) {
        int d = pop(S);
        rdN += d * m;
        m *= 10;
    }
    return rdN;
}

int main() {
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    int rdN = rN(n);
    cout << "So da dao nguoc: " << rdN << endl;
    return 0;
}
