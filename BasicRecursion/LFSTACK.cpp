#include <bits/stdc++.h>
using namespace std;

vector< stack<int> > v;
vector<int> popped;
set< vector<int> > states;

bool isPossible(int i, int maxIndex)
{
    if(i > maxIndex)
        return true;

    //current state is defined by i and by tops pf stacks in vector v.
    vector<int> cur_state;
    cur_state.push_back(i);
    for(int j=0; j<v.size(); ++j)
        cur_state.push_back((v[j].empty()?-1:v[j].top()));

    //if current state already exist in the set states, the sequence of popped elements is possible from this point onwards
    if(states.find(cur_state) != states.end())
        return true;

    for(int j=0; j<v.size(); ++j)
    {
        if(!v[j].empty())
        {
            if(popped[i] == v[j].top())
            {
                int temp = v[j].top();
                v[j].pop();
                if(isPossible(i+1, maxIndex))
                {
                    states.insert(cur_state);
                    return true;
                }
                else
                    v[j].push(temp);
            }
        }
    }

    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        v.clear();
        popped.clear();
        states.clear();
        int n, a, elem, totElem=0;
        cin>>n;

        while(n--)
        {
            stack<int> s;
            cin>>a;
            totElem += a;
            while(a--)
            {
                cin>>elem;
                s.push(elem);
            }

            v.push_back(s);
        }

        for(int i=0; i<totElem; ++i)
        {
            cin>>elem;
            popped.push_back(elem);
        }

        if(isPossible(0, totElem-1))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}
