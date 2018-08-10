#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long a, res=-1, tp;
    stack<long> s;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>a;
        if(s.empty())
            s.push(a);
        else if(s.top() > a)
            s.push(a);
        else
        {
            while(s.top() < a)
            {
                if(res == -1)
                    res = s.top() ^ a;
                else
                    res = max(s.top() ^ a, res);
                s.pop();
            }
            s.push(a);
        }
    }

    while(!s.empty())
    {
        tp = s.top();
        s.pop();
        if(!s.empty())
        {
            if(res == -1)
                res = s.top() ^ tp;
            else
                res = max(s.top() ^ tp, res);
        }
    }

    cout<<res<<endl;
    return 0;
}
