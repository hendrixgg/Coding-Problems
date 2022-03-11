#include <bits/stdc++.h>
using namespace std;


// reads a number
template <class T>
inline void readInt(T &res){
    char c;
    res=0;
    while((c=getchar())<'0'|c>'9');
    while(c>='0'&&c<='9'){
        res=res*10+(c-'0');
        c=getchar();
    }
}

/** https://codeforces.com/problemset/problem/706/B/ */
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int N, Q, allow;
    readInt(N);
    vector<int> prices(N);
    for (int i = 0; i < N; ++i)
        readInt(prices[i]);
    readInt(Q);
    sort(prices.begin(), prices.end());
    while (Q--)
    {
        readInt(allow);
        int l = -1; // the highest priced shop I CAN BUY from
        int r = N; // the lowest priced shop I CAN'T BUY from
        while (l + 1 < r)
        {
            int m = l + (r - l) / 2;
            if (prices[m] <= allow)
                l = m;
            else
                r = m;
        }
        cout << l + 1 << "\n"; // want the lower bound of search
    }

    return 0;
}
