class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums , int i )
    {
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i]!= -1){
            return dp[i];
        }
        int steal = nums[i]+solve(nums,i+2);
        int skip = solve(nums,i+1);

        return dp[i] = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return solve(nums,0);
    }
};