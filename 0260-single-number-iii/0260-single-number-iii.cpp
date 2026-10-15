class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int x : arr)
        {
            mp[x]++;
        }
        vector<int>ans;
        for(auto x : mp)
        {
            if(x.second==1)ans.push_back(x.first);
        }
        return ans;
        
    }
};