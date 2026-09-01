class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans  = "";
        stack<int>extra;
        stack<int>st;
        for(int i = 0 ; i < s.size() ;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
                ans+=s[i];
            }
            else if(s[i]==')')
            {
                if(!st.empty())
                {
                    st.pop();
                    ans+=s[i];
                }else extra.push(i);
            }
            else
                ans+=s[i];
        }
        string result = "";
        if(st.empty())return ans;
        for(int i = s.size()-1; i>=0  ; i--)
        {
            if(!st.empty() && i == st.top())
            {
                st.pop();
                continue;
            }
            else if(!extra.empty() && i == extra.top())
            {
                extra.pop();
                continue;
            }
            result+=s[i];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};