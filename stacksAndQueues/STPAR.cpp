#include <bits/stdc++.h>
using namespace std;
#define N 1001

int arr[N];
bool isPresent[N];

inline bool possible(int n)
{
    int required = 1;
    int j=0;
    bool poss = true;
    stack<int> s;

    while(required <= n)
    {
        if(!s.empty() && s.top() == required)
        {
            s.pop();
            required++;
        }

        else
        {
            if(isPresent[required])
            {
                while(arr[j] != required && j<n)
                {
                    isPresent[arr[j]] = false;
                    s.push(arr[j++]);
                }

                j++;
                required++;
            }

            else
            {
                poss = false;
                break;
            }
        }
    }

    return poss;
}

int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            isPresent[arr[i]] = true;
        }

        if(possible(n))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
