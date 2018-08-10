#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;

    stack<char> s;
    for(int i=0; i<str.length(); i++)
    {
        if(s.empty())
            s.push(str[i]);
        else if(s.top() != str[i])
            s.push(str[i]);
        else
            s.pop();
    }

    if(!s.empty())
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;

    return 0;
}
