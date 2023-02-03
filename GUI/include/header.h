#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <string>
#include <deque>
#include <string.h>
#include "node.h"
#include "tree.h"
#include "Graph.h"
#include <cstdlib>
#include <vector>
#include <QString>
#include <unordered_map>
#include <queue>

using namespace std;


typedef struct{
    int index_end;
    int index_start;
    std::string s;
} tag;

struct MinHeapNode
{
    char data; //For storing data of the input file
    int frequency; //Frequency of the characters of the input fie
    MinHeapNode *left, *right; //Left and right nodes of the minimum heap tree
};


/******************Functions Prototype************************/

bool compare2(string s1, string s2);
int order(string data,int i);
string conv_to_string(char characters[],int size1);
bool compare1(string s1,string stk);
QString check_errors(string data);
QString error_correction(string data);
QString minifying(string data);
QString prettifying(string data);
void compress(MinHeapNode* root, string data,
              unordered_map<char,string> &huffmanCode);
string decompress(MinHeapNode* root, int &index, string file);
string Compress(std::string data);
void XMLCompress(string data);
void XMLDecompress();
deque<string> intoQueue(string data);
QString convert_jason(string data);
void body_traverse(node* root, string s_search);
void traverse3(node* root, string s_search);
vector<string> searchTopic(node* m, string word, bool choice);
void traverse_graph(node * root);
Graph build_graph(string data);





#endif // HEADER_H
