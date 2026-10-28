class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int rem;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            rem = target-nums[i];
            if(mp.count(rem)>0)
            {
                return {mp[rem],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};