#ifndef NODE_H
#define NODE_H
#include "string"
#include <iostream>
#define max_child 7
using namespace std;

class node
{
    public:
        string data;
        node* children[max_child];
        int child_num;
        node(string data);
        node();

    friend class tree;
};

#endif // NODE_H
