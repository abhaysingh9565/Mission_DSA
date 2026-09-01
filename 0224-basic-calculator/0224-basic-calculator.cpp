class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        long number = 0 ;
        long result = 0 ;
        int sign = 1;
        for(char c : s)
        {
            if(isdigit(c))
            {
                number = number *10 + (c-'0');
            }
            else if(c == '+')
            {
                result += (number*sign);
                sign = 1;
                number = 0;
            }
            else if(c == '-')
            {
                result += (number*sign);
                sign = -1;
                number = 0;
            }
            else if ( c=='(')
            {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1 ;
                number = 0;
            }
            else if(c == ')')
            {
                result += (number*sign);
                number = 0;
                result = result * st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        result += (number*sign);

        return result;
        
    }
};