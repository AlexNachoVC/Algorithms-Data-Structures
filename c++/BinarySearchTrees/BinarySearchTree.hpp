#pragma once

using namespace std;
template <typename T>
class TreeNode {
public:
    T info;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) : info(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class BST {
private:
    TreeNode<T> *root;

    T* recursiveSearch(TreeNode<T> *curr, T data) {
        if (!curr) {
            return nullptr;
        }
        if (data < curr->info) {
            return(recursiveSearch(curr->left, data));
        }
        else if (data > curr->info) {
            return(recursiveSearch(curr->right, data));
        }
        return &curr->info;
    }

    bool recursiveInsert(TreeNode<T> *&node, T data) {
        if (!node) {
            node = new(nothrow) TreeNode<T>(data);
            if (!node) {
                return false;
            }
            return true;
        }

        if (data < node->info) {
            return recursiveInsert(node->left, data);
        }
        else if (data > node->info) {
            return recursiveInsert(node->right, data);
        }

        // El dato ya existe en el arbol, no se permite duplicados
        // si deseamos incluir duplicados, cambiar arriba "<" por "<="
        return false;
    }
    void walkInOrder(TreeNode<T>* curr) {
        if (curr == nullptr) {
            return;
        }
        walkInOrder(curr->left);
        cout << curr->info << " ";
        walkInOrder(curr->right);
    }

    void walkPreOrder(TreeNode<T>* curr) {
        if (curr == nullptr) {
            return;
        }
        
        cout << curr->info << " ";
        walkPreOrder(curr->left);
        walkPreOrder(curr->right);
    }

    void walkPostOrder(TreeNode<T>* curr) {
        if (curr == nullptr) {
            return;
        }

        walkPostOrder(curr->left);
        walkPostOrder(curr->right);
        cout << curr->info << " ";
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        deleteBST();
    }

    bool deleteBST() {
        
    };

    T* search(T data) {
        return(recursiveSearch(root, data));
    }

    bool insert(T data) {
        return(recursiveInsert(root, data));
    }

    void printInOrder() {
        walkInOrder(root);
        cout << endl;
    }

    void printPreOrder() {
        walkPreOrder(root);
        cout << endl;
    }

    void printPostOrder() {
        walkPostOrder(root);
        cout << endl;
    }
};