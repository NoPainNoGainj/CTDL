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

// Hàm kh?i t?o danh sách r?ng
void Init(SLIST& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

// Hàm t?o m?t node m?i
NODE* CreateNode(Laptop x) {
    NODE* p = new NODE;
    if (p == NULL) {
        cout << "Không d? b? nh?\n";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

// Hàm thêm m?t laptop vào cu?i danh sách
void AddTail(SLIST& l, NODE* p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// Hàm nh?p thông tin laptop
Laptop NhapLaptop() {
    Laptop lt;
    cout << "Nh?p mã lo?i máy tính: ";
    cin >> lt.maLoai;
    cin.ignore();
    cout << "Nh?p tên lo?i máy tính: ";
    cin.getline(lt.tenLoai, 30);
    cout << "Nh?p s? lu?ng t?n kho: ";
    cin >> lt.soLuongTon;
    return lt;
}

// Hàm hi?n th? thông tin m?t laptop
void XuatLaptop(Laptop lt) {
    cout << "Mã lo?i: " << lt.maLoai << ", Tên lo?i: " << lt.tenLoai 
         << ", S? lu?ng t?n: " << lt.soLuongTon << endl;
}

// Hàm hi?n th? danh sách laptop
void XuatDanhSach(SLIST l) {
    NODE* p = l.pHead;
    if (p == NULL) {
        cout << "Danh sách tr?ng!" << endl;
        return;
    }
    while (p != NULL) {
        XuatLaptop(p->data);
        p = p->pNext;
    }
}

// Hàm tìm ki?m laptop theo mã lo?i
NODE* TimKiemTheoMa(SLIST l, int maLoai) {
    NODE* p = l.pHead;
    while (p != NULL) {
        if (p->data.maLoai == maLoai)
            return p;
        p = p->pNext;
    }
    return NULL;
}

// Hàm xóa m?t node theo mã lo?i
void XoaTheoMa(SLIST& l, int maLoai) {
    NODE* p = l.pHead;
    NODE* prev = NULL;

    // Xóa ph?n t? d?u tiên n?u mã lo?i kh?p
    if (p != NULL && p->data.maLoai == maLoai) {
        l.pHead = p->pNext;
        delete p;
        cout << "Ðã xóa máy tính có mã " << maLoai << endl;
        return;
    }

    // Tìm ph?n t? c?n xóa và gi? l?i con tr? prev
    while (p != NULL && p->data.maLoai != maLoai) {
        prev = p;
        p = p->pNext;
    }

    // N?u không tìm th?y mã lo?i
    if (p == NULL) {
        cout << "Không tìm th?y mã máy tính.\n";
        return;
    }

    // G? ph?n t? kh?i danh sách liên k?t
    prev->pNext = p->pNext;
    if (p == l.pTail) {
        l.pTail = prev;
    }
    delete p;
    cout << "Ðã xóa máy tính có mã " << maLoai << endl;
}

// Hàm s?a thông tin laptop theo mã lo?i
void SuaThongTin(SLIST& l, int maLoai) {
    NODE* p = TimKiemTheoMa(l, maLoai);
    if (p == NULL) {
        cout << "Không tìm th?y máy tính v?i mã lo?i này.\n";
    } else {
cout << "Nh?p thông tin m?i cho máy tính mã " << maLoai << ":\n";
        p->data = NhapLaptop();
        cout << "C?p nh?t thông tin thành công.\n";
    }
}

// Hàm tìm và in các laptop có s? lu?ng t?n kho nh? hon ho?c b?ng k
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
        cout << "Không có lo?i máy tính nào có s? lu?ng t?n nh? hon ho?c b?ng " << k << ".\n";
    }
}

// Hàm main v?i menu thao tác
int main() {
    SLIST list;
    Init(list);

    int choice;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Thêm máy tính\n";
        cout << "2. Xóa máy tính theo mã\n";
        cout << "3. S?a thông tin máy tính theo mã\n";
        cout << "4. Tìm ki?m máy tính theo mã\n";
        cout << "5. Hi?n th? danh sách máy tính\n";
        cout << "6. In các máy tính có s? lu?ng t?n kho <= k\n";
        cout << "7. Thoát\n";
        cout << "Nh?p l?a ch?n: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Thêm máy tính vào danh sách
                Laptop lt = NhapLaptop();
                NODE* p = CreateNode(lt);
                AddTail(list, p);
                cout << "Ðã thêm máy tính vào danh sách.\n";
                break;
            }
            case 2: {
                // Xóa máy tính theo mã
                int maLoai;
                cout << "Nh?p mã lo?i máy tính c?n xóa: ";
                cin >> maLoai;
                XoaTheoMa(list, maLoai);
                break;
            }
            case 3: {
                // S?a thông tin máy tính theo mã
                int maLoai;
                cout << "Nh?p mã lo?i máy tính c?n s?a: ";
                cin >> maLoai;
                SuaThongTin(list, maLoai);
                break;
            }
            case 4: {
                // Tìm ki?m máy tính theo mã
                int maLoai;
                cout << "Nh?p mã lo?i máy tính c?n tìm: ";
                cin >> maLoai;
                NODE* found = TimKiemTheoMa(list, maLoai);
                if (found) {
                    XuatLaptop(found->data);
                } else {
                    cout << "Không tìm th?y máy tính có mã " << maLoai << ".\n";
                }
                break;
            }
            case 5: {
                // Hi?n th? danh sách máy tính
                XuatDanhSach(list);
                break;
            }
            case 6: {
                // In các máy tính có s? lu?ng t?n kho <= k
                int k;
                cout << "Nh?p giá tr? k: ";
                cin >> k;
InLaptopTonKhoNhoHonK(list, k);
                break;
            }
            case 7: {
                cout << "Thoát chuong trình.\n";
                break;
            }
            default:
                cout << "L?a ch?n không h?p l?, vui lòng nh?p l?i.\n";
        }
    } while (choice != 7);

    return 0;
}
