#include <bits/stdc++.h>
#define MAX 100
using namespace std;
typedef int item;

struct NODE {
    item Data;
    NODE *Next;
};

struct Stack {
    NODE *Top;
};

void Init(Stack &S) {
    S.Top = NULL;
}

int Isempty(Stack S) {
    return (S.Top == NULL);
}

NODE *TaoNODE(item x) {
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->Next = NULL;
    p->Data = x;
    return p;
}

void Push(Stack &S, item x) {
    NODE *p = TaoNODE(x);
    p->Next = S.Top;
    S.Top = p;
}

int Peak(Stack S) {
    return S.Top->Data;
}
int Pop(Stack &S) {
    if (!Isempty(S)) {
        item x = S.Top->Data;
        S.Top = S.Top->Next;
        return x;
    }
    return -1;
}

void nhap(int arr[], int &n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    
    cout << "Nhap gia tri: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}
void in(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void QuickSort(int a[], int n) {
    Stack stack;
    Init(stack);
    Push(stack, 0);
    Push(stack, n - 1);

    while (!Isempty(stack)) {
        int r = Pop(stack);
        int l = Pop(stack);

        int p = a[l];
        int i = l + 1;
        int j = r;

        while (i <= j) {
            while (i <= j && a[i] <= p) i++;
            while (i <= j && a[j] > p) j--;
            if (i < j) swap(a[i], a[j]);
        }
        swap(a[l], a[j]);
        if (l < j - 1) {
            Push(stack, l);
            Push(stack, j - 1);
        }
        if (j + 1 < r) {
            Push(stack, j + 1);
            Push(stack, r);
        }
    }
}

int main() {
    int a[MAX];
    int n;
    nhap(a, n);
    in(a, n);
    QuickSort(a, n);
    in(a,n);
    return 0;
}
