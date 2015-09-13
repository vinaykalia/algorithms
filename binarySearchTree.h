//
//  binarySearchTree.h
//  trees
//
//  Created by Vinay Kalia on 9/4/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#ifndef __trees__binarySearchTree__
#define __trees__binarySearchTree__

#include <stdio.h>
#include <iostream>
#include "binaryNode.h"

using namespace std;

template <typename T>
class binarySearchTree {
    binaryNode<T> *mRoot;
    void insert(binaryNode<T>* root, binaryNode<T>* node);
    void deleteTree(binaryNode<T>* root);
    void traverse(binaryNode<T>* root);
    int depth(binaryNode<T>* root);
    int numNodes(binaryNode<T>* root);
    int numLeafNodes(binaryNode<T>* root);
    int minDepth(binaryNode<T>* root);
    int isTreeBalanced(binaryNode<T>* root);
public:
    binarySearchTree(const T &data);
    ~binarySearchTree();
    void deleteTree();
    void insert(T data);
    void traverse();
    int depth();
    int minDepth();
    int numNodes();
    int numLeafNodes();
    int isTreeBalanced();
};

template <typename T>
binarySearchTree<T>::binarySearchTree(const T &data) {
    mRoot = new binaryNode<T>(data);
}

template <typename T>
void binarySearchTree<T>::deleteTree(binaryNode<T> *root) {
    if (root->mLeft) {
        deleteTree(root->mLeft);
        root->mLeft = nullptr;
    }
    if (root->mRight) {
        deleteTree(root->mRight);
        root->mRight = nullptr;
    }
    if (!root->mLeft && !root->mRight) {
        delete root;
    }
}


template <typename T>
binarySearchTree<T>::~binarySearchTree() {
    deleteTree(mRoot);
    mRoot = nullptr;
}

template <typename T>
void binarySearchTree<T>::insert(binaryNode<T>* root, binaryNode<T>* node) {
    if (node->mData < root->mData) {
        if (root->mLeft)
            insert(root->mLeft, node);
        else
            root->mLeft = node;
    } else {
        if (root->mRight)
            insert(root->mRight, node);
        else
            root->mRight = node;
    }
}

template <typename T>
void binarySearchTree<T>::insert(T data) {
    binaryNode<T>* node = new binaryNode<T>(data);
    insert(mRoot, node);
}


template <typename T>
void binarySearchTree<T>::traverse(binaryNode<T>* root) {
    if (!root)
        return;
    traverse(root->mLeft);
    cout<<"data = "<<root->mData<<endl;
    traverse(root->mRight);
}

template <typename T>
void binarySearchTree<T>::traverse() {
    traverse(mRoot);
}

template <typename T>
int binarySearchTree<T>::depth(binaryNode<T>* root) {
    if (!root)
        return 0;
    return (1 + max(depth(root->mLeft), depth(root->mRight)));
}

template <typename T>
int binarySearchTree<T>::depth() {
    return depth(mRoot);
}

template <typename T>
int binarySearchTree<T>::minDepth(binaryNode<T>* root) {
    if (!root)
        return 0;
    return (1 + min(depth(root->mLeft), depth(root->mRight)));
}

template <typename T>
int binarySearchTree<T>::minDepth() {
    return minDepth(mRoot);
}

template <typename T>
int binarySearchTree<T>::numNodes(binaryNode<T>* root) {
    if (!root)
        return 0;
    return (1 + numNodes(root->mLeft) + numNodes(root->mRight));
}

template <typename T>
int binarySearchTree<T>::numNodes() {
    return numNodes(mRoot);
}

template <typename T>
int binarySearchTree<T>::numLeafNodes(binaryNode<T>* root) {
    if (!root)
        return 0;
    if (!root->mLeft && !root->mRight)
        return 1;
    return (numLeafNodes(root->mLeft) + numLeafNodes(root->mRight));
}

template <typename T>
int binarySearchTree<T>::numLeafNodes() {
    return numLeafNodes(mRoot);
}

template <typename T>
int binarySearchTree<T>::isTreeBalanced(binaryNode<T>* root) {
    if (!root)
        return 1;
    int diff = depth(root->mLeft) - depth(root->mRight);
    if (abs(diff) > 1)
        return 0;
    else
        return isTreeBalanced(root->mLeft) && isTreeBalanced(root->mRight);
}

template <typename T>
int binarySearchTree<T>::isTreeBalanced() {
    return isTreeBalanced(mRoot);
}

#endif /* defined(__trees__binarySearchTree__) */
