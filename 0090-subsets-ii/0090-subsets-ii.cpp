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

        int idx = i+1;
        while(idx<n && nums[idx]==nums[idx-1])idx++;

        ans.pop_back();
        solve(nums,idx,n,ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        solve(nums,0,nums.size(),ans);
        return result;
    }
};