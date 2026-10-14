class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        int n= s.size();
        for(int i = 0 ; i<n ; i++)
        {
            mp[s[i]]++;
        }
        for(auto x : mp)
        {
            pq.push({x.second,x.first});
        }
        string ans="";
        while(!pq.empty())
        {
            auto [n,c] = pq.top();
            pq.pop();
            while(n--)
            {
                ans+=c;
            }
        }
        
        return ans;
        
    }
};