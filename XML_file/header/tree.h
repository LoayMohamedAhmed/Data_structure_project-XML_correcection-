#ifndef TREE_H
#define TREE_H
#include "node.h"
#include "string"
#include <deque>
#include <iostream>
using namespace std;


class tree
{
    private:

    public:
        node* root;
        tree();
        node* add_child(node* root1,deque<string>data);
        bool is_empty1();
        void print(node*root1);
        ~tree();


};

#endif // TREE_H
