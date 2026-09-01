class Solution {
public:
    int count = 0 ;
    void solve(vector<int>& nums, int target ,int sum,int i)
    {
        if(i==nums.size()){
            if(sum == target)count++;
            return;
        }


        solve(nums,target,sum+(-1*nums[i]),i+1);
        solve(nums,target,sum+nums[i],i+1);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums,target,0,0);
        return count;
    }
};