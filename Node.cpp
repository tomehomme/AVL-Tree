//main.cpp file given by Prof. Le Pendu
//Implementation of visualizeTree function given by program specifications
//used zybooks pseudocode to help implement functions
#include "Node.h"
#include <string>
using namespace std;

Node::Node(){
    data = "";
    height = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::Node(const string &data){
    this->data = data;
    left = nullptr;
    right = nullptr;
    height = 0;
}

string Node::getData() const{
    return data;
}


void Node::changeData(string newData){
    data = newData;
}
