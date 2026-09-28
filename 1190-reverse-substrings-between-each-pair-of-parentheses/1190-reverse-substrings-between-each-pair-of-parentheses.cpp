class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<char,int>>st;
        string ans;
        for(int i = 0 ; i < s.size(); i++)
        {
            char c = s[i];
            if(c == '(')
            {
                st.push({c,i});
            }
            else if(c == ')')
            {
                int j = st.top().second;
                st.pop();
                reverse(ans.begin()+j+1,ans.end());
            }
                ans+=c;
        }
        string result="";
        for(int i = 0 ; i < ans.size(); i++)
        {
            if(ans[i]=='(' || ans[i]==')')continue;
            result += ans[i];
        }
        return result;
    }
};