A Binary Search Tree (BST) is a type of binary tree in which the data is organized and stored in a sorted order. Unlike, a binary tree that doesn't follow a specific order for node placement, in a binary search tree all the elements on the left side of a node are smaller than the node itself, and elements on the right side of a node are greater.

In this article, we will learn more about the binary search tree, operations performed on BST, and implementation of BST, as well as the advantages, disadvantages, and applications of binary search tree in C++.
What is a Binary Search Tree (BST)?

A Binary Search Tree (BST) is a binary tree in which every node contains only smaller values in its left subtree and only larger values in its right subtree. This property is called the BST property and every binary search tree follows this property as it allows efficient insertion, deletion, and search operations in a tree.
Conditions for a Tree to be a Binary Search Tree

For a tree to be called a binary search, it should fulfill the following conditions:

    All the nodes in the left subtree of any node contain smaller values and all the nodes in the right subtree of any node contain larger values.
    Both the left and right subtrees of any node in the tree should themselves be a BST. This means that they should follow the BST rule.
    A unique path exists from the root node to every other node.

Binary Search Tree Representation in C++

In BST, every value on the left subtree < parent node < right subtree value.
BST
Binary Search Tree

Following are the basics terminologies used in BST:

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20240502183132/BST.webp" alt="bst"/>

Basic Operations on Binary Search Tree

The following are the basics operations performed on a binary search tree:

Here, we will discuss the basic three operation: search, insertion and deletion in a binary search tree. 
