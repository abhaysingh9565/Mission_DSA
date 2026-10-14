class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> st;
        sort(words.begin(),words.end());
        int n = words.size();

        for(string num : words)
            st[num]++;
        
        vector<vector<string>>freq(n+1,vector<string>());
        for(auto [num,frequency]:st)
        {
            freq[frequency].push_back(num);
        }

        vector<string> ans;

        for(int i = n ; i >=0 ; i--)
        {
            if(freq[i].size() !=0){
                sort(freq[i].begin(),freq[i].end());
                for(string s : freq[i])
                {
                    ans.push_back(s);
                    if(ans.size()==k)return ans;
                }
            }

        }
        return ans;
    }
};