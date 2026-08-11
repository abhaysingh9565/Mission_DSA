#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;  
class Solution {
  public:
      string removeDuplicates(string s) {
          stack<char>st;
          string ans = "";
          bool flag = false;
          for(int i  = 0 ; i< s.size() ; i++)
          {
              while(!st.empty() && st.top()==s[i]){
                  st.pop();
                  flag = true;
              }
              if(flag){
                  flag = false;
                  continue;
              }
              st.push(s[i]);
          }
          while(!st.empty())
          {
              ans += st.top();
              st.pop();
          }
          reverse(ans.begin(),ans.end());
          return ans;
          
      }
  };