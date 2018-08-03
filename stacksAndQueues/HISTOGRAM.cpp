#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n, i, tp;
    long long elem, area_with_top, max_area;
    stack<long long> s;

    while(1)
    {
        cin>>n;
        if(n==0)
            break;

        long long hist[n];

        for(i=0; i<n; i++)
            cin>>hist[i];

        i=0;
        max_area = 0;
        while(i<n)
        {
            if(s.empty() || hist[s.top()]<=hist[i])
                s.push(i++);

            else
            {
                tp = s.top();
                s.pop();
                area_with_top = hist[tp]*(s.empty()?i:i-s.top()-1);

                if(max_area<area_with_top)
                    max_area = area_with_top;
            }
        }

        while(!s.empty())
        {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp]*(s.empty()?i:i-s.top()-1);

            if(max_area<area_with_top)
                max_area = area_with_top;
        }

        cout<<max_area<<endl;
    }
    return 0;
}
