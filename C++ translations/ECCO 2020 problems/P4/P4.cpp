#include <iostream>
#include <fstream>
#include <unordered_map>
#include <stack>
#include <array>
using namespace std;

#define ll long long
#define cin inFile ///UNCOMMENT DEFINE TO TAKE FILE INPUT


/// prototypes
void takeInput(string& op);
void ADD(const ll& a);
void SUB(const ll& a);
void MULT(const ll& a);
void FUN(string& name);

class Function {
public:
    ll mult, add, sub;

    Function():mult(1), add(0), sub(0){}

    Function(ll& m, ll& a, ll& s):mult(m), add(a), sub(s){}

    void call() {
        MULT(mult);
        ADD(add);
        SUB(sub);
    }
};

unordered_map<string, Function> functions;
ifstream inFile("data.in");
ll X, MOD = (long long) 1e9 +7;
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

    cin >> T;
    for (int t=0; t<T; ++t) {
        X=0;
        functions = unordered_map<string, Function>();
        cin >> N;
        for (int n=0; n<N; ++n) {
            string input;
            cin >> input;
            takeInput(input);
        }
        cout <<"result " << t << ": " << X << " #of functions: " << functions.size() << "\n";
    }
}
/*
result 0: 801119017 #of functions: 0
result 1: 999999991 #of functions: 0
result 2: 277808625 #of functions: 0
result 3: 457136929 #of functions: 1
result 4: 205866163 #of functions: 1
result 5: 625588590 #of functions: 16666
result 6: 895983945 #of functions: 45004
result 7: 941678053 #of functions: 16663
result 8: 519754914 #of functions: 17959
result 9: 881303624 #of functions: 16722
*/
void takeInput(string& op) {
    ll num;
    if(op=="ADD") {
        cin >> num;
        ADD(num);
    } else if(op=="SUB") {
        cin >> num;
        SUB(num);
    } else if(op=="MULT") {
        cin >> num;
        MULT(num);
    } else if(op=="FUN") {
        FUN(op);
    } else if(op=="CALL") {
        cin >> op;
        functions[op].call();
    }
}

void FUN(string& input) {
    stack<string> toMake;
    stack<array<ll, 3>> vals;
    string fName;
    do {
        ll num;
        if (input=="FUN"){
            vals.push({1, 0, 0});
            cin >> fName; /// name of the function to be made
            toMake.push(fName);
        } else if (input=="END") {
            functions.emplace(toMake.top(), Function(vals.top()[0], vals.top()[1], vals.top()[2]));
            toMake.pop();
            vals.pop();
        }  else if(input=="MULT"){
            cin >> num;
            vals.top()[0] = (vals.top()[0] * num) % MOD;
            vals.top()[1] = (vals.top()[1] * num) % MOD;
            vals.top()[2] = (vals.top()[2] * num) % MOD;
        } else if(input=="ADD"){
            cin >> num;
            vals.top()[1] = (vals.top()[1] + num) % MOD;
        } else if(input=="SUB"){
            cin >> num;
            vals.top()[2] = (vals.top()[2] + num) % MOD;
        } else if(input=="CALL") {
            cin >> fName; /// name of the function to be called
            Function* f = &functions[fName];
            vals.top()[0] = (vals.top()[0] * f->mult) % MOD;
            vals.top()[1] = (vals.top()[1] * f->mult + f->add) % MOD;
            vals.top()[2] = (vals.top()[2] * f->mult + f->sub) % MOD;
        }

        if (!toMake.empty()){
            --N; /// need to account for taking input
            cin >> input; // next action to occur
        }
    } while(!toMake.empty());
}
void ADD(const ll& a) {
    X += a;
    if (X > MOD)
        X -= MOD;
}

void SUB(const ll& a) {
    X -= a;
    if (X < 0)
        X += MOD;
}

void MULT(const ll& a) {
    X = (X * a) % MOD;
}
