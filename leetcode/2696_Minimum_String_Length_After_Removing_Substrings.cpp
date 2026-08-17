class Solution {
  public:
      int minLength(string s) {
          string ans = "";
          for(int i = 0 ;i<s.size();i++)
          {
              if(ans.empty())
              {
                  ans.push_back(s[i]);
                  continue;
              }
              if(ans.back()=='A' && s[i]=='B')
              {
                  ans.pop_back();
                  continue;
              }
              if(ans.back()=='C' && s[i]=='D')
              {
                  ans.pop_back();
                  continue;
              }
              ans.push_back(s[i]);
          }
          return ans.size();
          
      }
  };