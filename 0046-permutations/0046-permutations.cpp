class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>& nums,int n)
    {
        if(n==nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i = n;i<nums.size();i++)
        {
            swap(nums[i],nums[n]);
            solve(nums,n+1);
            swap(nums[i],nums[n]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ans;
        solve(nums,0);
        return result;
        
    }
};