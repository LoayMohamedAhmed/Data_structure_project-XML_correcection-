#include "header.h"

void minifying(char* data, int size1)
{
	ofstream file2 ("mini.txt");
	deque <char> q;
    int flag =0;
	int n=0;
	long long count1=0;
	while(n<size1-2)
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
       /* if((data[n]==' ' && data[n+1]=='<'))
        {
            continue;
        }*/
        if(data[n]==' ' && data[n+1]=='<')
        {
            continue;
            // if(q.back()=='>')
             //  continue;
        }
        if(data[n]==' ' && (q.back()=='>'))
        {
            continue;
        }
        else
		{
                q.push_back(data[n]);
		}

       // while(data[n]=='>' && data[n+1]==' ')
       // {
         //   q.push_back(data[n]);
         //   n++;
         //   continue;
      //  }

	}
	 while(!q.empty())
	 {
	     //cout<<"renal";
		 file2<<q.front();
		 q.pop_front();
	 }
	file2.close();
    cout<<"end";
}
