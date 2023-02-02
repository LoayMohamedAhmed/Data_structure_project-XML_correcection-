#include "../include/node.h"

node::node(string data)
{
    this->data=data;
    this->child_num=0;
    for(int i=0 ;i<max_child;i++)
    {
        children[i]=NULL;
    }
}
node::node()
{
    this->child_num=0;
    for(int i=0 ;i<max_child;i++)
    {
        children[i]=NULL;
    }
}
