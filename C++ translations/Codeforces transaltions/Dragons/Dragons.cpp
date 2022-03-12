#include <bits/stdc++.h>
using namespace std;

/** https://codeforces.com/problemset/problem/230/B */

// YOU CAN ACTUALLY JUST SORT THE DRAGONS
// FROM WEAKEST TO STRONGEST and if
// you never come across one you can't kill
// print yes, otherwise no
int main()
{
    int S, N, killable=0;
    ios_base::sync_with_stdio(0);
    cin >> S >> N;
    int remain = N;
    int targetDragons[N], dragonstats[N][3];
    for (int i=0; i < N; ++i)
        dragonstats[i][2]=0;
    for (int i=0; i<N; ++i)
    {
        cin >> dragonstats[i][0] >> dragonstats[i][1];
        if (dragonstats[i][0] < S)
            targetDragons[killable++] = i; // killable dragon
    }
    while(remain && killable)
    {
        for(int i = 0; i < killable; ++i)
        {
            dragonstats[targetDragons[i]][2] = 1; // kill dragon
            S += dragonstats[targetDragons[i]][1]; // increase strength
            --remain;
        }
        killable=0;
        for (int i=0; i < N; ++i) // find more dragons to kill
            if (dragonstats[i][0] < S && dragonstats[i][2] != 1)
                targetDragons[killable++] = i;
    }

    if (remain == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
