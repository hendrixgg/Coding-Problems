#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/longest-word-in-dictionary
class Solution
{
public:
	string longestWord(const vector<string> &words)
	{
		const int MAX_LENGTH = 30;
		vector<vector<int>> sorted(MAX_LENGTH + 1);
		// sort the indexex into buckets based on the length
		for (int i = 0; i < words.size(); ++i)
		{
			sorted[words[i].length()].push_back(i);
		}
		// initialize answer string
		string answer = "";
		unordered_set<string> good;
		good.insert("");
		auto consider = [&](const string &s)
		{
			if (s.length() > answer.length() || s < answer)
			{
				answer = s;
			}
		};

		for (int i = 0; i < sorted.size(); ++i)
		{
			for (const int &j : sorted[i]) // for each word of length i
			{
				const string& s = words[j];
				if (s.length() >= answer.length())
				{
					if (good.count(s.substr(0, i - 1))) // if the string with one less character was present
					{
						consider(s);
						good.insert(s);
					}
				}
			}
		}
		return answer;
	}
};