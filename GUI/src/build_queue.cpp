#include "header.h"

deque<string>tags1;
stack<char> characters1;


deque<string> intoQueue(string data)
{
    int i =0;
    string S;
    while(i<data.size())
    {
        if(data[i]=='<')
        {
            int k=i;

            do
            {
                characters1.push(data[k]);
                k++;

            }
            while(data[k]!='>' && data[k+1]!='<');
            characters1.push(data[k]);
            int size1=characters1.size()-1;
            char temp_array[size1+1];

            for(int j=size1;j>=0;j--)
            {
                temp_array[j]=characters1.top();
                characters1.pop();
            }
            S=conv_to_string(temp_array,size1+1);
            tags1.push_back(S);

            i=k;
        }
        else
        {
            while(data[i]!='<' && i<data.size())
            {
                if((data[i]==' '&& data[i+1]==' ') || (data[i]==' ' && data[i+1]=='<') || data[i]=='\n')
                {

                }
                else
                    characters1.push(data[i]);
                i++;
            }
            i--;
            int size2=characters1.size()-1;

                if(size2>0)
                {
                    char temp_array[size2+1];

                    for(int j=size2;j>=0;j--)
                    {
                        temp_array[j]=characters1.top();
                        characters1.pop();
                    }
                    S=conv_to_string(temp_array,size2+1);
                    tags1.push_back(S);
                }
                else if(size2==0 && data[i]!=' ')
                {
                    char temp_array[1];
                    temp_array[0]=characters1.top();
                    characters1.pop();
                    S=conv_to_string(temp_array,size2+1);
                    tags1.push_back(S);
                }


        }
        i++;

    }
    return tags1;
}
