class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int ans = 0 ;
        for(char c : s)
        {
            if(c == '(')st.push(c);
            else{
                if(st.empty()){
                    ans++;
                    continue;
                }
                st.pop();
            }
        }

        return ans+st.size();
        
    }
};