#include <iostream>
using namespace std;

typedef int Data;

struct NODE {
    Data Info;
    NODE* pNext;
};

struct SLIST {
    NODE* pHead;
    NODE* pTail;
};

void Init(SLIST &l) {
    l.pHead = l.pTail = NULL;
}

NODE* GetNode(Data x) {
    NODE* p = new NODE;
    if (p == NULL) {
        cout << "Khong du bo nho!";
        return NULL;
    }
    p->Info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(SLIST &l, NODE* new_ele) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = new_ele;
    } else {
        l.pTail->pNext = new_ele;
        l.pTail = new_ele;
    }
}

void RemoveNode(SLIST& l, int x) {
    if (l.pHead == NULL) {
        cout << "Danh sach rong" << endl;
        return;
    }
 
    NODE* T = l.pHead;
    NODE* HT = NULL;
    while (T != NULL && T->Info != x) {
        HT = T;
        T = T->pNext;
    }

   
    if (T == NULL) {
        cout << "Khong tim thay phan tu " << x << endl;
        return;
    }

  
    HT->pNext = T->pNext;
    if (T == l.pTail) {
        l.pTail = HT;
    }
    delete T;
    cout << "Da xoa phan tu " << x << endl;
}

void NhapDanhSach(SLIST &l) {
    int n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> x;
        AddTail(l, GetNode(x));
    }
}
void PrintList(SLIST l) {
    NODE* p = l.pHead;
    while (p != NULL) {
        cout << p->Info << " ";
        p = p->pNext;
    }
    cout << endl;
}
bool IsInList(SLIST l, Data x) {
    NODE* p = l.pHead;
    while (p != NULL) {
        if (p->Info == x)
            return true;
        p = p->pNext;
    }
    return false;
}

void PrintDifferent(SLIST DS1, SLIST DS2) {
    NODE* p = DS2.pHead;
    cout << "Cac phan tu chi co trong DS2 ma khong co trong DS1: ";
    while (p != NULL) {
        if (!IsInList(DS1, p->Info))
            cout << p->Info << " ";
        p = p->pNext;
    }
    cout << endl;
}
int main() {
    SLIST DS1, DS2;

    Init(DS1);
    Init(DS2);

    cout << "Nhap danh sach DS1:\n";
    NhapDanhSach(DS1);

    cout << "Nhap danh sach DS2:\n";
    NhapDanhSach(DS2);

    cout << "Danh sach DS1: ";
    PrintList(DS1);

    cout << "Danh sach DS2: ";
    PrintList(DS2);

    AddTail(DS1, GetNode(-7));
    AddTail(DS1, GetNode(-9));
    cout << "Danh sach DS1 sau khi them -7 va -9: ";
    PrintList(DS1);

    RemoveNode(DS2, 9);
    RemoveNode(DS2, -1);
    cout << "Danh sach DS2 sau khi xoa 9 va -1: ";
    PrintList(DS2);

    PrintDifferent(DS1, DS2);

    return 0;
}
