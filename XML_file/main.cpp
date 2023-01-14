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
        cout<<"all is well god save the king";
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
            cout<<"you have an error in line "<<num<<"at tag ("<<errors_miss.top().s<<")"<<endl;
            errors_miss.pop();
        }
        while (!errors_wrong_poss.empty())
        {
            errors_wrong_poss1.push(errors_wrong_poss.top());
            int num = order(data, errors_wrong_poss.top().index) + 1;
            cout << "you have an error in line " << num << "at tag (" << errors_wrong_poss.top().s << ")" << endl;
            errors_wrong_poss.pop();
        }
    }
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

