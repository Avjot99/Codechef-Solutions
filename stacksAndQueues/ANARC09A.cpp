#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int t = 0;
    while(1)
    {
        cin>>str;
        if(str[0] == '-')
            break;

        t++;
        int cnt = 0, open = 0, close = 0, minOp = 0;

        for(int i=0; i<str.length(); i++)
        {
            if(str[i] == '{')
                cnt++;
            else if(cnt>0)
                cnt--;
            else
                close++;
        }

        open = cnt;
        minOp = open/2 + close/2 + open%2 + close%2;
        cout<<t<<"."<<" "<<minOp<<endl;
    }

    return 0;
}
