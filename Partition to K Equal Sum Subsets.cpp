class Solution {
public:
    bool solve(vector<int>& nums, int k, int target, vector<int>& subset, int idx) {
        if (idx == nums.size()) {
            for (int i = 0; i < subset.size(); i++) {
                if (subset[i] != target) return false;
            }
            return true;
        }

        for (int i = 0; i < subset.size(); i++) {
            if (subset[i] + nums[idx] <= target) {
                subset[i] += nums[idx];
                if (solve(nums, k, target, subset, idx + 1)) return true;
                subset[i] -= nums[idx];
            }
            if (subset[i] == 0) break; 
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> subset(k, 0);

        return solve(nums, k, target, subset, 0);
    }
};
