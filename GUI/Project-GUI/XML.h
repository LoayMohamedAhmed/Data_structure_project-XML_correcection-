#ifndef XML_H
#define XML_H
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <string.h>
#include <deque>
#include <QString>

using namespace std;

typedef struct{
    int index;
    string s;
} tag;

int order(string data,int i)
{
    int count1=0;
    int j=0;
    while(j<i)
    {
        if(data[j]=='\n')
            count1++;
        j++;
    }
    return count1;
}



string conv_to_string(char characters[],int size1)
{
    string s="";
    for(int i=0;i<size1;i++)
    {
        s+=characters[i];
    }
    return s;
}

bool compare1(string s1, string stk)
{
    bool check = false;
    if (s1[1] == '/')
    {
        s1.erase(s1.begin() + 1);
        if (s1.compare(stk) == 0)
            check = true;
    }
    return check;
}



#endif // XML_H
