class Solution {
public:
    int longestValidParentheses(string s) {
        int maxL = 0 ;
        int left = 0 , right = 0 ;
        for(char c : s)
        {
            if(c=='(')left++;

            else right++;

            if(left == right)
            {
                maxL = max(maxL , left+right);
            }
            if(right > left)
            {
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;

        for(int i = s.size()-1; i>=0 ; i--)
        {
            if(s[i]=='(')left++;

            else right++;

            if(left == right)
            {
                maxL = max(maxL , left+right);
            }
            if(right < left)
            {
                left = 0;
                right = 0;
            }
        }

        return maxL;
        
    }
};