//
//  binaryNode.h
//  trees
//
//  Created by Vinay Kalia on 9/4/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#ifndef trees_binaryNode_h
#define trees_binaryNode_h

template <typename T>
class binaryNode {
    template<typename U> friend class binarySearchTree;
private:
    T mData;
    binaryNode<T>* mLeft;
    binaryNode<T>* mRight;
public:
    binaryNode(const T &data):mData(data),mLeft(nullptr),mRight(nullptr){};
    ~binaryNode(){};
    T& getData() {
        return &mData;
    }
};

#endif
