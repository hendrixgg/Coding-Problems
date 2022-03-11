#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-word-in-dictionary
class Solution
{
	void dfs(int node, string& current, string &answer, const vector<vector<int>>& nxt, const vector<bool> is_terminal)
	{
		// strings are considered in increasing lexicographic order because the loop below iterates over characters a,b,c,...,z
		if (current.length() > answer.length())
			answer.assign(current);
		for (int c = 0; c < 26; ++c)
		{
			const int &tmp = nxt[node][c];
			if (tmp != 0 && is_terminal[tmp])
			{
				current.push_back(char(c + 'a'));
				dfs(tmp, current, answer, nxt, is_terminal);
				current.pop_back();
			}
		}
	}

public:
	string longestWord(const vector<string> &words)
	{
		vector<vector<int>> nxt(1, vector<int>(26));
		vector<bool> is_terminal(1);
		int N = 0; // will be the next available id
		for (const string &s : words)
		{
			int node = 0;
			for (const char &c : s)
			{
				if (nxt[node][c - 'a'] == 0)
				{
					nxt.push_back(vector<int>(26));
					is_terminal.push_back(false);					
					nxt[node][c - 'a'] = ++N;
				}
				node = nxt[node][c - 'a'];
			}
			is_terminal[node] = true;
		}
		string answer = "", current = "";
		dfs(0, current, answer, nxt, is_terminal);
		return answer;
	}
};