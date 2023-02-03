#ifndef NODE_H
#define NODE_H


#include <string.h>
#include <iostream>
#define max_child 7
using namespace std;

class node
{
    public:
        string data;
        node* children[max_child];
        int child_num;
        int id;
        node(string data);
        node();
        int num_siblings;
    friend class tree;
};


#endif // NODE_H
