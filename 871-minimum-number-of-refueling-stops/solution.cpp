#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> maxHeap;
        int fuel = startFuel;
        int stops = 0;
        int i = 0;

        while (fuel < target) {
            while (i < n && stations[i][0] <= fuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }

            if (maxHeap.empty()) return -1;

            fuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }
        
        return stops;
    }
};

int main() {
    Solution s;
    int target = 100, startFuel = 10;
    vector<vector<int>> stations = {
        {10, 60},
        {20, 30},
        {30, 30},
        {60, 40}
    };

    cout << s.minRefuelStops(target, startFuel, stations) << "\n";

    return 0;
}
