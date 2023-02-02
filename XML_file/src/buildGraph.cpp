#include "header.h"

int ID;
Graph g;
bool static flag;


void traverse_graph(node * root)
{
    if(root->data=="<user>")
    {
       flag=true;
    }
    if(root->data=="<id>" && flag)
    {
       ID=stoi(root->children[0]->data);
       flag=false;
    }

    if(root->data=="<name>")
    {
        g.addUserID(ID,root->children[0]->data);

    }
    if(root->data=="<follower>")
    {
        int o=stoi(root->children[0]->children[0]->data);
        g.addEdge(ID,o);
    }


    if(root->children[0]== NULL)
    {
      return;
    }

    for(int i=0;i<root->child_num;i++)
    {
        traverse_graph(root->children[i]);
    }


}

Graph build_graph(char data[], int max_size)
{
   deque<string> d=intoQueue(data,max_size);
   tree t;
   node* m=t.add_child(t.root,d,0);
    traverse_graph(m);
    return g;
}
