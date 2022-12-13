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
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
