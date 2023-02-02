
#include "tree.h"
#include "node.h"

deque<string> data_update;
bool compare(string s1,string stk)
{
    bool check=false;
    if (s1[1]=='/')
    {
        s1.erase(s1.begin()+1);
        if(s1.compare(stk)==0)
            check=true;
    }
    return check;
}
bool tree::is_empty1()
{
    if(this->root==NULL)
        return true;
    else
        return false;
}

tree::tree()
{
    this->root=NULL;
}

node *tree::add_child(node *root1,deque<string>data, int no_siblings)
{

    //cout<<"data: "<<data.front()<<endl;
  // cout<<"data: "<<data.front()<<endl;
    while(data.front()[1]=='/')
    {
        data.pop_front();
    }

    root1=new node(data.front());
    //cout<<root1->data<<endl;
    int count1=0;

    string X= data.front();
    data.pop_front();

    if(data.front()[1]=='/')
    {
        //cout<<"BASE"<<endl;
        data_update=data;
        return root1;

    }

    deque<string>temp=data;
    string Y=temp.front();
    while(!compare(temp.front(),X))
    {
        temp.pop_front();
        if(Y[0]!='<')
        {
            count1+=1;
        }
        if(compare(temp.front(),Y))
        {
            count1+=1;
            temp.pop_front();
            Y=temp.front();
        }
    }
//    cout<<"temp: "<<temp.front()<<endl;
//    cout<<"num"<<count1<<endl;
    root1->child_num=count1;
    root1->num_siblings=no_siblings;

    for(int i=0;i<count1;i++)
    {

        root1->children[i]=add_child(root1->children[i],data,count1);
        data=data_update;
        root1->children[i]->id=i+1;
    }

    return root1;

}
void tree::print(node*root1)
{
    std::cout<<root1->data<<"\t"<<root1->id<<"no_sib"<<root1->num_siblings<<endl;
    //std::cout<<"no_sib"<<root1->num_siblings<<endl;

    if(!root1)
        return;
    for(int i=0;i<root1->child_num;i++)
        print(root1->children[i]);
}

tree::~tree()
{
   delete root;
}

