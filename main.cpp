//
//  main.cpp
//  trees
//
//  Created by Vinay Kalia on 9/4/15.
//  Copyright (c) 2015 Vinay Kalia. All rights reserved.
//

#include <iostream>
#include "binarySearchTree.h"
#include "trie.h"
#include "sllNode.h"

/*int main(int argc, const char * argv[]) {
    int data = 6;
    binarySearchTree<int> bsTree(data);
    bsTree.insert(10);
    bsTree.insert(11);
    bsTree.insert(2);
    bsTree.insert(3);
    bsTree.insert(18);
    bsTree.insert(4);
    bsTree.insert(15);

    bsTree.traverse();
    cout<<"Depth of the binary search tree is: "<<bsTree.depth()<<endl;
    cout<<"Min depth of the binary search tree is: "<<bsTree.minDepth()<<endl;
    cout<<"Number of nodes in the binary search tree are: "<<bsTree.numNodes()<<endl;
    cout<<"Number of leaf nodes in the binary search tree are: "<<bsTree.numLeafNodes()<<endl;
    cout<<"Is tree balanced: "<<bsTree.isTreeBalanced()<<endl;
    return 0;
}*/
/*
int main(int argc, const char * argv[]) {
    trie<char> tr;
    char *str = "sleeper";
    tr.insert(str, strlen(str));
    str = "sleeping";
    tr.insert(str, strlen(str));
    str = "beauty";
    tr.insert(str, strlen(str));
    tr.traverse();
}*/

int main() {
    sllNode<int> head(1);
    sllNode<int> *newHead;
    head.addTail(2);
    head.addTail(3);
    head.addTail(4);
    head.addTail(5);
    head.addTail(6);
    head.print();
    head.reverse(&head, &newHead);
    newHead->print();
}
