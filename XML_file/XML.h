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
    int index;
    string s;
} tag;
stack<tag> errors_miss;
stack<tag> errors_miss1;
stack<tag> errors_wrong_poss;
stack<tag> errors_wrong_poss1;
deque<tag> tags;
deque<tag> temp;
int k=50;

