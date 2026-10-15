class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int ,int>mp;
        int c=0;
        for(int i:nums)
        {
            mp[i]++;
            if(mp[i]%2==0)
              c=c^i;
        }
        return c;
    }
};