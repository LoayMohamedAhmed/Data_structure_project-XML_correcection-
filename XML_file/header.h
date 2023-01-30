#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <string.h>
#include <deque>
#include "string.h"

using namespace std;

typedef struct{
    int index_end;
    int index_start;
    string s;
} tag;

int file_size(string path );
void read_file(char data[], string path);
int order(char data[],int i);
string conv_to_string(char characters[],int size1);
bool compare1(string s1,string stk);
void check_errors(char data[],int max_size);
void error_correction(char* data,int size1);
void minifying(char* data, int size1);
void prettifying(char* data,int size1);
