class Solution {
    vector<vector<int>>result;
private:
    void solve(vector<int>& nums,int i , int n,vector<int>& ans)
    {
        if(i>=n)
        {
            result.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        solve(nums,i+1,n,ans);
        ans.pop_back();
        while(i<n-1 && nums[i+1]==nums[i])i++;
        solve(nums,i+1,n,ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        solve(nums,0,nums.size(),ans);
        return result;
    }
};