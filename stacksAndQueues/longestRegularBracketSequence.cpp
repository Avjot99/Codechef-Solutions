#include <bits/stdc++.h>
using namespace std;
#define N 1000001

bool valid[N];

int main()
{
    string str;
    cin>>str;
    stack<int> s;

    for(int i=0; i<str.length(); ++i)
        valid[i] = true;
    for(int i=0; i<str.length(); ++i)
    {
        if(str[i]=='(')
            s.push(i);
        else if(s.empty())
            valid[i] = false;
        else
            s.pop();
    }

    while(!s.empty())
    {
        valid[s.top()] = false;
        s.pop();
    }

    int maxLen=0, numStrings=1, i=0, len=0;
    while(i<str.length())
    {
        if(!valid[i])
        {
            i++;
            continue;
        }

        while(valid[i])
        {
            len++;
            i++;
        }

        if(len>maxLen)
            numStrings = 1;
        else if(len==maxLen)
            numStrings++;

        maxLen = max(len, maxLen);
        len = 0;
    }

    cout<<maxLen<<" "<<numStrings<<endl;
    return 0;
}

