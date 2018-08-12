#include <iostream>
using namespace std;

inline int getMinLength(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 2;
    if(n%2==1)
        return n + 1 + 2*getMinLength((n-1)/2);
    else
        return n + 1 + getMinLength(n/2) + getMinLength(n/2 - 1);
}

int main()
{
    int t, n, m, minLength, maxLength;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        minLength = getMinLength(n);
        maxLength = n*(n+3)/2;
        if(m < minLength)
            cout<<-1<<endl;
        else if(m > maxLength)
            cout<<m-maxLength<<endl;
        else
            cout<<0<<endl;
    }

    return 0;
}
