#include "header.h"


deque <string> jason;
bool static flag4;
deque <bool> f;


void identation(int level)
{
    for(int j=0;j<level;j++)
    {
        jason.push_front("\t");
    }
}



string edit(string s)
{
  if(s[0]=='<')
  {
    //s[0]=='"';
    //s[s.length()-1]=='"';
    s.erase(s.begin());
    s.erase(s.begin()+(s.length()-1));
    s.insert(0,"\"");
    s.insert(s.length(),"\"");
  }
  else
  {
    s.insert(0,"\"");
    s.insert(s.length(),"\"");
  }

 return s;

}

void traverse(node *root, int level)
{

    cout<<flag4<<endl;
    cout<<root->data<<endl;
    //bool var=flag;
    if(root->data[0] == '<')
    {
        jason.push_front("\n");
        identation(level);
    }

    string s1= edit(root->data);
    if(flag4  && root->id > 1)
    {
       //jason.push_front(s1);
    }
    else
        jason.push_front(s1);


    if(root->children[0] != NULL && !(flag4  && root->id > 1))
    {
        jason.push_front(":");
        jason.push_front(" ");
    }
    else
    {
        jason.push_front(",");
    }

    if((!flag4) && root->child_num > 0)
    {
        if(root->children[0]->data[0] == '<')
            jason.push_front("{");
    }
    if(flag4 && root->child_num >0)
    {
        if(root->id==1)
        {
            jason.push_front("[");
            jason.push_front("\n");
            identation(level);
            if(root->children[0]->data[0]== '<' )
                jason.push_front("{");
        }
        if(root->id !=1 && root->children[0]->data[0]== '<')
        {
            jason.push_front("{");
        }
    }

    if(root->child_num > 1)
    {
        if(compare2(root->children[0]->data, root->children[1]->data))
           flag4=true;
        else
            flag4=false;
    }
    else
        flag4=false;

    f.push_front(flag4);


    if(root->children[0]== NULL)
    {
      return;
    }

    for(int i=0;i<root->child_num;i++)
    {

        flag4=f.front();
        f.pop_front();
        traverse(root->children[i],level+1);


        if(flag4)
        {
            cout<<root->data<<endl;
            if(root->id == root->num_siblings)
            {
                jason.push_front("\n");
                identation(level);
                if(root->children[0]->data[0] == '<')
                    jason.push_front("}");
                jason.push_front("\n");
                identation(level);
                jason.push_front("]");
            }
            else if(root->children[0]->data[0]!= '<' )
            {

            }
            else
            {
                jason.push_front("\n");
                identation(level);
                jason.push_front("}");
            }
        }
//        else if((!var ) && root->num_siblings >1 && root->child_num>1)
//        {
//            jason.push_front("\n");
//            identation(level);
//            jason.push_front("}");
//        }

    }



}


QString convert_jason(string data)
{
    string jasonStr = "";
   //ofstream file_j("jason_converter.txt");
   deque <string> result=intoQueue(data);
   tree t;
   node* n=t.add_child(t.root,result,0);

   jason.push_front("{");
   //cout<<"enter"<<endl;
   traverse(n,1);
   //cout<<"exit";
   jason.push_front("\n");
   jason.push_front("}");
   int g=jason.size();
//    while(!jason.empty())
//    {
//        for(int k=0;k<jason.back().length();k++)
//        {
//            file_j<<jason.back();
//            cout<<"file"<<endl;
//        }
//        jason.pop_back();
//    }
    for(int h=0;h<g;h++)
    {
        //cout<<jason.back();
        jasonStr+= jason.back();
        jason.pop_back();
    }

    return QString::fromStdString(jasonStr);

}
