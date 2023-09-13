/**
 * @file binarySearchTree.h
 * @brief Class template of binarySearchTree
 */


#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include<iostream>
using namespace std;

/**
 * @brief Class template of binarySearchTree
 */
template<class T>
class BST {

    /**
     * @brief Class of Node
     */
    struct Node {
        T data;
        Node* left;
        Node* right;
    };
    struct Node* root;///< Root node
    /**
    * @brief empty the input node data.
    * @param input node
    */
    struct Node* clean(struct Node* n);
    /**
    * @brief insert node with data.
    * @param input data
    * @param input node
    */
    struct Node* insert(T val, struct Node* n);
    /**
    * @brief find node with minimum value.
    * @param input node
    */
    struct Node* findMin(struct Node* n);
    /**
    * @brief find node with maximum value.
    * @param input node
    */
    struct Node* findMax(struct Node* n);
    /**
    * @brief remove node that contains input data.
    * @param input data
    * @param input node
    */
    struct Node* remove(T val, struct Node* n);
    /**
    * @brief print the nodes in inorder traversal.
    * @param input node
    */
    void inorder(struct Node* n);
    /**
    * @brief print the nodes in preorder traversal.
    * @param input node
    */
    void preorder(struct Node* n);
    /**
    * @brief print the nodes in postorder traversal.
    * @param input node
    */
    void postorder(struct Node* n);
    /**
    * @brief search for the node with input data.
    * @param input node
    * @param input value
    */
    struct Node* find(struct Node* n, T val);



public:

    int sizeOf = 0;
    /**
    * @brief Default constructor
    */
    BST() {
        root = NULL;
    }
    /**
     * @brief Default destructor
     */
    void clearAll() {
        root = clean(root);
    }
    /**
     * @brief Insertion of an element at the back of existing elements
     *
     * @param data element to insert
     */
    void insert(T val) {
        root = insert(val, root);
    }
    /**
     * @brief Removes the input element of the binarySearchTree
     * @param data element to remove
     */
    void remove(T val) {
        root = remove(val, root);
        sizeOf -= 1;
    }
    /**
     * @brief Prints the tree in inorder traversal
     */
    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }
    /**
     * @brief Prints the tree in preorder traversal
     */
    void preorderTraversal(){
        preorder(root);
        cout << endl;
    }
    /**
     * @brief Prints the tree in postorder traversal
     */
    void postorderTraversal(){
        postorder(root);
        cout << endl;
    }
    /**
     * @brief Search for the input value in the tree
     */
    void search(T val) {
        cout << find(root, val)->data << endl;
    }
    /**
     * @return return minimum value in the tree
     */
    T getMinimum(){
        return findMin(root)->data;
    }
    /**
     * @return return maximum value in the tree
     */
    T getMaximum() {
        return findMax(root)->data;
    }
};

#include "binarySearchTree.tpp"

#endif
