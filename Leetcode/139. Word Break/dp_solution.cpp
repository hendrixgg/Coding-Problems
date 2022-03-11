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

/**
 * time complexity = O(|s|*|s|*|s|)
 * 
 * Could compute rolling hash of string tmp, this would reduce complexity to O(|s|^2).
 * 
 * Also could use TRIE to store dictionary, this would make complexity:
 * O(sum_of_lengths_of_words_in_dict + |s|*min(|s|, length_of_longest_word_in_dict))
 */
bool wordBreak2(string s, vector<string>& wordDict) 
{
	unordered_set<string> dict(wordDict.begin(), wordDict.end());
	vector<bool> dp(s.length()+1);
	dp[0] = true;
	// dp[i] = can use some (or none) words from wordDict to form a prefix of s that ends at position i-1
	for(int i = 0; i < s.length(); ++i)
	{
		if(!dp[i])
			continue;
		string tmp(&s[i], 1);
		for(int j = i; i+tmp.length() <= s.length(); tmp+=s[++j])
		{
			if(dict.count(tmp))
			{
				// cout << tmp << '\n';
				dp[i+tmp.length()] = true;
				if(i + tmp.length() == s.length())
					return true;
			}
		}
	}
	return false;
}

/**
 * time complexity = O(|s+1|*sum_of_lengths_in_wordDict)
 */
bool wordBreak(string s, vector<string>& wordDict)
{
	vector<bool> dp(s.length()+1);
	dp[0] = true;
	// dp[i] = can use some (or none) words from wordDict to form a prefix of s that ends at position i-1
	for(int i = 0; i < s.length(); ++i)
	{
		if(!dp[i])
			continue;
		for(const string& word : wordDict)
		{									// string_view uses less memory
			if(i+word.length() <= s.length() && string_view(&s[i],word.length()) == word)
			{
				dp[i+word.length()] = true;
				if(i+word.length() == s.length())
					return true;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<string> wordDict(n);
	for (string &word : wordDict)
		cin >> word;
	cout << boolalpha << wordBreak(s, wordDict) << nl;
	return 0;
}