class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        int n= s.size();
        for(int i = 0 ; i<n ; i++)
        {
            mp[s[i]]++;
        }
        vector<vector<char>>freq(n+1);
        for(auto x : mp)
        {
            int n = x.second;
            while(n--)
            freq[x.second].push_back(x.first);
        }
        string ans="";
        for(int i = n ; i>=1;i--)
        {
            for(char c : freq[i])
            {
                ans+=c;
            }
        }
        return ans;
        
    }
};