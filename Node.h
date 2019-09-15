//main.cpp file given by Prof. Le Pendu
//Implementation of visualizeTree function given by program specifications
//used zybooks pseudocode to help implement functions
#ifndef __NODE_H_
#define __NODE_H_
#include <string>
using namespace std;

class Node{
    public:
        string data;
        Node(const string&);
        Node();
        Node* left;
        Node* right;
        Node* parent;
        int height;
        string getData() const;
        int getCount() const;
        void changeData(string);
        void increaseCount();
        void changeCount(int);
};
#endif