#include "header.h"

deque<string>t_search_b;
deque<string>t_search_n;
deque<string>final_search;
string s_search;

void traverse3(node* root)
{
    if(root->data == "<name>")
    {
        t_search_n.push_front(root->children[0]->data);

    }

    if(root->data =="<body>")
    {

        t_search_b.push_front(root->children[0]->data);
    }

    if(root->data=="<topic>")
    {
         root->children[0]->data.erase(root->children[0]->data.begin());
         if(compare2(root->children[0]->data,s_search))
         {
            final_search.push_front(t_search_n.front());
            final_search.push_front(t_search_b.front());
         }
    }

     if(!root)
    {
        return;
    }
    for(int i=0; i<root->child_num; i++)
    {
       traverse3(root->children[i]);
    }
}

 vector<string> searchTopic(string word)
{
    int size1=file_size("test.txt");
    char data2[size1];
    read_file(data2, "test.txt");
    deque<string> a=intoQueue(data2,size1);
    tree t;
    node* m=t.add_child(t.root,a,0);
    s_search=word;
    vector<string> vec_search;
    traverse3(m);
    int size_q=final_search.size();
    for(int i=0;i<size_q;i++)
    {
        vec_search.push_back(final_search.back());
        final_search.pop_back();
    }
    return vec_search;
}
