#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
  public:
      vector<int> findAnagrams(string s, string p) {
          if(s.size()<p.size())return {};
          vector<int>freq(26,0);
          vector<int>freq2(26,0);
          for(int i =0 ; i< p.size();i++)
          {
              freq[p[i]-'a']++;
              freq2[s[i]-'a']++;
          }
          vector<int>ans;
          for(int j = p.size();j<s.size();j++)
          {
              if(freq==freq2)
              {
                  ans.push_back(j-p.size());
              }
              freq2[s[j]-'a']++;
              freq2[s[j-p.size()]-'a']--;
          }
          if(freq==freq2)
              {
                  ans.push_back(s.size()-p.size());
              }
          return ans;
          
      }
  };