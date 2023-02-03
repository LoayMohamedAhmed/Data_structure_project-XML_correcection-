#include "header.h"
//string word;
deque<string>t_search_b;
deque<string>t_search_n;
deque<string>final_search;


//---------------------------------------------------------
void body_traverse(node* root, string s_search)
{
    if(root->data == "<name>")
    {
        t_search_n.push_front(root->children[0]->data);
    }

    if(root->data =="<body>")
    {
        if(root->children[0]->data.find(s_search)< root->children[0]->data.size())
        {
            final_search.push_front(t_search_n.front());
            final_search.push_front(root->children[0]->data);
        }

    }

    if(!root)
    {
        return;
    }

    for(int i=0; i<root->child_num; i++)
    {
        body_traverse(root->children[i], s_search);
    }
}


void traverse3(node* root, string s_search)
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
       traverse3(root->children[i], s_search);
    }
}

vector<string> searchTopic(node* m, string word, bool choice)
{
    vector<string> vec_search;
    //s_search=word;

    if(choice)       //topic
    {
        traverse3(m, word);
        int size_q=final_search.size();
        for(int i=0;i<size_q;i++)
        {
            vec_search.push_back(final_search.back());
            final_search.pop_back();
        }
    }
    else                //body
    {
         body_traverse(m, word);
         int size_q=final_search.size();
         for(int i=0;i<size_q;i++)
         {
             vec_search.push_back(final_search.back());
             final_search.pop_back();
         }

    }


    return vec_search;
}
