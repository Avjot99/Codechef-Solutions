#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, res;
    stack<char> s;
    cin>>str;

    int maxPos[26];
    for(int i=0; i<26; i++)
        maxPos[i] = -1;

    for(int i=str.length()-1; i>=0; --i)
        if(maxPos[str[i] - 'a'] == -1)
            maxPos[str[i] - 'a'] = i;

    int j = 0;
    for(int i=0; i<26; i++)
    {
        if(!s.empty())
        {
            while(!s.empty() && s.top() <= (char)(i+'a'))
            {
                res.push_back(s.top());
                s.pop();
            }
        }

        if(maxPos[i]>=j && maxPos[i]!=-1)
        {
            while(j<=maxPos[i] && j<str.length())
            {
                if(str[j] == (char)(i+'a'))
                    res.push_back(str[j]);
                else
                    s.push(str[j]);
                j++;
            }
        }
    }

    while(!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }

    cout<<res<<endl;
    return 0;
}
