#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

#define ll long long
#define cin inFile ///UNCOMMENT DEFINE TO TAKE FILE INPUT


/// prototypes
void test_case();

ifstream inFile("data.in");
/**
https://www.quora.com/What-are-some-tips-for-code-C-optimization-
to-get-a-better-time-in-competitive-programming

IF A VARIABLE DOES NOT NEED TO BE GLOBAL, DO NOT MAKE IT GLOBAL!!!!!!!!!!!!
*/
int main()
{
    // this just makes the printing happen at the end of program only
    ios::sync_with_stdio(0);
	// makes it so that the cout is not flushed everytime
	cin.tie(0);
    int T;
    cin >> T;
    for (int t=0; t<T; ++t) {
        //printf("case %d: ", t);
        test_case();
    }
}

void test_case() {
    int numStores, itemsAtStore, total_cost=0, toBuy, itemPrice, itemQty;
    cin >> numStores;
    string s; // name of an item
    // string=itemName, the vector: pair.first=price, pair.second=qty
    unordered_map<string, vector<pair<int,int>>> items;

    // available items
    for (int i=0; i<numStores; ++i) {
        cin >> itemsAtStore;
        for (int j=0; j < itemsAtStore; ++j) {
            cin >> s;
            cin >> itemPrice; // price
            cin >> itemQty; // quantity
            if (items.count(s) == 0) { // if item is new
                vector<pair<int, int>> item;
                item.push_back(make_pair(itemPrice,itemQty));
                items[s] = item;
            } else {
                items[s].push_back(make_pair(itemPrice,itemQty));
            }
        }
    }

    cin >> toBuy;
    int qty;
    for (int i=0; i<toBuy; ++i) {
        cin >> s;
        cin >> qty;
        vector<pair<int, int>> item = items[s];
        std::sort(item.begin(), item.end()); // https://www.geeksforgeeks.org/sorting-a-vector-in-c/
        for (int n=0, k=0; k<qty; ++k) {
            if (item[n].second > 0) {
                total_cost += item[n].first;
                --item[n].second;
            } else {
                ++n;
                --k;
            }
        }
        /* I thought this would be a lot faster but I guess not
         - probbably because the max the max cost and quantity is small (<100)
        for (int i=0; i < item.size() && qty > 0; ++i) {
            // item[t].second is always > 0 to begin with
            if (item[i].second <= qty) {
                qty -= item[i].second;
                total_cost += item[i].first * item[i].second;
            } else {
                total_cost += item[i].first * qty;
                qty=0;
            }
        }
        */
    }
    //printf("%d\n", total_cost);
    cout << total_cost << "\n";
}

/*
1
2
2
toiletpaper 1 50
catnip 2 25
1
toiletpaper 100 1
2
toiletpaper 51
catnip 10

*/
