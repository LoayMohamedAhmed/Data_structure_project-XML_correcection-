#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <string.h>
#include <deque>
//#define max_size 26
//2769
using namespace std;
int mark=0;
stack<char> characters;
//stack<tag> tags;
typedef struct{
    int index_end;
    int index_start;
    string s;
} tag;
stack<tag> errors_miss_tag;
stack<tag> errors_miss_tag1;
stack<tag> errors_miss_br;
deque<tag> tags;
deque<tag> maybe;
deque<tag> temp;
int k=50;

