class Solution {
public:
    int maxDepth(string s) {
        int ans = 0 ;
        int left = 0;
        for(char c : s)
        {
            if(c =='('){
                left++;
                ans = max(ans,left);
            }
            else if(c==')')left--;
        }
        return ans;
    }
};