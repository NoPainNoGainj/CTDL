#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

//tao cay
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

//them nut
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    } else if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// them con
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}

//tim nut con cua 1 nut
void timnutcon(Node* node) {
    if (node == nullptr) {
        cout << "Nut rong!" << endl;
        return;
    }
    if (node->left != nullptr) {
        cout << "Ben trai: " << node->left->value << endl;
    } else {
        cout << "Khong phai con ben trai" << endl;
    }
    
    if (node->right != nullptr) {
        cout << "Ben phai: " << node->right->value << endl;
    } else {
        cout << "Khong phai con ben phai." << endl;
    }
}

//tim nut cha cua mot nut
Node* timcha(Node* root, Node* node) {
    if (root == nullptr || root == node) return nullptr;
    
    if (root->left == node || root->right == node) {
        return root;
    }

    Node* chaTrai = timcha(root->left, node);
    if (chaTrai != nullptr) return chaTrai;

    return timcha(root->right, node);
}

//tim min
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

//xoa nut
Node* xoanut(Node* root, int value) {
    if (root == nullptr) return root;

    if (value < root->value) {
        root->left = xoanut(root->left, value);
    } else if (value > root->value) {
        root->right = xoanut(root->right, value);
    } else {
        // khong tim thay
        if (root->left == nullptr && root->right == nullptr) {
            //khong con
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            //co 1 con ben phai
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            //co 1 con ben trai
            Node* temp = root;
            root = root->left;
            delete temp;
        } else {
            //co 2 con
            Node* temp = findMin(root->right); // Find the inorder successor
            root->value = temp->value;
            root->right = xoanut(root->right, temp->value);
        }
    }
    return root;
}

//xoa cay
void xoaCay(Node* root) {
    if (root == nullptr) return;

    xoaCay(root->left);
    xoaCay(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    
    //them nut
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout << "Danh sach trong cay: ";
    inOrderTraversal(root);
    cout << endl;

    //tim nut con ben trai cua 30
    cout << "Nut con ben trai cua 30 la: " << endl;
    findChildNodes(root->left);
    
    //tim nut cha cua 40
    Node* parent = timcha(root, root->left->right);
    if (parent != nullptr) {
        cout << "Nut cha cua 40 la: " << parent->value << endl;
    } else {
        cout << "Khong co nut cha!" << endl;
    }

    //xoa nut
    root = xoanut(root, 20);
    cout << "In-order traversal after deleting 20: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

