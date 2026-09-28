class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<char,int>>st;
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
                reverse(s.begin()+j+1,s.begin()+i);
            }
        }
        string result="";
        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i]=='(' || s[i]==')')continue;
            result += s[i];
        }
        return result;
    }
};