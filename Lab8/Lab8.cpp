#include <iostream>
using namespace std;
enum Insert {
    child,
    sibling,
    reset
};
enum Order {
    print,
    search,
    searchWay,
    deleteNode
};
struct Node {
    int value;
    Node* leftChild;
    Node* rightSibling;
    Node(int _value) : value(_value), leftChild(nullptr), rightSibling(nullptr){}
};
struct Tree {
    Node* head = nullptr;
    Node* current = head;
    Node* prev = nullptr;
    bool isFound = false;
    Node* foundElement = nullptr;
    void addNode(int _value, const Insert node = child) {
        if (head == nullptr) {
            head = new Node(_value);
            current = head;
            return;
        }
        Node* newNode = new Node(_value);
        switch (node) {
        case child:
            current->leftChild = newNode;
            current = newNode;
            break;
        case sibling:
            current->rightSibling = newNode;
            current = newNode;
            break;
        }
    }
    void reset(int _value) {
        preOrder(head, search, _value);
        current = foundElement;
        isFound = false;
    }

    void preOrder(Node* node, const Order option = print, int _value = 0) {
        if (node == nullptr) return;
        switch (option) {
        case print:
            cout << node->value << endl;
            break;

        case search:
            if (!isFound) {
                if (node->value == _value) {
                    isFound = true;
                    foundElement = node;
                }
            }
            break;
        case searchWay:
            if (!isFound) {
                cout << node->value << endl;
                if (node->value == _value) {
                    isFound = true;
                }
            }
        case deleteNode:
            if (node->leftChild != nullptr && node->leftChild->value == _value) {
                prev = node;
            }
            if (node->rightSibling != nullptr && node->rightSibling->value == _value) {
                prev = node;
            }
            if (prev != nullptr && prev->leftChild == node && node->value == _value) {
                if (node->leftChild == nullptr) {
                    if (node->rightSibling == nullptr) {
                        prev->leftChild = nullptr;
                    }
                    else {
                        prev->leftChild = node->rightSibling;
                    }
                }
                else {
                    if (node->rightSibling == nullptr) {
                        prev->leftChild = node->leftChild;
                    }
                    else {
                        node->rightSibling->leftChild = node->leftChild;
                        prev->leftChild = node->rightSibling;
                    }
                }
            }
            if (prev != nullptr && prev->rightSibling == node && node->value == _value) {
                if (node->leftChild == nullptr) {
                    if (node->rightSibling == nullptr) {
                        prev->rightSibling = nullptr;
                    }
                    else {
                        prev->rightSibling = node->rightSibling;
                    }
                }
                else {
                    if (node->rightSibling == nullptr) {
                        prev->leftChild = node->leftChild;
                    }
                    else {
                        node->rightSibling->leftChild = node->leftChild;
                        prev->rightSibling = node->rightSibling;
                    }
                }
            }
            break;
        }      
        preOrder(node->leftChild, option, _value);
        preOrder(node->rightSibling, option, _value);
    }
    void inOrder(Node* node, const Order option = print, int _value = 0) {
        if (node == nullptr) return;
        inOrder(node->leftChild, option, _value);       
        switch (option) {
        case print:
            cout << node->value << endl;
            break;

        case search:
            if (!isFound) {
                if (node->value == _value) {
                    isFound = true;
                    foundElement = node;
                }
            }
            break;
        case searchWay:
            if (!isFound) {
                cout << node->value << endl;
                if (node->value == _value) {
                    isFound = true;
                }
            }
        case deleteNode:
            if (node->leftChild != nullptr && node->leftChild->value == _value) {
                prev = node;
            }
            if (node->rightSibling != nullptr && node->rightSibling->value == _value) {
                prev = node;
            }
            if (prev != nullptr && prev->leftChild == node && node->value == _value) {
                if (node->leftChild == nullptr) {
                    if (node->rightSibling == nullptr) {
                        prev->leftChild = nullptr;
                    }
                    else {
                        prev->leftChild = node->rightSibling;
                    }
                }
                else {
                    if (node->rightSibling == nullptr) {
                        prev->leftChild = node->leftChild;
                    }
                    else {
                        node->rightSibling->leftChild = node->leftChild;
                        prev->leftChild = node->rightSibling;
                    }
                }
            }
            if (prev != nullptr && prev->rightSibling == node && node->value == _value) {
                if (node->leftChild == nullptr) {
                    if (node->rightSibling == nullptr) {
                        prev->rightSibling = nullptr;
                    }
                    else {
                        prev->rightSibling = node->rightSibling;
                    }
                }
                else {
                    if (node->rightSibling == nullptr) {
                        prev->leftChild = node->leftChild;
                    }
                    else {
                        node->rightSibling->leftChild = node->leftChild;
                        prev->rightSibling = node->rightSibling;
                    }
                }
            }
            break;
        }
        inOrder(node->rightSibling, option, _value);
    }
    void postOrder(Node* node, const Order option = print, int _value = 0) {
        if (node == nullptr) return;
        postOrder(node->leftChild, option, _value);
        postOrder(node->rightSibling, option, _value);
        switch (option) {
        case print:
            cout << node->value << endl;
            break;

        case search:
            if (!isFound) {
                if (node->value == _value) {
                    isFound = true;
                    foundElement = node;
                }
            }           
            break;
        case searchWay:
            if (!isFound) {
                cout << node->value << endl;
                if (node->value == _value) {
                    isFound = true;
                }
            }
        case deleteNode:
            if (node->leftChild != nullptr && node->leftChild->value == _value) {
                prev = node;
            }
            if (node->rightSibling != nullptr && node->rightSibling->value == _value) {
                prev = node;
            }
            if (prev != nullptr && prev->leftChild == node && node->value == _value) {
                if (node->leftChild == nullptr) {
                    if (node->rightSibling == nullptr) {
                        prev->leftChild = nullptr;
                    }
                    else {
                        prev->leftChild = node->rightSibling;
                    }
                }
                else {
                    if (node->rightSibling == nullptr) {
                        prev->leftChild = node->leftChild;
                    }
                    else {
                        node->rightSibling->leftChild = node->leftChild;
                        prev->leftChild = node->rightSibling;
                    }
                }
            }
            if (prev != nullptr && prev->rightSibling == node && node->value == _value) {
                if (node->leftChild == nullptr) {
                    if (node->rightSibling == nullptr) {
                        prev->rightSibling = nullptr;
                    }
                    else {
                        prev->rightSibling = node->rightSibling;
                    }
                }
                else {
                    if (node->rightSibling == nullptr) {
                        prev->leftChild = node->leftChild;
                    }
                    else {
                        node->rightSibling->leftChild = node->leftChild;
                        prev->rightSibling = node->rightSibling;
                    }
                }
            }
            break;
        }
    }
};
int main()
{
    Tree tree;
    int option;
    int value;
    int method;
    while (true) {
        cout << "Choose option" << endl;
        cout << "1. Add child" << endl;
        cout << "2. Add sibling" << endl;
        cout << "3. Reset node" << endl;
        cout << "4. PreOrder" << endl;
        cout << "5. InOrder" << endl;
        cout << "6. PostOrder" << endl;
        cin >> option;
        switch (option) {
        case 1:
            cout << "Enter value" << endl;
            cin >> value;
            tree.addNode(value, child);
            break;
        case 2:
            cout << "Enter value" << endl;
            cin >> value;
            tree.addNode(value, sibling);
            break;
        case 3:
            cout << "Enter value" << endl;
            cin >> value;
            tree.reset(value);
            break;
        case 4:
            cout << "Choose method: 1 - print, 2 - delete node, 3 - search element, 4 - search way" << endl;
            cin >> method;
            switch (method) {
            case 1:
                tree.preOrder(tree.head, print);
                break;
            case 2:
                cout << "Enter value" << endl;
                cin >> value;
                tree.preOrder(tree.head, deleteNode, value);
                break;
            case 3:
                cout << "Enter value" << endl;
                cin >> value;
                tree.preOrder(tree.head, search, value);
                break;
            case 4:
                cout << "Enter value" << endl;
                cin >> value;
                tree.preOrder(tree.head, searchWay, value);
                break;
            }
        case 5:
            cout << "Choose method: 1 - print, 2 - delete node, 3 - search element, 4 - search way" << endl;
            cin >> method;
            switch (method) {
            case 1:
                tree.inOrder(tree.head, print);
                break;
            case 2:
                cout << "Enter value" << endl;
                cin >> value;
                tree.inOrder(tree.head, deleteNode, value);
                break;
            case 3:
                cout << "Enter value" << endl;
                cin >> value;
                tree.inOrder(tree.head, search, value);
                break;
            case 4:
                cout << "Enter value" << endl;
                cin >> value;
                tree.inOrder(tree.head, searchWay, value);
                break;
            }
        case 6:
            cout << "Choose method: 1 - print, 2 - delete node, 3 - search element, 4 - search way" << endl;
            cin >> method;
            switch (method) {
            case 1:
                tree.postOrder(tree.head, print);
                break;
            case 2:
                cout << "Enter value" << endl;
                cin >> value;
                tree.postOrder(tree.head, deleteNode, value);
                break;
            case 3:
                cout << "Enter value" << endl;
                cin >> value;
                tree.postOrder(tree.head, search, value);
                break;
            case 4:
                cout << "Enter value" << endl;
                cin >> value;
                tree.postOrder(tree.head, searchWay, value);
                break;
            }
        }
    }

}

