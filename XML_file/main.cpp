#include "header.h"

int main()
{
    int size1=file_size("test.txt");
    char data[size1];
    cout<<size1<<endl;
    read_file(data, "test.txt");


    check_errors(data,size1);
    error_correction(data,size1);
    minifying(data,size1);
    prettifying(data,size1);
   convert_jason(data,size1);

    vector<string> res=searchTopic("economy");
    for(int i=0;i<res.size();i++)
    {
       cout<<res[i]<<endl;
    }
}
