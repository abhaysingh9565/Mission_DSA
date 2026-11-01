class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 1 ; i < n ; i++)
        {
            nums[i]=nums[i-1]+nums[i];
        }

        unordered_map<int,int>mp;

        for(int i =0 ; i < n ; i++)
        {
            if(nums[i] == k)count++;

            int val = nums[i]-k;
            if(mp.count(val)!=0 || nums[i]==k){
                count+= mp[val];
            }
            mp[nums[i]]++;
        }
        return count;
    }
};