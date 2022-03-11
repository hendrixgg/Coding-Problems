#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, swaps = 0;
    string s;
    cin >> n >> s;

    for(int i = 0, j; i < n; i = j)
    {
        j = i;
        while(j < n && s[i] == s[j]) 
            ++j;
        string r = "RGB";
        r.erase(r.find(s[i]), 1);
        if(j < n)
            r.erase(r.find(s[j]), 1);
        for(int k = i + 1; k < j; k+=2)
        {
            ++swaps;
            s[k] = r[0];
        }
    }
    cout << swaps << nl << s;
    return 0;
}