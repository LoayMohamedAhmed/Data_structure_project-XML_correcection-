#include "header.h"


QString prettifying(string data)
{

    int i=0;
    int check=1; //the previous is opening check =1, if closing check =0.
    int flag=0;
    int countspace=0;
    deque <char> l;
    string prettified;

    while(i<data.size()-1)
    {
        if (flag !=0)
        {
            if(data[i+1]=='/')
            {
                if(check==0)
                {
                    countspace--;
                }
                check=0;
            }
            else
            {
                if(check==1)
                {
                    countspace++;
                }
                check=1;
            }
            if( (data[i+1]=='/' && data[i-1]=='\n' ) || data[i+1]!='/')
            {
                for(int j=0;j<countspace*4;j++)
                {
                    l.push_back(' ');
                }
            }
        }

        l.push_back(data[i]);

        i++;
        while(data[i]!='<'&& i<data.size()-1 )
        {
            if(data[i-1]=='\n'&&data[i-2]=='>'&&data[i]!='<')
            {
                countspace++;
                for(int j=0;j<countspace*4;j++)
                {
                    l.push_back(' ');
                }
                countspace--;
            }

            l.push_back(data[i]);
            i++;
        }
        flag=1;

    }

    while(!l.empty())
    {
        //cout<<l.front();
        prettified+= l.front();
        l.pop_front();

    }
    return QString::fromStdString(prettified);

}
