class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> st;
        int n = nums.size();

        for(int num : nums)
            st[num]++;

        vector<vector<int>> freq(n + 1);

        for(auto x : st)
            freq[x.second].push_back(x.first);

        vector<int> ans;

        for(int i = n; i >= 1 && k > 0; i--)
        {
            for(int num : freq[i])
            {
                ans.push_back(num);
                k--;

                if(k == 0)
                    break;
            }
        }

        return ans;
    }
};