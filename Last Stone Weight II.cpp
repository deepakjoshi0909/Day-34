class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(),stones.end(),0);
        int target = sum/2;
        vector<int>dp(target+1,0);

        for(int stone: stones){
            for(int j = target; j>= stone; j--){
                dp[j] = max(dp[j], dp[j-stone]+stone);
            }
        }

        return sum - 2*dp[target];
    }
};
