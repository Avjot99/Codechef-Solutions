#include <bits/stdc++.h>
using namespace std;

inline int maxLenPrefix(string str)
{
    int cnt = 0, maxLen = 0;
    for(int i=0; i<str.length(); ++i)
    {
        if(str[i] == '<')
            cnt++;
        else
            cnt--;

        if(cnt == 0)
            maxLen = i+1;
        else if(cnt<0)
            break;
    }

    return maxLen;
}

int main()
{
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        cout<<maxLenPrefix(str)<<endl;
    }

    return 0;
}
