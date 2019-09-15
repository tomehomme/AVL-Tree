//main.cpp file given by Prof. Le Pendu
//Implementation of visualizeTree function given by program specifications
//used zybooks pseudocode to help implement functions
#ifndef AVLTREE_H
#define AVLTREE_H
#include "Node.h"

class AVLTree{
    private:
        Node* root; //root of the avltree
       // Node* findUnbalancedNode; //Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
        //Node* rotate(Node* node); //Implement four possible imbalance cases and update the parent of the given node.
        Node* rotateLeft(Node* node); //Rotate the subtree to left at the given node and returns the new subroot. DONE
        Node* rotateRight(Node* node); //Rotate the subtree to right at the given node and returns the new subroot. DONE
        void printBalanceFactors(Node *); //DONE
        void visualizeTree(ofstream &, Node *); //DONE
        bool SetChild(Node* parent, const string & whichChild, Node* child);//DONE
        bool ReplaceChild(Node* parent,Node* currentChild,Node* newChild); //DONE
        void UpdateHeight(Node*); //DONE
        Node* Rebalance(Node* node); //DONE
    public:
        AVLTree(); //DONE
        void insert(const string &); //Insert an item to the binary search tree and perform rotation if necessary. FIX IF NODES ARE THE SAME
        int balanceFactor(Node* node);//Return the balance factor of a given node. DONE
        void printBalanceFactors(); //Traverse and print the tree in inorder notation. Print the string followed by its balance factor in parentheses followed by a , and one space. DONE
        void visualizeTree(const string &); //Generate dotty file and visualize the tree using dotty program. Call this function before and after rotation. DONE

};
#endif