
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <string>
#include <deque>
#include "string.h"
#include "node.h"
#include "tree.h"
#include "Graph.h"
#include <cstdlib>
#include <vector>
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

int file_size(string path );
void read_file(char data[], string path);
int order(char data[],int i);
string conv_to_string(char characters[],int size1);
bool compare1(string s1,string stk);
void check_errors(char data[],int max_size);
void error_correction(char* data,int size1);
void minifying(char* data, int size1);
void prettifying(char* data,int size1);
deque<string> intoQueue(char data[],int max_size);
void convert_jason(char data[],int max_size);
Graph build_graph(char data[], int max_size);
vector<string> bodySearch(node *node);
vector<string> searchTopic(string word, bool choice);
bool compare2(string s1, string s2);
void XMLCompress(char[] data, int max_size);
void XMLDecompress(char data[], int max_size);

