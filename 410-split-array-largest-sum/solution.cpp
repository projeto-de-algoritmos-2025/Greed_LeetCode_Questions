#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& nums, int max_sum, int k) {
        int counter = 1, current_sum = 0;
        for (int num : nums) {
            if (current_sum + num > max_sum) {
                counter++;
                current_sum = num;
            } else {
                current_sum += num;
            }
        }
        return counter <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (canSplit(nums, mid, k)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4,5};
    int k = 2;

    cout << s.splitArray(nums, k) << "\n";

    return 0;
}
