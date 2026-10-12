class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size()!=b.size())return max(a.size(),b.size());
        int ans = 0;
        for(int i =0 ; i < a.size(); i++)
        {
            if(a[i]!=b[i])return a.size();
        }
        return ans ==0?-1:ans;
    }
};