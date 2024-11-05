#pragma once
#include "../Queue/Queue.hpp"

using namespace std;
template <typename T>
class AVLNode {
public:
    T info;
    int height;
    AVLNode<T> *left;
    AVLNode<T> *right;

    AVLNode(T data) : info(data), height(0), left(nullptr), right(nullptr) {}
};

template <typename T>
class AVL {
private:
    AVLNode<T> *root;

    T* recursiveSearch(AVLNode<T> *curr, T data) {
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

    bool recursiveInsert(AVLNode<T> *&node, T data) {
        if (!node) {
            node = new(nothrow) AVLNode<T>(data);
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
    void walkInOrder(AVLNode<T>* curr) {
        if (curr == nullptr) {
            return;
        }
        walkInOrder(curr->left);
        cout << curr->info << " ";
        walkInOrder(curr->right);
    }

    void walkPreOrder(AVLNode<T>* curr) {
        if (curr == nullptr) {
            return;
        }
        
        cout << curr->info << " ";
        walkPreOrder(curr->left);
        walkPreOrder(curr->right);
    }

    void walkPostOrder(AVLNode<T>* curr) {
        if (curr == nullptr) {
            return;
        }

        walkPostOrder(curr->left);
        walkPostOrder(curr->right);
        cout << curr->info << " ";
    }

    bool recursiveRemove(AVLNode<T> *& root, T data) {
        if (root == nullptr) {
            return false;
        }
        else if (data < root->info) {
            recursiveRemove(root->left, data);
        }
        else if (data > root->info) {
            recursiveRemove(root->right, data);
        }
        else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
                return true;
            }
            else if (root->left == nullptr) {
                AVLNode<T> *tmp = root;
                root = root->right;
                delete tmp;
                return true;
            }
            else if (root->right == nullptr) {
                AVLNode<T> *tmp = root;
                root = root->left;
                delete tmp;
                return true;
            }
            else {
                AVLNode<T> *tmp = findMin(root->right);
                root->info = tmp->info;
                return recursiveRemove(root->right, tmp->info);
            }
        }
    }

    AVLNode<T>* findMin(AVLNode<T> *root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    void deletePostOrder(AVLNode<T> *curr) {
        if (curr == nullptr) {
            return;
        }
        deletePostOrder(curr->left);
        deletePostOrder(curr->right);
        delete curr;
    }

    AVLNode<T>* rightRotate(AVLNode<T>* y) {
        AVLNode<T> *x = y->left;
        AVLNode<T> *T2 = x->right;

        x->right = y;
        y->left = T2;

        calculateHeight(y);
        calculateHeight(x);
        
        return x;
    }

    AVLNode<T>* leftRotate(AVLNode<T>* x) {
        AVLNode<T> *y = x->right;
        AVLNode<T> *T2 = y->left;

        y->left = x;
        x->right = T2;

        calculateHeight(x);
        calculateHeight(y);
        
        return y;
    }

    AVLNode<T>* doubleRightRotate(AVLNode<T>* node) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    AVLNode<T>* doubleLeftRotate(AVLNode<T>* node) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

        // AVL

    int getHeight(AVLNode<T> *node) {
        if (!node) {
            return -1;
        }
        return node->height;
    }

    int getBalance(AVLNode<T> *node) {
        if (!node) {
            return -1;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    void calculateHeight(AVLNode<T> *node) {
        if (node) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }

    int checkBalance(AVLNode<T> *node) {
        if (!node) {
            return -1;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    void balance(AVLNode<T> *&node) {
        int balance = checkBalance(node);

        if (balance > 1){
            int balanceLeft = checkBalance(node->left);
            if (balanceLeft >= 0){
                node = rightRotate(node);
            }
            else{
                node = doubleRightRotate(node);
            }
        }
        if (balance < -1){
            int balanceRight = checkBalance(node->right); 
            if (balanceRight <= 0){
                node = leftRotate(node);
            }
            else{
                node = doubleLeftRotate(node);
            }
        }
    }

public:
    AVL() {
        root = nullptr;
    }

    ~AVL() {
        deleteAVL();
    }

    void deleteAVL() {
       deletePostOrder(root);
       root = nullptr;
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

    void remove(T data) {
        recursiveRemove(root, data);
    }

    void bfs() {
        Queue<AVLNode<T>*> queue;
        if (root == nullptr) {
            return;
        }

        queue.enqueue(root);

        while (!queue.isEmpty()) {
            AVLNode<T>** tmp = queue.peek();
            AVLNode<T>* curr = *tmp;
            queue.deque();

            cout << curr->info << " ";

            if (curr->left != nullptr) {
                queue.enqueue(curr->left);
            }
            if (curr->right != nullptr) {
                queue.enqueue(curr->right);
            }
        }
        cout << endl;
    }
};