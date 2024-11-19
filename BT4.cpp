#include <iostream>
#include <cstring>

using namespace std;

struct Laptop {
    int maLoai;
    char tenLoai[30];
    int soLuongTon;
};

struct NODE {
    Laptop data;
    NODE* pNext;
};

struct SLIST {
    NODE* pHead;
    NODE* pTail;
};

// H�m kh?i t?o danh s�ch r?ng
void Init(SLIST& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

// H�m t?o m?t node m?i
NODE* CreateNode(Laptop x) {
    NODE* p = new NODE;
    if (p == NULL) {
        cout << "Kh�ng d? b? nh?\n";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

// H�m th�m m?t laptop v�o cu?i danh s�ch
void AddTail(SLIST& l, NODE* p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// H�m nh?p th�ng tin laptop
Laptop NhapLaptop() {
    Laptop lt;
    cout << "Nh?p m� lo?i m�y t�nh: ";
    cin >> lt.maLoai;
    cin.ignore();
    cout << "Nh?p t�n lo?i m�y t�nh: ";
    cin.getline(lt.tenLoai, 30);
    cout << "Nh?p s? lu?ng t?n kho: ";
    cin >> lt.soLuongTon;
    return lt;
}

// H�m hi?n th? th�ng tin m?t laptop
void XuatLaptop(Laptop lt) {
    cout << "M� lo?i: " << lt.maLoai << ", T�n lo?i: " << lt.tenLoai 
         << ", S? lu?ng t?n: " << lt.soLuongTon << endl;
}

// H�m hi?n th? danh s�ch laptop
void XuatDanhSach(SLIST l) {
    NODE* p = l.pHead;
    if (p == NULL) {
        cout << "Danh s�ch tr?ng!" << endl;
        return;
    }
    while (p != NULL) {
        XuatLaptop(p->data);
        p = p->pNext;
    }
}

// H�m t�m ki?m laptop theo m� lo?i
NODE* TimKiemTheoMa(SLIST l, int maLoai) {
    NODE* p = l.pHead;
    while (p != NULL) {
        if (p->data.maLoai == maLoai)
            return p;
        p = p->pNext;
    }
    return NULL;
}

// H�m x�a m?t node theo m� lo?i
void XoaTheoMa(SLIST& l, int maLoai) {
    NODE* p = l.pHead;
    NODE* prev = NULL;

    // X�a ph?n t? d?u ti�n n?u m� lo?i kh?p
    if (p != NULL && p->data.maLoai == maLoai) {
        l.pHead = p->pNext;
        delete p;
        cout << "�� x�a m�y t�nh c� m� " << maLoai << endl;
        return;
    }

    // T�m ph?n t? c?n x�a v� gi? l?i con tr? prev
    while (p != NULL && p->data.maLoai != maLoai) {
        prev = p;
        p = p->pNext;
    }

    // N?u kh�ng t�m th?y m� lo?i
    if (p == NULL) {
        cout << "Kh�ng t�m th?y m� m�y t�nh.\n";
        return;
    }

    // G? ph?n t? kh?i danh s�ch li�n k?t
    prev->pNext = p->pNext;
    if (p == l.pTail) {
        l.pTail = prev;
    }
    delete p;
    cout << "�� x�a m�y t�nh c� m� " << maLoai << endl;
}

// H�m s?a th�ng tin laptop theo m� lo?i
void SuaThongTin(SLIST& l, int maLoai) {
    NODE* p = TimKiemTheoMa(l, maLoai);
    if (p == NULL) {
        cout << "Kh�ng t�m th?y m�y t�nh v?i m� lo?i n�y.\n";
    } else {
cout << "Nh?p th�ng tin m?i cho m�y t�nh m� " << maLoai << ":\n";
        p->data = NhapLaptop();
        cout << "C?p nh?t th�ng tin th�nh c�ng.\n";
    }
}

// H�m t�m v� in c�c laptop c� s? lu?ng t?n kho nh? hon ho?c b?ng k
void InLaptopTonKhoNhoHonK(SLIST l, int k) {
    NODE* p = l.pHead;
    bool found = false;
    while (p != NULL) {
        if (p->data.soLuongTon <= k) {
            XuatLaptop(p->data);
            found = true;
        }
        p = p->pNext;
    }
    if (!found) {
        cout << "Kh�ng c� lo?i m�y t�nh n�o c� s? lu?ng t?n nh? hon ho?c b?ng " << k << ".\n";
    }
}

// H�m main v?i menu thao t�c
int main() {
    SLIST list;
    Init(list);

    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Th�m m�y t�nh\n";
        cout << "2. X�a m�y t�nh theo m�\n";
        cout << "3. S?a th�ng tin m�y t�nh theo m�\n";
        cout << "4. T�m ki?m m�y t�nh theo m�\n";
        cout << "5. Hi?n th? danh s�ch m�y t�nh\n";
        cout << "6. In c�c m�y t�nh c� s? lu?ng t?n kho <= k\n";
        cout << "7. Tho�t\n";
        cout << "Nh?p l?a ch?n: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Th�m m�y t�nh v�o danh s�ch
                Laptop lt = NhapLaptop();
                NODE* p = CreateNode(lt);
                AddTail(list, p);
                cout << "�� th�m m�y t�nh v�o danh s�ch.\n";
                break;
            }
            case 2: {
                // X�a m�y t�nh theo m�
                int maLoai;
                cout << "Nh?p m� lo?i m�y t�nh c?n x�a: ";
                cin >> maLoai;
                XoaTheoMa(list, maLoai);
                break;
            }
            case 3: {
                // S?a th�ng tin m�y t�nh theo m�
                int maLoai;
                cout << "Nh?p m� lo?i m�y t�nh c?n s?a: ";
                cin >> maLoai;
                SuaThongTin(list, maLoai);
                break;
            }
            case 4: {
                // T�m ki?m m�y t�nh theo m�
                int maLoai;
                cout << "Nh?p m� lo?i m�y t�nh c?n t�m: ";
                cin >> maLoai;
                NODE* found = TimKiemTheoMa(list, maLoai);
                if (found) {
                    XuatLaptop(found->data);
                } else {
                    cout << "Kh�ng t�m th?y m�y t�nh c� m� " << maLoai << ".\n";
                }
                break;
            }
            case 5: {
                // Hi?n th? danh s�ch m�y t�nh
                XuatDanhSach(list);
                break;
            }
            case 6: {
                // In c�c m�y t�nh c� s? lu?ng t?n kho <= k
                int k;
                cout << "Nh?p gi� tr? k: ";
                cin >> k;
InLaptopTonKhoNhoHonK(list, k);
                break;
            }
            case 7: {
                cout << "Tho�t chuong tr�nh.\n";
                break;
            }
            default:
                cout << "L?a ch?n kh�ng h?p l?, vui l�ng nh?p l?i.\n";
        }
    } while (choice != 7);

    return 0;
}
