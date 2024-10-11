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

};