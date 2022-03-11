#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int INF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
#define dbarr(x, n) cerr << #x << ": ",_dbarr((x), (n))
#define dbarrt(x, n) cerr << #x << ": " << '\n',_dbarrt((x), (n))
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define PI 3.141592653589793238L
const char nl = '\n';
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
  cerr << ' ' << H;
  dbg_out(T...);
}
template <typename T>
void _dbarr(const T* a, size_t sz)
{
  for (size_t i = 0; i < sz; i++)
    cerr << a[i] << " \n"[i == sz - 1];
}
template <typename T>
void _dbarr(const vector<T> a, size_t sz)
{
  for (size_t i = 0; i < sz; i++)
    cerr << a[i] << " \n"[i == sz - 1];
}
template <typename T>
void _dbarrt(const vector<T> &a, size_t sz)
{
  for (size_t i = 0; i < sz; ++i)
    cerr << a[i] << '\n';
  cerr << "i:" << '\n';
  for (size_t i = 0; i < sz; ++i)
    cerr << i << '\n';
}
template <typename T>
void _dbarrt(const T* a, size_t sz)
{
  for (size_t i = 0; i < sz; ++i)
    cerr << a[i] << '\n';
  cerr << "i:" << '\n';
  for (size_t i = 0; i < sz; ++i)
    cerr << i << '\n';
}

/* global variables */

/* global variables */

void TestCase()
{
  int k, n;
  cin >> n >> k;
  if(k > (n+1)/2)
  {
    cout << "-1" << nl;
    return;
  }
  vector<string> board(n, string(n, '.'));
//   board[0][0] = 'R';
  for(int i = 0; i < n && (i>>1) < k; i += 2)
  {
      board[i][i] = 'R';
  }
  for(const string& s : board)
  {
      cout << s << nl;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();
  int TTT;
  for (cin >> TTT; TTT != 0; --TTT)
    TestCase();
  return 0;
}