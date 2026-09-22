class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        for(int i = 0 ; i< nums.size();i++)
        {
            int b = i+1,e = nums.size()-1;
            while(b<e)
            {
                int sum = nums[b]+nums[e];
                if(sum==abs(nums[i]))
                {
                    st.insert({nums[i],nums[b],nums[e]});
                    b++;
                    e--;
                }
                else if(sum < abs(nums[i]))
                b++;
                else e--;
            }
        }
        for(auto x : st)
        ans.push_back(x);
        return ans;
        
    }
};