#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        int start = 0;
        int currMax = 0;

        for (int i = 0; i < n; i++) {
            currMax = max(currMax, nums[i]);

            if (i == n - 1 || currMax <= suffixMin[i + 1]) {
                for (int j = start; j <= i; j++) {
                    ans[j] = currMax;
                }

                start = i + 1;
                currMax = 0;
            }
        }

        return ans;
    }
};