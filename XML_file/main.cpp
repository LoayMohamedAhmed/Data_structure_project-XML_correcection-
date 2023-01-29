#include "XML.h"
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
    int i =0;
    tag T;
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
            T.index_end = k;
            T.index_start=k-(T.s.length()-1);
            if (mark==1)
            {
                tags.push_front(T);
            }

            if (!tags.empty() && mark != 1)
            {
               if(T.s[T.s.length()-1]=='>']
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
               else
                  errors_miss_br.push(T):
            }
            i = k;
        }
        i++;
    }
    if(tags.empty())
    {
        cout<<"all is well god save the king";
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
            cout<<"you have an error in line "<<num<<"at tag ("<<errors_miss_tag.top().s<<")"<<endl;
            errors_miss_tag.pop();
        }

        while(!errors_miss_br.empty())
        {
            errors_miss_br1.push(errors_miss_br.top());
            int num =order(data,errors_miss_br.top().index_end)+1;
            cout<<"you have an error in line "<<num<<"at tag ("<<errors_miss_br.top().s<<")"<<endl;
            errors_miss_br.pop();
        }

    }
    tags.clear();
    temp.clear();
    maybe.clear();
 cout<<endl;
}

int main()
{
   int file_size=0;
    fstream file("test1.txt");
    if(file.is_open())
    {
        while(file)
        {
            char c=file.get();
            file_size++;
        }


    }
    //cout<<file_size;
    fstream file1("test1.txt");
    char data[file_size];
    int i=0;
    if(file1.is_open())
    {
        while(file1)
        {
            data[i]=file1.get();
            i++;
        }

    }

    check_errors(data,file_size);
    return 0;
}

