#include <bits/stdc++.h>
using namespace std;
#define N 1000001

int arr[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, i, j, temp, mx;
        cin>>n;
        for(i=0; i<n; i++)
            cin>>arr[i];
        queue<int> q;

        for(i=n-1; i>=0; i--)
        {
            if(q.empty())
            {
                q.push(arr[i]);
                mx = arr[i];
            }

            else if(arr[i] >= mx)
            {
                q.push(arr[i]);
                mx = arr[i];
            }
            else
            {
                temp = arr[i];
                break;
            }
        }

        if(i<0)
        {
            cout<<-1<<endl;
            continue;
        }

        j = i;
        for(i=i+1; i<=n-1; i++)
        {
            if(!q.empty() && q.front()<=temp)
            {
                arr[i] = q.front();
                q.pop();
            }
            else
            {
                arr[i] = temp;
                arr[j] = q.front();
                q.pop();
                temp = 10;
            }
        }

        for(int i=0; i<n; i++)
            cout<<arr[i];
        cout<<endl;
    }

    return 0;
}
