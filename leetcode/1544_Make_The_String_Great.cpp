class Solution {
  public:
      bool isSame(char s, char t)
      {
          return s==t-32 || t == s-32;
      }
      string makeGood(string s) {
          string ans = "";
          ans.push_back(s[0]);
          for(int i = 1 ; i< s.size(); i++)
          {
              if(!ans.empty() && isSame(ans.back(),s[i]))
                  ans.pop_back();
              else 
                  ans.push_back(s[i]);
  
          }
          return ans;
  
          
      }
  };