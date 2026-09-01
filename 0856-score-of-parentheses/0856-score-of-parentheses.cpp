class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int ans = 0 ;
        int count = 0 ;
        for(char c : s)
        {
            if(c == '(')
            {
                st.push(0);
            }
            else{
                int score = st.top()==0 ? 1 : st.top()*2;
                st.pop();
                score = score + st.top();
                st.pop();
                st.push(score);
            }
        }
        return st.top();
        
    }
};