#include <bits/stdc++.h>
using namespace std;

int main()
{
    int temp;
    string str;
    stack<int> s;
    cin>>str;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == 'C')
            s.push(12);
        else if(str[i] == 'H')
            s.push(1);
        else if(str[i] == 'O')
            s.push(16);
        else if(str[i]>='2' && str[i]<='9')
        {
            temp = s.top();
            s.pop();
            s.push(temp * (str[i] - '0'));
        }
        else if(str[i] == '(')
            s.push(-1);
        else
        {
            temp = 0;
            while(s.top() != -1)
            {
                temp += s.top();
                s.pop();
            }
            s.pop();
            s.push(temp);
        }
    }

    temp = 0;
    while(!s.empty())
    {
        temp += s.top();
        s.pop();
    }

    cout<<temp<<endl;
    return 0;
}
