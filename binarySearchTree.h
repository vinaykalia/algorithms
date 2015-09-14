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
#include "testable.h"

using namespace std;

template <typename T>
class binaryNode {
    template<typename U> friend class binarySearchTree;
private:
    T mData;
    binaryNode<T>* mLeft;
    binaryNode<T>* mRight;
public:
    binaryNode(const T data):mData(data),mLeft(nullptr),mRight(nullptr){};
    ~binaryNode(){};
    T getData() {
        return mData;
    }
};

template <typename T>
class binarySearchTree : public testable {
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
    binarySearchTree();
    binarySearchTree(const T data);
    ~binarySearchTree();
    void deleteTree();
    void insert(T data);
    void traverse();
    int depth();
    int minDepth();
    int numNodes();
    int numLeafNodes();
    int isTreeBalanced();
    int test();
};

template <typename T>
binarySearchTree<T>::binarySearchTree():mRoot(nullptr) {
}

template <typename T>
binarySearchTree<T>::binarySearchTree(const T data) {
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
    if (!mRoot)
        mRoot = node;
    else
        insert(mRoot, node);
}


template <typename T>
void binarySearchTree<T>::traverse(binaryNode<T>* root) {
    if (!root)
        return;
    traverse(root->mLeft);
    cout<<root->mData<<", ";
    traverse(root->mRight);
}

template <typename T>
void binarySearchTree<T>::traverse() {
    cout<<"In-order traversal: ";
    traverse(mRoot);
    cout<<endl;
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

template <typename T>
int binarySearchTree<T>::test() {
    cout<<"Testing binary search tree...\n";
    insert(5);
    insert(10);
    insert(11);
    insert(2);
    insert(3);
    insert(18);
    insert(4);
    insert(15);
    traverse();
    cout<<"Depth of the binary search tree is: "<<depth()<<endl;
    cout<<"Min depth of the binary search tree is: "<<minDepth()<<endl;
    cout<<"Number of nodes in the binary search tree are: "<<numNodes()<<endl;
    cout<<"Number of leaf nodes in the binary search tree are: "<<numLeafNodes()<<endl;
    cout<<"Is tree balanced: "<<isTreeBalanced()<<endl;
    cout<<"Binary search tree testing done.\n";
    return 0;
}

#endif /* defined(__trees__binarySearchTree__) */
