#include "header.h"


int main()
{
     int file_size=0;
    fstream file("test.txt");
    if(file.is_open())
    {
        while(file)

        {
            char c=file.get();
            file_size++;
        }


    }
    fstream file1("test.txt");
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
    error_correction(data,file_size);
    minifying(data,file_size);
    prettifying(data,file_size);
}
