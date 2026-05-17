#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int index = q.front();
            q.pop();

            // If value is 0, answer is true
            if (arr[index] == 0) {
                return true;
            }

            int forward = index + arr[index];
            int backward = index - arr[index];

            // Jump forward
            if (forward < n && !visited[forward]) {
                visited[forward] = true;
                q.push(forward);
            }

            // Jump backward
            if (backward >= 0 && !visited[backward]) {
                visited[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};