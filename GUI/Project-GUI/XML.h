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

int previous = 0;     //For storing the previous stack page
int max_size=0;     //For storing the size of the input file
QString filename;   //For storing the path in the path
QString text;      //For storing the content of the file in QString
string q;


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

QString check_errors(string data)
{

    stack<char> characters;
    stack<tag> errors_miss;
    stack<tag> errors_miss1;
    stack<tag> errors_wrong_poss;
    stack<tag> errors_wrong_poss1;
    stack<string> reverse_msg;
    deque<tag> tags;
    deque<tag> temp;
    string message;
    int i =0;
    tag T;
    int mark = 0;
    int k = 50;

    while(i<data.size())
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
            if (mark==1)
            {
                tags.push_front(T);
            }

            if (!tags.empty() && mark != 1)
            {
                if (compare1(T.s, tags.front().s))
                {

                    tags.pop_front();
                }
                else
                {
                    tags.push_front(T);
                }
            }
            i = k;
        }
        i++;
    }
    if(tags.empty())
    {

        message+="No errors found,the file is under control :)";

    }
    else
    {

        while(!tags.empty())
        {
            if(compare1(tags.front().s,tags.back().s))
            {
                tags.pop_front();
                tags.pop_back();
            }
            else
            {
                while(!tags.empty())
                {
                    if(compare1(tags.front().s,tags.back().s))
                    {
                       errors_wrong_poss.push(tags.back());
                       errors_wrong_poss.push(tags.front());
                       tags.pop_front();
                       tags.pop_back();
                       break;
                    }
                    else
                    {
                        if (tags.size() == 1)
                        {
                            errors_miss.push(tags.front());
                            tags.pop_front();
                            break;
                        }
                        temp.push_front(tags.front());
                        tags.pop_front();
                    }
                }
                while(!temp.empty())
                {

                    tags.push_front(temp.front());
                    temp.pop_front();
                }
            }
        }


        while(!errors_miss.empty())
        {

            errors_miss1.push(errors_miss.top());
            int num =order(data,errors_miss.top().index)+1;
            reverse_msg.push("You have an error in line " + to_string(num) + " at tag (" + errors_miss.top().s+")\n");
            errors_miss.pop();

        }

        while (!errors_wrong_poss.empty())
        {

            errors_wrong_poss1.push(errors_wrong_poss.top());
            int num = order(data, errors_wrong_poss.top().index) + 1;
            reverse_msg.push("You have an error in line " + to_string(num) + " at tag (" + errors_wrong_poss.top().s +")\n");
            errors_wrong_poss.pop();
        }


    }
    while(!reverse_msg.empty()){
        message += reverse_msg.top();
        reverse_msg.pop();
    }


    return QString::fromStdString(message);
}







#endif // XML_H
