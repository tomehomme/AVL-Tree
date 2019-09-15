//main.cpp file given by Prof. Le Pendu
//Implementation of visualizeTree function given by program specifications
//used zybooks pseudocode to help implement functions
#include "AVLTree.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

AVLTree::AVLTree(){
    root = nullptr;
}

bool AVLTree::SetChild(Node* parent, const string & whichChild, Node* child) {
   if (whichChild != "left" && whichChild != "right"){
      return false;
      }

   if (whichChild == "left"){
      parent->left = child;
      }
   else{
      parent->right = child;
      }
   if (child != nullptr){
      child->parent = parent;
   }
   UpdateHeight(parent);
   return true;
}

void AVLTree::UpdateHeight(Node* node) {
   int leftHeight = -1;
   if (node->left != nullptr){
      leftHeight = node->left->height;
   }
   int rightHeight = -1;
   if (node->right != nullptr){
      rightHeight = node->right->height;
   }
   node->height = max(leftHeight, rightHeight) + 1;
}
int AVLTree::balanceFactor(Node* node) {
   int leftHeight = -1;
   if (node->left != nullptr){
      leftHeight = node->left->height;
      }
   int rightHeight = -1;
   if (node->right != nullptr){
      rightHeight = node->right->height;
   }
   return leftHeight - rightHeight;
}
bool AVLTree::ReplaceChild(Node* parent,Node* currentChild, Node* newChild) {
   if (parent->left == currentChild){
      return SetChild(parent, "left", newChild);
      }
   else if (parent->right == currentChild){
      return SetChild(parent, "right", newChild);
      }
   return false;
}

Node* AVLTree::rotateRight(Node* node) {
   Node* leftRightChild = node->left->right;
   if (node->parent != nullptr){
      ReplaceChild(node->parent, node, node->left);
   }
   else { // node is root
      root = node->left;
      root->parent = nullptr;
   }
   SetChild(node->left, "right", node);
   SetChild(node, "left", leftRightChild);
   return node;
}
Node* AVLTree::rotateLeft(Node* node) {
   Node* rightLeftChild = node->right->left;
   if (node->parent != nullptr){
      ReplaceChild(node->parent, node, node->right);
   }
   else { // node is root
      root = node->right;
      root->parent = nullptr;
   }
   SetChild(node->right, "left", node);
   SetChild(node, "right", rightLeftChild);
   return node;
}

Node* AVLTree::Rebalance(Node* node) {
   UpdateHeight(node);       
   if (balanceFactor(node) == -2) {
      if (balanceFactor(node->right) == 1) {
         // Double rotation case.
         rotateRight(node->right);
      }
      return rotateLeft(node);
   }
   else if (balanceFactor(node) == 2) {
      if (balanceFactor(node->left) == -1) {
         // Double rotation case.
         rotateLeft(node->left);
      }
      return rotateRight(node);
   }        
   return node;
}

void AVLTree::insert(const string & nodeData) {
    Node* node = new Node (nodeData);
   if (root == nullptr) {
      root = new Node (nodeData);
      return;
   }

   Node* cur = root;
   while (cur != nullptr) {
       if (nodeData == cur->data){ //cannot have duplicates
           delete node; //because we made a new node "node" in the beginning
           return; //exit insert
       }
      if (nodeData < cur->data) {
         if (cur->left == nullptr) {
            cur->left = node;
            cur->left->parent = cur;
            cur = nullptr; //to exit the while loop
         }
         else
            cur = cur->left;
      }
      else {
         if (cur->right == nullptr) {
            cur->right = node;
            cur->right->parent = cur;
            cur = nullptr; //to exit the while loop
         }
         else
            cur = cur->right;
      }
   }

   node = node->parent;
   while (node != nullptr) {
      Rebalance(node);
      node = node->parent;
   }
}

void AVLTree::visualizeTree(const string &outputFilename){ //given by prof le pendu
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    // string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    // string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    // system(command.c_str());
}

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
    }
}

void AVLTree::printBalanceFactors(){
    printBalanceFactors(root);
    cout<< endl;
}
void AVLTree::printBalanceFactors(Node *node){
    if (node){
        printBalanceFactors(node->left);
        cout << node->data << "("<< balanceFactor(node)<<"), ";
        printBalanceFactors(node->right);
        }
}