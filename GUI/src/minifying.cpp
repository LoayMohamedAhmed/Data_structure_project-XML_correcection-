#include "header.h"


/******************Minifying the file************************/


QString minifying(string data)
{

    deque <char> q;
    int flag =0;
    int n=0;
    long long count1=0;
    string minified_text;


    while(n<data.size()-2)
    {
        if(flag!=0)
        {
            n++;
        }
        flag=1;
        if(data[n]=='\n' || (data[n]==' ' && data[n+1]==' '))
        {
            continue;
        }
        if(data[n]==' ' && data[n+1]=='<')
        {
            continue;
        }
        if(data[n]==' ' && (q.back()=='>'))
        {
            continue;
        }
        else
        {
            q.push_back(data[n]);
        }

    }
     while(!q.empty())
     {

         minified_text+=q.front(); //Storing the minified text
         q.pop_front();
     }

    return QString::fromStdString(minified_text);
}
