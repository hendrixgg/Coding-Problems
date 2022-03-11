#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

#define ll long long
#define cin inFile ///UNCOMMENT DEFINE TO TAKE FILE INPUT


/// prototypes
void test_case();
int seventh(int chord[]);

ifstream inFile("data.in");
const string note[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
unordered_map<string, int> notes;
int N, T;

/**
https://www.quora.com/What-are-some-tips-for-code-C-optimization-
to-get-a-better-time-in-competitive-programming
*/
int main()
{
    // this just makes the printing happen at the end of program only
    ios::sync_with_stdio(0);
	// makes it so that the cout is not flushed everytime
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
        notes[note[i]] = i;
    }

    cin >> T;
    for (int t=0; t<T; ++t) {
        //printf("case %d: ", t);
        test_case();
    }
}

void test_case() {
    int chord[4];
    string n;
    for (int i=0; i<4; ++i) {
        cin >> n;
        chord[i] = notes[n];
    }
    int out = seventh(chord);
    switch (out) {
        case -1:
            cout << "invalid" << "\n";
            break;

        case 0:
            cout << "root" << "\n";
            break;

        case 1:
            cout << "first" << "\n";
            break;

        case 2:
            cout << "second" << "\n";
            break;

        case 3:
            cout << "third" << "\n";
            break;
    }
}

/**
 * root:(chord[0] + 4) % 12 == chord[1]
 *      (chord[1] + 3) % 12 == chord[2]
 *      (chord[2] + 3) % 12 == chord[3]
 *
 *
 */
int seventh(int chord[4]) {
    for (int i = 0; i < 4; i++) {
        if ((chord[(0 - i + 4) % 4] + 4) % 12 == chord[(1 - i  + 4) % 4]) {
            if ((chord[(1 - i  + 4) % 4] + 3) % 12 == chord[(2 - i + 4) % 4]) {
                if ((chord[(2 - i + 4) % 4] + 3) % 12 == chord[(3 - i + 4) % 4]) {
                    return i;
                }
            }
        }
    }
    return -1;
}
