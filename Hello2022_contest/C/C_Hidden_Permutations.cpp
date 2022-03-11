#include <bits/stdc++.h>
using namespace std;

/* global variables */

/* global variables */

/*
hidden;
4 2 1 3

q:
1 2 3 4 -- what you get form 1st
4 2 1 3 -- what you get from 2nd
3 2 4 1 -- what you get from 3rd

1 2 3 4 -- what you get from 4th
4 2 1 3 -- what you get from 5th
3 2 4 1 -- what you get from 6th

hidden:
1 3 4 2

q:
1 2 3 4
1 3 4 2
1 4 2 3
1 2 3 4
1 3 4 2
1 4 2 3
1 2 3 4
1 3 4 2
1 4 2 3
*/

void TestCase()
{
    int n;
    cin >> n;
    vector<int> p(n+1);
    int found = 0, prev = 0, curr = 0, origin = 0;
    for(int i = 1; i <= n && found < n; ++i)
    {
        while(p[i] != 0) ++i;
        // query the i-th element
        cout << "? " << i << endl;
        cin >> origin;
        // query what ends up at i-th position
        cout << "? " << i << endl;
        cin >> curr;
        // assign the permutation
        p[origin] = curr;
        prev = curr;
        ++found;
        // while we have yet to cycle back to the original value
        while(prev != origin)
        {
            cout << "? " << i << endl;
            cin >> curr;
            p[prev] = curr;
            ++found;
            prev = curr;
        }
    }
    // print the permutation
    cout << "! ";
    for(int i = 1; i <= n; ++i)
    {
        cout << p[i] << ' ';
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TTT;
    for (cin >> TTT; TTT != 0; --TTT)
        TestCase();
    return 0;
}