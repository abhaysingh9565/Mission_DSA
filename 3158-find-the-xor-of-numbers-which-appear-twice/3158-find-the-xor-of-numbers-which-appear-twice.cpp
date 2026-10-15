class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int n : nums)mp[n]++;

        int ans = 0;
        for(auto x : mp)
        {
            if(x.second==2)ans^=x.first;
        }
        return ans;
        
    }
};