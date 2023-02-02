#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <unordered_map>
#include <deque>
#include "string"
#include <iostream>
#include "Graph.h"
#include <vector>
using namespace std;


class Graph
{

    public:
        Graph();
        virtual ~Graph();
        unordered_map<int,list<int>>l;  //
        unordered_map<int,list<int>>following;//first follows the list
        unordered_map<int, string> users;
        string influencer();
        string mostActive(); //follows alot
        int searchName(string n);
        string searchID(int id); //id1 is ahmed for example
        void addEdge(int user,int flr);//user and its followers
        void addUserID(int id,string name);
        void printAdjList(); //print l
        void printflrList(); //print following
        deque<string> common(string u1,string u2);
        deque<string> suggest(string user);


    protected:

    private:

};

#endif // GRAPH_H
