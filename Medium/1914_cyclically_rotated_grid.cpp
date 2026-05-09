#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans = grid;
        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            vector<int> vals;

            int top = layer;
            int bottom = m - 1 - layer;
            int left = layer;
            int right = n - 1 - layer;

            // clockwise order
            for (int j = left; j <= right; j++)
                vals.push_back(grid[top][j]);

            for (int i = top + 1; i <= bottom; i++)
                vals.push_back(grid[i][right]);

            for (int j = right - 1; j >= left; j--)
                vals.push_back(grid[bottom][j]);

            for (int i = bottom - 1; i > top; i--)
                vals.push_back(grid[i][left]);

            int len = vals.size();
            int rot = k % len;

            int idx = rot;

            for (int j = left; j <= right; j++)
                ans[top][j] = vals[idx++ % len];

            for (int i = top + 1; i <= bottom; i++)
                ans[i][right] = vals[idx++ % len];

            for (int j = right - 1; j >= left; j--)
                ans[bottom][j] = vals[idx++ % len];

            for (int i = bottom - 1; i > top; i--)
                ans[i][left] = vals[idx++ % len];
        }

        return ans;
    }
};