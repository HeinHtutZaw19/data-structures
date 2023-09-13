/**
 * @file binarySearchTree.h
 * @brief Class of binarySearchTree
 */
template<class T>
typename BST<T>::Node* BST<T>::clean(BST<T>::Node* n)
 {
    if(n == root)
        return NULL;
    {
        clean(n->left);
        clean(n->right);
        delete n;
    }
    return NULL;

}

template<class T>
typename BST<T>::Node* BST<T>::insert(T val, BST<T>::Node* n)
{
    if(n == NULL)
    {
        n = new Node;
        n->data = val;
        n->left = n->right = NULL;
        sizeOf = sizeOf+ 1;
    }
    else if(val <= n->data)
        n->left = insert(val, n->left);
    else if(val > n->data)
        n->right = insert(val, n->right);
    return n;
}

template<class T>
typename BST<T>::Node* BST<T>::findMin(BST<T>::Node* n)
{
    if(n == NULL)
        return NULL;
    else if(n->left == NULL)
        return n;
    else
        return findMin(n->left);
}

template<class T>
typename BST<T>::Node* BST<T>::findMax(BST<T>::Node* n) {
    if(n == NULL)
        return NULL;
    else if(n->right == NULL)
        return n;
    else
        return findMax(n->right);
}

template<class T>
typename BST<T>::Node* BST<T>::remove(T val, BST<T>::Node* n) {
    BST<T>::Node* temp;
    if(n == NULL)
        return NULL;
    else if(val < n->data)
        n->left = remove(val, n->left);
    else if(val > n->data)
        n->right = remove(val, n->right);
    else if(n->left && n->right)
    {
        temp = findMin(n->right);
        n->data = temp->data;
        n->right = remove(n->data, n->right);
    }
    else
    {
        temp = n;
        if(n->left == NULL)
            n = n->right;
        else if(n->right == NULL)
            n = n->left;
        delete temp;
    }

    return n;
}

template<class T>
void BST<T>::inorder(BST<T>::Node* n) {
    if(n == NULL)
        return;
    inorder(n->left);
    cout << n->data << " ";
    inorder(n->right);
}

template<class T>
void BST<T>::preorder(BST<T>::Node* n) {
    if(n == NULL)
        return;
    cout << n->data << " ";
    preorder(n->left);
    preorder(n->right);
}

template<class T>
void BST<T>::postorder(BST<T>::Node* n) {
    if(n == NULL)
        return;
    postorder(n->left);
    postorder(n->right);
    cout << n->data << " ";
}

template<class T>
typename BST<T>::Node* BST<T>::find(BST<T>::Node* n, T val) {
    if(n == NULL)
        return NULL;
    else if(val < n->data)
        return find(n->left, val);
    else if(val > n->data)
        return find(n->right, val);
    else
        return n;
}
