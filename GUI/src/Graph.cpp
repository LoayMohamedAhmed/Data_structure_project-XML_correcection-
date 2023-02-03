#include "Graph.h"
#include "header.h"

Graph::Graph()
{

}

Graph::~Graph()
{
    //dtor
}
void Graph:: addEdge(int user,int flr)
{
    l[user].push_back({flr});
    following[flr].push_back({user});
}
void Graph:: addUserID(int id,string name)
{
    if(users.size()==0)
    {
        users.insert(pair<int,string>(id,name));
    }
    else{
        for(auto i:users)
        {

            if(i.first==id)
                return;
            else
            {
                users.insert(pair<int,string>(id,name));
            }
        }
    }
}
QString Graph:: searchID(int id)
{
    bool flag;  // true if found
    for(auto i:users)
    {
        if(i.first==id)
        {
            flag=true;
            return QString::fromStdString(i.second);
        }
        else
            flag=false;
    }
    if(!flag)
        return QString::fromStdString("Not found");

}
int Graph:: searchName(string n)
{
    for(auto i:users)
    {
        if(!n.compare(i.second))
            return i.first;
    }

}
void Graph::printAdjList() //user and poeple who follow him
{
    for(auto x:l)
    {
        cout<<endl<<x.first<<"->";
        list<int> lista=x.second;
        for(auto lis:lista)
        {
            cout<<lis<<", ";
        }
    }
    cout<<endl;
}
void Graph::printflrList() //user and people he FOLLOWS
{
    for(auto x:following)
    {
        cout<<endl<<x.first<<"->";
        list<int> lista=x.second;
        for(auto lis:lista)
        {
            cout<<lis<<", ";
        }
    }
    cout<<endl;
}
QString Graph:: mostActive()
{
    int active;
    int count1=0;
    for(auto x:following)
    {
        int count2=0;
        count2=x.second.size();
        if(count2>count1)
        {
            active=x.first;
            count1=count2;
        }
    }
    return searchID(active);
}
QString Graph:: influencer()
{
    int person;
    int count1=0;
    for(auto x:l)
    {
        int count2=0;
        count2=x.second.size();
        if(count2>count1)
        {
            person=x.first;
            count1=count2;
        }
    }
    return searchID(person);
}

deque<string> Graph:: common(string u1,string u2)
{
    int id1=searchName(u1);
    int id2=searchName(u2);
    deque<int> f1;
    deque<int> f2;
    deque<int> temp;
    deque<string> res;
    for (auto u:l)
    {
        if(u.first==id1)
        {
            list<int> lista=u.second;
            for(auto lis:lista)
            {
                f1.push_front(lis);

            }
        }
        if(u.first==id2)
        {
            list<int> lista=l.at(id2);
            for(auto lis:lista)
            {
                f2.push_front(lis);

            }
        }
    }
////o(n)but if input name is wrong programm crashes
//    list<int> lista=l.at(id1);
//    for(auto lis:lista)
//        {
//            f1.push_front(lis);
//        }
//    list<int> lista2=l.at(id2);
//    for(auto lis:lista2)
//        {
//            f2.push_front(lis);
//        }

    int s1=f1.size();
    int s2=f2.size();
    for(int i=0;i<s1;i++)
    {
        temp=f2;
        for(int j=0;j<s2;j++)
        {
            if(f1.front()==temp.front())
            {
                string name=searchID(f1.front()).toStdString();
                //cout<<name<<", ";
                res.push_front(name);
            }
            temp.pop_front();
        }
        f1.pop_front();
    }
    return res;
}

deque<string> Graph:: suggest(string user)
{
    deque<int> fol; //followers of the first user
    deque<string> suggs;
    int id=searchName(user);
    list<int> lista=l.at(id);
    for(auto lis:lista)
        {
            fol.push_front(lis);
        }
    int sz=fol.size();
    for(int i=0;i<sz;i++)
    {
        for (auto u:l)
        {
            if(u.first==fol.front())
            {
                list<int> lista=u.second;
                for(auto lis:lista)
                {
                    if(lis!=id)
                        suggs.push_front(searchID(lis).toStdString());
                }
            }
        }
        fol.pop_front();
    }


    return suggs;
}
