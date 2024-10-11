#pragma once

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
        if (dato < curr->info) {
            return(recursiveSearch(curr->left, data));
        }
        else if (dato > curr->info) {
            return(recursiveSearch(curr->right, data))
        }
        return &curr->info;
    }

    bool recursiveInsert(TreeNode<T> &*node, T data) {
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
        else if (dato > node->info) {
            return recursiveInsert(node->right, data);
        }

        // El dato ya existe en el arbol, no se permite duplicados
        // si deseamos incluir duplicados, cambiar arriba "<" por "<="
        return false;
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        deleteBST();
    }

    bool deleteBST();

    T* search(T data) {
        return(recursiveSearch(root, data));
    }

    bool insert(T dato) {
        return(recursiveInsert(root, data));
    }

};