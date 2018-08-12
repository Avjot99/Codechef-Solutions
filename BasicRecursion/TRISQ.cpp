#include <iostream>
using namespace std;

inline int minSquares(int b)
{
    if(b%4==0)
        return b*(b-2)/8;
    else if(b<4)
        return 0;
    else
    {
        return minSquares(b - b%4) + ((b%4 >= 2)?(b - b%4)/2:0);
    }

}

int main()
{
    int t, b;
    cin>>t;
    while(t--)
    {
        cin>>b;
        cout<<minSquares(b)<<endl;
    }

    return 0;
}
