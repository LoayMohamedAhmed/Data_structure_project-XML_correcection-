#include "header.h"


/******************Error correction and detection functions************************/




std::stack<char> characters;
std::stack<tag> errors_miss_tag;
std::stack<tag> errors_miss_tag1;
std::stack<tag> errors_miss_br;
std::stack<tag> errors_miss_br1;
std::deque<tag> tags;
std::deque<tag> maybe;
std::deque<tag> temp;
tag wanted;

//




QString check_errors(string data)
{
    int mark = 0;
    int k;
    string message;
    int i =0;
    tag T;

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
                while(data[k]!='>' && data[k+1]!='<');
                characters.push(data[k]);
                int size1=characters.size()-1;
                char temp_array[size1+1];

                for(int j=size1;j>=0;j--)
                {
                    temp_array[j]=characters.top();
                    characters.pop();
                }
                T.s=conv_to_string(temp_array,size1+1);
                T.index_end=k;
                T.index_start=k-(T.s.length()-1);

                if (mark==1)
                {
                    tags.push_front(T);
                }

                if(!tags.empty()&& mark!=1)
                {
                    if(T.s[T.s.length()-1]=='>')
                    {
                            if(compare1(T.s,tags.front().s))
                            {
                                tags.pop_front();
                            }
                            else
                            {
                                tags.push_front(T);
                            }

                    }
                    else
                        errors_miss_br.push(T);


                }
                i=k;

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
                if(tags.front().s[1]!='/')
                {
                    errors_miss_tag.push(tags.front());
                    tags.pop_front();
                }
                if(compare1(tags.front().s,tags.back().s)&& !tags.empty())
                {

                    maybe.push_front(tags.front());
                    temp.push_front(tags.front());
                    tags.pop_front();
                    while(tags.size()!=1)
                    {
                        if(compare1(tags.front().s, tags.back().s))
                        {
                            maybe.push_front(tags.front());
                            temp.push_front(tags.front());
                            tags.pop_front();
                        }
                        else
                        {
                            temp.push_front(tags.front());
                            tags.pop_front();
                        }

                    }
                    tags.pop_back();
                    wanted=maybe.front();
                    while(maybe.size()!=0)
                    {
                        maybe.pop_front();
                    }
                    while(temp.size()!=0)
                    {
                        if(temp.front().index_end!=wanted.index_end)
                        {
                            tags.push_front(temp.front());
                            temp.pop_front();

                        }else temp.pop_front();
                    }

                }
                else
                {
                    if(tags.empty())
                        break;
                    errors_miss_tag.push(tags.back());
                    tags.pop_back();

                }

            }

            while(!errors_miss_tag.empty())
            {
                errors_miss_tag1.push(errors_miss_tag.top());
                int num =order(data,errors_miss_tag.top().index_end)+1;
                message +="You have an error in line " + to_string(num) + " at tag (" +errors_miss_tag.top().s+")\n";
                errors_miss_tag.pop();
            }

            while(!errors_miss_br.empty())
            {
                errors_miss_br1.push(errors_miss_br.top());
                int num =order(data,errors_miss_br.top().index_end)+1;
                message += "You have an error in line " + to_string(num) + " at tag (" + errors_miss_br.top().s +")\n";
                errors_miss_br.pop();
            }

        }
        tags.clear();
        temp.clear();
        maybe.clear();
        return QString::fromStdString(message);
}


QString error_correction(string data)
{

    deque<char> l;
    tag temp_tag;
    int flag=0;
    int j=0;
    unsigned long long int index;
    string corrected_text;

    while(!errors_miss_tag1.empty())
    {
        if(errors_miss_tag1.top().s[1]=='/')
        {
            int end1=temp_tag.index_end;
            if(flag!=0)
            {
                j=end1+1;
            }
            string word= errors_miss_tag1.top().s;
            word.erase(word.begin()+1);
            int i=errors_miss_tag1.top().index_start-1;
            while(data[i]!='>')
            {
                i--;
            }
            for(;j<=i;j++)
            {
                l.push_back(data[j]);
            }
            int o=i;
            for(int k=0;k<word.size();k++)
            {
                l.push_back(word[k]);
            }
            for(i+=1;i<=errors_miss_tag1.top().index_end;i++)
            {
                l.push_back(data[i]);
            }
            index=i;
        }


        if(flag!=0)
        {
            for(;index<=errors_miss_tag1.top().index_end;index++)
                l.push_back(data[index]);

        }




        if(errors_miss_tag1.top().s[1]!='/')
        {
            if(flag==0)
            {
                for(int o=0;o<=errors_miss_tag1.top().index_end;o++)
                {
                    l.push_back(data[o]);
                }
            }
            int i2=errors_miss_tag1.top().index_end+1;
            int j2=errors_miss_tag1.top().index_end+1;
            string word = errors_miss_tag1.top().s;
            word.insert(1,"/");
            while(data[i2]!='<')
            {
                i2++;
            }
            for(;j2<i2;j2++)
            {
                l.push_back(data[j2]);
            }

            for(int k=0;k < word.size();k++)
            {
                l.push_back(word[k]);
            }
            index=i2;
        }
        flag=1;
        temp_tag=errors_miss_tag1.top();
        errors_miss_tag1.pop();

    }

    while(!l.empty())
    {
        corrected_text+= l.front();
        l.pop_front();
    }
    for(;index < (data.size())-1;index++)
        corrected_text+= data[index];
    return QString::fromStdString(corrected_text);

}
