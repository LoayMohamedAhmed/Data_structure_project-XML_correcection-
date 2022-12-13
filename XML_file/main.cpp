#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <string.h>
#include <deque>
//#define max_size 26
//2769
using namespace std;
using namespace std;

int order(char* data,int i)
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
void check_errors(char* data,int max_size)
{
    while(i<max_size)
    {
        if(data[i]=='<')
        {
            int k=i;
            mark++;
            do
            {
                  characters.push(data[k]);
                  k++;

            }
            while(data[k]!='>');
            characters.push(data[k]);
            int size1 = characters.size() - 1;
            char temp_array[size1 + 1];



            for (int j = size1; j >= 0; j--)
            {
                temp_array[j] = characters.top();
                characters.pop();
            }
            T.s = conv_to_string(temp_array, size1 + 1);
            T.index = k;
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

