class Solution {
public:
    vector<vector<int>>result;
    void solve (vector<int>& nums , vector<int>& ans , int i , int n ){
        if(i>=n)
        {
            result.push_back(ans);
            return ;
        }
        ans.push_back(nums[i]);
        solve(nums,ans, i+1, n);
        ans.pop_back();
        solve(nums,ans, i+1 , n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        solve(nums,ans, 0 , nums.size());
        return result;
        
    }
};