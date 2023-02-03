#include "header.h"


/******************Supporting functions used in the correction and****
******************detection the file's errors************************/

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

bool compare1(string s1,string stk)
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

bool compare2(string str1,string str2)
{
    bool check1=false;
    if(str1.compare(str2)==0)
        check1=true;
    return check1;
}
