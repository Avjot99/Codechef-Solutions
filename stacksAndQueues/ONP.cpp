#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> m;
    m.insert(pair<char, int>('+', 1));
    m.insert(pair<char, int>('-', 2));
    m.insert(pair<char, int>('*', 3));
    m.insert(pair<char, int>('/', 4));
    m.insert(pair<char, int>('^', 5));
    m.insert(pair<char, int>('(', 0));

    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        stack<char> s;
        string res;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]>='a' && str[i]<='z')
                res.push_back(str[i]);
            else if(s.empty())
                s.push(str[i]);
            else
            {
                if(str[i]=='(')
                   s.push(str[i]);
                else if(str[i]==')')
                {
                    while(s.top()!='(')
                    {
                        res.push_back(s.top());
                        s.pop();
                    }
                    s.pop();
                }
                else
                {
                    if(m[s.top()] < m[str[i]])
                        s.push(str[i]);
                    else
                        res.push_back(str[i]);
                }
            }
        }

        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        cout<<res<<endl;
    }
    return 0;
}
