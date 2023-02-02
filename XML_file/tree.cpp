#include "../include/tree.h"
#include "../include/node.h"

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

node *tree::add_child(node *root1,deque<string>data)
{

//    if(is_empty1())
//        this->root=new node(data.front());
    cout<<"data: "<<data.front()<<endl;
    while(data.front()[1]=='/')
    {
        data.pop_front();
    }

    root1=new node(data.front());
    cout<<root1->data<<endl;
    int count1=0;

    string X= data.front();
    data.pop_front();

    if(data.front()[1]=='/')
    {
        cout<<"BASE"<<endl;
        data_update=data;
        return root1;

    }

    deque<string>temp=data;
    string Y=temp.front();
    while(!compare(temp.front(),X))
    {
        temp.pop_front();
        if(compare(temp.front(),Y))
        {
            count1+=1;
            temp.pop_front();
            Y=temp.front();
        }
    }
    cout<<"temp: "<<temp.front()<<endl;
    cout<<count1<<endl;
    root1->child_num=count1;

    for(int i=0;i<count1;i++)
    {
        root1->children[i]=add_child(root1->children[i],data);
        data=data_update;

    }

    return root1;

}
void tree::print(node*root1)
{
    std::cout<<root1->data<<"\t"<<root1->child_num<<endl;
    if(!root1)
        return;
    for(int i=0;i<root1->child_num;i++)
        print(root1->children[i]);
}

tree::~tree()
{
   delete root;
}
