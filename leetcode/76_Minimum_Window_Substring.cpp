class Solution {
  public:
      string minWindow(string s, string t) {
          unordered_map<char,int>mp;
          for(char c : t)
          {
              mp[c]++;
          }
          int start = 0;
          int minLen = INT_MAX;
          int b = 0;
          int count = t.size();
          for(int e = 0 ; e<s.size();e++)
          {
              if(mp.count(s[e])!=0)
              {
                  if(mp[s[e]]>0)
                  {
                      count--;
                  }
                  mp[s[e]]--;
              }
              while(count == 0)
              {
                  if (e - b + 1 < minLen) {
                      minLen = e - b + 1;
                      start = b;
                  }
  
                  if(mp.count(s[b]) != 0)
                  {
                      mp[s[b]]++;
  
                      if(mp[s[b]] > 0)
                          count++;
                  }
                  b++;
              }
  
          }
          return minLen==INT_MAX? "":s.substr(start,minLen);
          
      }
  };
  