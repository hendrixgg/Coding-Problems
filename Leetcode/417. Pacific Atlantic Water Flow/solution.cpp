#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
	{
		if (heights.empty())
			return {};

		const int H = heights.size(), W = heights[0].size();

		// check if a cell is inside the matrix
		auto inside = [&](const int &row, const int &col)
		{ return -1 < row && row < H && -1 < col && col < W; };

		// cnt[r][c] == 2 if (r, c) is in the output
		vector<vector<int>> cnt(H, vector<int>(W));
		vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		// ocean = 0: pacific, ocean = 1: atlantic
		for (const int ocean : {0, 1})
		{
			// BFS from cells adjacent to the ocean
			vector<pair<int, int>> q;
			vector<vector<bool>> vis(H, vector<bool>(W));
			// visite cells on the border
			for (int col = 0; col < W; ++col)
				q.emplace_back((ocean == 0 ? 0 : H - 1), col);
			for (int row = 0; row < H; ++row)
				q.emplace_back(row, (ocean == 0 ? 0 : W - 1));
			for (const auto &[row, col] : q)
				vis[row][col] = true;

			// now do BFS
			for (int i = 0; i < (int)q.size(); ++i)
			{
				const auto [row, col] = q[i];
				for (const auto &[drow, dcol] : dir)
				{
					const int new_row = row + drow, new_col = col + dcol;
					if (inside(new_row, new_col) && !vis[new_row][new_col] && heights[row][col] <= heights[new_row][new_col])
					{
						vis[new_row][new_col] = true;
						q.emplace_back(new_row, new_col);
					}
				}
			}
			for (int row = 0; row < H; ++row)
			{
				for (int col = 0; col < W; ++col)
				{
					if (vis[row][col])
						++cnt[row][col];
				}
			}
		}
		vector<vector<int>> peaks;
		for (int row = 0; row < H; ++row)
		{
			for (int col = 0; col < W; ++col)
			{
				if (cnt[row][col] == 2)
					peaks.push_back({row, col});
			}
		}
		return peaks;
	}
};
// faster solution
class Solution2
{
	static const int PAC = 1, ATL = 2, BOTH = 3;
	static constexpr int DIR[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
	{
		const int m = heights.size(), n = heights[0].size();
		vector<vector<int>> bitmask(m, vector<int>(n, 0));
		vector<vector<int>> res;

		function<void(int, int, int, int)> dfs = [&](const int row, const int col, const int ocean, const int prev)
		{
			// Out of bounds
			if (row < 0 || m <= row || col < 0 || n <= col)
				return;
			// Invalid flow
			if (heights[row][col] < prev)
				return;
			// Already visited
			if ((bitmask[row][col] & ocean) == ocean)
				return;

			// Set bitmask for this ocean (marks visited as well)
			bitmask[row][col] |= ocean;

			for (int d = 0; d < 4; ++d)
			{
				const int new_row = row + DIR[d][0];
				const int new_col = col + DIR[d][1];
				dfs(new_row, new_col, ocean, heights[row][col]);
			}
		};
		// Top row for Pacific Ocean
		for (int j = 0; j < n; ++j)
			dfs(0, j, PAC, INT_MIN);
		// Left column for Pacific ocean
		for (int i = 1; i < m; ++i)
			dfs(i, 0, PAC, INT_MIN);

		// Right column for Atlantic ocean
		for (int i = 0; i < m; ++i)
			dfs(i, n - 1, ATL, INT_MIN);
		// Bottom row for Atlantic ocean
		for (int j = 0; j < n - 1; ++j)
			dfs(m - 1, j, ATL, INT_MIN);

		// Find solutions with both flows
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (bitmask[i][j] == BOTH)
					res.push_back({i, j});
		return res;
	}
};