#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data; 
    vector<Node*> links; 

    Node(int val) : data(val) {}
};

void addNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode; 
    } else {
        head->links.push_back(newNode); 
        newNode->links.push_back(head); 
    }
}

void addLink(Node* fromNode, Node* toNode) {
    if (fromNode && toNode) {
        fromNode->links.push_back(toNode);
        toNode->links.push_back(fromNode);
    }
}

void display(Node* head) {
    if (!head) {
        cout << "Danh sách r?ng!" << endl;
        return;
    }
    
    cout << "Danh sách các node:" << endl;
    Node* current = head;
    while (current) {
        cout << "Node: " << current->data << " -> ";
        for (Node* link : current->links) {
            cout << link->data << " ";
        }
        cout << endl;
        current = current->links.empty() ? nullptr : current->links[0];
    }
}

void inputList(Node*& head) {
    int n, value;
    cout << "Nh?p s? lu?ng node mu?n thêm vào danh sách: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Nh?p giá tr? cho node th? " << (i + 1) << ": ";
        cin >> value;
        addNode(head, value);
    }
}
int main() {
    Node* head = nullptr;
    inputList(head);
    if (head && head->links.size() > 1) {
        addLink(head, head->links[0]);
        addLink(head->links[0], head->links[1]);
    }
    display(head);
    return 0;
}
