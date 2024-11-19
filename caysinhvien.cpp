#include <iostream>
#include <cstring> //de su dung strcpy

using namespace std;

struct SinhVien {
    int maSV;          //ma sinh vien
    int tuoi;          //tuoi
    char ten[50];      //ten
};

//dinh nghia cau truc cay sinh vien
struct Node {
    SinhVien data;     //du lieu cua sv
    Node* left;        //con tro tro vao cay con ben trai
    Node* right;       //con tro tro vào cay con ben phai
};

//ham tao nut moi 
Node* createNode(int maSV, int tuoi, const char* ten) {
    Node* newNode = new Node;
    newNode->data.maSV = maSV;
    newNode->data.tuoi = tuoi;
    strcpy(newNode->data.ten, ten);
    newNode->left = newNode->right = NULL;
    return newNode;
}

//ham them mot sinh vien vao cay
Node* themSinhVien(Node* root, int maSV, int tuoi, const char* ten) {
    if (root == NULL) {
        // cay rong, tao nut moi lam goc
        return createNode(maSV, tuoi, ten);
    }
    if (maSV < root->data.maSV) {
        // them vào cay con ben trai
        root->left = themSinhVien(root->left, maSV, tuoi, ten);
    }
    else if (maSV > root->data.maSV) {
        // them vao cay con ben phai
        root->right = themSinhVien(root->right, maSV, tuoi, ten);
    }
    else {
        // ma sinh vien da ton tai, khong them ma vao
        cout << "MaSV " << maSV << " da ton tai. Khong the them.\n";
    }
    return root;
}

//ham tim kiem sinh vien trong cay
Node* timKiem(Node* root, int maSV) {
    if (root == NULL || root->data.maSV == maSV)
        return root;
    if (maSV < root->data.maSV)
        return timKiem(root->left, maSV);
    else
        return timKiem(root->right, maSV);
}

//ham tim nut co gia tri nho nhat
Node* timMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// ham xoa sinh vien khoi cay
Node* xoaSinhVien(Node* root, int maSV) {
    if (root == NULL)
        return root;
    if (maSV < root->data.maSV) {
        root->left = xoaSinhVien(root->left, maSV);
    }
    else if (maSV > root->data.maSV) {
        root->right = xoaSinhVien(root->right, maSV);
    }
    else {
        // nut can xoa da tim thay
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // nút có 2 cay con
        Node* temp = timMin(root->right);
        root->data = temp->data;
        root->right = xoaSinhVien(root->right, temp->data.maSV);
    }
    return root;
}

// ham cap nhat thong tin sinh vien
bool capNhatSinhVien(Node* root, int maSV, int tuoiMoi, const char* tenMoi) {
    Node* target = timKiem(root, maSV);
    if (target != NULL) {
        target->data.tuoi = tuoiMoi;
        strcpy(target->data.ten, tenMoi);
        return true;
    }
    else {
        cout << "Sinh vien maSV " << maSV << " khong ton tai.\n";
        return false;
    }
}

//ham thay the sinh vien nay bang sinh vien khac
bool thayTheSinhVien(Node*& root, int maSVX, int maSVZ, int tuoiZ, const char* tenZ) {
    Node* nodeX = timKiem(root, maSVX);
    if (nodeX != NULL) {
        // kiem tra ma sinh vien da ton tai hay chx
        if (timKiem(root, maSVZ) != NULL) {
            cout << "MaSV " << maSVZ << " Da ton tai. Khong the thay the.\n";
            return false;
        }
        // luu thong tin sinh vien da chon
        int tuoiMoi = tuoiZ;
        char tenMoi[50];
        strcpy(tenMoi, tenZ);
        // them sinh vien da chon vao cay
        root = themSinhVien(root, maSVZ, tuoiMoi, tenMoi);
        // xoa ten sinh vien bi thay the
        root = xoaSinhVien(root, maSVX);
        return true;
    }
    else {
        cout << "Sinh vien maSV " << maSVX << " khong ton tai.\n";
        return false;
    }
}

// xoa toan bo cay
void xoaToanBoCay(Node* root) {
    if (root == NULL)
        return;
    xoaToanBoCay(root->left);
    xoaToanBoCay(root->right);
    delete root;
}

// ham duyet va in danh sach sinh vien
void xuattuoitangdan(Node* root) {
    if (root == NULL)
        return;
    duyetInOrder(root->left);
    cout << "MaSV: " << root->data.maSV 
         << ", Tuoi: " << root->data.tuoi
         << ", Ten: " << root->data.ten << endl;
    xuat(root->right);
}

int main() {
    Node* root = NULL;
    int luaChon;
    do {
        cout << "\n===== QUAN LY SINH VIEN BANG CAY NHI PHAN TIM KIEM =====\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xoa sinh vien\n";
        cout << "3. Cap nhat sinh vien\n";
        cout << "4. Thay the sinh vien\n";
        cout << "5. In danh sach sinh vien theo thu tu tang dan\n";
        cout << "6. Xoa toan bo cay\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        if (luaChon == 1) {
            int maSV, tuoi;
            char ten[50];
            cout << "Nhap ma sinh vien: ";
            cin >> maSV;
            cout << "Nhap tuoi: ";
            cin >> tuoi;
            cout << "Nhap ten sinh vien: ";
            cin.ignore();
            cin.getline(ten, 50);
            root = themSinhVien(root, maSV, tuoi, ten);
        }
        else if (luaChon == 2) {
            int maSV;
            cout << "Nhap ma sinh vien can xoa: ";
            cin >> maSV;
            root = xoaSinhVien(root, maSV);
        }
        else if (luaChon == 3) {
            int maSV, tuoiMoi;
            char tenMoi[50];
            cout << "Nhap ma sinh vien can cap nhat: ";
            cin >> maSV;
            cout << "Nhap tuoi moi: ";
            cin >> tuoiMoi;
            cout << "Nhap ten moi: ";
            cin.ignore();
            cin.getline(tenMoi, 50);
            capNhatSinhVien(root, maSV, tuoiMoi, tenMoi);
        }
        else if (luaChon == 4) {
            int maSVX, maSVZ, tuoiZ;
            char tenZ[50];
            cout << "Nhap ma sinh vien can thay the (x): ";
            cin >> maSVX;
            cout << "Nhap ma sinh vien thay the (z): ";
            cin >> maSVZ;
            cout << "Nhap tuoi sinh vien z: ";
            cin >> tuoiZ;
            cout << "Nhap ten sinh vien z: ";
            cin.ignore();
            cin.getline(tenZ, 50);
            thayTheSinhVien(root, maSVX, maSVZ, tuoiZ, tenZ);
        }
        else if (luaChon == 5) {
            cout << "\n===== DANH SACH SINH VIEN THEO THU TU TANG DAN =====\n";
            xuattuoitangdan(root);
        }
        else if (luaChon == 6) {
            xoaToanBoCay(root);
            root = NULL;
            cout << "Da xoa toan bo cay BST.\n";
        }
        else if (luaChon == 0) {
            cout << "Chuong trinh ket thuc.\n";
        }
        else {
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (luaChon != 0);

    //trc khi ket thuc giai phong cay
    xoaToanBoCay(root);
    return 0;
}

