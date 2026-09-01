class Solution {
public:
    string decodeString(string s) {
        // stack<int>times;
        // stack<int>strs;
        // int num = 0 ;
        // string ans = "";
        // string curr = "";
        // for(int i = 0 ;i<s.size(); i++){
        //     if(isdigit(s[i]))
        //     {
        //         num = num * 10 + (s[i]-'0');
        //     }
        //     else if(s[i]=='[')
        //     {
        //         times.push(num);
        //         strs.push(curr);
        //         num = 0 ;
        //         curr="";
        //     }

        //     else if(s[i]==']')
        //     {
        //         int no = times.top();
        //         times.pop();
        //         string prev = strs.top();
        //         strs.pop();

        //         string temp = "";

        //         for (int i = 0; i < times; i++) {
        //             temp += curr;
        //         }

        //         curr = prev + temp;
        //     }
        //     else {
        //         curr += s[i];
        //     }
        // }
        // return curr;

        stack<char>st;
        for(char c : s)
        {
            if(c != ']'){
                st.push(c);
            }
            else{
                string str = "";
                while(st.top() != '['){
                    str = st.top()+str;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && isdigit(st.top()))
                {
                    num = st.top()+num;
                    st.pop();
                }
                int repeat = stoi(num);
                string repeated = "";
                while(repeat--)
                {
                    repeated += str;
                }
                for(char c : repeated)
                {
                    st.push(c);
                }
            }
        }
        string result = "";
        while(!st.empty())
        {
            result = st.top()+result;
            st.pop();
        }
        return result;
        
    }
};