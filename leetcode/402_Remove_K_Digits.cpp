class Solution {
  public:
      string removeKdigits(string nums, int k) {
          if(nums.size()==k)return "0";
          string ans = "";
  
          stack<char>st;
          for(int i = 0 ; i< nums.size(); i++)
          {
              while(!st.empty() && st.top()>nums[i] && k>0){
                  st.pop();
                  k--;
              }
              st.push(nums[i]);
          }
          while(k>0){
              st.pop();
              k--;
          }
          while(!st.empty())
          {
              ans+=st.top();
              st.pop();
          }
          int i = 0;
          reverse(ans.begin(),ans.end());
          while(i < ans.size() && ans[i] == '0')
              i++;
  
          if(i == ans.size())
              return "0";
          return ans.substr(i);
      }
  };